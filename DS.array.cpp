#include <iostream>
using namespace std;

int maxElement(int p[], int n)
{
    static int maximum = 0;

    if (n == -1)
        return maximum;

    if (p[n] > maximum)
        maximum = p[n];

    return maxElement(p, n - 1);
}

int main()
{
    int x[10];

    cout << "Enter 10 elements: ";
    for (int i = 0; i < 10; i++)
        cin >> x[i];

    int r = maxElement(x, 9);

    cout << "Maximum element = " << r << endl;

    return 0;
}