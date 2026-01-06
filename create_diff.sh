#!/usr/bin/env bash

# Exit on error or missing argument
set -e

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <CVE-ID>"
  exit 1
fi

CVE_ID="$1"
OUTPUT_DIR="../contiki-patches"
OUTPUT_FILE="${OUTPUT_DIR}/${CVE_ID}.diff"

# Ensure output directory exists
mkdir -p "$OUTPUT_DIR"

# Generate diff
git diff > "$OUTPUT_FILE"

echo "Diff written to $OUTPUT_FILE"

