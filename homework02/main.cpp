#include "address.hpp"

int main(int argc, char const *argv[]) {

  try {
    std::vector<adr::string_vector> ip_pool;

    for (std::string line; std::getline(std::cin, line);) {
      auto v = adr::split(line, '\t');
      ip_pool.push_back(adr::split(v.at(0), '.'));
    }

    // TODO reverse lexicographically sort
    const size_t ip_size = 4;
    const size_t ip_pool_size = ip_pool.size();

    std::vector<adr::address> ip_v4;

    int index = 0;
    for (auto ip : ip_pool) {
      adr::setIp(const_cast<adr::string_vector &>(ip),
                 const_cast<std::vector<adr::address> &>(ip_v4), index);
      ip_v4[index].addr_index = index;
      ++index;
    }

    adr::merge_sort(const_cast<std::vector<adr::address> &>(ip_v4), 0,
                    ip_pool_size);

    std::cout << "\n";
    // TODO filter by first byte and output
    std::vector<adr::address> ip__filtered_first;
    ip__filtered_first =
        adr::filter(const_cast<std::vector<adr::address> &>(ip_v4), 1);
    for (auto ip : ip__filtered_first) {
      adr::print_ip(ip);
    }

    std::cout << "\n";
    // TODO filter by first and second bytes and output
    std::vector<adr::address> ip__filtered_fs;
    ip__filtered_fs =
        adr::filter(const_cast<std::vector<adr::address> &>(ip_v4), 46, 70);
    for (auto ip : ip__filtered_fs) {
      adr::print_ip(ip);
    }

    std::cout << "\n";
    // TODO filter by any byte and output
    std::vector<adr::address> ip__filtered_any;
    ip__filtered_any =
        adr::filter_any(const_cast<std::vector<adr::address> &>(ip_v4), 46);
    for (auto ip : ip__filtered_any) {
      adr::print_ip(ip);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
