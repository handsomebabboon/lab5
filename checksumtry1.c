#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char str1[20];
    char str2[20];
    int len;
    char sum[20];
    char comp[20];
    int carry = 0;
    printf("enter the binary string 1:");
    scanf("%s",str1);
    printf("enter the binary string 2:");
    scanf("%s",str2);

    if(strlen(str1) == strlen(str2)){
        len = strlen(str1);
        for(int i=len-1;i>=0;i--){
            if(str1[i] == '0' && str2[i] == '0' && carry == 0){
                carry = 0;
                sum[i] = '0';
            }
            else if(str1[i] == '0' && str2[i] == '0' && carry == 1){
                sum[i] = '1';
                carry = 0;
            }
            else if(str1[i] == '0' && str2[i] == '1' && carry == 1){
                sum[i]='0';carry = 1;
            }
            else if(str1[i] == '1' && str2[i] == '1' && carry == 1){
                sum[i]='1';carry=1;
            }
            else if(str1[i] == '1' && str2[i] == '0' && carry == 1){
                sum[i]='0';carry=1;
            }
            else if(str1[i] == '0' && str2[i] == '1' && carry == 0){
                sum[i]='1';carry=0;
            }
            else if(str1[i] == '1' && str2[i] == '1' && carry == 0){
                sum[i]='0';carry=1;
            }
            else if(str1[i] == '1' && str2[i] == '0' && carry == 0){
                sum[i]='1';carry=0;
            }
            

        }
        

    printf("sum:%d",carry);
    for(int i=0;i<len;i++){
        printf("%c",sum[i]);
    }
    for(int i=0;i<len;i++){
        if(sum[i]=='0')
            comp[i]='1';
        else
            comp[i]='0';
    }
    printf("\n");
    if(carry==0)
        carry=1;
    else
        carry=0;
    
  //  printf("\nChecksum=%c%s",carry,comp);
        printf("checksum:%d",carry);
        for(int i=0;i<len;i++){
            printf("%c",comp[i]);
        }
        
    }
    else{
        printf("invalid input");
    }
}