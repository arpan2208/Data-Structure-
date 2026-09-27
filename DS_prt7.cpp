#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head = nullptr;

void insertBeginning(int value)
{
    node* newNode = new node;

    newNode->data = value;

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    node* ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    newNode->next = head;
    ptr->next = newNode;
    head = newNode;
}

void insertEnd(int value)
{
    node* newNode = new node;

    newNode->data = value;

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    node* ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    newNode->next = head;
    ptr->next = newNode;
}

void insertAfter(int givenValue, int value)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    node* ptr = head;

    do
    {
        if (ptr->data == givenValue)
        {
            node* newNode = new node;

            newNode->data = value;
            newNode->next = ptr->next;
            ptr->next = newNode;

            return;
        }

        ptr = ptr->next;

    } while (ptr != head);

    cout << "Given node not found" << endl;
}

void deleteFirst()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    node* ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    node* temp = head;

    head = head->next;
    ptr->next = head;

    delete temp;
}

void deleteLast()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    node* ptr = head;
node
    while (ptr->next->next != head)
    {
        ptr = ptr->next;
    }

    node* temp = ptr->next;

    ptr->next = head;

    delete temp;
}

void deleteAfter(int givenValue)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    node* ptr = head;

    do
    {
        if (ptr->data == givenValue)
        {
            if (ptr->next == ptr)
            {
                cout << "No node exists after it" << endl;
                return;
            }

            node* temp = ptr->next;


            if (temp == head)
            {
                head = head->next;
            }

            ptr->next = temp->next;

            if (temp == head)
            {
                node* last = head;

                while (last->next != temp)
                {
                    last = last->next;
                }

                last->next = head;
            }

            delete temp;
            return;
        }

        ptr = ptr->next;

    } while (ptr != head);

    cout << "Given node not found" << endl;
}

void display()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    node* ptr = head;

    cout << "Circular Linked List: ";

    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;

    } while (ptr != head);

    cout << endl;
}

int main()
{
    int choice;
    int value, givenValue;

    do
    {
        cout << "\n1. Insert at beginning";
        cout << "\n2. Insert at end";
        cout << "\n3. Insert after a given node";
        cout << "\n4. Delete first node";
        cout << "\n5. Delete last node";
        cout << "\n6. Delete node after a given node";
        cout << "\n7. Display";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;

                insertEnd(value);
                break;

            case 3:
                cout << "Enter given node value: ";
                cin >> givenValue;

                cout << "Enter new value: ";
                cin >> value;

                insertAfter(givenValue, value);
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                cout << "Enter given node value: ";
                cin >> givenValue;

                deleteAfter(givenValue);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}