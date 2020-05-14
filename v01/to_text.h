#pragma once

#include "../common/binary_conversion.h"

#include <cstdint>
#include <string>
#include <type_traits>

// to make a function less preferable
template <typename T>
struct implicit_from
{
  implicit_from(T const&) {}
};

// general definition:
// only fall back to it if there is
// no matching explicit specialisation
template <typename T>
std::string to_text(
    implicit_from<std::uint8_t const*>,
    std::size_t)
{
  return "[unknown_type]";
}

// specialisations: one per each type

template <typename S, typename T>
using string_if_same = std::enable_if_t<std::is_same_v<S, T>, std::string>;

template <typename T>
string_if_same<T, std::uint64_t>
  to_text(std::uint8_t const* bytes, std::size_t size)
{
  auto const value = binary_conversion::to_uint64(bytes, size);
  return "[uint64: " + std::to_string(value) + "]";
}

template <typename T>
string_if_same<T, std::string>
  to_text(std::uint8_t const* bytes, std::size_t size)
{
  auto const value = binary_conversion::to_string(bytes, size);
  return "[string: " + value + "]";
}

