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
    for (int i = 0; i < (int)matrix.size(); ++i) {
      for (int j = 0; j < (int)matrix[i].size(); ++j) {
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
    for (int i = 0; i < (int)matrix.size(); ++i) {
      for (int j = 0; j < (int)matrix[i].size(); ++j) {
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

// 1x 1 Piece
struct B1O : BlockBase {
  B1O() : BlockBase({
    { 1 }
  }) {};
};
// 1x 2 Piece
struct B2O : BlockBase {
  B2O() : BlockBase({
    { 1, 1 }
  }) {};
};
// 2x 3 Piece
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
// 4x 4 Piece
struct B4O : BlockBase {
  B4O() : BlockBase({
    { 1, 1, 1, 1 }
  }) {};
};
struct B4P : BlockBase {
  B4P() : BlockBase({
    { 1, 1 },
    { 1, 1 }
  }) {};
};
struct B4Q : BlockBase {
  B4Q() : BlockBase({
    { 1, 1, 1 },
    { 1, 0, 0 }
  }) {};
};
struct B4S : BlockBase {
  B4S() : BlockBase({
    { 0, 1, 1 },
    { 1, 1, 0 }
  }) {};
};
// 12x 5 Piece
struct B5O : BlockBase {
  B5O() : BlockBase({
    { 1, 1, 1, 1, 1 }
  }) {};
};
struct B5P : BlockBase {
  B5P() : BlockBase({
    { 1, 1, 0 },
    { 1, 1, 1 }
  }) {};
};
struct B5Q : BlockBase {
  B5Q() : BlockBase({
    { 1, 1, 1, 1 },
    { 1, 0, 0, 0 }
  }) {};
};
struct B5R : BlockBase {
  B5R() : BlockBase({
    { 0, 1, 1 },
    { 1, 1, 0 },
    { 0, 1, 0 }
  }) {};
};
struct B5S : BlockBase {
  B5S() : BlockBase({
    { 0, 0, 1, 1 },
    { 1, 1, 1, 0 }
  }) {};
};
struct B5T : BlockBase {
  B5T() : BlockBase({
    { 1, 1, 1 },
    { 0, 1, 0 },
    { 0, 1, 0 }
  }) {};
};
struct B5U : BlockBase {
  B5U() : BlockBase({
    { 1, 0, 1 },
    { 1, 1, 1 }
  }) {};
};
struct B5V : BlockBase {
  B5V() : BlockBase({
    { 1, 0, 0 },
    { 1, 0, 0 },
    { 1, 1, 1 }
  }) {};
};
struct B5W : BlockBase {
  B5W() : BlockBase({
    { 1, 0, 0 },
    { 1, 1, 0 },
    { 0, 1, 1 }
  }) {};
};
struct B5X : BlockBase {
  B5X() : BlockBase({
    { 1, 0, 1 },
    { 0, 1, 0 },
    { 1, 0, 1 }
  }) {};
};
struct B5Y : BlockBase {
  B5Y() : BlockBase({
    { 0, 1, 0, 0 },
    { 1, 1, 1, 1 }
  }) {};
};
struct B5Z : BlockBase {
  B5Z() : BlockBase({
    { 1, 1, 0 },
    { 0, 1, 0 },
    { 0, 1, 1 }
  }) {};
};
