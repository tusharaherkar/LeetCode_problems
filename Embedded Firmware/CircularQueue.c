// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

// Circular Queue
#define MAX_BUFF_SIZE 10


typedef struct CirQueue{
    int buffer[MAX_BUFF_SIZE];
    int front;
    int rear;
} CirQueue;

bool full(CirQueue* q);
bool empty(CirQueue* q);

void initQueue(CirQueue* q)
{   
    q->front = 0;
    q->rear = 0;
}

bool enqueue(CirQueue* q, int EnqueueVal)
{
    if(full(q))
        return false;
      
    
    q->buffer[q->rear] = EnqueueVal;
    q->rear = (q->rear+1) % MAX_BUFF_SIZE;
    
    return true;
    
    
}

bool dequeue(CirQueue* q, int *returnedVal)
{
    if(empty(q))
        return false;
    
    *returnedVal = q->buffer[q->front];
    q->front = (q->front+1)%MAX_BUFF_SIZE;
    return true;
    
}

bool full(CirQueue* q)
{
    if((q->front) == (q->rear+1)%MAX_BUFF_SIZE)
        return true;
    else
        return false;
}

bool empty(CirQueue* q)
{
    if(q->front == q->rear)
        return true;
    else
        return false;
}

int main() {
    // Write C code here
    CirQueue obj;
    CirQueue *q = &obj;
    int dequeuedVal;
    int i;
    
    initQueue(q);
    
    for(i = 0 ; i < 12 ; i++)
    {
        if(enqueue(q, i))
        {
            printf("Enqueued : %d\n", i);
        }
        else
        {
            printf("Enqueue operation failed: %d\n", i);
        }
    }
    
    for(i = 0 ; i < 12 ; i++)
    {
        if(dequeue(q, &dequeuedVal))
        {
            printf("Dequeued : %d\n", dequeuedVal);
        }
        else
        {
            printf("Dequeued operation failed: %d\n", i);
        }
    }
    
    
    return 0;
}