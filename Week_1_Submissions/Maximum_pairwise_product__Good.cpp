#include<bits/stdc++.h>
using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers){
	long long result = 0;
	int n = numbers.size();
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			result = max(result , numbers[i] * (long long) numbers[j]);
		}
	}
	
	return result;
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