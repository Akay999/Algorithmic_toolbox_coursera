#include<bits/stdc++.h>
using namespace std;

long long MaxPairwiseProduct(const vector<int>& vi){
	long long result = 0;
	int max_1 = -1, max_2 = -1;
	int n = vi.size();
	for(int i = 0; i < n; i++) {
		if(vi[i] > max_1) {
			max_2 = max_1;
			max_1 = vi[i];
		}
		else if(vi[i] > max_2 && vi[i] <= max_1) {
			max_2 = vi[i];
		}
	}
	
	return max_2 * (long long) max_1;
}

int main () {
	
	int n;
	cin >> n;
	vector<int> numbers(n);
	for(int i = 0; i < n; i++) {
		cin >> 	numbers[i];
	}
	
	long long result = MaxPairwiseProduct(numbers);
	cout << result << "\n";
	
	
	return 0;
}