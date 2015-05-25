/* Copyright (c) 2009 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT. 
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 * $LastChangedRevision$
 */ 

/** @file
 * @brief Interface for hal_aci_tl.
 */
 
/** @defgroup hal_aci_tl hal_aci_tl
@{
@ingroup hal
 
@brief Module for the ACI Transport Layer interface
@details This module is responsible for sending and receiving messages over the ACI interface of the nRF8001 chip.
 The hal_aci_tl_send_cmd() can be called directly to send ACI commands.


The RDYN line is hooked to an interrupt on the MCU when the level is low.
The SPI master clocks in the interrupt context.
The ACI Command is taken from the head of the command queue is sent over the SPI
and the received ACI event is placed in the tail of the event queue.

*/
 
#ifndef HAL_ACI_TL_H__
#define HAL_ACI_TL_H__

#include "hal_platform.h"
#include "stdint.h"

#ifndef HAL_ACI_MAX_LENGTH
#define HAL_ACI_MAX_LENGTH 31
#endif //HAL_ACI_MAX_LENGTH

#define ACI_QUEUE_SIZE  3
#define bool char

/** Data type for ACI commands and events */
typedef struct hal_aci_data_t{
  uint8_t status_byte;
  uint8_t buffer[HAL_ACI_MAX_LENGTH+1];
} hal_aci_data_t;

typedef struct {
 hal_aci_data_t           aci_data[ACI_QUEUE_SIZE];
 uint8_t                  head;
 uint8_t                  tail;
} aci_queue_t;


/** ACI Transport Layer configures inputs/outputs.
 */
void hal_aci_tl_io_config(void);


/** ACI Transport Layer initialization.
 */
void hal_aci_tl_init(void);

/**@brief Sends an ACI command to the radio.
 *  @details
 *  This function sends an ACI command to the radio. This will memorize the pointer of the message to send and 
 *  lower the request line. When the device lowers the ready line, @ref hal_aci_tl_poll_rdy_line() will send the data.
 *  @param aci_buffer Pointer to the message to send.
 *  @return True if the send is started successfully, false if a transaction is already running.
 */
bool hal_aci_tl_send(hal_aci_data_t *aci_buffer);


/** @brief process pending transaction.
 *  @details 
 *  Call this function from the main context after checking if the nRF8001 RDYN line indicates a pending transaction.
 *  If a transaction is pending, call this function will process it and get the event and send the command from the respective queues
 *  This is called by lib_aci_event_get
 */
hal_aci_data_t * hal_aci_tl_poll_get(void);

/** @brief Get an ACI event from the event queue
 *  @details 
 *  Call this function from the main context to get an event from the ACI event queue
 *  This is called by lib_aci_event_get
 */
bool hal_aci_tl_event_get(hal_aci_data_t *p_aci_data);

/** @brief Flush the ACI command Queue and the ACI Event Queue
 *  @details
 *  Call this function in the main thread
*/
void m_aci_q_flush(void);

/** @brief Enable debug printing of all ACI commands sent and ACI events received
 *  @details
 *  when the enable parameter is true. The debug printing is enabled on the Serial.
 *  When the enable parameter is false. The debug printing is disabled on the Serial.
 *  By default the debug printing is disabled.
*/
void hal_aci_debug_print(bool enable);

/** @brief 
 *  @details
 *
*/
void m_rdy_line_handle(void);

/** @brief Is the queue empty
 *  @details
 *
*/
bool m_aci_q_is_empty(aci_queue_t *aci_q);

/** @brief Is the queue full
 *  @details
 *
*/
bool m_aci_q_is_full(aci_queue_t *aci_q);



#endif // HAL_ACI_TL_H__
/** @} */