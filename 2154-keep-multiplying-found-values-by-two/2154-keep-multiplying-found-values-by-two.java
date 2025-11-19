class Solution {
   
    public int findFinalValue(int[] nums, int original) { 
        Set<Integer> numSet = new HashSet<>();
       
        for (int num : nums) {
            numSet.add(num);
        }
       
        while (numSet.contains(original)) {
             
            original <<= 1;
        }
       
        return original;
    }
}