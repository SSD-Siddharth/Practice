#include <iostream>
#include <vector>
using namespace std;

void print_SwPos(string a, string b) {
	int lena = a.size();
	int lenb = b.size();
	
	if (lena != lenb) {
		cout << "Not possible";
	}
	int pos[lena][2];
	int k=0;
	int swapped[lena];  
	for (int i = 0; i < lena; i++) {
		swapped[i] = -1;
	}

	for (int i = 0; i < lena; i++) {
		if (a[i] == b[i])
		    continue;
		int j;
		for (j = i + 1; j < lena; j++) {
			if (swapped[j]==1)
			    continue;
			if (a[i] == b[j] && b[i] == a[j]) {
				pos[k][0]=i;	
				pos[k][1]=j;
				k++;
				swapped[i] = 1;
				swapped[j] = 1;
				swap(a[i], a[j]);
				break;
			}
		}
		if (j == lena) {
			cout<<"Not possible";
			return;
		}
	}
	int i=0;
	while(i<k){
	    	cout<<pos[i][0]+1<<" "<<pos[i][1]+1<<"\n";
	    	i++;
	}

}

int main() {
	string S1,S2;
	cin>>S1; 
	cin>>S2;

	print_SwPos(S1, S2);
	return 0;
}


//abcd cdba
//Np


//abcd cdab
