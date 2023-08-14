#include <iostream>
using namespace std;

typedef struct dubly
{
    int data;
    struct dubly *next;
    struct dubly *prev;
} node;

node *head = NULL; // Initialize head to NULL for an empty list

// Function to insert a node at the beginning of the circular linked list
void insert_at_begining(int val)
{
    node *new_node = (node *)malloc(sizeof(node));

    if (new_node == NULL)
    {
        cerr << "Error" << endl;
        return;
    }

    new_node->data = val;
    if (head == NULL)
    {
        new_node->next = new_node; // Point to itself for a single node
        new_node->prev = new_node; // Point to itself for a single node
    }
    else
    {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }

    head = new_node; // Update the head to point to the new_node
}

// Function to insert a node at the end of the circular linked list
void insert_at_end(int val)
{
    node *new_node = (node *)malloc(sizeof(node));

    if (head == NULL)
    {
        insert_at_begining(val);
        return;
    }

    new_node->data = val;
    new_node->next = head;
    new_node->prev = head->prev;
    head->prev->next = new_node;
    head->prev = new_node;
}

// Function to insert a node at a random position in the circular linked list
void insert_at_random(int val, int pos)
{
    if (pos <= 1)
    {
        insert_at_begining(val);
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;

    node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head) // If the position exceeds the number of nodes, return an error
        {
            cerr << "Error: Exceeded the number of data" << endl;
            return;
        }
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}

// Function to delete the node at the beginning of the circular linked list
void delete_at_beginning()
{
    if (head == NULL)
    {
        cerr << "Error: Empty list" << endl;
        return;
    }

    if (head->next == head) // Only one node in the list
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *del = head;
        head = head->next;
        head->prev = del->prev;
        del->prev->next = head;
        free(del);
    }
}

// Function to delete the node at the end of the circular linked list
void delete_at_end()
{
    if (head == NULL)
    {
        cerr << "Error: Empty list" << endl;
        return;
    }

    if (head->next == head) // Only one node in the list
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *del = head->prev;
        head->prev = del->prev;
        del->prev->next = head;
        free(del);
    }
}

// Function to delete a node at a random position in the circular linked list
void delete_at_random(int pos)
{
    if (head == NULL)
    {
        cerr << "Error: Empty list" << endl;
        return;
    }

    if (pos <= 1)
    {
        delete_at_beginning();
        return;
    }

    node *del = head;
    for (int i = 1; i < pos; i++)
    {
        del = del->next;
        if (del == head) // If the position exceeds the number of nodes, return an error
        {
            cerr << "Error: Exceeded the number of data" << endl;
            return;
        }
    }

    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
}

// Function to display the circular linked list
void display()
{
    if (head == NULL)
    {
        cerr << "Nothing to show" << endl;
        return;
    }

    node *temp = head;
    do
    {
        cout << temp->data << "\t";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    int choice, val, pos;
    do
    {
        cout << "\n";
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Display the linked list" << endl;
        cout << "4: Insert at random" << endl;
        cout << "5: Delete at beginning" << endl;
        cout << "6: Delete at end" << endl;
        cout << "7: Delete at random" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the data to insert at the beginning: ";
            cin >> val;
            insert_at_begining(val);
            break;
        case 2:
            cout << "Enter the data to insert at the end: ";
            cin >> val;
            insert_at_end(val);
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Insert the position: ";
            cin >> pos;
            cout << "Enter the value: ";
            cin >> val;
            insert_at_random(val, pos);
            break;
        case 5:
            delete_at_beginning();
            break;
        case 6:
            delete_at_end();
            break;
        case 7:
            cout << "Insert the position: ";
            cin >> pos;
            delete_at_random(pos);
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
