#include <iostream>
#include <vector>

std::vector<int> inputNumVec(std::vector<int> vec) {
  int n;
  do {
    std::cout << "Input size array: ";
    std::cin >> n;
    if (n < 1) {
      std::cerr << "Array size must be greater than 0\n";
    }
  } while (n < 1);

  std::cout << "Input numbers in array: \n";

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    vec.push_back(a);
  }

  return vec;
}

void printVec(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << (i == vec.size() - 1 ? "\n" : " ");
  }
}

int main() {
  std::cout << "Finding a sum in an array:\n";

  std::vector<int> vec;
  vec = inputNumVec(vec);

  std::cout << "You array: ";
  printVec(vec);

  int result;
  std::cout << "Enter the result you are looking for: ";
  std::cin >> result;

  int index_1, index_2;
  bool haveSum = false;

  for (int i = 0; i < vec.size() - 1 && !haveSum; i++) {
    for (int j = i + 1; j < vec.size(); j++) {
      if (vec[i] + vec[j] == result) {
        haveSum = true;
        index_1 = i;
        index_2 = j;
        break;
      }
    }
  }

  if (haveSum) {
    std::cout << "The array have sum " << result << " from " << vec[index_1]
              << " and " << vec[index_2];
  } else {
    std::cout << "There is no such amount in the array";
  }
}