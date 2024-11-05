#include <string>
#include <iostream>
#include <vector>


// Definition for a Pair
class Pair {
public:
    int key;
    std::string value;

    Pair(int key, std::string value) : key(key), value(value) {}
};

class Solution {
public:
    std::vector<std::vector<Pair>> insertion_sort(std::vector<Pair>& pairs) {
        std::vector<std::vector<Pair>> result;
        if (pairs.size() == 0) {
            return result;
        }

        result.push_back(pairs);

        for (int i = 1; i < pairs.size(); i++) {
            std::vector<Pair> previous_state = result.back();
            std::vector<Pair> temp_state = previous_state;
            Pair current = pairs[i];
            bool inserted = false;

            for (int j = 0; j <= i; j++) {
                if (current.key < temp_state[j].key && !inserted) {
                    temp_state.erase(temp_state.begin() + i);
                    temp_state.insert(temp_state.begin() + j, current);
                    break;
                }
            }

            result.push_back(temp_state);
        }

        return result;
    }
};

void print_pairs(const std::vector<Pair>& pairs) {
    for (const auto& pair : pairs) {
        std::cout << "{" << pair.key << ", " << pair.value << "} ";
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    std::vector<Pair> test_pairs_1 = { Pair(3, "three"), Pair(1, "one"), Pair(2, "two") };
    std::vector<std::vector<Pair>> result1 = solution.insertion_sort(test_pairs_1);

    std::cout << "Test Case 1:" << std::endl;
    for (auto& step : result1) {
        print_pairs(step);
    }

    std::vector<Pair> test_pairs_2 = { Pair(5, "five"), Pair(3, "three"), Pair(4, "four"), Pair(1, "one"), Pair(2, "two") };
    std::vector<std::vector<Pair>> result2 = solution.insertion_sort(test_pairs_2);

    std::cout << "Test Case 2:" << std::endl;
    for (auto& step : result2) {
        print_pairs(step);
    }

    std::vector<Pair> test_pairs_3 = { Pair(1, "one") };
    std::vector<std::vector<Pair>> result3 = solution.insertion_sort(test_pairs_3);

    std::cout << "Test Case 3:" << std::endl;
    for (auto& step : result3) {
        print_pairs(step);
    }

    std::vector<Pair> test_pairs_4;
    std::vector<std::vector<Pair>> result4 = solution.insertion_sort(test_pairs_4);

    std::cout << "Test Case 4:" << std::endl;
    for (auto& step : result4) {
        print_pairs(step);
    }

    return 0;
}