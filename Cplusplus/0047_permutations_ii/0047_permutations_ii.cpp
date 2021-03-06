class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) 
            return res;
        sort(nums.begin(), nums.end());
        permutation(res, nums, 0);
        return res;
    }
    
    void permutation(vector<vector<int>> &res, vector<int> &nums, int pos) {
        if (pos == nums.size()) {
            vector<int> temp;
            for (int n : nums)
                temp.push_back(n);
            res.push_back(temp);
        }
        else {
            unordered_set<int> appear; 
            for (int i = pos; i < nums.size(); i++) {
                if (appear.find(nums[i]) == appear.end()) {
                    appear.insert(nums[i]);
                    swap(nums[i], nums[pos]);
                    permutation(res, nums, pos + 1);
                    swap(nums[i], nums[pos]);
                }
            }
        }
    }
};
