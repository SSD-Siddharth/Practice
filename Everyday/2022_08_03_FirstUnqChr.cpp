/*

First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1


*/




class Solution {
public:
    int firstUniqChar(string s) {
        
        int n=s.length();
        /*
        for (int i=0;i<n-1;i++){
            int temp=0;
            for(int j=i+1;j<n;j++){
                if (s[i]==s[j])
                {
                    temp=1;
                    break;
                }
            }
            if (temp!=1)
                return i;
        }
        */
        //Using Map
        unordered_map<int,int> mp;
        //int val = s[i]-'a';
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;   //Adding the frequencies
        }
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]] == 1) 
                return i;
        }
        return -1;
    }
};