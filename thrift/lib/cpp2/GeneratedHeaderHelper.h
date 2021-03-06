/*
 * Copyright 2016-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

namespace folly {
class IOBufQueue;
namespace io {
class QueueAppender;
} // io
} // folly

namespace apache {
namespace thrift {
class SimpleJSONProtocolReader;
class SimpleJSONProtocolWriter;
class BinaryProtocolReader;
class BinaryProtocolWriter;
class CompactProtocolReader;
class CompactProtocolWriter;
class Frozen2ProtocolReader;
class Frozen2ProtocolWriter;

} // thrift
} // apache
