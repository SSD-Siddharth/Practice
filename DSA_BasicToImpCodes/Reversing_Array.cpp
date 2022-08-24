//Reversing an _Array

#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int l[n];
    	for (int i=0; i<n; i++){
    	    cin>>l[i];
    	}
    	for(int i=n-1; i>=0; i--){
    	    cout<<l[i]<<" ";
    	}
    	cout<<endl;
	}
	return 0;
}
