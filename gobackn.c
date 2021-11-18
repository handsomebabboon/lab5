#include<stdio.h>
#include<stdlib.h>
int main(){
    int framecount;
    int window;
    printf("enter number of frames to input\n");
    scanf("%d",&framecount);

    int* frames = (int*)malloc(sizeof(int) * framecount);
    printf("Enter frames\n");
    for(int i=0;i<framecount;i++){
        printf("enter frame %d:",i+1);
        scanf("%d",&frames[i]);
        
    }

    printf("enter window size:");
    scanf("%d",&window);

    for(int i=0;i<framecount;i++){
        if((i+1)%window==0){
            printf("%d\t",frames[i]);
            printf("\nacknowledgement of the above frames sent is recieved by user\n");
        }
        else{
            printf("%d\t",frames[i]);
        }
    }
    if(framecount % window != 0){
        printf("acknowledgement of above frames sent is recieved by user");
    }
    return 0;

}