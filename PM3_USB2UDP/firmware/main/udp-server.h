#pragma once

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sys/socket.h"
#include "netdb.h"
#include "errno.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"

/**
 * @brief Indicates that the file descriptor represents an invalid (uninitialized or closed) socket
 *
 * Used in the TCP server structure `sock[]` which holds list of active clients we serve.
 */
#define INVALID_SOCK (-1)

/**
 * @brief Time in ms to yield to all tasks when a non-blocking socket would block
 *
 * Non-blocking socket operations are typically executed in a separate task validating
 * the socket status. Whenever the socket returns `EAGAIN` (idle status, i.e. would block)
 * we have to yield to all tasks to prevent lower priority tasks from starving.
 */
#define YIELD_TO_ALL_MS 50

#define UDP_SERVER_BIND_ADDRESS "0.0.0.0"
#define UDP_SERVER_BIND_PORT 3344

// https://docs.espressif.com/projects/esp-idf/en/release-v5.0/esp32s3/api-guides/lwip.html#limitations
// "Applications sending a high volume of UDP datagrams who don’t wish for any to be dropped by the sender should check for this error code and re-send the datagram after a short delay."
#define UDP_ENOMEM_RETRY 3

void udp_server_init();
int socket_send(const char *tag, const int sock, const char *data, const size_t len);
