/*
 * FreeRTOS V202112.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* Standard includes. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#include "PacketDrillHandlerTask.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* If ipconfigUSE_TCP_WIN is 1 then the Tx sockets will use a buffer size set by
ipconfigTCP_TX_BUFFER_LENGTH, and the Tx window size will be
configECHO_SERVER_TX_WINDOW_SIZE times the buffer size.  Note
ipconfigTCP_TX_BUFFER_LENGTH is set in FreeRTOSIPConfig.h as it is a standard TCP/IP
stack constant, whereas configECHO_SERVER_TX_WINDOW_SIZE is set in
FreeRTOSConfig.h as it is a demo application constant. */
#ifndef configECHO_SERVER_TX_WINDOW_SIZE
	#define configECHO_SERVER_TX_WINDOW_SIZE	20
#endif

/* If ipconfigUSE_TCP_WIN is 1 then the Rx sockets will use a buffer size set by
ipconfigTCP_RX_BUFFER_LENGTH, and the Rx window size will be
configECHO_SERVER_RX_WINDOW_SIZE times the buffer size.  Note
ipconfigTCP_RX_BUFFER_LENGTH is set in FreeRTOSIPConfig.h as it is a standard TCP/IP
stack constant, whereas configECHO_SERVER_RX_WINDOW_SIZE is set in
FreeRTOSConfig.h as it is a demo application constant. */
#ifndef configECHO_SERVER_RX_WINDOW_SIZE
	#define configECHO_SERVER_RX_WINDOW_SIZE	20
#endif

/* Rx and Tx time outs are used to ensure the sockets do not wait too long for
missing data. */
// static const TickType_t xConnectTimeOut = pdMS_TO_TICKS( 1000 );
// static const TickType_t xReceiveTimeOut = portMAX_DELAY;
// static const TickType_t xSendTimeOut = pdMS_TO_TICKS( 10000 );

static uint32_t getFreeRTOSSinAddr(struct in_addr sin_addr);
static struct in_addr getUnixSinAddr(uint32_t freertosSinAddr);

ssize_t IntToString(char *s, int x);

#define MAX_SOCKET_ARRAY 10

Socket_t socketArray[MAX_SOCKET_ARRAY] = {NULL, NULL, NULL};
int socketCounter = 3;

uint8_t destinationMacBytes[6] = {0x46, 0xE7, 0xD7, 0xAA, 0x9B, 0x5F};

#define echoECHO_PORT				  ( 7 )

