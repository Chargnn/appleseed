
//
// This source file is part of appleseed.
// Visit https://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2018 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

// appleseed.foundation headers.
#include "foundation/platform/arch.h"

// Standard headers.
#include <cinttypes>
#include <cstddef>
#include <cstdint>

namespace foundation
{

//
// Define fixed-size integral types.
//

using int8   = std::int8_t;
using int16  = std::int16_t;
using int32  = std::int32_t;
using int64  = std::int64_t;
using uint8  = std::uint8_t;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;


//
// Define a signed counterpart to std::size_t, i.e. a synonym for the non-standard ssize_t type.
//

#if defined APPLESEED_ARCH32
    typedef int32 isize_t;
#elif defined APPLESEED_ARCH64
    typedef int64 isize_t;
#else
    #error Cannot determine machine architecture.
#endif

static_assert(
    sizeof(isize_t) == sizeof(size_t),
    "foundation::isize_t must have the same size as std::size_t");


//
// Format strings to use with std::printf() variants.
//

#define FMT_UINT64          "%" PRIu64
#define FMT_UINT64_HEX      "%" PRIx64
#define FMT_SIZE_T          "%zu"

}   // namespace foundation
