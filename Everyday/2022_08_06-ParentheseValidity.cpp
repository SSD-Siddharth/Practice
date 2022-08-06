/*
Parentheses Validity
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.


*/




class Solution {
public:
    bool isValid(string s) {

        int n=s.size(),ind=0;
        if(n%2!=0)
            return false; //since it has to be even to be equal
        /*
        int a=0,b=0,c=0;
        //can also use a for
        while(ind<n){
            if(s[ind]=='('){
                if(s[ind+1]!=')')
                    return false;}
            else if(s[ind]==')')
            {
                if(s[ind+1]!='(')
                    return false;
            }
            else if(s[ind]=='[')
            {
                if(s[ind+1]!=']')
                    return false;}
            else if(s[ind]==']'){
                if(s[ind+1]!='[')
                    return false;}
            else if(s[ind]=='{'){
                if(s[ind+1]!='}')
                    return false;}
            else if(s[ind]=='}'){
                if(s[ind+1]!='{')
                    return false;}
            ind++;
            ind++;
        }
        return true;
        
        //The above code also passed, but not for all the cases
        */
        stack<char>stk;
        for(int i = 0;i<s.length();i++)
        {
            //Checking the opening ones
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
            }
            //for the closing cases
            else
            {
                if(stk.empty()) 
                    return false;
                if(s[i] == ')' && stk.top() != '(')
                    return false;
                else if(s[i] == ']' && stk.top() != '[') 
                    return false;
                else if(s[i] == '}' && stk.top() != '{') 
                    return false;
                else{
                   stk.pop();
                 }
             }
        }
        //for the remaining ones
        if(!stk.empty()){
            return false;
        }
        return true;
    }
};