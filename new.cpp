#include <iostream>
using namespace std;
int maximum(int a[],int n){
    
    int max=a[0];
    for(int i=0;i<n;i++){
       if (a[i]>max){
           max=a[i];
       }
    }
    return max;
}

int minimum(int a[], int n){
    int min=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    return min;
}

int retrurner(int a[],int s,int e){
    for(int i=s;i<e;i++){
        
    }
}


int main(){
    int a[]={2,1,4,3,5,7};
    cout<<maximum(a,6)<<endl;
    cout<<a[2:3];







}
