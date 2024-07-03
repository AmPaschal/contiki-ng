/**
 * @file ppv_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for parse_publish_vhdr function
 * @version 0.1
 * @date 2024-07-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/mqtt/mqtt.h"

#include <stdlib.h>
#include <string.h>

void harness() {

    // Define unconstrained input data length:

    int isize;

    // MQTT_TCP_INPUT_BUFF_SIZE
    __CPROVER_assume(isize <= MQTT_TCP_INPUT_BUFF_SIZE && isize >= 0);

    // Create input data:

    uint8_t data = (uint8_t *)malloc(sizeof(uint8_t) * isize);

    __CPROVER_assume(data != NULL);

    // Create a connection:

    struct mqtt_connection conn = {0};

    // Need to zero out struct for complexity reasons

    // memset((&conn), 0, sizeof(conn));

    // Define some values:

    // uint16_t str_legnth = 0;

    // __CPROVER_assume(str_legnth <= 50);

    // conn.client_id.length = str_legnth;
    // conn.client_id.string = (char *)malloc(sizeof(char) * str_legnth);

    // conn.will.topic.length = 0;
    // conn.will.topic.string = NULL;

    // conn.will.message.length = 0;
    // conn.will.message.string = NULL;

    // conn.credentials.password.length = 0;
    // conn.credentials.password.string = NULL;

    // conn.credentials.username.length = 0;
    // conn.credentials.username.string = NULL;

    // Position value:

    uint32_t pos;

    parse_publish_vhdr(&conn, &pos, data, isize);
}
