Sort an array of 0s, 1s and 2s
//Sorting only 0, 1, 2 
//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        /*
        //We can also use selection sort, till 'k' no. of times and solve it.
        for (int i = 0; i < k; i++)
        {
            int min_idx = i;
            for (int j = i+1; j < r+1; j++)
            {
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            }
            // Swapping the found minimum element with the first element
            if(min_idx!=i)
            {
                int temp=arr[min_idx];
                arr[min_idx]=arr[i];
                arr[i]=temp;
            }
        }
        //for (int i=0;i<r;i++)
          //  cout<<arr[i]<<", ";
        //return arr[k-1];
        */
        
        //The above is not much optimized, so directly applyting the STL
        sort(arr, arr + r+1);
        return arr[k-1];
        
        
        

    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
