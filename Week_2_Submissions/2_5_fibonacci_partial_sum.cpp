#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {

    if(to <= 1){
        return to;
    }

    long long to_sum = fibonacci_sum_fast(to);
    long long from_index = (from == 0) ? 0 : from - 1;
    long long from_sum = fibonacci_sum_fast(from_index);
    to_sum = (to_sum < from_sum) ? 10 + to_sum : to_sum;
    return to_sum - from_sum;

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}