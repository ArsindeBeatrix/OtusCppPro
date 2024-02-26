#include "../address.hpp"
#include <gtest/gtest.h>

TEST(CHeckMergeSort, check_merge_sort) {
  std::vector<adr::address> ip_v4 = {
      {0, {1, 2, 3, 4}}, {1, {4, 5, 6, 7}}, {2, {2, 3, 4, 5}}};

  adr::merge_sort(ip_v4, 0, ip_v4.size());

  std::vector<adr::address> ip_v4_test = {
      {0, {4, 5, 6, 7}}, {1, {2, 3, 4, 5}}, {2, {1, 2, 3, 4}}};

  for (auto i = 0; i < ip_v4.size(); ++i) {
    ASSERT_EQ(ip_v4[i].addr_index, ip_v4_test[i].addr_index);
    for (auto j = 0; j < 4; ++j) {
      ASSERT_EQ(ip_v4[i].ip_array[j], ip_v4_test[i].ip_array[j]);
    }
  }
}

TEST(CHeckMergeSort, check_merge_sort_empty) {
  std::vector<adr::address> ip_v4 = {};

  adr::merge_sort(ip_v4, 0, ip_v4.size());

  std::vector<adr::address> ip_v4_test = {};

  ASSERT_EQ(ip_v4.empty(), ip_v4_test.empty());
}