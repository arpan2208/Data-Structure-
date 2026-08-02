#include <iostream>
using namespace std;

void callbyreference(int &x, int &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a, b;

    cout << "Enter two values: ";
    cin >> a >> b;

    cout << "Before change: " << a << " " << b << endl;

    callbyreference(a, b);

    cout << "After change: " << a << " " << b << endl;

    return 0;
}