// The common test body to be included
// into the actual test source files
// that only differ in header version.
//
// The headers have identical interfaces
// and differ in implementation details.

#include <catch.hpp>

#define QUOTE(str) #str
#define EXPAND_AND_QUOTE(str) QUOTE(str)

TEST_CASE(EXPAND_AND_QUOTE(HEADER_VERSION) ": std::uint64_t") {
  constexpr uint8_t raw[] { 0x04, 0x00 };
  CHECK(HEADER_VERSION::to_text<std::uint64_t>(raw, sizeof(raw)) == "[uint64: 1024]");
}

TEST_CASE(EXPAND_AND_QUOTE(HEADER_VERSION) "std::string") {
  constexpr uint8_t raw[] { 'a', 'b', 'c', 'd' };
  CHECK(HEADER_VERSION::to_text<std::string>(raw, sizeof(raw)) == "[string: abcd]");
}

TEST_CASE(EXPAND_AND_QUOTE(HEADER_VERSION) "custom type") {
  struct dummy { int data; };
  constexpr uint8_t raw[] { 'a', 'b', 'c', 'd' };
  CHECK(HEADER_VERSION::to_text<dummy>(raw, sizeof(raw)) == "[unknown_type]");
}

