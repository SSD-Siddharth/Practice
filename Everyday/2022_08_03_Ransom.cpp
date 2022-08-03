/*
Ransom Note



Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

*/



class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    /*
        int finl=0;
        int l[5000],tmp=0,chk=0;
        for(int i=0;i<ransomNote.size();i++){
            int t1=0;
            for(int j=0;j<magazine.size();j++){
                chk=0;
                for(int k=0;k<tmp;k++)
                {
                    if(j==l[k])
                        chk=1;
                }
                if(chk!=1){
                    if (ransomNote[i]==magazine[j])
                    {
                        l[tmp++]=j;
                        //cout<<ransomNote[i];
                        t1=1;
                        break;
                    }
                }
                if(t1==1)
                    break;
            }
        }
        if(tmp==ransomNote.size())
        {
            //cout<<"turu";
            return true;
        }
    return false;
        
    */
    // From the above code, time limit exceeds, so we'll use dictionary
        //int cnt[26]={0};
        unordered_map<int,int> mp;
        //Checking all the freq. of magazine...
        for(int i=0;i<magazine.size();i++){
            int x = magazine[i]-'a';
            //cnt[x]++;
            mp[x]++;
        }
        //Now, seeing if, the alphabets are available in ransomNote
        for(int i=0;i<ransomNote.size();i++){
            int x = ransomNote[i]-'a';
            /*
            cnt[x]--;
            if(cnt[x]<0) 
                return false;
            */
            mp[x]--;
            if (mp[x]<0)
                return false;
        }
        return true;
    }
};