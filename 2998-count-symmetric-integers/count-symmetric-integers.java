

class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int count=0;
        for (int num = low; num <= high; ++num) {
           String str = String.valueOf(num); // ✅ Convert number to string
            int len = str.length();

           
            if (len % 2 != 0) continue;

            int half = len / 2;
            int leftSum = 0, rightSum = 0;

            // ⬅️ Calculate sum of left half
            for (int i = 0; i < half; ++i) {
                leftSum += str.charAt(i) - '0';
            }

            // ➡️ Calculate sum of right half
            for (int i = half; i < len; ++i) {
                rightSum += str.charAt(i) - '0';
            }

            // ☯️ If both halves are equal, count it
            if (leftSum == rightSum) {
                count++;
            }
        }
        return count;

    }
}