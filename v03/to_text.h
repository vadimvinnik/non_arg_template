#pragma once

#include "../common/binary_conversion.h"

#include <cstdint>
#include <string>

namespace v03
{

template <typename T>
struct type_id {}; // deliberately empty

// fallback for all types that do not have explicit implementations
template <typename T>
std::string to_text_helper(std::uint8_t const* bytes, std::size_t size, type_id<T>)
{
  return "[unknown_type]";
}

std::string to_text_helper(std::uint8_t const* bytes, std::size_t size, type_id<std::uint64_t>);
std::string to_text_helper(std::uint8_t const* bytes, std::size_t size, type_id<std::string>);

// the facade function
template <typename T>
std::string to_text(std::uint8_t const* bytes, std::size_t size)
{
  return to_text_helper(bytes, size, type_id<T>{});
}

} // namespace v03

