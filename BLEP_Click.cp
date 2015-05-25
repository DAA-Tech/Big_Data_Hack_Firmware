#line 1 "C:/Users/Ayodele/Google Drive/DAA STEM Academy/Hack Software/Big_Data_Hack_Firmware/BLEP_Click.c"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/blep.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/hal_platform.h"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 112 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_STORE_INVALID = 0x0,
 ACI_STORE_LOCAL= 0x01,
 ACI_STORE_REMOTE= 0x02
} aci_pipe_store_t;
#line 123 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_TX_BROADCAST = 0x0001,
 ACI_TX = 0x0002,
 ACI_TX_ACK = 0x0004,
 ACI_RX = 0x0008,
 ACI_RX_ACK = 0x0010,
 ACI_TX_REQ = 0x0020,
 ACI_RX_REQ = 0x0040,
 ACI_SET = 0x0080,
 ACI_TX_SIGN = 0x0100,
 ACI_RX_SIGN = 0x0200,
 ACI_RX_ACK_AUTO = 0x0400
} aci_pipe_type_t;
#line 142 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_BD_ADDR_TYPE_INVALID = 0x00,
 ACI_BD_ADDR_TYPE_PUBLIC = 0x01,
 ACI_BD_ADDR_TYPE_RANDOM_STATIC = 0x02,
 ACI_BD_ADDR_TYPE_RANDOM_PRIVATE_RESOLVABLE = 0x03,
 ACI_BD_ADDR_TYPE_RANDOM_PRIVATE_UNRESOLVABLE = 0x04
} aci_bd_addr_type_t;
#line 155 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_DEVICE_OUTPUT_POWER_MINUS_18DBM = 0x00,
 ACI_DEVICE_OUTPUT_POWER_MINUS_12DBM = 0x01,
 ACI_DEVICE_OUTPUT_POWER_MINUS_6DBM = 0x02,
 ACI_DEVICE_OUTPUT_POWER_0DBM = 0x03
} aci_device_output_power_t;
#line 167 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_DEVICE_INVALID =0x00,
 ACI_DEVICE_TEST =0x01,
 ACI_DEVICE_SETUP =0x02,
 ACI_DEVICE_STANDBY =0x03,
 ACI_DEVICE_SLEEP =0x04
} aci_device_operation_mode_t;
#line 180 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_REASON_TERMINATE =0x01,
 ACI_REASON_BAD_TIMING =0x02
} aci_disconnect_reason_t;
#line 190 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_TEST_MODE_DTM_UART = 0x01,
 ACI_TEST_MODE_DTM_ACI = 0x02,
 ACI_TEST_MODE_EXIT = 0xFF

} aci_test_mode_change_t;
#line 202 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_PERMISSIONS_NONE =0x00,
 ACI_PERMISSIONS_LINK_AUTHENTICATED =0x01
} aci_permissions_t;
#line 219 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef struct
{
 uint16_t min_conn_interval;



 uint16_t max_conn_interval;



 uint16_t slave_latency;

 uint16_t timeout_mult;



} aci_ll_conn_params_t;
#line 296 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef struct
{
 uint8_t pipe_number;
 uint8_t aci_data[ (20) ];
} aci_tx_data_t;
#line 306 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef struct
{
 uint8_t pipe_number;
 uint8_t aci_data[ (22) ];
} aci_rx_data_t;
#line 316 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_HW_ERROR_NONE = 0x00,
 ACI_HW_ERROR_FATAL = 0x01
} aci_hw_error_t;
#line 326 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_CLOCK_ACCURACY_500_PPM = 0x00,
 ACI_CLOCK_ACCURACY_250_PPM = 0x01,
 ACI_CLOCK_ACCURACY_150_PPM = 0x02,
 ACI_CLOCK_ACCURACY_100_PPM = 0x03,
 ACI_CLOCK_ACCURACY_75_PPM = 0x04,
 ACI_CLOCK_ACCURACY_50_PPM = 0x05,
 ACI_CLOCK_ACCURACY_30_PPM = 0x06,
 ACI_CLOCK_ACCURACY_20_PPM = 0x07
} aci_clock_accuracy_t;
#line 342 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_APP_LATENCY_DISABLE = 0,
 ACI_APP_LATENCY_ENABLE = 1
} aci_app_latency_mode_t;
#line 352 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_GATT_FORMAT_NONE = 0x00,
 ACI_GATT_FORMAT_BOOLEAN = 0x01,
 ACI_GATT_FORMAT_2BIT = 0x02,
 ACI_GATT_FORMAT_NIBBLE = 0x03,
 ACI_GATT_FORMAT_UINT8 = 0x04,
 ACI_GATT_FORMAT_UINT12 = 0x05,
 ACI_GATT_FORMAT_UINT16 = 0x06,
 ACI_GATT_FORMAT_UINT24 = 0x07,
 ACI_GATT_FORMAT_UINT32 = 0x08,
 ACI_GATT_FORMAT_UINT48 = 0x09,
 ACI_GATT_FORMAT_UINT64 = 0x0A,
 ACI_GATT_FORMAT_UINT128 = 0x0B,
 ACI_GATT_FORMAT_SINT8 = 0x0C,
 ACI_GATT_FORMAT_SINT12 = 0x0D,
 ACI_GATT_FORMAT_SINT16 = 0x0E,
 ACI_GATT_FORMAT_SINT24 = 0x0F,
 ACI_GATT_FORMAT_SINT32 = 0x10,
 ACI_GATT_FORMAT_SINT48 = 0x11,
 ACI_GATT_FORMAT_SINT64 = 0x12,
 ACI_GATT_FORMAT_SINT128 = 0x13,
 ACI_GATT_FORMAT_FLOAT32 = 0x14,
 ACI_GATT_FORMAT_FLOAT64 = 0x15,
 ACI_GATT_FORMAT_SFLOAT = 0x16,
 ACI_GATT_FORMAT_FLOAT = 0x17,
 ACI_GATT_FORMAT_DUINT16 = 0x18,
 ACI_GATT_FORMAT_UTF8S = 0x19,
 ACI_GATT_FORMAT_UTF16S = 0x1A,
 ACI_GATT_FORMAT_STRUCT = 0x1B
} aci_gatt_format_t;
#line 387 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_GATT_NAMESPACE_INVALID = 0x00,
 ACI_GATT_NAMESPACE_BTSIG = 0x01
} aci_gatt_namespace_t;
#line 396 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_KEY_TYPE_INVALID = 0x00,
 ACI_KEY_TYPE_PASSKEY = 0x01
} aci_key_type_t;
#line 406 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
#line 411 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_SUCCESS = 0x00,
#line 415 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED = 0x01,
#line 419 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_TIMED_OUT = 0x02,
#line 423 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_PASSKEY_ENTRY_FAILED = 0x81,
#line 427 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_OOB_UNAVAILABLE = 0x82,
#line 431 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_AUTHENTICATION_REQ = 0x83,
#line 435 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_CONFIRM_VALUE = 0x84,
#line 439 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_PAIRING_UNSUPPORTED = 0x85,
#line 443 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_ENCRYPTION_KEY_SIZE = 0x86,
#line 447 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_SMP_CMD_UNSUPPORTED = 0x87,
#line 451 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_UNSPECIFIED_REASON = 0x88,
#line 455 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_REPEATED_ATTEMPTS = 0x89,
#line 459 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_BOND_STATUS_FAILED_INVALID_PARAMETERS = 0x8A

} aci_bond_status_code_t;
#line 467 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
 ACI_BOND_STATUS_SOURCE_INVALID = 0x00,
 ACI_BOND_STATUS_SOURCE_LOCAL = 0x01,
 ACI_BOND_STATUS_SOURCE_REMOTE = 0x02

} aci_bond_status_source_t;
#line 479 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
typedef enum
{
#line 484 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_SUCCESS = 0x00,
#line 488 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_TRANSACTION_CONTINUE = 0x01,
#line 492 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_TRANSACTION_COMPLETE = 0x02,
#line 496 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_EXTENDED = 0x03,
#line 500 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_UNKNOWN = 0x80,
#line 504 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_INTERNAL = 0x81,
#line 508 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_CMD_UNKNOWN = 0x82,
#line 512 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_DEVICE_STATE_INVALID = 0x83,
#line 516 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_INVALID_LENGTH = 0x84,
#line 520 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_INVALID_PARAMETER = 0x85,
#line 524 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_BUSY = 0x86,
#line 528 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_INVALID_DATA = 0x87,
#line 532 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_CRC_MISMATCH = 0x88,
#line 536 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_UNSUPPORTED_SETUP_FORMAT = 0x89,
#line 540 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_INVALID_SEQ_NO = 0x8A,
#line 544 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_SETUP_LOCKED = 0x8B,
#line 548 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_LOCK_FAILED = 0x8C,
#line 552 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_BOND_REQUIRED = 0x8D,
#line 556 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_REJECTED = 0x8E,
#line 560 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_DATA_SIZE = 0x8F,
#line 564 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_PIPE_INVALID = 0x90,
#line 568 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_CREDIT_NOT_AVAILABLE = 0x91,
#line 572 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_PEER_ATT_ERROR = 0x92,
#line 576 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_ADVT_TIMEOUT = 0x93,
#line 580 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_PEER_SMP_ERROR = 0x94,
#line 584 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_PIPE_TYPE_INVALID = 0x95,
#line 588 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_PIPE_STATE_INVALID = 0x96,
#line 592 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_INVALID_KEY_SIZE = 0x97,
#line 596 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_ERROR_INVALID_KEY_DATA = 0x98,
#line 600 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_RESERVED_START = 0xF0,
#line 604 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
 ACI_STATUS_RESERVED_END = 0xFF

} aci_status_code_t;
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 34 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef enum
{
#line 39 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_TEST = 0x01,
#line 43 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_ECHO = 0x02,
#line 47 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_DTM_CMD = 0x03,
#line 51 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SLEEP = 0x04,
#line 55 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_WAKEUP = 0x05,
#line 60 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SETUP = 0x06,
#line 64 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_READ_DYNAMIC_DATA = 0x07,
#line 68 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_WRITE_DYNAMIC_DATA = 0x08,
#line 72 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_GET_DEVICE_VERSION = 0x09,
#line 76 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_GET_DEVICE_ADDRESS = 0x0A,
#line 80 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_GET_BATTERY_LEVEL = 0x0B,
#line 84 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_GET_TEMPERATURE = 0x0C,
#line 88 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SET_LOCAL_DATA = 0x0D,
#line 92 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_RADIO_RESET = 0x0E,
#line 96 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_CONNECT = 0x0F,
#line 100 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_BOND = 0x10,
#line 104 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_DISCONNECT = 0x11,
#line 108 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SET_TX_POWER = 0x12,
#line 112 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_CHANGE_TIMING = 0x13,
#line 116 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_OPEN_REMOTE_PIPE = 0x14,
#line 120 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SEND_DATA = 0x15,
#line 124 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SEND_DATA_ACK = 0x16,
#line 128 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_REQUEST_DATA = 0x17,
#line 132 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SEND_DATA_NACK = 0x18,
#line 136 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SET_APP_LATENCY = 0x19,
#line 140 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_SET_KEY = 0x1A,
#line 144 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_OPEN_ADV_PIPE = 0x1B,
#line 148 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_BROADCAST = 0x1C,
#line 152 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_BOND_SECURITY_REQUEST = 0x1D,
#line 156 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_CONNECT_DIRECT = 0x1E,
#line 160 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_CLOSE_REMOTE_PIPE = 0x1F,
#line 164 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
 ACI_CMD_INVALID = 0xFF

} aci_cmd_opcode_t;
#line 172 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t test_mode_change;
} aci_cmd_params_test_t;
#line 181 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t echo_data[ ( (32)  - 3) ];
} aci_cmd_params_echo_t;
#line 190 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t cmd_msb;
 uint8_t cmd_lsb;
} aci_cmd_params_dtm_cmd_t;
#line 200 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t setup_data[1];
} aci_cmd_params_setup_t;
#line 210 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t seq_no;
 uint8_t dynamic_data[1];
} aci_cmd_params_write_dynamic_data_t;
#line 220 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 aci_tx_data_t tx_data;
} aci_cmd_params_set_local_data_t;
#line 229 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint16_t timeout;
 uint16_t adv_interval;
} aci_cmd_params_connect_t;
#line 239 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint16_t timeout;
 uint16_t adv_interval;
} aci_cmd_params_bond_t;
#line 249 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t reason;
} aci_cmd_params_disconnect_t;
#line 258 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t device_power;
} aci_cmd_params_set_tx_power_t;
#line 267 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 aci_ll_conn_params_t conn_params;
} aci_cmd_params_change_timing_t;
#line 276 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t pipe_number;
} aci_cmd_params_open_remote_pipe_t;
#line 285 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 aci_tx_data_t tx_data;
} aci_cmd_params_send_data_t;
#line 294 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t pipe_number;
} aci_cmd_params_send_data_ack_t;
#line 303 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t pipe_number;
} aci_cmd_params_request_data_t;
#line 312 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t pipe_number;
 uint8_t error_code;
} aci_cmd_params_send_data_nack_t;
#line 322 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 aci_app_latency_mode_t mode;
 uint16_t latency;
} aci_cmd_params_set_app_latency_t;
#line 332 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 aci_key_type_t key_type;
 union
 {
 uint8_t passkey[6];
 uint8_t oob_key[16];
 } key;
} aci_cmd_params_set_key_t;
#line 346 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t pipes[8];
} aci_cmd_params_open_adv_pipe_t;
#line 355 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint16_t timeout;
 uint16_t adv_interval;
} aci_cmd_params_broadcast_t;
#line 365 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t pipe_number;
} aci_cmd_params_close_remote_pipe_t;
#line 374 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
typedef struct
{
 uint8_t len;
 uint8_t cmd_opcode;
 union
 {
 aci_cmd_params_test_t test;
 aci_cmd_params_echo_t echo;
 aci_cmd_params_dtm_cmd_t dtm_cmd;
 aci_cmd_params_setup_t setup;
 aci_cmd_params_write_dynamic_data_t write_dynamic_data;
 aci_cmd_params_set_local_data_t set_local_data;
 aci_cmd_params_connect_t connect;
 aci_cmd_params_bond_t bond;
 aci_cmd_params_disconnect_t disconnect;
 aci_cmd_params_set_tx_power_t set_tx_power;
 aci_cmd_params_change_timing_t change_timing;
 aci_cmd_params_open_remote_pipe_t open_remote_pipe;
 aci_cmd_params_send_data_t send_data;
 aci_cmd_params_send_data_ack_t send_data_ack;
 aci_cmd_params_request_data_t request_data;
 aci_cmd_params_send_data_nack_t send_data_nack;
 aci_cmd_params_set_app_latency_t set_app_latency;
 aci_cmd_params_set_key_t set_key;
 aci_cmd_params_open_adv_pipe_t open_adv_pipe;
 aci_cmd_params_broadcast_t broadcast;
 aci_cmd_params_close_remote_pipe_t close_remote_pipe;

 } params;
} aci_cmd_t;
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
#line 29 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef enum
{
#line 34 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_INVALID = 0x00,
#line 38 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_DEVICE_STARTED = 0x81,
#line 42 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_ECHO = 0x82,
#line 46 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_HW_ERROR = 0x83,
#line 50 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_CMD_RSP = 0x84,
#line 54 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_CONNECTED = 0x85,
#line 58 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_DISCONNECTED = 0x86,
#line 62 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_BOND_STATUS = 0x87,
#line 66 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_PIPE_STATUS = 0x88,
#line 71 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_TIMING = 0x89,
#line 76 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_DATA_CREDIT = 0x8A,
#line 80 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_DATA_ACK = 0x8B,
#line 84 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_DATA_RECEIVED = 0x8C,
#line 88 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_PIPE_ERROR = 0x8D,
#line 92 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_DISPLAY_PASSKEY = 0x8E,
#line 96 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
 ACI_EVT_KEY_REQUEST = 0x8F

} aci_evt_opcode_t;
#line 104 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t device_mode;
 uint8_t hw_error;
 uint8_t credit_available;
} aci_evt_params_device_started_t;
#line 115 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint16_t line_num;
 uint8_t file_name[20];
} aci_evt_params_hw_error_t;
#line 125 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t evt_msb;
 uint8_t evt_lsb;
} aci_evt_cmd_rsp_params_dtm_cmd_t;
#line 136 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t seq_no;
 uint8_t dynamic_data[1];
} aci_evt_cmd_rsp_read_dynamic_data_t;
#line 146 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint16_t configuration_id;
 uint8_t aci_version;
 uint8_t setup_format;
 uint32_t setup_id;
 uint8_t setup_status;
} aci_evt_cmd_rsp_params_get_device_version_t;
#line 159 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t bd_addr_own[ (6) ];
 uint8_t bd_addr_type;
} aci_evt_cmd_rsp_params_get_device_address_t;
#line 169 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint16_t battery_level;
} aci_evt_cmd_rsp_params_get_battery_level_t;
#line 178 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 int16_t temperature_value;
} aci_evt_cmd_rsp_params_get_temperature_t;
#line 187 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t cmd_opcode;
 uint8_t cmd_status;
 union
 {
 aci_evt_cmd_rsp_params_dtm_cmd_t dtm_cmd;
 aci_evt_cmd_rsp_read_dynamic_data_t read_dynamic_data;
 aci_evt_cmd_rsp_params_get_device_version_t get_device_version;
 aci_evt_cmd_rsp_params_get_device_address_t get_device_address;
 aci_evt_cmd_rsp_params_get_battery_level_t get_battery_level;
 aci_evt_cmd_rsp_params_get_temperature_t get_temperature;
 uint8_t padding[29];
 } params;
} aci_evt_params_cmd_rsp_t;
#line 207 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 aci_bd_addr_type_t dev_addr_type;
 uint8_t dev_addr[ (6) ];
 uint16_t conn_rf_interval;
 uint16_t conn_slave_rf_latency;
 uint16_t conn_rf_timeout;
 uint8_t master_clock_accuracy;
} aci_evt_params_connected_t;
#line 221 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t aci_status;
 uint8_t btle_status;
} aci_evt_params_disconnected_t;
#line 231 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t status_code;
 uint8_t status_source;
 uint8_t secmode1_bitmap;
 uint8_t secmode2_bitmap;
 uint8_t keys_exchanged_slave;
 uint8_t keys_exchanged_master;
} aci_evt_params_bond_status_t;
#line 245 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t pipes_open_bitmap[8];
 uint8_t pipes_closed_bitmap[8];
} aci_evt_params_pipe_status_t;
#line 255 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint16_t conn_rf_interval;
 uint16_t conn_slave_rf_latency;
 uint16_t conn_rf_timeout;
} aci_evt_params_timing_t;
#line 266 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t credit;
} aci_evt_params_data_credit_t;
#line 275 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t pipe_number;
} aci_evt_params_data_ack_t;
#line 284 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 aci_rx_data_t rx_data;
} aci_evt_params_data_received_t;

