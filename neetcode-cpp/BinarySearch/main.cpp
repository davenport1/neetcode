#include <vector>
#include <string>
#include <iostream>

class Solution {
  public:
  int search(std::vector<int>& nums, int target) {
      return binarySearch(nums, target, 0, nums.size() - 1);
  }

  private:
  int binarySearch(std::vector<int>& nums, int target, int left, int right) {
      if (left > right) {
          return -1;
      }

      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
          return mid;
      }

      if (nums[mid] > target) {
          return binarySearch(nums, target, left, mid -1);
      }
      else {
          return binarySearch(nums, target, mid + 1, right);
      }
  }
};

int main() {
    Solution solution;

    // Test case 1: Target found in the middle
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    std::cout << "Index of target " << target1 << " is: " << solution.search(nums1, target1) << std::endl; // Expected output: 2

    // Test case 2: Target not found
    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    int target2 = 6;
    std::cout << "Index of target " << target2 << " is: " << solution.search(nums2, target2) << std::endl; // Expected output: -1

    // Test case 3: Target is the first element
    std::vector<int> nums3 = {1, 2, 3, 4, 5};
    int target3 = 1;
    std::cout << "Index of target " << target3 << " is: " << solution.search(nums3, target3) << std::endl; // Expected output: 0

    // Test case 4: Target is the last element
    std::vector<int> nums4 = {1, 2, 3, 4, 5};
    int target4 = 5;
    std::cout << "Index of target " << target4 << " is: " << solution.search(nums4, target4) << std::endl; // Expected output: 4

    // Test case 5: Empty vector
    std::vector<int> nums5 = {};
    int target5 = 1;
    std::cout << "Index of target " << target5 << " is: " << solution.search(nums5, target5) << std::endl; // Expected output: -1

    // Test case 6: One element vector, target found
    std::vector<int> nums6 = {2};
    int target6 = 2;
    std::cout << "Index of target " << target6 << " is: " << solution.search(nums6, target6) << std::endl; // Expected output: 0

    // Test case 7: One element vector, target not found
    std::vector<int> nums7 = {2};
    int target7 = 1;
    std::cout << "Index of target " << target7 << " is: " << solution.search(nums7, target7) << std::endl; // Expected output: -1

    return 0;
}