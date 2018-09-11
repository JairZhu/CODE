#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for  (int i = 0; i < T; ++i) {
        int m, n;
        cin >> m >> n;
        while (m != n) {
            if (m < n) {
                n = n / 2;
            }
            else if (m > n) {
                m = m / 2;
            }
        }
        cout << m << endl;
    }
}