typedef struct
{
 uint8_t content[1];
} error_data_t;
#line 298 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t pipe_number;
 uint8_t error_code;
 union
 {
 error_data_t error_data;
 } params;
} aci_evt_params_pipe_error_t;
#line 312 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t passkey[6];
} aci_evt_params_display_passkey_t;
#line 321 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t key_type;
} aci_evt_params_key_request_t;
#line 330 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t echo_data[ ( (32)  - 3) ];
} aci_evt_params_echo_t;
#line 339 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
typedef struct
{
 uint8_t len;
 uint8_t evt_opcode;
 union
 {
 aci_evt_params_device_started_t device_started;
 aci_evt_params_echo_t echo;
 aci_evt_params_hw_error_t hw_error;
 aci_evt_params_cmd_rsp_t cmd_rsp;
 aci_evt_params_connected_t connected;
 aci_evt_params_disconnected_t disconnected;
 aci_evt_params_bond_status_t bond_status;
 aci_evt_params_pipe_status_t pipe_status;
 aci_evt_params_timing_t timing;
 aci_evt_params_data_credit_t data_credit;
 aci_evt_params_data_ack_t data_ack;
 aci_evt_params_data_received_t data_received;
 aci_evt_params_pipe_error_t pipe_error;
 aci_evt_params_display_passkey_t display_passkey;
 aci_evt_params_key_request_t key_request;
 } params;
} aci_evt_t;
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib.h"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_protocol_defines.h"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_defs.h"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_protocol_defines.h"
#line 35 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_set_test_mode(uint8_t *buffer, aci_cmd_params_test_t *p_aci_cmd_params_test);
#line 43 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_sleep(uint8_t *buffer);
#line 51 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_get_device_version(uint8_t *buffer);
#line 61 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_set_local_data(uint8_t *buffer, aci_cmd_params_set_local_data_t *p_aci_cmd_params_set_local_data, uint8_t data_size);
#line 70 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_connect(uint8_t *buffer, aci_cmd_params_connect_t *p_aci_cmd_params_connect);
#line 79 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_bond(uint8_t *buffer, aci_cmd_params_bond_t *p_aci_cmd_params_bond);
#line 88 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_disconnect(uint8_t *buffer, aci_cmd_params_disconnect_t *p_aci_cmd_params_disconnect);
#line 96 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
 void acil_encode_baseband_reset(uint8_t *buffer);
