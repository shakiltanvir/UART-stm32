/*
 * uart_handler.h
 *
 *  Created on: Jun 7, 2024
 *      Author: USER
 */

#ifndef INC_UART_HANDLER_H_
#define INC_UART_HANDLER_H_

#include "main.h"
#include "push_button.h"

#define RX_BUFF_SIZE 32
#define TX_BUFF_SIZE 32

// Buffers for transmission and reception
extern uint8_t txbuff[TX_BUFF_SIZE];
extern uint8_t rxbuff[RX_BUFF_SIZE];

extern UART_HandleTypeDef huart1;

// Data structure for master data

typedef struct{
    uint32_t first_header;
    uint32_t node_id;
    uint32_t broadcastCounter;
    uint32_t feedbackCounter;
    uint32_t command_a;
    uint32_t command_b;
} MasterDatatypedef;

extern MasterDatatypedef masterRxdata;

// Data structure for slave data
typedef struct{
    uint32_t first_header;
    uint32_t device_id;
    float temperature;
    float humidity;
    float latitude;
    float longitude;
    uint32_t altitude;
} SlaveDatatypedef;

extern SlaveDatatypedef slaveTxData;

//typedef enum{
//	DATA_SENT,
//	DATA_RECEIVED
//}ComState;

/**
 * @brief Initializes UART communication.
 * @param huart: UART handle
 */
void uartCommInit(UART_HandleTypeDef *huart);

/**
 * @brief Assigns data to the MasterDatatypedef structure.
 * @param data: Pointer to MasterDatatypedef structure
 * @param id: Node ID
 * @param temp: temperature
 * @param hum: humidity
 * @param lat: latitude
 * @param lon: longitude
 * @param altittude: altittude
 *
 */
void assignSlaveData(SlaveDatatypedef *data, uint32_t id, float temp, float hum, float lat, float lon, uint32_t altittude);

/**
 * @brief Sends the master data over UART.
 * @param huart: UART handle
 * @param data: Pointer to SlaveDatatypedef structure
 */
void sendSlaveData(UART_HandleTypeDef *huart, SlaveDatatypedef *data);

/**
 * @brief Receives the slave data over UART.
 * @param huart: UART handle
 * @param data: Pointer to MasterDatatypedef structure
 */
void receiveMasterData(UART_HandleTypeDef *huart, MasterDatatypedef *data);

#endif /* INC_UART_HANDLER_H_ */
