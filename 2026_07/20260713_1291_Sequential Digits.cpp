// 13th July 2026

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        for(int start = 1; start <= 9; start++){
            int number = 0;
            for(int digit = start; digit <= 9; digit++){
                number = number * 10 + digit;

                if (number >= low && number <= high) {
                    result.push_back(number);
                }
                if (number > high) {
                    break;
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};