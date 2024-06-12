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
  std::cout << "Find maximal sum numbers in array in array: \n";

  std::vector<int> vec;

  vec = inputNumVec(vec);

  printVec(vec);

  if (vec.size() == 1) {
    int maxSum = vec[0], index = 0;
    std::cout << "Maximal sum = " << maxSum << " in index 0";

    return 0;
  }

  int maxSum = vec[0] + vec[1];
  int index_1, index_2;

  for (int i = 0; i < vec.size() - 1; i++) {
    for (int j = i + 1; j < vec.size(); j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {  // calculate amount between i and j
        sum += vec[k];
      }
      if (sum > maxSum) {
        maxSum = sum;
        index_1 = i;  
        index_2 = j;
      }
    }
  }

  std::cout << "Maximal sum = " << maxSum << " in indexes from " << index_1
            << " to " << index_2;
}