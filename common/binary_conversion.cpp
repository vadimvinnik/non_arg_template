#include "binary_conversion.h"

#include <numeric>

namespace
{

constexpr std::uint64_t append_byte(std::uint64_t acc, std::uint8_t item)
{
  return acc * 0x100 + item;
}

}

namespace binary_conversion
{

std::uint64_t to_uint64(std::uint8_t const* bytes, std::size_t count)
{
  return std::accumulate(
      bytes,
      bytes + count,
      std::uint64_t {0},
      &append_byte);
}

std::string to_string(std::uint8_t const* bytes, std::size_t count)
{
  return std::string { reinterpret_cast<char const*>(bytes), count };
}

}

