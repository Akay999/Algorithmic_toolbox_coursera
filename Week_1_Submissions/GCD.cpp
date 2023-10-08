#include<bits/stdc++.h>
using namespace std;

long long CalculateGCD(long long number1, long long number2) {
	if(number2 == 0) {
		return number1;
	}
	
	return CalculateGCD(number2, number1 % number2);
}

int main () {
	
	long long number1;
	long long number2;
	
	cin >> number1;
	cin >> number2;
	
	long long result = CalculateGCD(number1, number2);
	
	cout << "GCD of " << number1 << " and " << number2 << " is : " << result << endl;
	
	
	return 0;
}