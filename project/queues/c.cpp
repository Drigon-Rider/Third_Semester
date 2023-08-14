#include <iostream>
#include <cstdlib>
using namespace std;

#define size 3

typedef struct rotating_queue {
    int front;
    int rear;
    int mem[size];
} queue;

void initqueue(queue* q)
{
    q->front = -1;
    q->rear = -1;
}

int isempty(queue* q)
{
    if (q->front == -1 || q->front == q->rear + 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isfull(queue* q)
{
    if ((q->rear + 1) % size == q->front && q->front != -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(queue* q, int val)
{
    if (isfull(q)) {
        cerr << "Error: Queue is full" << endl;
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % size;
        q->mem[q->rear] = val;
    }
}

void dequeue(queue* q)
{
    if (isempty(q)) {
        cerr << "Error: Queue is empty" << endl;
    }
    else {
        int deleted_variable = q->mem[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        else {
            q->front = (q->front + 1) % size;
        }
        cout << "Dequeued variable: " << deleted_variable << endl;
    }
}

void display(queue* q)
{
    cout << "Your queue is:" << endl;
    int i = q->front;
    while (i != q->rear) {
        cout << i << ": " << q->mem[i] << endl;
        i = (i + 1) % size;
    }
    cout << i << ": " << q->mem[i] << endl;
}

int main()
{
    queue* q;
    q = (queue*)malloc(sizeof(queue));
    initqueue(q);
    int var = 0, input;
    do {
        cout << "What do you want to do:" << endl
             << "1: Enqueue" << endl
             << "2: Dequeue" << endl
             << "3: Display" << endl
             << "0: Stop" << endl;
        cin >> input;
        switch (input) {
            case 1:
                cout << "Enter variable: ";
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
                cout << "Stopping the operation" << endl;
                break;
            default:
                cerr << "Error: Invalid input" << endl;
                break;
        }
    } while (input != 0);

    free(q);
    return 0;
}
