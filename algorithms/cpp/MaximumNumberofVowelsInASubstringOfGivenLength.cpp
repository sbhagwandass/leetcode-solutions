/************************************************************************************************************************
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
************************************************************************************************************************/

bool isVowel(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int max = 0;
        int count=0;

        for(int x=0;x<k;x++)
        {
            if(isVowel(s[x]))
                count++;
        }

        max = count;

        for(int x = k;x<s.size();x++)
        {
            if(isVowel(s[x]))
                count++;
            if(isVowel(s[x-k]))
                count--;
            if(count>max)
                max = count;
        }
        return max;
    }
};
