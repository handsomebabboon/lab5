#include<stdio.h>
#include<stdlib.h>

int sentCalc(int tempAmt,int orate){
    if(tempAmt < orate){
        return tempAmt;
    }
    return orate;
}

int main(){
    int seconds,second,temp,orate,recieved,sent,dropped,remained=0,capacity;
    printf("enter the number of seconds to recieve input\n");
    scanf("%d",&seconds);
    int* inputs = (int*)malloc(sizeof(int) * seconds+1);

    for(int i=0;i<seconds;i++){
        printf("enter the number of packets coming at second:%d\n",i+1);
        scanf("%d",&inputs[i]);
    }
    inputs[seconds+1] = 0;
    printf("enter the outpu rate of the bucket");
    scanf("%d",&orate);
    printf("enter the capacity of the bucket\n");
    scanf("%d",&capacity);
    printf("second\trecieved\tsent\tdropped\tremained");
    
    for(int i=0;;i++){

         if (inputs[i] == 0 && remained ==0 && sent == 0 && dropped == 0){
            break;
        }

        printf("%d\t",i+1);    //column 1
        printf("%d\t",inputs[i]);   //column 2

        int tempAmount = remained + inputs[i];

        sent = sentCalc(tempAmount,orate);
        remained = tempAmount - sent;
        if(remained > capacity){
            dropped = tempAmount - capacity;
            remained = capacity;
        }
        else{
            dropped = 0;
        }

       

        printf("%d\t",sent);
        printf("%d\t",dropped);
        printf("%d\t",remained);

        printf("\n");

    }


    return 0;
}