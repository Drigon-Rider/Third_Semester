#include <iostream>
#include <cstdlib>
using namespace std;
#define size 3
typedef struct Queue
{
    int front;
    int rare;
    int mem[size];
} queue;
void initqueue(queue *q)
{

    q->front = -1;
    q->rare = -1;
}
int isempty(queue *q)
{
    if (q->rare == -1 || q->front > q->rare)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(queue *q)
{
    if (q->rare >= size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(queue *q, int val)
{
    if (isfull(q))
    {
        cerr << "Error: Stack is full"<<endl;
    }
    else
    {
        if (q->front == -1)
        {
            q->front =0;
        }  
        q->rare++;
        q->mem[q->rare] = val;
    }
}
void dequeue(queue *q)
{
    int delet_variable;
    if (q->front == -1)
        {
            q->front =0;
        }
    if (isempty(q))
    {
        cerr << "Error:Stack is empty"<<endl;
    }
    else
    {
        delet_variable = q->mem[q->front];
        q->front++;
		cout<<"Dequeue variable:"<<delet_variable<<endl;
    }
    
}
void display(queue *q)
{
    cout << "Your queue is:"<<endl;
    for (int i = q->front; i <= q->rare; i++)
    {
        cout <<i<<":"<<q->mem[i] << endl;
    }
}
int main()
{
    queue *q;
    q = (Queue *)malloc(sizeof(Queue *));
    initqueue(q);
    int var=0, input;
    do
    {
        cout << "What you want to do:" << endl
             << "1: enqueue" << endl
             << "2: dequeue" << endl
             << "3: Display" << endl
             << "0: stop" << endl;
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "Enter variable:";
            cin >> var;
            enqueue(q, var);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        case 0:
            cout << "Stop the operation" << endl;
            break;
        default:
            cerr << "Error:";
            break;
        }

    } while (input != 0);

    return 0;
}