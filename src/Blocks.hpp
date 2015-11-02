#pragma once
#include <stdio.h>
#include <vector>

struct BlockBase {
  enum BLK { B, E, F, C };
  // X - Block
  // E - Edge
  // F - Free space
  // C - Corner
  std::vector<std::vector<BLK>> matrix;

protected:
  std::vector<std::vector<bool>> block;
  void ConstructMatrix(std::vector<std::vector<bool>> block) {
    // Allocate space on matrix
    int width = block.size() + 2;
    int height = block[0].size() + 2;
    for (int i = 0; i < height; ++i) {
      std::vector<BLK> row(width);
      std::fill(row.begin(), row.end(), BLK::F);
      matrix.push_back(row);
    }

    // Fill in block
    for (int i = 1; i < height - 1; ++i) {
      for (int j = 1; j < width - 1; ++j) {
        matrix[i][j] = (block[i - 1][j - 1] == 1) ? BLK::B : BLK::F;
      }
    }

    // Fill in edge space

  }
};

struct B1O : BlockBase {
  B1O() {
    ConstructMatrix({
      { 1 }
    });
  }
};

struct B2O : public BlockBase {
  B2O() {
    ConstructMatrix({
      { 1, 1 }
    });
  }
};

struct B3O : public BlockBase {
  B3O() {
    ConstructMatrix({
      { 1, 1, 1 }
    });
  }
};

struct B3P : public BlockBase {
  B3P() {
    ConstructMatrix({
      { 1, 1 },
      { 1, 0 }
    });
  }
};
//
//struct B4O : public BlockBase {};
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