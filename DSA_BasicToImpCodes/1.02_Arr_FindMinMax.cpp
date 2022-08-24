
#include <bits/stdc++.h>
using namespace std;
#define ll long long
pair<long long, long long> getMinMax(long long a[], int n) ;
/*
Input format, 
No. of test cases, t
	For each test case t, no. of element in the array, n
		Elements of the array
*/
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> minmax_ssd;   //can direcly use 'll'
    long long int minm=INT_MAX;
    long long int maxm=INT_MIN;  //can also use 1e12, i.e., a million million
    for(int i=0; i<n;i++){
        if (minm>a[i])
            minm=a[i];
        if (maxm<a[i])
            maxm=a[i];
    }
    minmax_ssd.first=minm;
    minmax_ssd.second=maxm;
    return minmax_ssd;
}
