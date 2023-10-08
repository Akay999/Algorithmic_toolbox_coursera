#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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

int get_fibonacci_huge_fast(long long n, long long m) {
    if(n <= 1) {
        return n;
    }

    int pisano_period = get_pisano_period(m);

    int rem = n % pisano_period;
    if (rem <= 1) {
        return rem;
    }

    int prev = 0, current = 1;

    for(int i = 2; i <= rem; i++) {
        int temp = (prev + current) % m;
        prev = current;
        current = temp;
    }

    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n,m) << '\n';
}
