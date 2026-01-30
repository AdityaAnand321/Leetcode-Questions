class Solution {
    public long numberOfWays(String s) {

        int totalZero = 0, totalOne = 0;
  for (char ch : s.toCharArray()) {
            if (ch == '0') totalZero++;
            else totalOne++;
        }

        long leftZero = 0, leftOne = 0;
        long ans = 0;
  for (char ch : s.toCharArray()) {

            if (ch == '0') {
                totalZero--;    
                ans += leftOne * totalOne;

                leftZero++;     
            } else {
                totalOne--;    
                ans += leftZero * totalZero;

                leftOne++;     
            }
        }

        return ans;
    }
}
