#pragma once

#include "../common/binary_conversion.h"

#include <cstdint>
#include <string>

namespace v02
{

// general definition:
// only fall back to it if there is
// no matching explicit specialisation
template <typename T>
struct to_text_helper
{
  static std::string to_text(std::uint8_t const*, std::size_t)
  {
    return "[unknown_type]";
  }
};

// specialisations: one per each type

template <>
struct to_text_helper<std::uint64_t>
{
  static std::string to_text(std::uint8_t const* bytes, std::size_t size)
  {
    auto const value = binary_conversion::to_uint64(bytes, size);
    return "[uint64: " + std::to_string(value) + "]";
  }
};

template <>
struct to_text_helper<std::string>
{
  static std::string to_text(std::uint8_t const* bytes, std::size_t size)
  {
    auto const value = binary_conversion::to_string(bytes, size);
    return "[string: " + value + "]";
  }
};

// the facade function
template <typename T>
std::string to_text(std::uint8_t const* bytes, std::size_t size)
{
  return to_text_helper<T>::to_text(bytes, size);
}

} // namespace v02

