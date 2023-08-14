#include<iostream>
using namespace std;
int gum(int n){
    if(n==0){
        return 0;
    }
    else{
        return n+=gum(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter a integer"<<endl;
    cin>>n;
    cout<<"The sum of given natural number is :"<<gum(n);
    return 0;
}