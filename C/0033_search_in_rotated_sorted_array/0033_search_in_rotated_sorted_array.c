int search(int* nums, int numsSize, int target){
    if (numsSize == 0) {
        return -1;
    }
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left + 1 < right) {
        if (nums[left] == target) {
            return left;
        }
        if (nums[right] == target) {
            return right;
        }
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[left] < nums[mid]) {
            if (target < nums[left] || target > nums[mid])
                left = mid;
            else
                right = mid;
        } else if (nums[left] > nums[mid]) {
            if (target < nums[mid] || target > nums[right])
                right = mid;
            else
                left = mid;
        } else {
            left++;
        }
    }
    if (nums[left] == target) 
        return left;
    if (nums[right] == target)
        return right;
    return -1;
}