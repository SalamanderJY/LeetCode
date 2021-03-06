class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> list;
        if (nums.size() == 0) {
            res.push_back(list);
            return res;
        }
        sort(nums.begin(), nums.end());
        backtracking(res, list, nums, 0);
        return res; 
    }
    
    void backtracking(vector<vector<int>> &res, vector<int> list, vector<int> &nums, int pos) {
        res.push_back(list);    
        for (int i = pos; i < nums.size(); i++) {
            /* ignore traversed situation though i != pos and nums duplication. */
            if (i > 0 && nums[i] == nums[i - 1] && i != pos) 
                continue;
            list.push_back(nums[i]);
            backtracking(res, list, nums, i + 1);
            list.pop_back();
        }
    }
};