static void handlePacketDrillCommand(struct SyscallPackage *syscallPackage, struct SyscallResponsePackage *syscallResponse) {

    for (;;) {

            FreeRTOS_debug_printf(("Packetdrill command received: %s\n", syscallPackage->syscallId));

            int8_t response = 0;

            if (strcmp(syscallPackage->syscallId, "socket_create") == 0) {
                /* Create a TCP socket. */

                #if( ipconfigUSE_TCP_WIN == 1 )
                    WinProperties_t xWinProps;

                    /* Fill in the buffer and window sizes that will be used by the socket. */
                    xWinProps.lTxBufSize = ipconfigTCP_TX_BUFFER_LENGTH;
                    xWinProps.lTxWinSize = configECHO_SERVER_TX_WINDOW_SIZE;
                    xWinProps.lRxBufSize = ipconfigTCP_RX_BUFFER_LENGTH;
                    xWinProps.lRxWinSize = configECHO_SERVER_RX_WINDOW_SIZE;
                #endif /* ipconfigUSE_TCP_WIN */

                struct SocketPackage socketPackage = syscallPackage->socketPackage;

                int type = socketPackage->type == 2 ? FREERTOS_SOCK_DGRAM : FREERTOS_SOCK_STREAM;
                BaseType_t protocol = socketPackage->protocol == 17 ? FREERTOS_IPPROTO_UDP : FREERTOS_IPPROTO_TCP;

                int xSocket = FreeRTOS_socket( FREERTOS_AF_INET, type, protocol );

                if ( xSocket == FREERTOS_INVALID_SOCKET ) {
                    response = 0;
                    FreeRTOS_debug_printf(("Error creating socket...\n"));
                    syscallResponse->result = response;
                    continue;
                }

                // TODO: Check for array out of bounds access
                socketArray[socketCounter] = xSocket;

                /* Set a time out so a missing reply does not cause the task to block
                indefinitely. */
                //FreeRTOS_setsockopt( xSocket, 0, FREERTOS_SO_RCVTIMEO, &xReceiveTimeOut, sizeof( xReceiveTimeOut ) );
                //FreeRTOS_setsockopt( xSocket, 0, FREERTOS_SO_SNDTIMEO, &xSendTimeOut, sizeof( xSendTimeOut ) );

                response = socketCounter;
                socketCounter++;

                syscallResponse->result = response;

            } else if (strcmp(syscallPackage->syscallId, "socket_bind") == 0) {

                struct BindPackage bindPackage = syscallPackage->bindPackage;

                struct freertos_sockaddr xBindAddress;

                struct sockaddr_in *sock_addr = (struct sockaddr_in *) &bindPackage.addr;
                xBindAddress.sin_port = sock_addr->sin_port;
                int8_t bindResult = FreeRTOS_bind( socketArray[bindPackage.sockfd], &xBindAddress, sizeof( xBindAddress ) );

                if (bindResult < 0) {
                    FreeRTOS_debug_printf(("Error binding to port with response: %d\n", bindResult));
                }

                syscallResponse->result = bindResult;

            } /*else if (strcmp(syscallPackage->syscallId, "socket_listen") == 0) {

                struct ListenPackage listenPackage = syscallPackage->listenPackage;

                int listenResult = FreeRTOS_listen( socketArray[listenPackage.sockfd], listenPackage.backlog );

                if (listenResult < 0) {
                    FreeRTOS_debug_printf(("Error listening on socket with response: %d\n", listenResult));
                }

                syscallResponse->result = listenResult;

            } else if (strcmp(syscallPackage->syscallId, "socket_accept") == 0) {

                struct AcceptPackage acceptPackage = syscallPackage->acceptPackage;

                struct freertos_sockaddr xClient;
                socklen_t xSize = sizeof( xClient );

                FreeRTOS_setsockopt( socketArray[acceptPackage.sockfd], 0, FREERTOS_SO_RCVTIMEO, &xConnectTimeOut, sizeof( xConnectTimeOut ) );

                //TODO: Return the client socket to packetdrill
                Socket_t xConnectedSocket = FreeRTOS_accept( socketArray[acceptPackage.sockfd], &xClient, &xSize );

                FreeRTOS_setsockopt( socketArray[acceptPackage.sockfd], 0, FREERTOS_SO_RCVTIMEO, &xReceiveTimeOut, sizeof( xReceiveTimeOut ) );

                if ( xConnectedSocket == FREERTOS_INVALID_SOCKET ) {
                    response = 0;
                    FreeRTOS_debug_printf(("Error connecting to client socket...\n"));

                    syscallResponse->result = response;
                    continue;
                } else if (xConnectedSocket == NULL) {
                    response = 0;
                    FreeRTOS_debug_printf(("Error connecting to client socket with null...\n"));

                    syscallResponse->result = response;
                    continue;
                }

                // TODO: Check for array out of bounds access
                socketArray[socketCounter] = xConnectedSocket;

                response = socketCounter;
                socketCounter++;

                struct sockaddr_in addr;
                addr.sin_family = AF_INET;
                addr.sin_port = xClient.sin_port;
                addr.sin_addr = getUnixSinAddr(xClient.sin_addr);

                struct AcceptResponsePackage acceptResponse;
                acceptResponse.addr = *((struct sockaddr *)(&addr));
                acceptResponse.addrlen = sizeof(struct sockaddr_in);

                syscallResponse->result = response;
                syscallResponse->acceptResponse = acceptResponse;

            } else if (strcmp(syscallPackage->syscallId, "socket_connect") == 0) {

                struct BindPackage connectPackage = syscallPackage->connectPackage;

                struct freertos_sockaddr xEchoServerAddress;

                struct sockaddr_in *sock_addr = (struct sockaddr_in *) &connectPackage.addr;
                xEchoServerAddress.sin_port = sock_addr->sin_port;
                uint32_t destinationIPAddress = getFreeRTOSSinAddr(sock_addr->sin_addr);
                xEchoServerAddress.sin_addr = destinationIPAddress;

                if (xIsIPInARPCache(xEchoServerAddress->sin_addr) == pdFALSE) {
                    FreeRTOS_debug_printf(("Connect IP address not in ARP cache...Adding now...\n"));
                    MACAddress_t destinationMacAddress;
                    memcpy(&destinationMacAddress, destinationMacBytes, sizeof(MACAddress_t));
                    vARPRefreshCacheEntry( &destinationMacAddress, destinationIPAddress );
                } else {
                    FreeRTOS_debug_printf(("Connect IP address found in ARP cache...\n"));
                }

                FreeRTOS_setsockopt( socketArray[connectPackage.sockfd], 0, FREERTOS_SO_RCVTIMEO, &xConnectTimeOut, sizeof( xReceiveTimeOut ) );

                int connectResult = FreeRTOS_connect( socketArray[connectPackage.sockfd],
                                &xEchoServerAddress, sizeof( xEchoServerAddress ) );

                FreeRTOS_setsockopt( socketArray[connectPackage.sockfd], 0, FREERTOS_SO_RCVTIMEO, &xReceiveTimeOut, sizeof( xReceiveTimeOut ) );

                if (connectResult < 0) {
                    FreeRTOS_debug_printf(("Error connecting to socket with response: %d\n", connectResult));
                } else {
                    FreeRTOS_debug_printf(("Successfully connected to socket\n"));

                }

                syscallResponse->result = connectResult;
            } else if (strcmp(syscallPackage->syscallId, "socket_write") == 0) {

                struct WritePackage writePackage = syscallPackage->writePackage;

                int writeResult = FreeRTOS_send(socketArray[writePackage.sockfd],
                                        syscallPackage->buffer, syscallPackage->bufferedCount, 0);

                if (writeResult < 0) {
                    FreeRTOS_debug_printf(("Error writing to socket with response: %d\n", writeResult));
                }

                syscallResponse->result = writeResult;
            }*/ else if (strcmp(syscallPackage->syscallId, "socket_sendto") == 0) {

                struct SendToPackage sendtoPackage = syscallPackage->sendToPackage;

                struct freertos_sockaddr destinationAddress;

                struct sockaddr_in *sock_addr = (struct sockaddr_in *) &sendtoPackage.addr;
                destinationAddress.sin_port = sock_addr->sin_port;
                uint32_t destinationIPAddress = getFreeRTOSSinAddr(sock_addr->sin_addr);
                destinationAddress.sin_addr = destinationIPAddress;

                if (xIsIPInARPCache(destinationAddress.sin_addr) == pdFALSE) {
                    FreeRTOS_debug_printf(("Sendto IP address not in ARP cache...Adding now...\n"));
                    MACAddress_t destinationMacAddress;
                    memcpy(&destinationMacAddress, destinationMacBytes, sizeof(MACAddress_t));
                    vARPRefreshCacheEntry( &destinationMacAddress, destinationIPAddress );
                } else {
                    FreeRTOS_debug_printf(("Sendto IP address found in ARP cache...\n"));
                }

                int writeResult = FreeRTOS_sendto(socketArray[sendtoPackage.sockfd],
                                        syscallPackage->buffer, syscallPackage->bufferedCount, 0, 
                                        &destinationAddress, sizeof(destinationAddress));

                if (writeResult < 0) {
                    FreeRTOS_debug_printf(("Error writing to socket with response: %d\n", writeResult));
                }

                syscallResponse->result = writeResult;
            } /*else if (strcmp(syscallPackage->syscallId, "socket_read") == 0) {

                struct ReadPackage readPackage = syscallPackage.readPackage;

                char *readBuffer = pvPortMalloc(readPackage.count);

                int result = FreeRTOS_recv( socketArray[readPackage.sockfd],
                                            (void *) readBuffer,
                                            readPackage.count,
                                            0 );

                if (result < 0 ) {
                    FreeRTOS_debug_printf(("Error reading from socket with result: %d\n", result));
                }

            
                vPortFree(readBuffer);

                syscallResponse->result = result;

            } */else if (strcmp(syscallPackage->syscallId, "socket_recvfrom") == 0) {

                struct RecvFromPackage recvFromPackage = syscallPackage->recvFromPackage;

                char *readBuffer = pvPortMalloc(recvFromPackage.count);

                struct freertos_sockaddr xClient;
                socklen_t xSize = sizeof( xClient );

                FreeRTOS_setsockopt( socketArray[recvFromPackage.sockfd], 0, FREERTOS_SO_RCVTIMEO, &xConnectTimeOut, sizeof( xConnectTimeOut ) );

                int result = FreeRTOS_recvfrom( socketArray[recvFromPackage.sockfd],
                                            (void *) readBuffer,
                                            recvFromPackage.count,
                                            0, &xClient, &xSize);

                FreeRTOS_setsockopt( socketArray[recvFromPackage.sockfd], 0, FREERTOS_SO_RCVTIMEO, &xReceiveTimeOut, sizeof( xReceiveTimeOut ) );

                if (result < 0 ) {
                    FreeRTOS_debug_printf(("Error reading from socket with result: %d\n", result));
                    syscallResponse->result = result;
                    continue;
                }

                struct sockaddr_in addr;
                addr.sin_family = AF_INET;
                addr.sin_port = xClient.sin_port;
                addr.sin_addr = getUnixSinAddr(xClient.sin_addr);

                struct AcceptResponsePackage acceptResponse;
                acceptResponse.addr = *((struct sockaddr *)(&addr));
                acceptResponse.addrlen = sizeof(struct sockaddr_in);

                syscallResponse->result = result;
                syscallResponse->acceptResponse = acceptResponse;

            } else if (strcmp(syscallPackage->syscallId, "socket_close") == 0){

                struct ClosePackage closePackage = syscallPackage->closePackage;

                Socket_t socketToClose = socketArray[closePackage.sockfd];

                int closeResult = FreeRTOS_shutdown(socketToClose, 0);

                if (closeResult != 0) {
                    FreeRTOS_debug_printf(("Error closing socket with response: %d\n", closeResult));
                }

                syscallResponse->result = closeResult;
            } else if (strcmp(syscallPackage->syscallId, "freertos_init") == 0){

            int sizeSocketArray = resetPacketDrillTask();

            syscallResponse->result = sizeSocketArray;
        } else {
             syscallResponse->result = 0;
        }

    }

    


}

