#include <iostream>
using namespace std;
int
main() {
    double n = 463.01;
    double b;
    b = n - 463;
    b = b * 100;
    cout << (b < 1) << endl;
    printf("%.30f\n", b);
    printf("%.20f\n", b);
    printf("%.10f\n", b);
    return 0;
}