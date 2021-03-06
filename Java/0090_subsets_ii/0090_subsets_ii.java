class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        ArrayList solution = new ArrayList<ArrayList<Integer>>();
        if (nums.length == 0) {
            solution.add(list);
            return solution;
        }     
        Arrays.sort(nums);     
        backtracking(solution, list, nums, 0);        
        return solution;
    }
    
    public static void backtracking(ArrayList<ArrayList<Integer>> solution, 
                                    ArrayList<Integer> list, int[] nums, int pos) {
        solution.add(new ArrayList<Integer>(list));     
        for (int i = pos; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && i != pos)
                continue;
            list.add(nums[i]);
            backtracking(solution, list, nums, i + 1);
            list.remove(list.size() - 1);
        }
    }
}