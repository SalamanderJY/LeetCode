class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = right = mid;
                while (left >= 0 && nums[left] == nums[mid])
                    left -= 1;
                while (right <= nums.length - 1 && nums[right] == nums[mid])
                    right += 1;
                int[] found = {left + 1, right - 1};
                return found;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        int[] notFound = {-1, -1};
        return notFound; 
    }
}