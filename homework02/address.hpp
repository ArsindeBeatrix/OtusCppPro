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
  bool operator<(address &right);

  // bool operator==(address &right);
  int addr_index;
  int ip_array[4];
};

void print_reverse(std::vector<address> &s_ip);

void setIp(const adr::string_vector &s_ip, std::vector<address> &d_id,
           int index);

void print_ip(address &ip);

void merge_sort(std::vector<address> &arr, int left_index, size_t size);

std::vector<adr::address> filter(std::vector<address> &arr, int first);
std::vector<adr::address> filter(std::vector<address> &arr, int first,
                                 int second);
std::vector<adr::address> filter_any(std::vector<address> &arr, int first);

} // namespace adr
