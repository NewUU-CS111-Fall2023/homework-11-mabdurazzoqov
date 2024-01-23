#include <vector>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int num : nums) sum += num;

    if (sum < target || (sum + target) % 2 != 0) return 0;

    int newTarget = (sum + target) / 2;
    vector<int> dp(newTarget + 1, 0);
    dp[0] = 1;

    for (int num : nums) {
        for (int i = newTarget; i >= num; i--) {
            dp[i] += dp[i - num];
        }
    }

    return dp[newTarget];
}