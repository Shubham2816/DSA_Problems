class Solution {
public:
    bool isValid(string s) {
          int n = s.length();
        if (n < 3) return false;
        // Check length: If the string is shorter than 3, it can’t be valid.

         int vowels = 0, consonants = 0;
        string vowelList = "aeiouAEIOU";

for (char c : s) {
            if (isalpha(c)) {
                if (vowelList.find(c) != string::npos) {
                    vowels++;
                } else {
                    consonants++;
                }
            } else if (!isdigit(c)) {
                return false; // invalid character
            }
        }
// Loop through characters:

// If it’s a letter:
// Check if it’s a vowel → increase vowel count.
// Else → increase consonant count.
// If it’s not a letter or digit → return false immediately.



        return vowels >= 1 && consonants >= 1;
        // Final check: Return true only if:

// There is at least one vowel.
// There is at least one consonant.
    }
};