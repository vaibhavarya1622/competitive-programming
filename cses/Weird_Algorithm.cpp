#include<bits/stdc++.h>
using namespace std;

int main(){
    int64_t num;
    cin>>num;
    while(num!=1){
        cout<<num<<" ";
        if(num&1){
            num=num*3+1;
        }
        else{
            num/=2;
        }
    }
    cout<<num;
    return 0;
}