#line 104 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
 void acil_encode_direct_connect(uint8_t *buffer);
#line 112 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_wakeup(uint8_t *buffer);
#line 121 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_set_radio_tx_power(uint8_t *buffer, aci_cmd_params_set_tx_power_t *p_aci_cmd_params_set_tx_power);
#line 129 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_get_address(uint8_t *buffer);
#line 139 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_send_data(uint8_t *buffer, aci_cmd_params_send_data_t *p_aci_cmd_params_send_data_t, uint8_t data_size);
#line 148 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_request_data(uint8_t *buffer, aci_cmd_params_request_data_t *p_aci_cmd_params_request_data);
#line 157 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_open_remote_pipe(uint8_t *buffer, aci_cmd_params_open_remote_pipe_t *p_aci_cmd_params_open_remote_pipe);
#line 166 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_close_remote_pipe(uint8_t *buffer, aci_cmd_params_close_remote_pipe_t *p_aci_cmd_params_close_remote_pipe);
#line 176 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_echo_msg(uint8_t *buffer, aci_cmd_params_echo_t *p_cmd_params_echo, uint8_t msg_size);
#line 184 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_battery_level(uint8_t *buffer);
#line 192 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_temparature(uint8_t *buffer);
#line 200 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_read_dynamic_data(uint8_t *buffer);
#line 209 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_change_timing_req(uint8_t *buffer, aci_cmd_params_change_timing_t *p_aci_cmd_params_change_timing);
#line 218 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_change_timing_req_GAP_PPCP(uint8_t *buffer);
#line 230 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_write_dynamic_data(uint8_t *buffer, uint8_t seq_no, uint8_t* dynamic_data, uint8_t dynamic_data_size);
#line 239 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_send_data_ack(uint8_t *buffer, const uint8_t pipe_number);
#line 249 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_send_data_nack(uint8_t *buffer, const uint8_t pipe_number,const uint8_t error_code);
#line 258 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_set_app_latency(uint8_t *buffer, aci_cmd_params_set_app_latency_t *p_aci_cmd_params_set_app_latency);
#line 268 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_setup(uint8_t *buffer, aci_cmd_params_setup_t *p_aci_cmd_params_setup, uint8_t setup_data_size);
#line 277 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_dtm_cmd(uint8_t *buffer, aci_cmd_params_dtm_cmd_t *p_aci_cmd_params_dtm_cmd);
#line 285 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_set_key(uint8_t *buffer, aci_cmd_params_set_key_t *p_aci_cmd_params_set_key);
#line 293 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_bond_security_request(uint8_t *buffer);
#line 303 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
char acil_encode_cmd(uint8_t *buffer, aci_cmd_t *p_aci_cmd);
#line 312 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_broadcast(uint8_t *buffer, aci_cmd_params_broadcast_t * p_aci_cmd_params_broadcast);
#line 321 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_encode_cmd_open_adv_pipes(uint8_t *buffer, aci_cmd_params_open_adv_pipe_t * p_aci_cmd_params_set_adv_svc_data);
#line 330 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_command_response(uint8_t *buffer_in, aci_evt_params_cmd_rsp_t *p_evt_params_cmd_rsp);
#line 339 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_device_started(uint8_t *buffer_in, aci_evt_params_device_started_t *p_evt_params_device_started);
#line 348 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_pipe_status(uint8_t *buffer_in, aci_evt_params_pipe_status_t *p_aci_evt_params_pipe_status);
#line 357 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_disconnected(uint8_t *buffer_in, aci_evt_params_disconnected_t *p_aci_evt_params_disconnected);
#line 366 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_bond_status(uint8_t *buffer_in, aci_evt_params_bond_status_t *p_aci_evt_params_bond_status);
#line 375 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
uint8_t acil_decode_evt_data_received(uint8_t *buffer_in, aci_evt_params_data_received_t *p_evt_params_data_received);
#line 384 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_data_ack(uint8_t *buffer_in, aci_evt_params_data_ack_t *p_evt_params_data_ack);
#line 393 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
uint8_t acil_decode_evt_hw_error(uint8_t *buffer_in, aci_evt_params_hw_error_t *p_aci_evt_params_hw_error);
#line 402 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_credit(uint8_t *buffer_in, aci_evt_params_data_credit_t *p_evt_params_data_credit);
#line 411 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_connected(uint8_t *buffer_in, aci_evt_params_connected_t *p_aci_evt_params_connected);
#line 420 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_timing(uint8_t *buffer_in, aci_evt_params_timing_t *p_evt_params_timing);
#line 428 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_pipe_error(uint8_t *buffer_in, aci_evt_params_pipe_error_t *p_evt_params_pipe_error);
#line 437 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_key_request(uint8_t *buffer_in, aci_evt_params_key_request_t *p_evt_params_key_request);
#line 446 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
uint8_t acil_decode_evt_echo(uint8_t *buffer_in, aci_evt_params_echo_t *buffer_out);
#line 455 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
char acil_decode_evt(uint8_t *buffer_in, aci_evt_t *p_aci_evt);
#line 464 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_if.h"
void acil_decode_evt_display_passkey(uint8_t *buffer_in, aci_evt_params_display_passkey_t *p_aci_evt_params_display_passkey);
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/acilib_types.h"
#line 81 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/blep.h"
extern int8_t readBuff[32];
extern int8_t open_adv_pipe[10];
extern int8_t bond[6];
extern int8_t connect[6];
extern int8_t Directconnect[2];
extern int8_t broadcast[6];
extern int8_t set_local_data[4];
extern uint8_t sendData[];





