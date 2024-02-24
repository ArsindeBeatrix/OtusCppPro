#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace adr {

typedef std::vector<std::string> string_vector;
using adr::string_vector;
typedef std::string::size_type str_size;
using adr::str_size;

string_vector split(const std::string &str, char d);

class address {
public:
  bool operator>(address &right);
  // friend bool swap(address &left, address &right) {
  //   if (left.ip_array[0] > right.ip_array[0]) {
  //     /* code */
  //   }
  // }
  int addr_index;
  int ip_array[4];
};

void setIp(const adr::string_vector &s_ip, std::vector<address> &d_id,
           int index);

void print_ip(address &ip);

void merge_sort(std::vector<address> &arr, int left_index, size_t size);

} // namespace adr
