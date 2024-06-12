#include <cmath>
#include <iostream>
#include <vector>

void printVec(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << (i == vec.size() - 1 ? "\n" : " ");
  }
}

void printSortNumVecModulo(std::vector<int> vec, int val) {
  int i = val - 1;
  int j = val + 1;

  for (int count = vec.size() - 1; count >= 0; count--) {
    if (count == vec.size() - 1) {
      std::cout << vec[val] << " ";
    } else if (i >= 0 && fabs(vec[i]) < fabs(vec[j])) {
      std::cout << vec[i] << " ";
      i--;
    } else if (j < vec.size() && fabs(vec[i]) > fabs(vec[j])) {
      std::cout << vec[j] << " ";
      j++;
    }
  }
}

int main() {
  std::cout << "Sort number array modulo\n";

  std::vector<int> vec = {-100, -50, -5, 1, 10, 15};

  std::cout << "You array: ";
  printVec(vec);

  int indexBegin = 0;
  int begin = fabs(vec[0]);

  for (int i = 1; i < vec.size(); i++) {
    if (begin > fabs(vec[i])) {
      begin = fabs(vec[i]);
      indexBegin = i;
    }
  }

  printSortNumVecModulo(vec, indexBegin);
}