#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL; // Initialize the top of the stack to NULL for an empty stack

// Function to push an element onto the stack
void push(int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        cerr << "Error: Memory allocation failed" << endl;
        return;
    }

    new_node->data = val;
    new_node->next = top;
    top = new_node;
}

// Function to pop an element from the stack
void pop()
{
    if (top == NULL)
    {
        cerr << "Error: Stack is empty" << endl;
        return;
    }

    Node *temp = top;
    top = top->next;
    free(temp);
}

// Function to get the top element of the stack
int peek()
{
    if (top == NULL)
    {
        cerr << "Error: Stack is empty" << endl;
        return -1;
    }

    return top->data;
}

// Function to check if the stack is empty
bool isEmpty()
{
    return top == NULL;
}

// Function to display the elements of the stack
void display()
{
    if (top == NULL)
    {
        cerr << "Stack is empty" << endl;
        return;
    }

    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, val;

    do
    {
        cout << "\n";
        cout << "1. Push element onto the stack" << endl;
        cout << "2. Pop element from the stack" << endl;
        cout << "3. Peek the top element of the stack" << endl;
        cout << "4. Check if the stack is empty" << endl;
        cout << "5. Display the stack" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to push onto the stack: ";
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (!isEmpty())
                cout << "Top element of the stack: " << peek() << endl;
            break;
        case 4:
            cout << "Stack is " << (isEmpty() ? "empty" : "not empty") << endl;
            break;
        case 5:
            cout << "Stack elements: ";
            display();
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
