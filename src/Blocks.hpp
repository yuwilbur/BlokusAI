#pragma once
#include <stdio.h>
#include <vector>
#include <algorithm>

struct BlockBase {
  enum BLK { Block, Corner, Edge, Empty };
  BlockBase(std::vector<std::vector<bool>> block) {
    ConstructMatrix(block);
  }
  std::vector<std::vector<BLK>> matrix;

protected:
  void ConstructMatrix(std::vector<std::vector<bool>> block) {
    // Allocate matrix with block
    int height = block.size() + 2;
    int width = block[0].size() + 2;
    matrix.resize(height, std::vector<BLK>(width));
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
          matrix[i][j] = BLK::Empty;
        }
        else {
          matrix[i][j] = (block[i - 1][j - 1] == 0) ? BLK::Empty : BLK::Block;
        }
      }
    }

    // Fill in edge and corner space
    int iMin = 0;
    int iMax = height - 1;
    int jMin = 0;
    int jMax = width - 1;
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        if (matrix[i][j] == BLK::Block) {
          continue;
        }
        if (
          (matrix[std::max(i - 1, iMin)][j] == BLK::Block) ||
          (matrix[std::min(i + 1, iMax)][j] == BLK::Block) ||
          (matrix[i][std::max(j - 1, jMin)] == BLK::Block) ||
          (matrix[i][std::min(j + 1, jMax)] == BLK::Block)
          ) {
          matrix[i][j] = BLK::Edge;
        }
        else if (
          (matrix[std::max(i - 1, iMin)][std::max(j - 1, jMin)] == BLK::Block) ||
          (matrix[std::max(i - 1, iMin)][std::min(j + 1, jMax)] == BLK::Block) ||
          (matrix[std::min(i + 1, iMax)][std::max(j - 1, jMin)] == BLK::Block) ||
          (matrix[std::min(i + 1, iMax)][std::min(j + 1, jMax)] == BLK::Block)
          ) {
          matrix[i][j] = BLK::Corner;
        }
      }
    }

  }
};

struct B1O : BlockBase {
  B1O() : BlockBase({
      { 1 }
  }) {};
};

struct B2O : BlockBase {
  B2O() : BlockBase({
      { 1, 1 }
  }) {};
};

struct B3O : BlockBase {
  B3O() : BlockBase({
      { 1, 1, 1 }
  }) {};
};

struct B3P : BlockBase {
  B3P() : BlockBase({
      { 1, 1 },
      { 1, 0 }
  }) {};
};

struct B4O : BlockBase {
  B4O() : BlockBase({
      { 1, 1, 1, 1 }
    }) {};
};

//struct B4P : public BlockBase {};
//struct B4Q : public BlockBase {};
//struct B4R : public BlockBase {};
//struct B4S : public BlockBase {};
//
//struct B5O : public BlockBase {};
//struct B5P : public BlockBase {};
//struct B5Q : public BlockBase {};
//struct B5R : public BlockBase {};
//struct B5S : public BlockBase {};
//struct B5T : public BlockBase {};
//struct B5U : public BlockBase {};
//struct B5V : public BlockBase {};
//struct B5W : public BlockBase {};
//struct B5X : public BlockBase {};
//struct B5Y : public BlockBase {};
//struct B5Z : public BlockBase {};