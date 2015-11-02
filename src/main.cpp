#include <stdio.h>
#include <iostream>
#include "Blocks.hpp"

int main() {
  B1O test;
  std::vector<std::vector<BlockBase::BLK>> data = test.matrix;
  for (int i = 0; i < data.size(); ++i) {
    for (int j = 0; j < data[i].size(); ++j) {
      std::cout << data[i][j] << " ";
    }
    std::cout << std::endl;
  }
	return 0;
}