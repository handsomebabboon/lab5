#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

void showQueue(struct Queue* q){
    for(int i=q->front;i<= q->rear;i++){
        printf("%d\t",q -> array[i]);
    }
    printf("\n");
}
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)% queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}
 
// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)% queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
void printQueues(struct Queue* hi,struct Queue* low){
    if(isEmpty(hi)){
        printf("high priority queue is empty\n");
    }
    else{
        printf("high priority queue:\t");
        showQueue(hi);
    }

    if(isEmpty(low)){
        printf("low priority queue is empty\n");
    }
    else{
        printf("low priority queue:\t");
        showQueue(low);
    }

}
 
// Driver program to test above functions./
int main()
{
    struct Queue* highPri = createQueue(20);
    struct Queue* lowPri = createQueue(20);



    int choice=-1,choice1,data,packetNum=0,front;
    while(choice != 3){
        printf("Select an option\n1:Add element into the priority queue\n2:Remove element from priority queue\n3:exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter which queue to add to\n1:high priority\n2:low priority\n");
                scanf("%d",&choice1);
                
                if(choice1 == 1){
                    enqueue(highPri,packetNum);
                    packetNum ++;
                }
                else if(choice1 == 2){
                    enqueue(lowPri,packetNum);
                    packetNum ++;
                }
                else{
                    printf("invalid option\n");
                }
                printQueues(highPri,lowPri);
            break;

            case 2:
                if(!isEmpty(highPri)){
                    front = dequeue(highPri);
                    printf("%d dequeued from high priority queue\n",front);
                }
                else if(!isEmpty(lowPri)){
                    front = dequeue(lowPri);
                    printf("%d dequeued from low priority queue\n",front);
                }
                else{
                    printf("both queues empty");
                }
                if(isEmpty(highPri)){
                    printf("high priority queue is empty\n");
                }
                printQueues(highPri,lowPri);
            break;

            case 3:
                printQueues(highPri,lowPri);
            break;
        }


    }
 
    return 0;
}