void InitGPIOInt();
void Init_MCU();
void Blep_Write(uint8_t *dat, uint16_t len);
void Blep_Read();
void Blep_Setup();
uint8_t Blep_WaitForEvent(uint8_t event);

extern void Blep_Bond(uint16_t timeout, uint16_t adv_interval);
extern void Blep_SendData(uint8_t *dat, uint8_t len, uint8_t pipe);
extern void Blep_DirectConnect();
extern void Blep_Connect();
extern void Blep_TestModeState(char state);
extern void Blep_SendDataAck(uint8_t pipe);
extern void Blep_OpenRemotePipe(uint8_t pipe);
extern void Blep_SetLocalData(char *dat, char len, char pipe);
extern void Blep_GetTemp();
extern char Blep_DecodeTemp();
extern void Blep_Disconnect();
extern char Blep_EventCode();
extern char Blep_EventOpcode();
extern char Blep_EventStatus();





typedef struct
{
 uint8_t status_byte;
 uint8_t buffer[32];
} TSetupMsg;



extern void acil_encode_cmd_set_test_mode(uint8_t *buffer, aci_cmd_params_test_t *p_aci_cmd_params_test);
extern void acil_encode_cmd_sleep(uint8_t *buffer);
extern void acil_encode_cmd_get_device_version(uint8_t *buffer);
extern void acil_encode_cmd_set_local_data(uint8_t *buffer, aci_cmd_params_set_local_data_t *p_aci_cmd_params_set_local_data, uint8_t data_size);
extern void acil_encode_cmd_connect(uint8_t *buffer, aci_cmd_params_connect_t *p_aci_cmd_params_connect);
extern void acil_encode_cmd_bond(uint8_t *buffer, aci_cmd_params_bond_t *p_aci_cmd_params_bond);
extern void acil_encode_cmd_disconnect(uint8_t *buffer, aci_cmd_params_disconnect_t *p_aci_cmd_params_disconnect);
extern void acil_encode_baseband_reset(uint8_t *buffer);
extern void acil_encode_direct_connect(uint8_t *buffer);
extern void acil_encode_cmd_wakeup(uint8_t *buffer);
extern void acil_encode_cmd_set_radio_tx_power(uint8_t *buffer, aci_cmd_params_set_tx_power_t *p_aci_cmd_params_set_tx_power);
extern void acil_encode_cmd_get_address(uint8_t *buffer);
extern void acil_encode_cmd_send_data(uint8_t *buffer, aci_cmd_params_send_data_t *p_aci_cmd_params_send_data_t, uint8_t data_size);
extern void acil_encode_cmd_request_data(uint8_t *buffer, aci_cmd_params_request_data_t *p_aci_cmd_params_request_data);
extern void acil_encode_cmd_open_remote_pipe(uint8_t *buffer, aci_cmd_params_open_remote_pipe_t *p_aci_cmd_params_open_remote_pipe);
extern void acil_encode_cmd_close_remote_pipe(uint8_t *buffer, aci_cmd_params_close_remote_pipe_t *p_aci_cmd_params_close_remote_pipe);
extern void acil_encode_cmd_echo_msg(uint8_t *buffer, aci_cmd_params_echo_t *p_cmd_params_echo, uint8_t msg_size);
extern void acil_encode_cmd_battery_level(uint8_t *buffer);
extern void acil_encode_cmd_temparature(uint8_t *buffer);
extern void acil_encode_cmd_read_dynamic_data(uint8_t *buffer);
extern void acil_encode_cmd_write_dynamic_data(uint8_t *buffer, uint8_t seq_no, uint8_t* dynamic_data, uint8_t dynamic_data_size);
extern void acil_encode_cmd_change_timing_req(uint8_t *buffer, aci_cmd_params_change_timing_t *p_aci_cmd_params_change_timing);
extern void acil_encode_cmd_set_app_latency(uint8_t *buffer, aci_cmd_params_set_app_latency_t *p_aci_cmd_params_set_app_latency);
extern void acil_encode_cmd_change_timing_req_GAP_PPCP(uint8_t *buffer);
extern void acil_encode_cmd_setup(uint8_t *buffer, aci_cmd_params_setup_t *p_aci_cmd_params_setup, uint8_t setup_data_size);
extern void acil_encode_cmd_dtm_cmd(uint8_t *buffer, aci_cmd_params_dtm_cmd_t *p_aci_cmd_params_dtm_cmd);
extern void acil_encode_cmd_send_data_ack(uint8_t *buffer, const uint8_t pipe_number );
extern void acil_encode_cmd_send_data_nack(uint8_t *buffer, const uint8_t pipe_number, const uint8_t err_code );
extern void acil_encode_cmd_bond_security_request(uint8_t *buffer);
extern void acil_encode_cmd_broadcast(uint8_t *buffer, aci_cmd_params_broadcast_t * p_aci_cmd_params_broadcast);
extern void acil_encode_cmd_open_adv_pipes(uint8_t *buffer, aci_cmd_params_open_adv_pipe_t * p_aci_cmd_params_open_adv_pipe);
extern void acil_encode_cmd_set_key(uint8_t *buffer, aci_cmd_params_set_key_t *p_aci_cmd_params_set_key);
extern char acil_encode_cmd(uint8_t *buffer, aci_cmd_t *p_aci_cmd);
extern void acil_decode_evt_command_response(uint8_t *buffer_in, aci_evt_params_cmd_rsp_t *p_evt_params_cmd_rsp);
extern void acil_decode_evt_device_started(uint8_t *buffer_in, aci_evt_params_device_started_t *p_evt_params_device_started);
extern void acil_decode_evt_pipe_status(uint8_t *buffer_in, aci_evt_params_pipe_status_t *p_aci_evt_params_pipe_status);
extern void acil_decode_evt_disconnected(uint8_t *buffer_in, aci_evt_params_disconnected_t *p_aci_evt_params_disconnected);
extern void acil_decode_evt_bond_status(uint8_t *buffer_in, aci_evt_params_bond_status_t *p_aci_evt_params_bond_status);
extern uint8_t acil_decode_evt_data_received(uint8_t *buffer_in, aci_evt_params_data_received_t *p_evt_params_data_received);
extern void acil_decode_evt_data_ack(uint8_t *buffer_in, aci_evt_params_data_ack_t *p_evt_params_data_ack);
extern uint8_t acil_decode_evt_hw_error(uint8_t *buffer_in, aci_evt_params_hw_error_t *p_aci_evt_params_hw_error);
extern void acil_decode_evt_credit(uint8_t *buffer_in, aci_evt_params_data_credit_t *p_evt_params_data_credit);
extern void acil_decode_evt_connected(uint8_t *buffer_in, aci_evt_params_connected_t *p_aci_evt_params_connected);
extern void acil_decode_evt_timing(uint8_t *buffer_in, aci_evt_params_timing_t *p_evt_params_timing);
extern void acil_decode_evt_pipe_error(uint8_t *buffer_in, aci_evt_params_pipe_error_t *p_evt_params_pipe_error);
extern void acil_decode_evt_key_request(uint8_t *buffer_in, aci_evt_params_key_request_t *p_evt_params_key_request);
extern uint8_t acil_decode_evt_echo(uint8_t *buffer_in, aci_evt_params_echo_t *aci_evt_params_echo);
extern void acil_decode_evt_display_passkey(uint8_t *buffer_in, aci_evt_params_display_passkey_t *p_aci_evt_params_display_passkey);
extern char acil_decode_evt(uint8_t *buffer_in, aci_evt_t *p_aci_evt);
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_cmds.h"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/aci_evts.h"
#line 1 "c:/users/ayodele/google drive/daa stem academy/hack software/big_data_hack_firmware/android.h"







