#include <iostream>
using namespace std;

void callbyvalue(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;

    cout << "Inside function: " << x << " " << y << endl;
}

int main()
{
    int a, b;

    cout << "Enter two values: ";
    cin >> a >> b;

    cout << "Before change: " << a << " " << b << endl;

    callbyvalue(a, b);

    cout << "After change: " << a << " " << b << endl;

    return 0;
}