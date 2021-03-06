/*-
 * Copyright (c) 2015 David T. Chisnall
 *
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237
 * ("CTSRD"), as part of the DARPA CRASH research programme.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-11-C-0249
 * ("MRC2"), as part of the DARPA MRC research programme.
 *
 * @BERI_LICENSE_HEADER_START@
 *
 * Licensed to BERI Open Systems C.I.C. (BERI) under one or more contributor
 * license agreements.  See the NOTICE file distributed with this work for
 * additional information regarding copyright ownership.  BERI licenses this
 * file to you under the BERI Hardware-Software License, Version 1.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at:
 *
 *   http://www.beri-open-systems.org/legal/license-1-0.txt
 *
 * Unless required by applicable law or agreed to in writing, Work distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 *
 * @BERI_LICENSE_HEADER_END@
 */

#pragma once
#include <cstdint>

namespace cheri {
inline uint8_t cheri_byte_order_to_host(uint8_t src) { return src; }
#ifndef __BIG_ENDIAN__
inline uint16_t cheri_byte_order_to_host(uint16_t src)
{
	return __builtin_bswap16(src);
}
inline uint32_t cheri_byte_order_to_host(uint32_t src)
{
	return __builtin_bswap32(src);
}
inline uint64_t cheri_byte_order_to_host(uint64_t src)
{
	return __builtin_bswap64(src);
}
#else
inline uint16_t cheri_byte_order_to_host(uint16_t src) { return src; }
inline uint32_t cheri_byte_order_to_host(uint32_t src) { return src; }
inline uint64_t cheri_byte_order_to_host(uint64_t src) { return src; }
#endif
}
