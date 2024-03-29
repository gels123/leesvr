/*!The Treasure Box Library
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * Copyright (C) 2009 - 2018, TBOOX Open Source Group.
 *
 * @author      ruki
 * @file        prefix.S
 *
 * modified by Alvin at 2018/12/21
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */
#ifdef __ELF__
#   define EXTERN_ASM
#else
#   define EXTERN_ASM   _
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * arch
 */

#if defined(ARCH_ARM_v8)
        .arch armv8-a
#elif defined(ARCH_ARM_v7A)
        .arch armv7-a
#elif defined(ARCH_ARM_v7)
        .arch armv7
#elif defined(ARCH_ARM_v6) 
        .arch armv6
#elif defined(ARCH_ARM_v5te) 
        .arch armv5te
#elif defined(ARCH_ARM_v5) 
        .arch armv5
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * fpu
 */

#if defined(ARCH_ARM_NEON) && !defined(ARCH_ARM64)
        .fpu neon
#elif defined(ARCH_VFP)
        .fpu vfp
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * syntax
 */
#if defined(ARCH_ARM) && !defined(ARCH_ARM64)
        .syntax unified
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * eabi
 */
#if defined(__ELF__) && defined(ARCH_ARM) && !defined(ARCH_ARM64)
        .eabi_attribute 25, 1 
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */

/*! function
 * 
 * @code
    function func_xxxx, export=1
        ...
    endfunc
   @endcode
 */
.macro function name, export=0
    .macro endfunc
#ifdef __ELF__
        .size \name, . - \name
#endif
        .purgem endfunc
    .endm

        .text
        .align CPU_BYTE_SIZE
    .if \export
        .global EXTERN_ASM\name
#ifdef __ELF__
        .type   EXTERN_ASM\name, %function
        .hidden EXTERN_ASM\name
#endif
EXTERN_ASM\name:
    .else
#ifdef __ELF__
        .type   \name, %function
        .hidden \name
#endif
\name:
    .endif
.endm

/*! label
 * 
 * @code
    label name
        ...
   @endcode
 */
.macro label name
        .align CPU_BYTE_SIZE
\name:
.endm

