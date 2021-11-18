#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct queue{
    int front,rear,size,capacity;
    int* arr;
}queue;

queue* createQ(int n){
    queue* q = (struct queue*)malloc(sizeof(queue));
    q -> capacity = n;
    q -> front = 0;
    q -> rear = 0;
    q -> size = 0;
    q -> arr = (int*)malloc(n * sizeof(int));
    return q;
}

int isFull(queue* q){
    if(q -> size == q -> capacity){
        return 1;
    }
    return 0;
}

int isEmpty(queue* q){
    if(q -> size == 0){
        return 1;
    }
    return 0;
}

int enqueue(queue* q,int data){
    if(isFull(q)){
        return 0;
    }
    else{
        q->size++;
        q->rear = (q->rear + 1)%(q -> capacity);
        q -> arr[q -> rear] = data;
        return 1;
    }

}

int dequeue(queue* q){
    if(isEmpty(q)){
        return 0;
    }
    else{
        q -> size--;
        int temp = q -> arr[q -> front];
        q -> front = (q -> front + 1)%(q->capacity);
        return temp;
    }
}


int showQueue(queue* q){
    
    //int i = q ->front;
    //do{
    //    printf("%d\t",q->arr[i]);
    //    i = (i + 1) % (q -> capacity);
    //}while(i != q->front);

    for(int i=q->front;i <= q -> rear;i = (i + 1)%q->capacity){
        printf("%d\t",q->arr[i]);
    }
}

void printQueues(queue* low,queue* hi){

    if(isEmpty(hi)){
        printf("high pirq is empty\n");
    }
    else{
        printf("high priority queue\n");
        showQueue(hi);
    }
    if(isEmpty(low)){
        printf("\nlow priq is empty\n");
    }else{
        printf("low priority queue:\n");
        showQueue(low);
    }
    printf("\n");
}

int main(){
    queue* hi = createQ(20);
    queue* low = createQ(20);
    int temp1,temp2,temp3,temp4,temp5,packet_num=1;
    while(1){
        printf("Enter an option 1:add to queu\n2:delete from queu\n3:exit\n");
        scanf("%d",&temp1);

        if(temp1 == 1){     //enqueue
            printf("enter an option\n1:insert into high priority\n2:insert into low priority\n");
            scanf("%d",&temp2);

            if(temp2 == 1){ //enqueue hi pri
                enqueue(hi,packet_num);
                packet_num++;
            }
            else{   //enqueue low pri
                enqueue(low,packet_num);
                packet_num++;
            }
            printQueues(low,hi);
        }
        else if(temp1 == 2){    //dequeu
            if(isEmpty(hi)){
               dequeue(low);
               
            }
            else{
                dequeue(hi);
            }
            printQueues(low,hi);
        }
        else if(temp1 == 3){    //exit
            printQueues(low,hi);
            break;
        }
        else{
            printf("invalide option\n");
        }



    }

    return 0;
}