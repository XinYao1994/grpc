/*
 *
 * Copyright 2016 gRPC authors.
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

#ifndef GRPC_CORE_LIB_TRANSPORT_ERROR_UTILS_H
#define GRPC_CORE_LIB_TRANSPORT_ERROR_UTILS_H

#include <grpc/support/port_platform.h>

#include <string>

#include "absl/status/status.h"

#include <grpc/status.h>

#include "src/core/lib/gprpp/time.h"
#include "src/core/lib/iomgr/error.h"
#include "src/core/lib/iomgr/exec_ctx.h"
#include "src/core/lib/transport/http2_errors.h"

/// A utility function to get the status code and message to be returned
/// to the application.  If not set in the top-level message, looks
/// through child errors until it finds the first one with these attributes.
/// All attributes are pulled from the same child error. error_string will
/// be populated with the entire error string. If any of the attributes (code,
/// msg, http_status, error_string) are unneeded, they can be passed as
/// NULL.
void grpc_error_get_status(grpc_error_handle error,
                           grpc_core::Timestamp deadline,
                           grpc_status_code* code, std::string* message,
                           grpc_http2_error_code* http_error,
                           const char** error_string);

/// Utility Function to convert a grpc_error_handle  \a error to an
/// absl::Status. Does NOT consume a ref to grpc_error.
absl::Status grpc_error_to_absl_status(grpc_error_handle error);

/// Utility function to convert an absl::Status \a status to grpc_error. Note
/// that this method does not return "special case" errors such as
/// GRPC_ERROR_CANCELLED, with the exception of GRPC_ERROR_NONE returned for
/// \a absl::OkStatus().
grpc_error_handle absl_status_to_grpc_error(absl::Status status);

/// A utility function to check whether there is a clear status code that
/// doesn't need to be guessed in \a error. This means that \a error or some
/// child has GRPC_ERROR_INT_GRPC_STATUS set, or that it is GRPC_ERROR_NONE or
/// GRPC_ERROR_CANCELLED
bool grpc_error_has_clear_grpc_status(grpc_error_handle error);

#endif /* GRPC_CORE_LIB_TRANSPORT_ERROR_UTILS_H */
