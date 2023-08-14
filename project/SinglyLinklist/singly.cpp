#include <iostream>
#include<cstdlib>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *head = NULL;
void insert_at_beginning(int val)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        cerr << "Error: Node is not created" << endl;
    }
    else
    {
        new_node->data = val;
        new_node->next = head;
        head = new_node;
    }
}
void insert_at_end(int val)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *temp;
    if (new_node == NULL)
    {
        cerr << "Error: Node is not created" << endl;
    }
    else if (head == NULL)
    {
        new_node->data = val;
        new_node->next = head;
        head = new_node;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
        new_node->data = val;
    }
}
void insert_at_random(int val, int poss)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *temp;
    if (new_node == NULL)
    {
        cerr << "Error: Node is not created" << endl;
    }
    else
    {
        temp = head;
        for (int i = 1; i < poss - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cerr << "Exceed the number of nodes" << endl;
                return;
            }
        }
        new_node->data = val;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void delet_at_beginning()
{
    node *del_node;
    if (head == NULL)
    {
        printf("Nothing to delete \n");
        return;
    }
    else
    {
        del_node = head;
        head = head->next;
        free(del_node);
    }
}
void delet_at_end()
{
    node *del_node;
    node *temp;
    if (head == NULL)
    {
        printf("Nothing to delete \n");
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        del_node = head;
        while (del_node->next != NULL)
        {
            temp = del_node;
            del_node = del_node->next;
        }
        temp->next = NULL;
        free(del_node);
    }
}
void delete_at_random(int poss)
{
    if (head == NULL)
    {
        cerr << "Error: Nothing to delete" << endl;
        return;
    }
    if (poss == 1)
    {
        node *del_node = head;
        head = head->next;
        free(del_node);
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < poss - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cerr << "Error: Exceed the number of nodes" << endl;
                return;
            }
        }
        node *del_node = temp->next;
        if (del_node == NULL)
        {
            cerr << "Error: Exceed the number of nodes" << endl;
            return;
        }
        temp->next = del_node->next;
        free(del_node);
    }
}

void display()
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        cerr << "Error: Nothing to show" << endl;
        return;
    }
    else
    {
        cout << "The data are as: ";

        while (temp != NULL)
        {
            printf("%d \t", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int choice, val, poss;
    do
    {
        printf("\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Display the linked list\n");
        printf("4: Insert at random \n");
        printf("5: delet at beginnig \n");
        printf("6: delet at end \n");
        printf("7: delet at random \n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &val);
            insert_at_beginning(val);
            break;
        case 2:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &val);
            insert_at_end(val);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Insert the position\n");
            scanf("%d", &poss);
            printf("Inter the val\n");
            scanf("%d", &val);
            insert_at_random(val, poss);
            break;
        case 5:
            delet_at_beginning();
            break;
        case 6:
            delet_at_end();
            break;
        case 7:
            printf("Insert the position\n");
            cin>>poss;
            delete_at_random(poss);
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}

