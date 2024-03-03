#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace adr {

using string_vector = std::vector<std::string>;
using str_size = std::string::size_type;

string_vector split(const std::string &str, char d);

struct address {
  bool operator<(address &right);
  std::array<int, 4> ip_array{};
};

using address_vector = std::vector<address>;

void setIp(const adr::string_vector &s_ip, address_vector &d_id, int index);

void print_ip(const adr::address &ip);

void merge_sort(address_vector &arr, int left_index, size_t size);

address_vector filter(const address_vector &arr, int first);
address_vector filter(const address_vector &arr, int first, int second);
address_vector filter_any(const address_vector &arr, int first);

} // namespace adr
