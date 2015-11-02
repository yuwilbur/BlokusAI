#include <stdio.h>
#include <iostream>
#include "Blocks.hpp"

int main() {
  B4O test;
  std::vector<std::vector<BlockBase::BLK>> data = test.matrix;
  for (size_t i = 0; i < data.size(); ++i) {
    for (size_t j = 0; j < data[i].size(); ++j) {
      std::cout << data[i][j] << " ";
    }
    std::cout << std::endl;
  }
	return 0;
}