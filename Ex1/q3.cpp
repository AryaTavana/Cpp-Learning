#include <iostream>

using namespace std;

int main() {
    long long a, x;
    int n;
    cin >> a >> x >> n;

    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= a + x;
    }

    cout << result << endl;
    return 0;
}
