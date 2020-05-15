#include "to_text.h"

namespace v04
{

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

} // namespace v04