void OnDataReceived();
#line 9 "C:/Users/Ayodele/Google Drive/DAA STEM Academy/Hack Software/Big_Data_Hack_Firmware/BLEP_Click.c"
sbit Blep_RST at GPIOD_ODR.B6;
sbit Blep_BONDED at GPIOD_ODR.B14;
sbit Blep_RDY at GPIOC_IDR.B11;
sbit Blep_REQ at GPIOD_ODR.B7;
sbit Blep_ACT at GPIOB_IDR.B0;
sbit LED_CONN at GPIOD_ODR.B15;

sbit GSM_STAT at GPIOC_IDR.B5;
sbit GSM_RST at GPIOE_ODR.B4;
sbit GSM_CTS at GPIOD_IDR.B2;
sbit GSM_RTS at GPIOE_ODR.B5;
sbit GSM_PWRKEY at GPIOB_ODR.B1;

sbit GPS_RST at GPIOE_ODR.B10;

sbit LED_GRN at GPIOD_ODR.B12;
sbit LED_ORNG at GPIOD_ODR.B13;
sbit LED_RED at GPIOD_ODR.B14;

char CONN_STATE = 0;
char NEW_EVT, EVT_STATUS, EVT_OPCODE;

char txt[768];
char txt2[1200];
char *string;
int i = 0;
unsigned short data_ready;
char lat_str[8];
char long_str[9];
unsigned short tmp, DataReady;
unsigned long ticked = 0;
unsigned int l = 0;
unsigned int cnt = 0;
#line 45 "C:/Users/Ayodele/Google Drive/DAA STEM Academy/Hack Software/Big_Data_Hack_Firmware/BLEP_Click.c"
void wait();
void read_gps_data();
void send_atc(const char *s);
void Open_GPRS();
void Close_GPRS();
void Send_GPS_Data(char reps);
#line 53 "C:/Users/Ayodele/Google Drive/DAA STEM Academy/Hack Software/Big_Data_Hack_Firmware/BLEP_Click.c"
void interrupt() iv IVT_INT_USART3 ics ICS_AUTO
{
 txt[i] = UART3_Read();
 i++;
 if (i > 768)
 {
 i = 0;
 }
}

