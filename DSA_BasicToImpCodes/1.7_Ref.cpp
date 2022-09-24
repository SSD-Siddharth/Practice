#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>      //for, int_min, and max...
struct details
{
    int low;
    int high;
    int sum;
};
details find_max_crossing_subarray(vector<int> a, int low, int mid, int high)
{
    int left_sum, right_sum, sum, i, max_left, max_right;
    details d;
    right_sum = INT_MIN;
    sum=0;
    //Left to right -> in one part
    for(i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        if (sum>right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    sum = 0;
    left_sum = INT_MIN;
    //from mid to low
    //Right to left -> in one part of the
    for(i=mid;i>=low;i--)
    {
        /*
        //When a negative value is reached
        if(a[i]<0){
            sum = 0;
            left_sum = sum;
            max_left = i;
            
        }
        */
        sum += a[i];
        if (sum>left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    d.low = max_left;
    d.high = max_right;
    d.sum = left_sum + right_sum;
    return d;
}
details find_maximum_subarray(vector<int> a,int low,int high)  //;low is the starting index, and high is the ending index
{
    //Taking three conditions, i.e., when the Max sub array is either in Left, or Right or combined sub arrays
    details left_details,right_details,cross_details,d;
    int mid;
    if(low==high)
    {
        d.low = low;
        d.high = high;
        d.sum = a[low];
        return d;
    }
    mid = (low+high)/2;
    left_details = find_maximum_subarray(a,low,mid);  //Left to right 
    right_details = find_maximum_subarray(a,mid+1,high);
    cross_details = find_max_crossing_subarray(a,low,mid,high);
    if((left_details.sum>=right_details.sum)&&(left_details.sum>=cross_details.sum))
    {
        //Along with the Maximum values, Checking the max sub-array's length
            return left_details;
    }
    else if((right_details.sum>=left_details.sum)&&(right_details.sum>=cross_details.sum)){
               //if((sb_len>(left_details.high-right_details.low)) &&(sb_len>(cross_details.high-cross_details.low)))
            return right_details;
    }
    //When the Max. subarray is not in either of the distributed subarrays
    else
        return cross_details;
}
int main()
{
    vector<int> A;
    int low,high,n,i,ele;
    details ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        A.push_back(ele);
    }
    ans = find_maximum_subarray(A,0,n-1);
    //cout<<"Low: "<<ans.low<<" , High: "<<ans.high<<" , Sum: "<<ans.sum<<endl;
    cout<<(ans.low+1)<<endl<<(ans.high+1)<<endl<<ans.sum;
}

