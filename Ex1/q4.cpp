#include <iostream>

using namespace std;

int main() {
    long long a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;

    long long redPrice = a + c * m;
    long long greenPrice = b + d * m;

    if ((redPrice > greenPrice && c > d) ||
        (greenPrice > redPrice && d > c)) {
        cout << "Eyval baba!\n";
    } else {
        cout << "Naaa, eshtebahe!\n";
    }

    return 0;
}
