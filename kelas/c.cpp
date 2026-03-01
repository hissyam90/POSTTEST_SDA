#include <iostream>
using namespace std;

int main() {
    int boxA = 10;
    int boxB = 20; 
    int boxC = 30;

    int *p1 = &boxA; //pointer p1 menunjuk ke boxA
    int *p2 = &boxB; //pointer p2 menunjuk ke boxB
    int *p3 = &boxC; //pointer p3 menunjuk ke boxC

    *p1 = *p2 + 5;
    p2 = p3;
    *p2 = *p1 + 10;
    p3 = &boxA;
    *p3 = *p2 - 5;


    cout << p1 << endl;
    cout <<  *p1 << endl;
    cout << &p1 << endl;

return 0;
}