int resetPacketDrillTask() {
    int sizeSocketArray = socketCounter - 3;
    if (sizeSocketArray > 0) {
        memset(socketArray + (3*sizeof(Socket_t)), 0, sizeSocketArray * sizeof(Socket_t));

        /* We want to close all the socket we opened during this session */
        for (int counter = 0; counter < sizeSocketArray; counter++) {
            Socket_t socket = socketArray[counter + 3];
            FreeRTOS_closesocket(socket);
        }
    }

    socketCounter = 3;

    FreeRTOS_debug_printf(("PacketDrill Handler Task Reset..\n"));

    return sizeSocketArray;

}

static uint32_t getFreeRTOSSinAddr(struct in_addr sin_addr) {

    char *ip_address = inet_ntoa(sin_addr);

    FreeRTOS_debug_printf(("Connect IP address: %s\n", ip_address));

    uint8_t ip_bytes[4];
    int count = 0;
    char *ip_part = strtok(ip_address, ".");

    while (ip_part != NULL) {
        ip_bytes[count] = (uint8_t) atoi (ip_part);
        ip_part = strtok(NULL, ".");
        count++;
    }

    return FreeRTOS_inet_addr_quick(ip_bytes[0], ip_bytes[1], ip_bytes[2], ip_bytes[3]);

}

static struct in_addr getUnixSinAddr(uint32_t freertosSinAddr) {

    char cBuffer[ 16 ];
    FreeRTOS_inet_ntoa( freertosSinAddr, cBuffer );
    FreeRTOS_debug_printf( ( "\r\n\r\nIP Address: %s\r\n", cBuffer ) );

    struct in_addr sin_addr;
    int result = inet_aton(cBuffer, &sin_addr);

    if (result == 0) {
        FreeRTOS_debug_printf(("Error converting IP address to inet format...\n"));
    }

    return sin_addr;
}


size_t IntToString(char *s, int x)
{
    //  Set pointer to current position.
    char *p = s;

    //  Set t to absolute value of x.
    unsigned t = x;
    if (x < 0) t = -t;

    //  Write digits.
    do
    {
        *p++ = '0' + t % 10;
        t /= 10;
    } while (t);

    //  If x is negative, write sign.
    if (x < 0)
        *p++ = '-';

    //  Remember the return value, the number of characters written.
    size_t r = p-s;

    //  Since we wrote the characters in reverse order, reverse them.
    while (s < --p)
    {
        char t = *s;
        *s++ = *p;
        *p = t;
    }

    return r;
}