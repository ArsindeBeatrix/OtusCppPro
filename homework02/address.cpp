#include "address.hpp"

void print_ip_vector(const adr::address_vector &ip_vector) {
  for (auto ip : ip_vector) {
    adr::print_ip(ip);
  }
}

void adr::print_ip(const address &ip) {

  int n = 4;

  for (int i = 0; i < n; ++i) {
    std::cout << static_cast<int>(ip.ip_array[i]);
    if (i != n - 1) {
      std::cout << ".";
    }
  }
  std::cout << std::endl;
}

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

void merge(adr::address_vector &arr, int left, int right_end_index,
           int middle) {

  int i_index = left + (middle - 1);
  int r_index = i_index + 1;

  for (auto i = i_index; i >= left; --i) {
    int k = i;

    for (auto j = i + 1; j < right_end_index; ++j) {
      if (arr[k] < arr[j]) {

        std::swap(arr[k], arr[j]);
        ++k;
      } else {
        break;
      }
    }
  }
}

void adr::merge_sort(adr::address_vector &arr, int l_index, size_t size) {

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

adr::address_vector adr::filter(const adr::address_vector &s_ip, int first) {
  adr::address_vector tmp;

  for (size_t i = 0; i <= s_ip.size(); ++i) {
    if (s_ip[i].ip_array[0] == first) {
      tmp.push_back(s_ip[i]);
    }
  }
  print_ip_vector(tmp);
  return tmp;
}

adr::address_vector adr::filter(const adr::address_vector &s_ip, int first,
                                int second) {
  adr::address_vector tmp;

  for (size_t i = 0; i <= s_ip.size(); ++i) {
    if (s_ip[i].ip_array[0] == first && s_ip[i].ip_array[1] == second) {
      tmp.push_back(s_ip[i]);
    }
  }
  print_ip_vector(tmp);
  return tmp;
}

adr::address_vector adr::filter_any(const adr::address_vector &s_ip,
                                    int first) {
  adr::address_vector tmp;

  for (size_t i = 0; i <= s_ip.size(); ++i) {
    if (s_ip[i].ip_array[0] == first || s_ip[i].ip_array[1] == first ||
        s_ip[i].ip_array[2] == first || s_ip[i].ip_array[3] == first) {
      tmp.push_back(s_ip[i]);
    }
  }
  print_ip_vector(tmp);
  return tmp;
}

void adr::setIp(const adr::string_vector &s_ip, adr::address_vector &d_id,
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

bool adr::address::operator<(address &right) {
  return this->ip_array < right.ip_array;
}
