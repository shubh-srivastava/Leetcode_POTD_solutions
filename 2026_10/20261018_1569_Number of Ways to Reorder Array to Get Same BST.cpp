// 18th October 2026

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> pascal(n, vector<int>(n, 0));
        pascal[0][0] = 1;

        for (int i = 1; i < n; ++i) {
            pascal[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
            }
        }

        function<int(vector<int>)> countBSTArrangements =
            [&](vector<int> sequence) -> int {
            if (sequence.size() < 2) {
                return 1;
            }

            // Partition elements based on the root (first element)
            vector<int> leftSubtree, rightSubtree;
            int root = sequence[0];

            for (int& value : sequence) {
                if (value < root) {
                    leftSubtree.push_back(value);
                } else if (value > root) {
                    rightSubtree.push_back(value);
                }
            }

            int leftSize = leftSubtree.size();
            int rightSize = rightSubtree.size();

            int leftArrangements = countBSTArrangements(leftSubtree);
            int rightArrangements = countBSTArrangements(rightSubtree);

            return (1LL * pascal[leftSize + rightSize][leftSize] *
                    leftArrangements % MOD) *
                   rightArrangements % MOD;
        };

        return (countBSTArrangements(nums) - 1 + MOD) % MOD;
    }
};
