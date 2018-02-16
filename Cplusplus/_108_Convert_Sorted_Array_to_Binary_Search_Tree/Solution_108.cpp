/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() <= 0)
			return NULL;
		else {
			TreeNode* root = new TreeNode(nums[nums.size() / 2]);
			vector<int> left_nums(nums.begin(), nums.begin() + nums.size() / 2);
			vector<int> right_nums(nums.begin() + nums.size() / 2 + 1, nums.end());
			root->left = sortedArrayToBST(left_nums);
			root->right = sortedArrayToBST(right_nums);
			return root;
		}
    }
};