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

#ifndef PLC4C_S7_READ_WRITE_SZL_MODULE_TYPE_CLASS_H_
#define PLC4C_S7_READ_WRITE_SZL_MODULE_TYPE_CLASS_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

enum plc4c_s7_read_write_szl_module_type_class {
  plc4c_s7_read_write_szl_module_type_class_CPU = 0x0,
  plc4c_s7_read_write_szl_module_type_class_IM = 0x4,
  plc4c_s7_read_write_szl_module_type_class_FM = 0x8,
  plc4c_s7_read_write_szl_module_type_class_CP = 0xC
};
typedef enum plc4c_s7_read_write_szl_module_type_class plc4c_s7_read_write_szl_module_type_class;

// Create an empty NULL-struct
static const plc4c_s7_read_write_szl_module_type_class plc4c_s7_read_write_szl_module_type_class_null;


#ifdef __cplusplus
}
#endif
#endif  // PLC4C_S7_READ_WRITE_SZL_MODULE_TYPE_CLASS_H_
