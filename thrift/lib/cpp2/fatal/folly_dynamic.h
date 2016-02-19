/*
 * Copyright 2016 Facebook, Inc.
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
#ifndef THRIFT_FATAL_FOLLY_DYNAMIC_H_
#define THRIFT_FATAL_FOLLY_DYNAMIC_H_ 1

#include <thrift/lib/cpp2/fatal/reflection.h>

#include <folly/dynamic.h>

#include <fatal/type/transform.h>

#include <type_traits>
#include <utility>

/**
 * READ ME FIRST: this header enhances Thrift support for the `folly::dynamic`
 * container.
 *
 * Please refer to the top of `thrift/lib/cpp2/fatal/reflection.h` on how to
 * enable compile-time reflection for Thrift types. The present header relies on
 * it for its functionality.
 *
 * TROUBLESHOOTING:
 *  - make sure you've followed the instructions on `reflection.h` to enable
 *    generation of compile-time reflection;
 *  - make sure you've included the metadata for your Thrift types, as specified
 *    in `reflection.h`.
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */

namespace apache { namespace thrift {

/**
 * Describes the format of the data contained in the `folly::dynamic`.
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
enum class dynamic_format {
  /**
   * A data format that's aimed at being more portable and easier to read by
   * humans.
   *
   * @author: Marcelo Juchem <marcelo@fb.com>
   */
  PORTABLE,
  /**
   * A data format that's compatible with `readFromJson()` and
   * `TSimpleJSONProtocol` from Thrift 1.
   *
   * @author: Marcelo Juchem <marcelo@fb.com>
   */
  JSON_1
};

namespace detail {
template <dynamic_format, thrift_category, bool> struct dynamic_converter_impl;
} // namespace detail {

/**
 * Converts an object to its `folly::dynamic` representation using Thrift's
 * reflection support.
 *
 * All Thrift types are required to be generated using the 'fatal' cpp2 flag,
 * otherwise compile-time reflection metadata won't be available.
 *
 * The root object is output to the given `folly::dynamic` output parameter.
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <dynamic_format Format, typename T>
void to_dynamic(folly::dynamic &out, T &&input) {
  using impl = detail::dynamic_converter_impl<
    Format,
    reflect_category<typename std::decay<T>::type>::value,
    true
  >;

  static_assert(
    fatal::is_complete<impl>::value,
    "to_dynamic: unsupported type"
  );

  impl::to(out, std::forward<T>(input));
}

/**
 * Converts an object to its `folly::dynamic` representation using Thrift's
 * reflection support.
 *
 * All Thrift types are required to be generated using the 'fatal' cpp2 flag,
 * otherwise compile-time reflection metadata won't be available.
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <dynamic_format Format, typename T>
folly::dynamic to_dynamic(T &&input) {
  folly::dynamic result(folly::dynamic::object);

  to_dynamic<Format>(result, std::forward<T>(input));

  return result;
}

/**
 * Converts an object from its `folly::dynamic` representation using Thrift's
 * reflection support.
 *
 * When the `Strict` option is `true`, only documents that strictly follow the
 * given format will be accepted. When it is `false`, documents that don't
 * strictly adhere to the format but which still could be understood will also
 * be accepted, making the decoder more lenient to differences in encoders.
 *
 * All Thrift types are required to be generated using the 'fatal' cpp2 flag,
 * otherwise compile-time reflection metadata won't be available.
 *
 * The decoded object is output to the given `out` parameter.
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <dynamic_format Format, bool Strict = true, typename T>
void from_dynamic(T &out, folly::dynamic const &input) {
  using impl = detail::dynamic_converter_impl<
    Format,
    reflect_category<typename std::decay<T>::type>::value,
    Strict
  >;

  static_assert(
    fatal::is_complete<impl>::value,
    "from_dynamic: unsupported type"
  );

  impl::from(out, input);
}

/**
 * Converts an object from its `folly::dynamic` representation using Thrift's
 * reflection support.
 *
 * When the `Strict` option is `true`, only documents that strictly follow the
 * given format will be accepted. When it is `false`, documents that don't
 * strictly adhere to the format but which still could be understood will also
 * be accepted, making the decoder more lenient to differences in encoders.
 *
 * All Thrift types are required to be generated using the 'fatal' cpp2 flag,
 * otherwise compile-time reflection metadata won't be available.
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <dynamic_format Format, typename T, bool Strict = true>
T from_dynamic(folly::dynamic const &input) {
  T result;

  from_dynamic<Format, Strict>(result, input);

  return result;
}

}} // apache::thrift

#include <thrift/lib/cpp2/fatal/folly_dynamic-inl.h>

#endif // THRIFT_FATAL_FOLLY_DYNAMIC_H_
