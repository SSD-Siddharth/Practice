/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        Negative Issue
        int min=*min_element(prices.begin(), prices.end());
        int mx=INT_MIN;
        //for (int i=)
        int fin=*find(prices.begin(), prices.end(), min);
        for(int i=fin+1;i<prices.size();i++)
        {
            if (mx<prices[i])
                mx=prices[i];
        }
        */
        
        /*
        Time limit exceeded
        int rs=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                int an=prices[j]-prices[i];
                if (rs<an)
                    rs=an;
            }
        }
        if (rs<0)
            rs=0;
        */
        int mx = 0; 
        int mn = INT_MAX;
       
        for(int i=0;i<prices.size();i++){
            mn =  min( mn, prices[i] );

            mx = max( mx,prices[i] - mn );
        }
        return mx;
    }
};



