#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int get_pisano_period(int m) {
    int prev = 0, current = 1;
    int counter = 2;
    for(counter = 2; counter < m * m ; counter++) {
        int temp = (prev + current) % m;
        prev = current;
        current = temp;
        if(prev == 0 && current == 1) {
            break;
        }
    }

    return counter - 1;

}

int fibonacci_sum_fast(long long n) {
    if(n <= 1){
        return n;
    }

    long long pisano_period = get_pisano_period(10);
    int q = n / pisano_period, r = n % pisano_period;
    int prev = 0, curr = 1, sum = 1, rem_sum = 1;
    if(r <= 1) {
        rem_sum = r;
    }
    
    for(long long i = 2; i < pisano_period; i++) {
        long long temp = (prev + curr) % 10;
        prev = curr;
        curr = temp;
        sum = (sum + temp) % 10;
        if(i == r) {
            rem_sum = sum;
        }
    }

    return ((sum * q )+ rem_sum )% 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n) << "\n";
}
