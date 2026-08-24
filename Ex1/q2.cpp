#include <iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        sum += i;
        if (i == n) {
            cout << i << " = " << sum << endl;
        }
        else {
            cout << i << " + ";
        }
    }
    return 0;
}
