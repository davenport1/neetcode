#include <stack>
#include <string>
#include <iostream>

class Solution {
public:
  bool isValid(std::string s) {
      std::stack<char> chars;
      for (int i = 0; i < s.length(); i++) {
          switch (s[i]) {
              case '[': case '{': case '(':
                  chars.push(s[i]);
                  break;
              case ']':
                  if (chars.size() == 0) {
                      return false;
                  }

                  if (chars.top() != '[') {
                      return false;
                  }

                  chars.pop();
                  break;
              case '}':
                  if (chars.size() == 0) {
                      return false;
                  }

                  if (chars.top() != '{') {
                      return false;
                  }

                  chars.pop();
                  break;
              case ')':
                  if (chars.size() == 0) {
                      return false;
                  }

                  if (chars.top() != '(') {
                      return false;
                  }

                  chars.pop();
                  break;
          }
      }

      if (chars.size() != 0) {
          return false;
      }

      return true;
  }
};

int main() {
    Solution solution;

    std::string test1 = "()";
    std::cout << "Test Case 1: " << test1 << " -> " << (solution.isValid(test1) ? "True" : "False") << std::endl;

    std::string test2 = "()[]{}";
    std::cout << "Test Case 2: " << test2 << " -> " << (solution.isValid(test2) ? "True" : "False") << std::endl;

    std::string test3 = "(]";
    std::cout << "Test Case 3: " << test3 << " -> " << (solution.isValid(test3) ? "True" : "False") << std::endl;

    std::string test4 = "([)]";
    std::cout << "Test Case 4: " << test4 << " -> " << (solution.isValid(test4) ? "True" : "False") << std::endl;

    std::string test5 = "{[]}";
    std::cout << "Test Case 5: " << test5 << " -> " << (solution.isValid(test5) ? "True" : "False") << std::endl;

    std::string test6 = "[";
    std::cout << "Test Case 6: " << test6 << " -> " << (solution.isValid(test6) ? "True" : "False") << std::endl;

    return 0;
}