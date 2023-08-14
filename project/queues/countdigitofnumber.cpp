#include<iostream>
using namespace std;
#define c 0
int count(int n){

    if(n==0){
        return 0;
    }
    else{
     
       return 1+count(n/10); 
    
    }
}
int main(){
    int n;
    cout<<"Enter a integer"<<endl;
    cin>>n;
    cout<<"The sum of given natural number is :"<<count(n);
    return 0;
}