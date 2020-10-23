//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
package model

import (
    "plc4x.apache.org/plc4go-modbus-driver/v0/internal/plc4go/spi"
    "plc4x.apache.org/plc4go-modbus-driver/v0/internal/plc4go/utils"
)

// The data-structure of this message
type BACnetUnconfirmedServiceRequestWriteGroup struct {
    BACnetUnconfirmedServiceRequest
}

// The corresponding interface
type IBACnetUnconfirmedServiceRequestWriteGroup interface {
    IBACnetUnconfirmedServiceRequest
    Serialize(io utils.WriteBuffer) error
}

// Accessors for discriminator values.
func (m BACnetUnconfirmedServiceRequestWriteGroup) ServiceChoice() uint8 {
    return 0x0A
}

func (m BACnetUnconfirmedServiceRequestWriteGroup) initialize() spi.Message {
    return m
}

func NewBACnetUnconfirmedServiceRequestWriteGroup() BACnetUnconfirmedServiceRequestInitializer {
    return &BACnetUnconfirmedServiceRequestWriteGroup{}
}

func CastIBACnetUnconfirmedServiceRequestWriteGroup(structType interface{}) IBACnetUnconfirmedServiceRequestWriteGroup {
    castFunc := func(typ interface{}) IBACnetUnconfirmedServiceRequestWriteGroup {
        if iBACnetUnconfirmedServiceRequestWriteGroup, ok := typ.(IBACnetUnconfirmedServiceRequestWriteGroup); ok {
            return iBACnetUnconfirmedServiceRequestWriteGroup
        }
        return nil
    }
    return castFunc(structType)
}

func CastBACnetUnconfirmedServiceRequestWriteGroup(structType interface{}) BACnetUnconfirmedServiceRequestWriteGroup {
    castFunc := func(typ interface{}) BACnetUnconfirmedServiceRequestWriteGroup {
        if sBACnetUnconfirmedServiceRequestWriteGroup, ok := typ.(BACnetUnconfirmedServiceRequestWriteGroup); ok {
            return sBACnetUnconfirmedServiceRequestWriteGroup
        }
        if sBACnetUnconfirmedServiceRequestWriteGroup, ok := typ.(*BACnetUnconfirmedServiceRequestWriteGroup); ok {
            return *sBACnetUnconfirmedServiceRequestWriteGroup
        }
        return BACnetUnconfirmedServiceRequestWriteGroup{}
    }
    return castFunc(structType)
}

func (m BACnetUnconfirmedServiceRequestWriteGroup) LengthInBits() uint16 {
    var lengthInBits uint16 = m.BACnetUnconfirmedServiceRequest.LengthInBits()

    return lengthInBits
}

func (m BACnetUnconfirmedServiceRequestWriteGroup) LengthInBytes() uint16 {
    return m.LengthInBits() / 8
}

func BACnetUnconfirmedServiceRequestWriteGroupParse(io *utils.ReadBuffer) (BACnetUnconfirmedServiceRequestInitializer, error) {

    // Create the instance
    return NewBACnetUnconfirmedServiceRequestWriteGroup(), nil
}

func (m BACnetUnconfirmedServiceRequestWriteGroup) Serialize(io utils.WriteBuffer) error {
    ser := func() error {

        return nil
    }
    return BACnetUnconfirmedServiceRequestSerialize(io, m.BACnetUnconfirmedServiceRequest, CastIBACnetUnconfirmedServiceRequest(m), ser)
}