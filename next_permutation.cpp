#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n) {
  //  Write your code here.
  int k = -1;
  for (int i = n - 2; i >= 0; i--) {
    if (permutation[i] < permutation[i + 1]) {
      k = i;
      break;
    }
  }
  if (k != -1) {
    for (int i = n - 1; i > k; i--) {
      if (permutation[i] > permutation[k]) {
        swap(permutation[k], permutation[i]);
        break;
      }
    }
  }
  reverse(permutation.begin() + k + 1, permutation.end());

  return permutation;
}