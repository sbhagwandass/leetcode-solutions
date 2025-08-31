/********************************************************************************************************************************
Source: https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"

 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
********************************************************************************************************************************/
class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };

        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;

            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
