#include<bits/stdc++.h>
using namespace std;

long long MaxPairwiseProduct(vector<int> numbers){
	long long result = 0;
	int n = numbers.size();
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			result = max(result , numbers[i] * (long long) numbers[j]);
		}
	}
	
	return result;
}

long long MaxPairwiseProduct_Fast(const vector<int>& vi){
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
	bool isRight = true;
	srand(time(0));
	while(isRight) {
		int n = (rand() % 20) + 2;
		vector<int> numbers(n);
		
		for(int i = 0; i < n; i++) {
			numbers[i] = ( rand() % 100000 );
		}
		
		long long result_1 = MaxPairwiseProduct(numbers);
		long long result_2 = MaxPairwiseProduct_Fast(numbers);
		
		if(result_1 != result_2) {
			for(int i = 0; i < n; i++) {
				cout << numbers[i] << " ";
			}
			
			cout << "\nWrong answer  Result 1 : " << result_1 << " Result 2 : " << result_2 << "\n";
			isRight = false;
		}
		else {
			cout << "OK" << "\n";
		}
		
	}
	
	
	return 0;
}