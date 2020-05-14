#pragma once

#include "../common/binary_conversion.h"

#include <cstdint>
#include <string>
#include <type_traits>

// general definition:
// only fall back to it if there is
// no matching explicit specialisation
template <typename T>
std::string to_text(std::uint8_t const*, std::size_t)
{
  return "[unknown_type]";
}

// specialisations: one per each type

template <>
std::string to_text<std::uint64_t>(std::uint8_t const* bytes, std::size_t size)
{
  auto const value = binary_conversion::to_uint64(bytes, size);
  return "[uint64: " + std::to_string(value) + "]";
}

template <>
std::string to_text<std::string>(std::uint8_t const* bytes, std::size_t size)
{
  auto const value = binary_conversion::to_string(bytes, size);
  return "[string: " + value + "]";
}

