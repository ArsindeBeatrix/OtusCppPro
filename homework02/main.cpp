#include "address.hpp"
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {

  try {
    std::vector<adr::string_vector> ip_pool;

    std::ifstream in(argv[1]);
    std::string line;

    if (in.is_open()) {
      while (std::getline(in, line)) {
        auto v = std::move(adr::split(line, '\t'));
        ip_pool.push_back(std::move(adr::split(v.at(0), '.')));
      }
    }
    in.close();

    std::cout << "------- Reverse lexicographically sort -----\n";
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

    std::cout << "\n------- Filter by first byte and output -----\n";
    std::vector<adr::address> ip__filtered_first;
    ip__filtered_first = std::move(
        adr::filter(const_cast<std::vector<adr::address> &>(ip_v4), 1));

    std::cout
        << "\n------- Filter by first and second bytes and output -------\n";
    std::vector<adr::address> ip__filtered_fs;
    ip__filtered_fs = std::move(
        adr::filter(const_cast<std::vector<adr::address> &>(ip_v4), 46, 70));

    std::cout << "\n------- Filter by any byte and output ---------\n";
    std::vector<adr::address> ip__filtered_any;
    ip__filtered_any = std::move(
        adr::filter_any(const_cast<std::vector<adr::address> &>(ip_v4), 46));

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