SysTick_interrupt() iv IVT_INT_SysTick
{


 LED_ORNG = 1;
 Delay_ms(100);
 LED_ORNG = 0;
 Delay_ms(100);
}

void Init_MCU() {




 GPIO_Digital_Input (&GPIOA_BASE, _GPIO_PINMASK_0);
 GPIO_Alternate_Function_Enable(&_GPIO_MODULE_USART2_PA23);

 GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_6);
 GPIO_Digital_Input(&GPIOB_IDR, _GPIO_PINMASK_0);
 GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_7);
 GPIO_Digital_Input(&GPIOC_IDR, _GPIO_PINMASK_11);
 GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_15);
 GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_12);
 GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_13);
 GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_14);
 GPIO_Digital_Output(&GPIOC_IDR, _GPIO_PINMASK_5);
 GPIO_Digital_Output(&GPIOE_ODR, _GPIO_PINMASK_4);
 GPIO_Digital_Output(&GPIOB_ODR, _GPIO_PINMASK_1);
 GPIO_Digital_Output(&GPIOE_ODR, _GPIO_PINMASK_10);

 SPI3_Init_Advanced(_SPI_FPCLK_DIV16, _SPI_MASTER | _SPI_8_BIT | _SPI_CLK_IDLE_LOW | _SPI_FIRST_CLK_EDGE_TRANSITION | _SPI_LSB_FIRST | _SPI_SS_DISABLE | _SPI_SSM_ENABLE | _SPI_SSI_1, &_GPIO_MODULE_SPI3_PB345);
 UART2_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART2_PA23);

 UART3_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART3_PB10_11);
 Delay_ms(100);
 USART3_CR1bits.RXNEIE = 1;
 NVIC_IntEnable(IVT_INT_USART3);
 Delay_ms(100);

 UART6_Init_Advanced(9600, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART6_PC67 );
 Delay_ms(100);




 NVIC_SYSTICKRVR = 8000000;



 NVIC_SYSTICKCVR = 0;

 NVIC_SYSTICKCSR.B0 = 1;
 NVIC_SYSTICKCSR.B1 = 1;
 NVIC_SYSTICKCSR.B2 = 1;

 NVIC_SetIntPriority(IVT_INT_SysTick, _NVIC_INT_PRIORITY_LVL4);

 NVIC_SetIntPriority(IVT_INT_USART3, _NVIC_INT_PRIORITY_LVL0);

 Blep_RST = 0;
 Blep_REQ = 1;
 Blep_RST = 1;
 Delay_ms(100);
 Blep_RST = 0;
 Delay_ms(100);
 Blep_RST = 1;
 GSM_RST = 0;

 Delay_ms(200);
 GSM_PWRKEY = 1;
 Delay_ms(2000);
 GSM_PWRKEY = 0;

 wait();
 wait();
 wait();
 wait();

 LED_GRN = 1;
 UART_Set_Active(&UART3_Read, &UART3_Write, &UART3_Data_Ready, &UART3_Tx_Idle);
}

