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

package org.apache.plc4x.simulator.server.s7;

import org.apache.commons.lang3.NotImplementedException;

import java.math.BigInteger;

/**
 * TODO write comment
 *
 * @author julian
 * Created by julian on 22.05.20
 */
public class S7ValueFactory {

    // Signed 2 Byte INT
    public static S7Value INT(short s) {
        return new S7Value(S7Type.INT, s);
    }

    // Unsigned 2 Byte INT
    public static S7Value UINT(int i) {
        checkUnsigned(i);
        return new S7Value(S7Type.UINT, i);
    }

    // Signed 4 Byte INT
    public static S7Value DINT(int i) {
        return new S7Value(S7Type.DINT, i);
    }

    // Unsigned 4 Byte INT
    public static S7Value UDINT(long l) {
        checkUnsigned(l);
        throw new NotImplementedException("");
    }

    // Signed 8 Byte Int
    public static S7Value LINT(long l) {
        return new S7Value(S7Type.LINT, l);
    }

    // Unsigned 8 Byte INT
    public static S7Value ULINT(BigInteger bi) {
        checkUnsigned(bi.doubleValue());
        throw new NotImplementedException("");
    }

    // 4 Byte floating point
    public static S7Value REAL(float f) {
        return new S7Value(S7Type.REAL, f);
    }

    // 8 Byte floating point
    public static S7Value LREAL(double d) {
        throw new NotImplementedException("");
    }

    private static void checkUnsigned(double v) {
        if (v < 0) {
            throw new IllegalArgumentException("Unsigned Value cannot have negative value");
        }
    }
}