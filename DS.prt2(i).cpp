
#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array in reverse order: ";
    for (int *ptr = arr + n - 1; ptr >= arr; ptr--) {
        cout << *ptr << " ";
    }

    return 0;
}