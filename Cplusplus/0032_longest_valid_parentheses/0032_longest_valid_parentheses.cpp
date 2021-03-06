class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        if (s.size() < 2)
            return 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            if (s.at(i) == ')') {
                if (s.at(i - 1) == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && s.at(i - dp[i - 1] - 1) == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                max = max > dp[i] ? max : dp[i];
            }
        }
        return max;
    }
};
