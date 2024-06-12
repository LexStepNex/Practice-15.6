#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> inputNumVec(std::vector<int> vec, int n) {
  if (vec.size() < 5) {
    vec.push_back(n);
  } else {
    if (vec[4] > n) {
      vec[4] = n;
    }
  }

  if (vec.size() == 5) sort(vec.begin(), vec.end());

  return vec;
}

int main() {
  std::cout << "Printing the fifth element of an array\n";

  std::vector<int> vec;

  int n = 0;
  
  std::cout << "To display the fifth element enter -1\n";
  std::cout << "To exit program enter -2\n";
  
  while (n != -2) {
    if (n == -1 && vec.size() == 5) {
      std::cout << "Five element in array: " << vec[4] << "\n";
    } else if (n == -1) {
      std::cerr << "There is no fifth element in the array\n";
    }
     
    std::cout << "Input number: ";
    std::cin >> n;
    if (n == -1 || n == -2) continue;

    vec = inputNumVec(vec, n);
  }
}