#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node *head = NULL;

void insertBeginning(int value) {
    node* newNode = new node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout<< "Node inserted at the beginning with value:\n " << value << endl;

    
}

void insertEnd(int value) {

    node* newnode = new node();
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL){
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    cout<< "Node inserted at the end with value:\n " << value << endl;

    
}

void insertafter(int value,int aftervalue) {
    node *temp = head;
    while (temp !=NULL && temp->data !=aftervalue) {
        temp = temp->next;
    }
    if (temp != NULL) {

        cout<< "Given node not found:\n ";
        return;
    }
        node *newNode = new node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout<< "Node inserted after sucessfully.\n";
    }
    
    void deletefirst() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete first node." << endl;
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
        cout << "First node deleted successfully." << endl;
    }

    void deletelast() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Last node deleted successfully.\n";
        }
    }
    void deleteafter(int aftervalue) {
        node*temp =head;
        while (temp != NULL && temp->data != aftervalue) {
            temp = temp->next;
        }
        if (temp == NULL )
        {
            cout << "Node not found.\n";
            return;
        }

        if(temp->next == NULL) {
            cout << "No Node Exists after the given node.\n";
            return;
        }

        node* deleteNode = temp->next;
        temp->next = deleteNode->next;  
        delete deleteNode;
        cout << "Node deleted successfully after the given node"<< aftervalue <<endl;
    }
        void display() {
            if (head == NULL) {
                cout << "List is empty." << endl;
                return;
            }
            node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout <<"NULL"<<endl;
        }

        int main() {
            int choice, value, aftervalue;
            do {
                cout << "\nMenu:\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert After a Node\n";
                cout << "4. Delete First Node\n";
                cout << "5. Delete Last Node\n";
                cout << "6. Delete After a Node\n";
                cout << "7. Display List\n";
                cout << "8. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter value to insert at beginning: ";
                        cin >> value;
                        insertBeginning(value);
                        break;
                    case 2:
                        cout << "Enter value to insert at end: ";
                        cin >> value;
                        insertEnd(value);
                        break;
                    case 3:
                        cout << "Enter value to insert: ";
                        cin >> value;
                        cout << "Enter the value after which to insert: ";
                        cin >> aftervalue;
                        insertafter(value, aftervalue);
                        break;
                    case 4:
                        deletefirst();
                        break;
                    case 5:
                        deletelast();
                        break;
                    case 6:
                        cout << "Enter the value after which to delete: ";
                        cin >> aftervalue;
                        deleteafter(aftervalue);
                        break;
                    case 7:
                        display();
                        break;
                    case 8:
                        cout << "Exiting...\n";
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                }
            } while (choice != 8);

            return 0;
        }
