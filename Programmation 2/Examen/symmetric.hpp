#pragma once

class SymmetricMtx{
  double* symmx;

public:
  SymmetricMtx(int n);

  int dimn;

  double& operator()(int i, int j);

};