void wait() {
 Delay_ms(3000);
}

void read_gps_data()
{

}

void Open_GPRS()
{
 DisableInterrupts();
 UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
 UART6_Write_Text("AT+SAPBR=3,1,Contype,GPRS\r\n");
 Delay_ms(1000);
 UART6_Write_Text("AT+SAPBR=3,1,APN,payandgo.o2.co.uk\r\n");
 Delay_ms(1000);
 UART6_Write_Text("AT+SAPBR=3,1,USER,payandgo\r\n");
 Delay_ms(1000);
 UART6_Write_Text("AT+SAPBR=3,1,PWD,password\r\n");
 Delay_ms(1000);
 UART6_Write_Text("AT+SAPBR=1,1\r\n");
 Delay_ms(1000);
 LED_GRN = 0;
 EnableInterrupts();
 return;
}

void Close_GPRS()
{
 DisableInterrupts();
 UART6_Write_Text("AT+SAPBR=0,1\r\n");
 Delay_ms(1000);
 EnableInterrupts();
 return;
}

void start_HTTP(char *post_data)
{
 DisableInterrupts();

 UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
 UART6_Write_Text("AT+HTTPINIT\r\n");
 Delay_ms(1000);
 UART6_Write_Text("AT+HTTPPARA=CID,1\r\n");
 Delay_ms(1000);
 UART6_Write_Text("AT+HTTPPARA=URL,http://requestb.in/1jpw8ja1\r\n");
 Delay_ms(1000);
 UART6_Write_Text("AT+HTTPPARA=CONTENT,text/plain\r\n");
 Delay_ms(1000);
 UART6_Write_Text("AT+HTTPDATA=1200,5000\r\n");
 Delay_ms(500);


 while(*post_data)
 {
 UART6_Write(*post_data++);
 }
 UART6_Write(0x0D);
 UART6_Write_Text("DATA From Tracker\r\n");
 UART6_Write(0x0D);
 Delay_ms(10000);
 UART6_Write_Text("AT+HTTPACTION=1\r\n");
 Delay_ms(1000);

 EnableInterrupts();
 return;
}

