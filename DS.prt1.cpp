#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

// Helper function to safely read integer input and prevent invalid input infinite loops
int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "Invalid input! Please enter a valid integer.\n";
        cin.clear(); // Clear the cin error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush input buffer
    }
}

// Function for array traversal (displaying elements)
void traverse(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is currently empty.\n";
        return;
    }
    cout << "Array Elements (" << arr.size() << "): ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Function for element insertion at 1-based position
void insertElement(vector<int>& arr) {
    int pos = getIntInput("Enter position (1 to " + to_string(arr.size() + 1) + "): ");
    if (pos < 1 || pos > static_cast<int>(arr.size()) + 1) {
        cout << "Invalid Position! Must be between 1 and " << arr.size() + 1 << ".\n";
        return;
    }
    int value = getIntInput("Enter value to insert: ");

    arr.insert(arr.begin() + (pos - 1), value);
    cout << "Element " << value << " inserted successfully at position " << pos << ".\n";
}

// Function for element deletion at 1-based position
void deleteElement(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty! Nothing to delete.\n";
        return;
    }
    int pos = getIntInput("Enter position to delete (1 to " + to_string(arr.size()) + "): ");
    if (pos < 1 || pos > static_cast<int>(arr.size())) {
        cout << "Invalid Position! Must be between 1 and " << arr.size() << ".\n";
        return;
    }

    int deletedValue = arr[pos - 1];
    arr.erase(arr.begin() + (pos - 1));
    cout << "Element " << deletedValue << " deleted successfully from position " << pos << ".\n";
}

// Function for element searching
void searchElement(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty! Nothing to search.\n";
        return;
    }
    int value = getIntInput("Enter value to search: ");

    bool found = false;
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == value) {
            cout << "Element " << value << " found at position " << i + 1 << " (index " << i << ").\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element " << value << " not found.\n";
    }
}

int main() {
    int n = getIntInput("Enter initial number of elements: ");
    while (n < 0) {
        cout << "Number of elements cannot be negative.\n";
        n = getIntInput("Enter initial number of elements: ");
    }

    vector<int> arr;
    arr.reserve(n);

    if (n > 0) {
        cout << "Enter " << n << " element(s):\n";
        for (int i = 0; i < n; i++) {
            arr.push_back(getIntInput("Element " + to_string(i + 1) + ": "));
        }
    }

    int choice = 0;
    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Traversal\n";
        cout << "2. Insertion\n";
        cout << "3. Deletion\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        choice = getIntInput("");

        switch (choice) {
            case 1:
                traverse(arr);
                break;
            case 2:
                insertElement(arr);
                break;
            case 3:
                deleteElement(arr);
                break;
            case 4:
                searchElement(arr);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid Choice! Please enter a number between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}