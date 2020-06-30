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
#ifndef PLC4C_S7_READ_WRITE_S7_ADDRESS_H_
#define PLC4C_S7_READ_WRITE_S7_ADDRESS_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <plc4c/utils/list.h>
#include "s7_address.h"
#include "memory_area.h"
#include "transport_size.h"

// Structure used to contain the discriminator values for discriminated types using this as a parent
struct plc4c_s7_read_write_s7_address_discriminator {
  uint8_t addressType;
};
typedef struct plc4c_s7_read_write_s7_address_discriminator plc4c_s7_read_write_s7_address_discriminator;

// Enum assigning each sub-type an individual id.
enum plc4c_s7_read_write_s7_address_type {
  plc4c_s7_read_write_s7_address_type_s7_read_write_s7_address_any = 0};
typedef enum plc4c_s7_read_write_s7_address_type plc4c_s7_read_write_s7_address_type;

// Function to get the discriminator values for a given type.
plc4c_s7_read_write_s7_address_discriminator plc4c_s7_read_write_s7_address_get_discriminator(plc4c_s7_read_write_s7_address_type type);

struct plc4c_s7_read_write_s7_address {
  /* This is an abstract type so this property saves the type of this typed union */
  plc4c_s7_read_write_s7_address_type _type;
  /* Properties */
  union {
    struct { /* S7AddressAny */
      plc4c_s7_read_write_transport_size s7_address_any_transport_size;
      uint16_t s7_address_any_number_of_elements;
      uint16_t s7_address_any_db_number;
      plc4c_s7_read_write_memory_area s7_address_any_area;
      uint16_t s7_address_any_byte_address;
      unsigned int s7_address_any_bit_address : 3;
    };
  };
};
typedef struct plc4c_s7_read_write_s7_address plc4c_s7_read_write_s7_address;

// Create an empty NULL-struct
static const plc4c_s7_read_write_s7_address plc4c_s7_read_write_s7_address_null;

plc4c_return_code plc4c_s7_read_write_s7_address_parse(plc4c_spi_read_buffer* buf, plc4c_s7_read_write_s7_address** message);

plc4c_return_code plc4c_s7_read_write_s7_address_serialize(plc4c_spi_write_buffer* buf, plc4c_s7_read_write_s7_address* message);

uint8_t plc4c_s7_read_write_s7_address_length_in_bytes(plc4c_s7_read_write_s7_address* message);

uint8_t plc4c_s7_read_write_s7_address_length_in_bits(plc4c_s7_read_write_s7_address* message);

#ifdef __cplusplus
}
#endif
#endif  // PLC4C_S7_READ_WRITE_S7_ADDRESS_H_
