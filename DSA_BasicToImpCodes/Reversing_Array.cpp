//Reversing an _Array

#include <iostream>
using namespace std;
/*
Input format, 
No. of test cases, t
	For each test case t, no. of element in the array, n
		Elements of the array
*/
int main() {
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int l[n];
		//Getting the elements
		for (int i=0; i<n; i++){
		    cin>>l[i];
		}
		//We can also use swap, to swap elements till mid, and then print the array.
		for(int i=n-1; i>=0; i--){
		    cout<<l[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
