#include "address.hpp"

adr::string_vector adr::split(const std::string &str, char d) {

  string_vector r;

  str_size start = 0;
  str_size stop = str.find_first_of(d);

  while (stop != std::string::npos) {
    r.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(d, start);
  }

  r.push_back(str.substr(start));

  return r;
}

void merge(std::vector<adr::address> &arr, int left, int right_end_index,
           int middle) {

  int i_index = left + (middle - 1);
  int r_index = i_index + 1;

  for (auto i = i_index; i >= left; --i) {
    int k = i;

    for (auto j = i + 1; j < right_end_index; ++j) {
      if (arr[k] > arr[j]) {
        std::swap(arr[k], arr[j]);
        int tmp = arr[k].addr_index;
        arr[k].addr_index = arr[j].addr_index;
        arr[j].addr_index = tmp;
        ++k;
      } else {
        break;
      }
    }
  }
}

void adr::merge_sort(std::vector<address> &arr, int l_index, size_t size) {

  int left_size = size / 2;
  int right_size = left_size + (size % 2);
  int r_index = l_index + left_size;
  int end_index = r_index + right_size;

  if (size > 1) {
    merge_sort(arr, l_index, left_size);
    merge_sort(arr, r_index, right_size);
    merge(arr, l_index, end_index, left_size);
  }
}

void adr::setIp(const adr::string_vector &s_ip, std::vector<address> &d_id,
                int index) {

  address addr{};
  int i = 0;

  for (auto ip_part : s_ip) {
    int tmp = static_cast<int>(std::stoul(ip_part));
    addr.ip_array[i] = tmp;
    ++i;
  }
  d_id.push_back(addr);
}

void adr::print_ip(address &ip) {

  int n = 4;

  std::cout << ip.addr_index << ": ";
  for (int i = 0; i < n; ++i) {
    std::cout << static_cast<int>(ip.ip_array[i]);
    if (i != n - 1) {
      std::cout << ".";
    }
  }
  std::cout << std::endl;
}

bool adr::address::operator>(address &right) {

  if (this->ip_array[0] > right.ip_array[0]) {
    return true;
  }
  if (this->ip_array[0] == right.ip_array[0] &&
      this->ip_array[1] > right.ip_array[1]) {
    return true;
  }
  if (this->ip_array[0] == right.ip_array[0] &&
      this->ip_array[1] == right.ip_array[1] &&
      this->ip_array[2] > right.ip_array[2]) {
    return true;
  }
  if (this->ip_array[0] == right.ip_array[0] &&
      this->ip_array[1] == right.ip_array[1] &&
      this->ip_array[2] == right.ip_array[2] &&
      this->ip_array[3] > right.ip_array[3]) {
    return true;
  }

  return false;
}
