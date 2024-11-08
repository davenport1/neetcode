#include <vector>
#include <string>
#include <iostream>

class Solution {
  public:
      int maxProfit(std::vector<int>& prices) {
          int largest_profit = 0;

          for (int i = 0; i < prices.size(); ++i) {
              for (int j = i + 1; j < prices.size(); ++j) {
                  if (prices[j] - prices[i] > largest_profit) {
                      largest_profit = prices[j] - prices[i];
                  }
              }
          }

          return largest_profit;
      }
};

int main() {
  Solution solution;

  // Test case 1
  std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
  std::cout << "Test Case 1: " << solution.maxProfit(prices1) << std::endl; // Expected output: 5

  // Test case 2
  std::vector<int> prices2 = {7, 6, 4, 3, 1};
  std::cout << "Test Case 2: " << solution.maxProfit(prices2) << std::endl; // Expected output: 0

  // Test case 3
  std::vector<int> prices3 = {1, 2, 3, 4, 5};
  std::cout << "Test Case 3: " << solution.maxProfit(prices3) << std::endl; // Expected output: 4

  // Test case 4
  std::vector<int> prices4 = {3, 2, 6, 5, 0, 3};
  std::cout << "Test Case 4: " << solution.maxProfit(prices4) << std::endl; // Expected output: 4

  return 0;
}