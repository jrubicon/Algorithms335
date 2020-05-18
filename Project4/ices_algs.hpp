///////////////////////////////////////////////////////////////////////////////
// crossing_algs.hpp
//
// Algorithms that solve the iceberg avoiding problem.
//
// All of the TODO sections for this project reside in this file.
//
// This file builds on ices_types.hpp, so you should familiarize yourself
// with that file before working on this file.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cassert>
#include <iostream>

#include "ices_types.hpp"

namespace ices {
// Solve the iceberg avoiding problem for the given grid, using an exhaustive
// optimization algorithm.
//
// This algorithm is expected to run in exponential time, so the grid's
// width+height must be small enough to fit in a 64-bit int; this is enforced
// with an assertion.
//
// The grid must be non-empty.
unsigned int iceberg_avoiding_exhaustive(const grid& setting) {

  // grid must be non-empty.
  assert(setting.rows() > 0);
  assert(setting.columns() > 0);

  // Compute the path length, and check that it is legal.
  const size_t steps = setting.rows() + setting.columns() - 2;
  assert(steps < 64);

  unsigned int counter = 0;
  bool valid = true;

  for (unsigned int bits = 0; bits <= pow(2, steps)-1; bits++){
      path candidate(setting);
      for(unsigned int k = 0; k <= steps -1; k++){
        int bit = (bits >> k) & 1;
        step_direction s1;
        if(bit == 1){
          s1 = STEP_DIRECTION_RIGHT;
        }
        else {
          s1 = STEP_DIRECTION_DOWN;
        }
        if (candidate.is_step_valid(s1)){
          candidate.add_step(s1);
          valid = true;
        }
        else {
          valid = false;
          break;
        }
      }
      if (valid == true){
        counter++;
      }
  }
  return counter;
}

// Solve the iceberg avoiding problem for the given grid, using a dynamic
// programming algorithm.
//
// The grid must be non-empty.
unsigned int iceberg_avoiding_dyn_prog(const grid& setting) {

  // grid must be non-empty.
  assert(setting.rows() > 0);
  assert(setting.columns() > 0);


  const int DIM=100;
  std::vector<std::vector<unsigned>> A(DIM, std::vector<unsigned>(DIM));

  A[0][0] = 1;
  unsigned int from_above, from_left;

  for(unsigned int i = 0; i <= setting.rows() -1; i++){
    for(unsigned int j = 0; j<= setting.columns()-1; j++){
      if (i==0 && j==0)
        continue;

      if (setting.get(i, j) == CELL_ICEBERG){
        A[i][j] = 0;
        continue;
      }
      from_left = from_above = 0;

      if (i > 0 && A[i-1][j]){
        from_above = A[i-1][j];
      }
      if (j > 0 && A[i][j-1]){
        from_left = A[i][j-1];
      }
      A[i][j] =  from_above + from_left;
    }
  }

  return A[setting.rows()-1][setting.columns()-1];
}

}
