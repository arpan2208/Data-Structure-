#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice, value, pos;

    cout << "Enter the number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Traversal\n";
        cout << "2. Insertion\n";
        cout << "3. Deletion\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            // Traversal
            case 1:
                cout << "Array Elements: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            // Insertion
            case 2:
                cout << "Enter position (1 to " << n + 1 << "): ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> value;

                if (pos < 1 || pos > n + 1) {
                    cout << "Invalid Position!\n";
                } else {
                    for (int i = n; i >= pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos - 1] = value;
                    n++;
                    cout << "Element inserted successfully.\n";
                }
                break;

            // Deletion
            case 3:
                cout << "Enter position to delete (1 to " << n << "): ";
                cin >> pos;

                if (pos < 1 || pos > n) {
                    cout << "Invalid Position!\n";
                } else {
                    for (int i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    cout << "Element deleted successfully.\n";
                }
                break;

            // Search
            case 4:
                cout << "Enter value to search: ";
                cin >> value;

                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        cout << "Element found at position " << i + 1 << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Element not found.\n";
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}