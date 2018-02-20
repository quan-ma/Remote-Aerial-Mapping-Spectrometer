/* 
	SimpleBGC Serial API  library - definition of commands
	More info: http://www.basecamelectronics.com

  * last edit date: 18.10.2014
  * compatible with the revision 2.4 of Serial API specification.


	Copyright (c) 2014 Aleksei Moskalenko
	All rights reserved.
	
	
  This software is free for use and redistribution under a BSD license:
   
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	    * Redistributions of source code must retain the above copyright
	      notice, this list of conditions and the following disclaimer.
	    * Redistributions in binary form must reproduce the above copyright
	      notice, this list of conditions and the following disclaimer in the
	      documentation and/or other materials provided with the distribution.
	    * Neither the name of the Basecamelectronics company nor the
	      names of its contributors may be used to endorse or promote products
	      derived from this software without specific prior written permission.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/   

#ifndef  __SBGC_command__
#define  __SBGC_command__

#include <inttypes.h>
#include "SBGC_rc.h"


// Size if header and checksums
#define SBGC_CMD_PAYLOAD_BYTES 5

// Max. size of a command after packing to bytes
#define SBGC_CMD_MAX_BYTES 255



////////////////////// Command ID definitions ////////////////
#define SBGC_CMD_READ_PARAMS  82
#define SBGC_CMD_WRITE_PARAMS  87
#define SBGC_CMD_REALTIME_DATA  68
#define SBGC_CMD_BOARD_INFO  86
#define SBGC_CMD_CALIB_ACC  65
#define SBGC_CMD_CALIB_GYRO  103
#define SBGC_CMD_CALIB_EXT_GAIN  71
#define SBGC_CMD_USE_DEFAULTS  70
#define SBGC_CMD_CALIB_POLES  80
#define SBGC_CMD_RESET  114
#define SBGC_CMD_HELPER_DATA 72
#define SBGC_CMD_CALIB_OFFSET  79
#define SBGC_CMD_CALIB_BAT  66
#define SBGC_CMD_MOTORS_ON   77
#define SBGC_CMD_MOTORS_OFF  109
#define SBGC_CMD_CONTROL   67
#define SBGC_CMD_TRIGGER_PIN  84
#define SBGC_CMD_EXECUTE_MENU 69
#define SBGC_CMD_GET_ANGLES  73
#define SBGC_CMD_CONFIRM  67


// Starting from board ver.3.0
#define SBGC_CMD_BOARD_INFO_3  20
#define SBGC_CMD_READ_PARAMS_3 21
#define SBGC_CMD_WRITE_PARAMS_3 22
#define SBGC_CMD_REALTIME_DATA_3  23
#define SBGC_CMD_SELECT_IMU_3 24
#define SBGC_CMD_REALTIME_DATA_4  25
#define SBGC_CMD_ENCODERS_CALIB_OFFSET_4  26
#define SBGC_CMD_ENCODERS_CALIB_FLD_OFFSET_4 27
#define SBGC_CMD_READ_PROFILE_NAMES 28
#define SBGC_CMD_WRITE_PROFILE_NAMES 29

#define SBGC_CMD_QUEUE_PARAMS_INFO_3 30
#define SBGC_CMD_SET_ADJ_VARS 31
#define SBGC_CMD_SAVE_PARAMS_3 32
#define SBGC_CMD_READ_PARAMS_EXT 33
#define SBGC_CMD_WRITE_PARAMS_EXT 34
#define SBGC_CMD_AUTO_PID 35
#define SBGC_CMD_SERVO_OUT 36
#define SBGC_CMD_BODE_TEST_START_STOP 37
#define SBGC_CMD_BODE_TEST_DATA 38
#define SBGC_CMD_I2C_WRITE_REG_BUF 39
#define SBGC_CMD_I2C_READ_REG_BUF 40
#define SBGC_CMD_WRITE_EXTERNAL_DATA 41
#define SBGC_CMD_READ_EXTERNAL_DATA 42
#define SBGC_CMD_READ_ADJ_VARS_CFG 43
#define SBGC_CMD_WRITE_ADJ_VARS_CFG 44
#define SBGC_CMD_API_VIRT_CH_CONTROL 45
#define SBGC_CMD_ADJ_VARS_STATE 46

#define SBGC_CMD_SIGN_MESSAGE_3 50
#define SBGC_CMD_BOOT_MODE_3 51
#define SBGC_CMD_SYSTEM_STATE 52

#define SBGC_CMD_DEBUG_VARS_INFO_3 253
#define SBGC_CMD_DEBUG_VARS_3  254


#define SBGC_CMD_ERROR  255






///////////// Helpers for some commands ////////////////////
// CMD_CONTROL
typedef struct __attribute__((__packed__)) {
  uint8_t mode;
  int16_t speedROLL;
  int16_t angleROLL;
  int16_t speedPITCH;
  int16_t anglePITCH;
  int16_t speedYAW;
  int16_t angleYAW;
} SBGC_cmd_control_data;

// CMD_TRIGGER_PIN
typedef struct {
  uint8_t pin;
  int8_t state;
} SBGC_cmd_trigger_data;


// CMD_SERVO_OUT
typedef struct {
  int16_t servo[8];
} SBGC_cmd_servo_out_data;

//CMD_SET_ADJ_VARS
typedef struct {
  uint8_t id;
  int32_t val;
} SBGC_cmd_set_adj_vars_var_data;

//CMD_API_VIRT_CH_CONTROL
typedef struct {
	int16_t data[SBGC_API_VIRT_NUM_CHANNELS];
} SBGC_cmd_api_virt_ch_control;


#endif //__SBGC_command__
