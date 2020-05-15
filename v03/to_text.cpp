#include "to_text.h"

namespace v03
{

std::string to_text_helper(std::uint8_t const* bytes, std::size_t size, type_id<std::uint64_t>)
{
  auto const value = binary_conversion::to_uint64(bytes, size);
  return "[uint64: " + std::to_string(value) + "]";
}

std::string to_text_helper(std::uint8_t const* bytes, std::size_t size, type_id<std::string>)
{
  auto const value = binary_conversion::to_string(bytes, size);
  return "[string: " + value + "]";
}

} // namespace v03

