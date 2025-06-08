class Solution {
  public:
       bool check(string s, int start, string num1, string num2) {
        string sum = addStrings(num1, num2);
        int sumLength = sum.length();

        if (start + sumLength > s.length() || s.substr(start, sumLength) != sum)
            return false;

        if (start + sumLength == s.length()) return true;

        return check(s, start + sumLength, num2, sum);
    }

    // Helper function to add two numbers as strings
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isSumString(string &s) {
        int n = s.length();
        
        // Try all pairs of first and second numbers
        for (int i = 1; i < n; i++) {
            for (int j = 1; i + j < n; j++) {
                string num1 = s.substr(0, i);
                string num2 = s.substr(i, j);

                // Skip if leading zeros
                if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) 
                    continue;

                if (check(s, i + j, num1, num2)) return true;
            }
        }
        return false;
    }
};