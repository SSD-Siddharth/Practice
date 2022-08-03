/*
Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

*/




class Solution {
public:
    bool isAnagram(string s, string t) {
    /*
        int tmp=0;
        for(int i=0;i<s.length();i++){
            
            for(int j=0;j<t.length();j++){
                if (s[i]==t[j])
                {
                    t[j]='.';  
                    tmp++;
                    break;
                }
            }
        }
    if(tmp==s.length() && tmp==t.length())
        return true;
     //cout<<tmp;
     return false;   
    }
    
    
    */
        //Time limit Exceeded
        //So, now using more efficient way/

        //Less time complexity
        sort(s.begin(),s.end()); 
        sort(t.begin(),t.end());
        if(s.length()!=t.length())  //Checking length
            return false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }
    
};