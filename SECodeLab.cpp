#include <iostream>
#include <vector>
using namespace std;

struct point {
    double x;
    double y;
};
vector<point> calculate(vector<point> points, int n, double x, double p = 1, double y = 0) {
    if (x < 0) {    //Formula itself.
        for (int i = 2; i <= n; i++) {
            y += ((i - 3 + x) * (i - 3 + x));
        }
    }
    else {
        for (int i = 0; i <= n; i++) {
            p = 1;
            for (int j = 1; j <= n - 1; j++) {
                p *= ((i + j) / (2 * (1 - x) * (1 - x)));
            }
            y += p;
        }
    }
    points.push_back({ x, y });
    return points;
}
void nochars() {    //Function, used in WHILE loops, that prevents the usage of non-values
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please enter a number!\n";
}
double range(double a, double b) {
    while (a > b) {
        cout << "a must be less than b. Input the correct value of b\n";
        cin >> b;
        while (cin.fail()) {
            nochars();
            cin >> b;
        }
    }
    return a, b;
}
double step(double a, double b, double k){
    while (k <= 0) {
        cout << "Input the correct value of k\n";
        cin >> k;
        while (cin.fail()) {
            nochars();
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
                nochars();
                cin >> k;
            }
        }
    }
    return k;
}

int main()
{
    int n, r, z;
    double x, a, b, k, p = 0, y = 0;
    vector<point> points;
    restart:
    cout << "This program calculates the values by the formula.\nChoose mode: [0]- normal, [1] - ranged\n";
    cin >> z;
    while (cin.fail()) {    //This WHILE loop prevents the usage of non-values.
        nochars();
        cin >> z;
        while (z < 0 || z > 1) {    //This WHILE loop prohibits anything that is not 0 or 1.
            cout << "Please enter correct value. Only 0 and 1 are allowed\n";
            cin >> z;
        }
    }
    if (z == 0) {
        cout << "Input n (n > 2)\n";
        cin >> n;
        while (n < 3) {
            cout << "n must be greater than 2. Input the correct value of n\n";
            cin >> n;
            while (cin.fail()) {
                nochars();
                cin >> n;
            }
        }
        cout << "Input x\n";
        cin >> x;
        while (cin.fail()) {
            nochars();
            cin >> x;
        }
        vector<point> result = calculate(points, n, x, p, y);
        for (const auto& point : result) {
            cout << "x = " << point.x << "; y = " << point.y << "\n";
        }
        cout << "Do you want to restart the program? [1] - yes, [0] - no, exit program\n";
        cin >> r;
        while (r < 0 || r > 1) {
            cout << "Please enter correct value. Only 0 and 1 are allowed\n";
            cin >> r;
            while (cin.fail()) {
                nochars();
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
    else {
        cout << "Input n (n > 2)\n";    //If ranged mode selected.
        cin >> n;
        while (n < 3) {
            cout << "n must be greater than 2. Input the correct value of n\n";
            cin >> n;
            while (cin.fail()) {
                nochars();
                cin >> n;
            }
        }
        cout << "Input minimum range value a\n";
        cin >> a;
        while (cin.fail()) {
            nochars();
            cin >> a;
        }
        cout << "Input maximum range value b\n";
        cin >> b;
        while (cin.fail()) {
            nochars();
            cin >> b;
        }
        range(a, b);
        cout << "Input step of the range value k (k > 0)\n";
        cin >> k;
        step(a, b, k);
        for (x = a; x <= b; x += k) {   //Cycle FOR is only executed if ranged mode selected before.
            vector<point> result = calculate(points, n, x, p, y);
            for (const auto& point : result) {
                cout << "x = " << point.x << "; y = " << point.y << "\n";
            }
        }
        cout << "Do you want to restart the program? [1] - yes, [0] - no, exit program\n";
        cin >> r;
        while (r < 0 || r > 1) {
            cout << "Please enter correct value. Only 0 and 1 are allowed\n";
            cin >> r;
            while (cin.fail()) {
                nochars();
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
}