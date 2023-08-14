#include <iostream>
using namespace std;
typedef struct dubly
{
    int data;
    struct dubly *next;
    struct dubly *prev;
} node;
node *head;

void insert_at_begining(int val)
{
    node *new_node = (node *)malloc(sizeof(node));

    if (new_node == NULL)
    {
        cerr << "Error" << endl;
        return;
    }
    if (head == NULL)
    {
        new_node->data = val;
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
    }
    else
    {
        new_node->next = head;
        new_node->data = val;
        head->prev = new_node;
        head = new_node;
        head->prev = NULL;
    }
}
void insert_at_end(int val)
{
    node *new_node = (node *)malloc(sizeof(node));

    if (head == NULL)
    {
        head = new_node;
        head->data = val;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = temp;
        temp->next = new_node;
    }
}
void inset_at_random(int val, int poss)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *temp;
    if (head == NULL)
    {
        insert_at_begining(val);
        return;
    }
    else
    {
        temp = head;
        for (int i = 1; i < poss - 1; i++)
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                cerr << "Error:exceed the number of data" << endl;
                return;
            }
        }
        new_node->data = val;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next->prev = new_node;
    }
}
void delete_at_begining()
{
    node *del;
    if (head == NULL)
    {
        cerr << "Error" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        del = head;
        head = head->next;
        free(del);
        head->prev = NULL;
    }
}
void delete_at_end()
{
    node *del, temp;
    if (head == NULL)
    {
        cerr << "Error" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        del = head;
        while (del->next != NULL)
        {
            del = del->next;
        }
        del->prev->next = NULL;
        free(del);
    }
}
void delete_at_random(int poss)
{
    node *del_node;
    if (head == NULL)
    {
        cerr << "Error" << endl;
        return;
    }
    if (poss == 1)
    {
        delete_at_begining();
        return;
    }
    else
    {

        del_node = head;
        for (int i = 0; i < poss-1; i++)
        {
            del_node = del_node->next;
            if (del_node == NULL)
            {
                cerr << "Error: exceed the number of data" << endl;
                return;
            }
        }
        del_node->prev->next = del_node->next;
        del_node->next->prev = del_node->prev;
        free(del_node);
    }
}
void display()
{
    if (head == NULL)
    {
        cerr << "NOthing to show" << endl;
        return;
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
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
            insert_at_begining(val);
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
            inset_at_random(val, poss);
            break;
        case 5:
            delete_at_begining();
            break;
        case 6:
            delete_at_end();
            break;
        case 7:
            printf("Insert the position\n");
            cin >> poss;
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