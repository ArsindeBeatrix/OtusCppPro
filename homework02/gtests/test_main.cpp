#include "../address.hpp"
#include <gtest/gtest.h>

TEST(CheckSetIp, correct_int_vector) {
  std::vector<adr::string_vector> ip_pool = {
      {"1", "2", "3", "4"}, {"4", "5", "6", "7"}, {"2", "3", "4", "5"}};
  std::vector<adr::address> ip_v4;

  int index = 0;
  for (auto ip : ip_pool) {
    adr::setIp(const_cast<adr::string_vector &>(ip),
               const_cast<std::vector<adr::address> &>(ip_v4), index);
    ip_v4[index].addr_index = index;
    ++index;
  }

  std::vector<adr::address> ip_v4_test = {
      {0, {1, 2, 3, 4}}, {1, {4, 5, 6, 7}}, {2, {2, 3, 4, 5}}};

  ASSERT_EQ(ip_v4.size(), ip_v4_test.size());

  for (auto i = 0; i < ip_pool.size(); ++i) {
    ASSERT_EQ(ip_v4[i].addr_index, ip_v4_test[i].addr_index);
    for (auto j = 0; j < 4; ++j) {
      ASSERT_EQ(ip_v4[i].ip_array[j], ip_v4_test[i].ip_array[j]);
    }
  }
}

TEST(CheckSetIp, correct_empty_vector) {
  std::vector<adr::string_vector> ip_pool = {};
  std::vector<adr::address> ip_v4;

  int index = 0;
  for (auto ip : ip_pool) {
    adr::setIp(const_cast<adr::string_vector &>(ip),
               const_cast<std::vector<adr::address> &>(ip_v4), index);
    ip_v4[index].addr_index = index;
    ++index;
  }

  std::vector<adr::address> ip_v4_test = {};

  ASSERT_EQ(ip_v4.empty(), ip_v4_test.empty());
}