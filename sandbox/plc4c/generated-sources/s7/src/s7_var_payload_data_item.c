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

#include <stdio.h>
#include <plc4c/spi/read_buffer.h>
#include <plc4c/spi/write_buffer.h>
#include <plc4c/spi/evaluation_helper.h>
#include "s7_var_payload_data_item.h"

// Parse function.
plc4c_return_code plc4c_s7_read_write_s7_var_payload_data_item_parse(plc4c_spi_read_buffer* buf, bool lastItem, plc4c_s7_read_write_s7_var_payload_data_item** _message) {
  uint16_t startPos = plc4c_spi_read_get_pos(buf);
  uint16_t curPos;
  plc4c_return_code _res = OK;

  // Allocate enough memory to contain this data structure.
  (*_message) = malloc(sizeof(plc4c_s7_read_write_s7_var_payload_data_item));
  if(*_message == NULL) {
    return NO_MEMORY;
  }

  // Enum field (returnCode)
  plc4c_s7_read_write_data_transport_error_code returnCode = plc4c_s7_read_write_data_transport_error_code_null;
  _res = plc4c_spi_read_byte(buf, 8, (int8_t*) &returnCode);
  if(_res != OK) {
    return _res;
  }
  (*_message)->return_code = returnCode;

  // Enum field (transportSize)
  plc4c_s7_read_write_data_transport_size transportSize = plc4c_s7_read_write_data_transport_size_null;
  _res = plc4c_spi_read_byte(buf, 8, (int8_t*) &transportSize);
  if(_res != OK) {
    return _res;
  }
  (*_message)->transport_size = transportSize;

  // Simple Field (dataLength)
  uint16_t dataLength = 0;
  _res = plc4c_spi_read_unsigned_int(buf, 16, (uint32_t*) &dataLength);
  if(_res != OK) {
    return _res;
  }
  (*_message)->data_length = dataLength;

  // Array field (data)
  plc4c_list* data = malloc(sizeof(plc4c_list));
  if(data == NULL) {
    return NO_MEMORY;
  }
  {
    // Count array
    uint8_t itemCount = ((plc4c_s7_read_write_data_transport_size_get_size_in_bits(transportSize)) ? plc4c_spi_evaluation_helper_ceil((dataLength) / (8.0)) : dataLength);
    for(int curItem = 0; curItem < itemCount; curItem++) {
      
                
      int8_t _value = 0;
      _res = plc4c_spi_read_byte(buf, 8, (int8_t*) &_value);
      if(_res != OK) {
        return _res;
      }
      plc4c_utils_list_insert_head_value(data, &_value);
    }
  }
  (*_message)->data = data;

  // Padding Field (padding)
  {
    bool _needsPadding = (bool) ((plc4c_spi_read_has_more(buf, 8)) && ((!(lastItem)) && (((((plc4c_spi_evaluation_helper_count(data)) % (2))) == (1)))));
    if(_needsPadding) {
      // Just read the padding data and ignore it
      uint8_t _paddingValue = 0;
      _res = plc4c_spi_read_unsigned_short(buf, 8, (uint16_t*) &_paddingValue);
      if(_res != OK) {
        return _res;
      }
    }
  }

  return OK;
}

plc4c_return_code plc4c_s7_read_write_s7_var_payload_data_item_serialize(plc4c_spi_write_buffer* buf, plc4c_s7_read_write_s7_var_payload_data_item* _message, bool lastItem) {
  plc4c_return_code _res = OK;

  // Enum field (returnCode)
  _res = plc4c_spi_write_byte(buf, 8, _message->return_code);
  if(_res != OK) {
    return _res;
  }

  // Enum field (transportSize)
  _res = plc4c_spi_write_byte(buf, 8, _message->transport_size);
  if(_res != OK) {
    return _res;
  }

  // Simple Field (dataLength)
  _res = plc4c_spi_write_unsigned_int(buf, 16, _message->data_length);
  if(_res != OK) {
    return _res;
  }

  // Array field (data)
  {
    uint8_t itemCount = plc4c_utils_list_size(_message->data);
    for(int curItem = 0; curItem < itemCount; curItem++) {

      int8_t* _value = (int8_t*) plc4c_utils_list_get_value(_message->data, curItem);
      plc4c_spi_write_byte(buf, 8, *_value);
    }
  }

  // Padding Field (padding)
  {
    bool _needsPadding = (bool) ((!(lastItem)) && (((((plc4c_spi_evaluation_helper_count(_message->data)) % (2))) == (1))));
    if(_needsPadding) {
      // Just output the default padding data
      _res = plc4c_spi_write_unsigned_short(buf, 8, 0);
      if(_res != OK) {
        return _res;
      }
    }
  }

  return OK;
}

uint8_t plc4c_s7_read_write_s7_var_payload_data_item_length_in_bytes(plc4c_s7_read_write_s7_var_payload_data_item* _message) {
  return plc4c_s7_read_write_s7_var_payload_data_item_length_in_bits(_message) / 8;
}

uint8_t plc4c_s7_read_write_s7_var_payload_data_item_length_in_bits(plc4c_s7_read_write_s7_var_payload_data_item* _message) {
  uint8_t lengthInBits = 0;

  // Enum Field (returnCode)
  lengthInBits += 8;

  // Enum Field (transportSize)
  lengthInBits += 8;

  // Simple field (dataLength)
  lengthInBits += 16;

  // Array field
  lengthInBits += 8 * plc4c_utils_list_size(_message->data);

  // Padding Field (padding)
  if((bool) ((!(false)) && (((((plc4c_spi_evaluation_helper_count(_message->data)) % (2))) == (1))))) {
    lengthInBits += 8;
  }

  return lengthInBits;
}

