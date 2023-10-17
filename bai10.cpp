#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

        int delta = b*b - 4*a*c;

        if (delta > 0) {
            double x1 = (-b - sqrt(delta)) / (2*a);
            double x2 = (-b + sqrt(delta)) / (2*a);
            cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
        } else if (delta == 0) {
            double x0 = -b / (2*a);
            cout << fixed << setprecision(2) << x0 << endl;
        } else {
            cout << "NO SOLUTION" << endl;
        }

    return 0;
}
