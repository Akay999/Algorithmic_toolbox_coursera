#include<bits/stdc++.h>
using namespace std;

int main () {
	
	srand(time(0));
	int n = (rand() % 1000) + 2;
	cout << n << "\n";
	for(int i = 0; i < n; i++) {
		cout << (rand() % 100000 ) << " ";
	}
	
	return 0;
}