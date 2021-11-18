#include<stdio.h>
#include<stdlib.h>

int main(){
    int temp1,temp2,temp3,temp4,temp5;

    printf("enter the number of frames to be sent\n");
    scanf("%d",&temp1);

    int* arr = (int*)malloc(sizeof(int) * temp1);

    for(int i=0;i<temp1;i++){
        printf("\nEnter the data for frame %d:",i+1);
        scanf("%d",&temp2);
        arr[i] = temp2;
    }
    printf("enter the window size\n");
    scanf("%d",&temp3);
    for(int i=0;i<temp1;i++){
        if((i+1)%temp3 == 0){
            printf("%d\n",arr[i]);
            printf("acknowledgements for the above %d frames recieved",temp3);
        }
        else{
            printf("%d\n",arr[i]);
        }
    }

    printf("acknowledgements for the above %d frames recieved",temp1 % temp3);



    return 0;
}