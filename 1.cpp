#include <iostream>

double multiply(double number, int n) {
    double ans = 1.0;
    for (int i = 1; i <= n; i++) {
        ans = ans * number;
    }
    return ans;
}

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6;
    while ((high - low) > eps) {
        double mid = (low + high) / 2;
        if (multiply(mid, n) < m) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low; // or return (low + high) / 2;
}

int main() {
    int n = 3;
    int m = 27;
    double result = getNthRoot(n, m);
    std::cout << "The " << n << "th root of " << m << " is " << result << std::endl;
    return 0;
}
