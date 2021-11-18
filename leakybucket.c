#include<stdio.h>

int sentCalc(int x,int orate){
    if(x > orate){
        return orate;
    }
    return x;
}

int main(){
    int cap,orate;
    int inp[100];
    int i=0;
    int ch;
    int seconds;
    printf(" \n enter bucket size : ");
    scanf("%d",&cap);
    printf("\n enter output rate :");
    scanf("%d",&orate);
    printf("enter the number of seconds to recieve packets\n");
    scanf("%d",&seconds);

    

    for(int i=0;i<seconds;i++){
        printf("\n enter number of packets coming at second %d : ",i+1);
        scanf("%d",&inp[i]);
    }
    
    for(int i=seconds;i<100;i++){
        inp[i] = 0;
    }

    

    printf("second \t recieved \t sent \t dropped \t remained \n");
    int seconds_count = 0;
    
    int remaining = 0;
    int sent;
    int dropped;
    int temp_amt;
    for(int i=0;;i++){
        if (inp[i] == 0 && remaining ==0 && sent == 0 && dropped == 0)
        {
            break;
        }


        printf("%d\t",i+1);     //second column
        printf("%d\t",inp[i]);  //recieved column
        temp_amt = remaining + inp[i]; //prevs remaining + current recieved

        sent = sentCalc(temp_amt,orate);
        remaining = temp_amt - sent;

        if(remaining > cap){
            dropped = remaining - cap;
            remaining = cap;
            
        }else{
            dropped = 0;
        }
        
        printf("%d\t",sent);     //sent column
        printf("%d\t",dropped);  //dropped column
        printf("%d\t",remaining);   //remained column
        printf("\n");
    }

    return 0;
}