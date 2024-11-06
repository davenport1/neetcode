#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
  bool isPalindrome(std::string s) {
      std::vector<char> chars;
      for(int i = 0; i < s.length(); i++) {
          if (s[i] != ' ' && !ispunct(s[i])) {
              chars.push_back(s[i]);
          }
      }

      int j = chars.size() - 1;
      for(int i = 0; i < (chars.size()/2); i++) {
          if(tolower(chars[i]) != tolower(chars[j])) {
              return false;
          }

          j--;
      }

      return true;
  }
};

int main() {
    Solution solution;

    std::string test1 = "A man, a plan, a canal, Panama!";
    std::cout << "Test Case 1: " << test1 << " -> " << (solution.isPalindrome(test1) ? "True" : "False") << std::endl;

    std::string test2 = "race a car";
    std::cout << "Test Case 2: " << test2 << " -> " << (solution.isPalindrome(test2) ? "True" : "False") << std::endl;

    std::string test3 = "No 'x' in Nixon";
    std::cout << "Test Case 3: " << test3 << " -> " << (solution.isPalindrome(test3) ? "True" : "False") << std::endl;

    std::string test4 = "Was it a car or a cat I saw?";
    std::cout << "Test Case 4: " << test4 << " -> " << (solution.isPalindrome(test4) ? "True" : "False") << std::endl;

    std::string test5 = " ";
    std::cout << "Test Case 5: " << test5 << " -> " << (solution.isPalindrome(test5) ? "True" : "False") << std::endl;

    return 0;
}