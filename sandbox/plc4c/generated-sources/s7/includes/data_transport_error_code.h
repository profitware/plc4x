/*
  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing,
  software distributed under the License is distributed on an
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  KIND, either express or implied.  See the License for the
  specific language governing permissions and limitations
  under the License.
*/

#ifndef PLC4C_S7_READ_WRITE_DATA_TRANSPORT_ERROR_CODE_H_
#define PLC4C_S7_READ_WRITE_DATA_TRANSPORT_ERROR_CODE_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

enum plc4c_s7_read_write_data_transport_error_code {
  plc4c_s7_read_write_data_transport_error_code_RESERVED = 0x00,
  plc4c_s7_read_write_data_transport_error_code_OK = 0xFF,
  plc4c_s7_read_write_data_transport_error_code_ACCESS_DENIED = 0x03,
  plc4c_s7_read_write_data_transport_error_code_INVALID_ADDRESS = 0x05,
  plc4c_s7_read_write_data_transport_error_code_DATA_TYPE_NOT_SUPPORTED = 0x06,
  plc4c_s7_read_write_data_transport_error_code_NOT_FOUND = 0x0A
};
typedef enum plc4c_s7_read_write_data_transport_error_code plc4c_s7_read_write_data_transport_error_code;

// Create an empty NULL-struct
static const plc4c_s7_read_write_data_transport_error_code plc4c_s7_read_write_data_transport_error_code_null;


#ifdef __cplusplus
}
#endif
#endif  // PLC4C_S7_READ_WRITE_DATA_TRANSPORT_ERROR_CODE_H_
