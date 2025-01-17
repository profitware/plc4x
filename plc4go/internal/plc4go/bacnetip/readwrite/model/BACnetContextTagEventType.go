/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package model

import (
	"github.com/apache/plc4x/plc4go/internal/plc4go/spi/utils"
	"github.com/pkg/errors"
)

// Code generated by code-generation. DO NOT EDIT.

// The data-structure of this message
type BACnetContextTagEventType struct {
	*BACnetContextTag
	EventType        BACnetEventType
	ProprietaryValue uint32
	IsProprietary    bool
}

// The corresponding interface
type IBACnetContextTagEventType interface {
	LengthInBytes() uint16
	LengthInBits() uint16
	Serialize(writeBuffer utils.WriteBuffer) error
}

///////////////////////////////////////////////////////////
// Accessors for discriminator values.
///////////////////////////////////////////////////////////
func (m *BACnetContextTagEventType) DataType() BACnetDataType {
	return BACnetDataType_EVENT_TYPE
}

func (m *BACnetContextTagEventType) InitializeParent(parent *BACnetContextTag, header *BACnetTagHeader, tagNumber uint8, actualLength uint32, isNotOpeningOrClosingTag bool) {
	m.BACnetContextTag.Header = header
	m.BACnetContextTag.TagNumber = tagNumber
	m.BACnetContextTag.ActualLength = actualLength
	m.BACnetContextTag.IsNotOpeningOrClosingTag = isNotOpeningOrClosingTag
}

func NewBACnetContextTagEventType(eventType BACnetEventType, proprietaryValue uint32, isProprietary bool, header *BACnetTagHeader, tagNumber uint8, actualLength uint32, isNotOpeningOrClosingTag bool) *BACnetContextTag {
	child := &BACnetContextTagEventType{
		EventType:        eventType,
		ProprietaryValue: proprietaryValue,
		IsProprietary:    isProprietary,
		BACnetContextTag: NewBACnetContextTag(header, tagNumber, actualLength, isNotOpeningOrClosingTag),
	}
	child.Child = child
	return child.BACnetContextTag
}

func CastBACnetContextTagEventType(structType interface{}) *BACnetContextTagEventType {
	castFunc := func(typ interface{}) *BACnetContextTagEventType {
		if casted, ok := typ.(BACnetContextTagEventType); ok {
			return &casted
		}
		if casted, ok := typ.(*BACnetContextTagEventType); ok {
			return casted
		}
		if casted, ok := typ.(BACnetContextTag); ok {
			return CastBACnetContextTagEventType(casted.Child)
		}
		if casted, ok := typ.(*BACnetContextTag); ok {
			return CastBACnetContextTagEventType(casted.Child)
		}
		return nil
	}
	return castFunc(structType)
}

func (m *BACnetContextTagEventType) GetTypeName() string {
	return "BACnetContextTagEventType"
}

func (m *BACnetContextTagEventType) LengthInBits() uint16 {
	return m.LengthInBitsConditional(false)
}

func (m *BACnetContextTagEventType) LengthInBitsConditional(lastItem bool) uint16 {
	lengthInBits := uint16(m.ParentLengthInBits())

	// Manual Field (eventType)
	lengthInBits += uint16(int32(m.ActualLength) * int32(int32(8)))

	// Manual Field (proprietaryValue)
	lengthInBits += uint16(int32(0))

	// A virtual field doesn't have any in- or output.

	return lengthInBits
}

func (m *BACnetContextTagEventType) LengthInBytes() uint16 {
	return m.LengthInBits() / 8
}

func BACnetContextTagEventTypeParse(readBuffer utils.ReadBuffer, tagNumberArgument uint8, dataType BACnetDataType, isNotOpeningOrClosingTag bool, actualLength uint32) (*BACnetContextTag, error) {
	if pullErr := readBuffer.PullContext("BACnetContextTagEventType"); pullErr != nil {
		return nil, pullErr
	}

	// Validation
	if !(isNotOpeningOrClosingTag) {
		return nil, utils.ParseAssertError{"length 6 and 7 reserved for opening and closing tag"}
	}

	// Manual Field (eventType)
	eventType, _eventTypeErr := ReadEventType(readBuffer, actualLength)
	if _eventTypeErr != nil {
		return nil, errors.Wrap(_eventTypeErr, "Error parsing 'eventType' field")
	}

	// Manual Field (proprietaryValue)
	proprietaryValue, _proprietaryValueErr := ReadProprietaryEventType(readBuffer, eventType, actualLength)
	if _proprietaryValueErr != nil {
		return nil, errors.Wrap(_proprietaryValueErr, "Error parsing 'proprietaryValue' field")
	}

	// Virtual field
	_isProprietary := bool((eventType) == (BACnetEventType_VENDOR_PROPRIETARY_VALUE))
	isProprietary := bool(_isProprietary)

	if closeErr := readBuffer.CloseContext("BACnetContextTagEventType"); closeErr != nil {
		return nil, closeErr
	}

	// Create a partially initialized instance
	_child := &BACnetContextTagEventType{
		EventType:        eventType,
		ProprietaryValue: proprietaryValue,
		IsProprietary:    isProprietary,
		BACnetContextTag: &BACnetContextTag{},
	}
	_child.BACnetContextTag.Child = _child
	return _child.BACnetContextTag, nil
}

func (m *BACnetContextTagEventType) Serialize(writeBuffer utils.WriteBuffer) error {
	ser := func() error {
		if pushErr := writeBuffer.PushContext("BACnetContextTagEventType"); pushErr != nil {
			return pushErr
		}

		// Manual Field (eventType)
		_eventTypeErr := WriteEventType(writeBuffer, m.EventType)
		if _eventTypeErr != nil {
			return errors.Wrap(_eventTypeErr, "Error serializing 'eventType' field")
		}

		// Manual Field (proprietaryValue)
		_proprietaryValueErr := WriteProprietaryEventType(writeBuffer, m.EventType, m.ProprietaryValue)
		if _proprietaryValueErr != nil {
			return errors.Wrap(_proprietaryValueErr, "Error serializing 'proprietaryValue' field")
		}
		// Virtual field
		if _isProprietaryErr := writeBuffer.WriteVirtual("isProprietary", m.IsProprietary); _isProprietaryErr != nil {
			return errors.Wrap(_isProprietaryErr, "Error serializing 'isProprietary' field")
		}

		if popErr := writeBuffer.PopContext("BACnetContextTagEventType"); popErr != nil {
			return popErr
		}
		return nil
	}
	return m.SerializeParent(writeBuffer, m, ser)
}

func (m *BACnetContextTagEventType) String() string {
	if m == nil {
		return "<nil>"
	}
	buffer := utils.NewBoxedWriteBufferWithOptions(true, true)
	m.Serialize(buffer)
	return buffer.GetBox().String()
}
