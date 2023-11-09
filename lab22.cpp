#include <iostream>

int main()
{
    using namespace std;
    int n, r, z;
    double x, a, b, k, p = 1, y = 0, s = 0;
    restart:
    cout << "This program calculates the values by the formula.\nChoose mode: [1] - ranged, [0]- normal\n";
    cin >> z;
    while (z < 0 || z > 1) {    //This WHILE loop prohibits anything that is not 0 or 1.
        cout << "Please enter correct value. Only 0 and 1 are allowed\n";
        cin >> z;
        while (cin.fail()) {    //This WHILE loop prevents the usage of non-values.
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a number!\n";
            cin >> z;
        }
    }
    if (z == 0) {   // This IF statement makes normal mode possible.
        cout << "Input n (n > 2)\n";
        cin >> n;
        while (n < 3) {
            cout << "n must be greater than 2. Input the correct value of n\n";
            cin >> n;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a number! \n";
                cin >> n;
            }
        }
        cout << "Input x\n";
        cin >> x;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a number! \n";
            cin >> x;
        }
        k = 1;
        b = x;
        goto normal;
    }
    cout << "Input n (n > 2)\n";    //If ranged mode selected.
    cin >> n;
    while (n < 3) {
        cout << "n must be greater than 2. Input the correct value of n\n";
        cin >> n;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a number! \n";
            cin >> n;
        }
    }
    cout << "Input minimum range value a\n";
    cin >> a;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a number! \n";
        cin >> a;
    }
    cout << "Input maximum range value b\n";
    cin >> b;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a number! \n";
        cin >> b;
    }
    while (a > b) {
        cout << "a must be less than b. Input the correct value of b\n";
        cin >> b;
    }
    cout << "Input step of the range value k (k > 0)\n";
    cin >> k;
    while (k <= 0) {
        cout << "Input the correct value of k\n";
        cin >> k;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a number! \n";
            cin >> k;
        }
    }
    if (k >= b - a) {   //" >= " allows getting one value anyway, even when ranged mode selected.
        cout << "Warning! K is more or equal to the  range.\nInput a new value of k to calculate the range values\n";
        cin >> k;   //And at the same time, notifies the user, that only one value to be calculated, if the same k is provided.
        while (k <= 0) {
            cout << "Input the correct value of k\n";
            cin >> k;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a number! \n";
                cin >> k;
            }
        }
    }
    for (x = a; x <= b; x += k) {   //Cycle FOR is only executed if ranged mode selected before.
        normal:
        if (x < 0) {    //Formula itself.
            for (int i = 2; i <= n; i++) {
                y += ((i - 3 + x) * (i - 3 + x));
            }
            cout << "x = " << x << "; y = " << y << "\n";
        }
        else {
            for (int i = 0; i <= n; i++) {
                p = 1;
                for (int j = 1; j <= n - 1; j++) {
                    p *= ((i + j) / (2 * (1 - x) * (1 - x)));
                }
                s += p;
            }
            cout << "x = " << x << "; y = " << s << "\n";
        }
    }
    cout << "Do you want to restart the program? [1] - yes, [0] - no, exit program\n";
    cin >> r;
    while (r < 0 || r > 1) {
        cout << "Please enter correct value. Only 0 and 1 are allowed\n";
        cin >> r;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a number!\n";
            cin >> r;
        }
    }
    if (r == 1) {
        goto restart; //Starts the program from the very beginning.
    }
    else {
        return 0;
    }
}