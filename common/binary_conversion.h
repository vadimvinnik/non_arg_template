#pragma once

#include <cstdint>
#include <string>

namespace binary_conversion
{

std::uint64_t to_uint64(std::uint8_t const* bytes, std::size_t count);
std::string to_string(std::uint8_t const* bytes, std::size_t count);

} // namespace binary_conversion

