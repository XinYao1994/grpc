/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPC_CORE_LIB_SLICE_SLICE_STRING_HELPERS_H
#define GRPC_CORE_LIB_SLICE_SLICE_STRING_HELPERS_H

#include <grpc/support/port_platform.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <grpc/slice.h>

#include "src/core/lib/gpr/string.h"

/* Calls gpr_dump on a slice. */
char* grpc_dump_slice(const grpc_slice& slice, uint32_t flags);
/* Calls gpr_dump on a slice and returns the result as a slice. */
grpc_slice grpc_dump_slice_to_slice(const grpc_slice& slice, uint32_t flags);

bool grpc_parse_slice_to_uint32(grpc_slice str, uint32_t* result);

#endif /* GRPC_CORE_LIB_SLICE_SLICE_STRING_HELPERS_H */
