#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

int fibonaci_sum_squares_fast(long long n) {
    if(n <= 1) {
        return n;
    }

    int pisano_period = get_pisano_period(10);
    int q = n / pisano_period, r = n % pisano_period;
    long long prev = 0, curr = 1, sum = 1, rem_sum = 1;
    if(r <= 1) {
        rem_sum = r;
    }

    for(long long i = 2; i < pisano_period; i++) {
        long long temp  = (curr + prev) % 10;
        prev = curr;
        curr = temp;
        long long last_sq = (temp * temp) % 10;
        sum = (sum + last_sq) % 10;

        if(i == r) {
            rem_sum = sum;
        }
    }
    
    return ((sum * q) + rem_sum) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonaci_sum_squares_fast(n) << "\n";
}
