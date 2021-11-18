#include<string>
#include<iostream>

using namespace std;

string xor1(string a,string b){
    int n = a.length();
    string res = "";
    for(int i=1;i<n;i++){
        if(a[i] == b[i]){
            res += "0";
        }
        else{
            res += "1";
        }
    }
    return res;
}

string mod2div(string poly,string dividend){
    int n1 = poly.length();
    int n2 = dividend.length();
    string remainder = dividend;
    string temp = remainder.substr(0,n1);
    int divisorlen = n1;
    while(n1 < n2){
        if(temp[0] == '1'){
            temp = xor1(temp,poly) + remainder[n1];
        }
        else{
            temp = xor1(temp,string(divisorlen,'0')) + remainder[n1];
        }
        n1 +=1;



    }

    if(temp[0]=='1'){
        temp = xor1(temp,poly);
    }
    else{
        temp = xor1(temp,string(divisorlen,'0'));
    }

    return temp;

}

string appendData(string poly,string dividend){
    string append1 = string(poly.length() -1,'0');
    string appended_data = dividend + append1;

    return appended_data;
}

int main(){

    string data = "100100";
    string key = "1101";

    string new_dividend = appendData(key,data);

    string crc = mod2div(key,new_dividend);

    cout<<"crc is is:"<<crc<<endl;
    cout<<"encoded data:"<<data<<crc<<endl;

    return 0;
}