void term_HTTP()
{
 DisableInterrupts();
 LED_RED = 1;
 UART_Set_Active(&UART6_Read, &UART6_Write, &UART6_Data_Ready, &UART6_Tx_Idle);
 UART6_Write_Text("AT+HTTPTERM\r\n");
 Delay_ms(1000);
 EnableInterrupts();
 return;
}

void Send_GPS_Data(char reps)
{
 unsigned char c;

 if (reps > 10)
 {
 for (c = 0; c <= reps; c++ )
 {
 Open_GPRS();
 start_HTTP(txt);
 term_HTTP();
 Delay_Ms(30000);
 }
 }

 else{

 for (c = 0; c <= reps; c++ )
 {
 Open_GPRS();
 start_HTTP(txt);
 term_HTTP();

 }
 }
 return;
}

void main()
{
 Init_MCU();
 Delay_ms(200);
 Blep_Setup();
 LED_CONN = 0;
 Blep_Bond(0xB4, 0x20);
 delay_ms(2000);



 while (1)
 {
 NEW_EVT = Blep_EventCode();
 EVT_STATUS = Blep_EventStatus();
 EVT_OPCODE = Blep_EventOpcode();

 switch(NEW_EVT)
 {
 case ACI_EVT_HW_ERROR:




 if (CONN_STATE) {
 delay_ms(20);
 }
 break;
 case ACI_EVT_CMD_RSP:

 if (EVT_STATUS > 0x03) {
 Blep_Disconnect();
 delay_ms(20);
 }
 break;
 case ACI_EVT_CONNECTED:
 CONN_STATE = 1;
 LED_CONN = CONN_STATE;
 Send_GPS_Data(24);
 break;
 case ACI_EVT_DISCONNECTED:
 CONN_STATE = 0;
 LED_CONN = CONN_STATE;
 Blep_Bond(0xB4, 0x20);
 break;
 case ACI_EVT_DATA_RECEIVED:
 OnDataReceived();
 }

 }

}
