#include <iostream>
using namespace std;

#define MAX 5

int stk[MAX];
int tos = -1;

// Check if stack is full
bool full()
{
    return (tos == MAX - 1);
}

// Check if stack is empty
bool empty()
{
    return (tos == -1);
}

// Push operation
void push(int x)
{
    if (!full())
    {
        tos++;
        stk[tos] = x;
        cout << "Element pushed successfully.\n";
    }
    else
    {
        cout << "Stack Overflow!\n";
    }
}

// Pop operation
int pop()
{
    if (!empty())
    {
        return stk[tos--];
    }
    else
    {
        cout << "Stack Underflow!\n";
        return -1;
    }
}

// Peep operation
int peep()
{
    if (!empty())
    {
        return stk[tos];
    }
    else
    {
        cout << "Stack is Empty!\n";
        return -1;
    }
}

int main()
{
    int choice, num, x;
    char ch;

    while (1)
    {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peep\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to push: ";
            cin >> num;
            push(num);
            break;

        case 2:
            x = pop();
            if (x != -1)
                cout << "Popped element: " << x << endl;
            break;

        case 3:
            x = peep();
            if (x != -1)
                cout << "Top element: " << x << endl;
            break;

        default:
            cout << "Invalid choice!\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
            break;
    }

    return 0;
}