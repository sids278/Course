#include <iostream>
using namespace std;

int locate_the_smallest(int a[],int s,int e){
    int i=s;
    int j=i;
    while(i<=e){
        if(a[i]<a[j]){
            j=i;
        }
        i++;
    }
    return j;
}

void swap(int a[],int i,int j){
    int current=a[i];
    a[i]=a[j];
    a[j]=current;
}

void selection_sort(int a[],int n){
    for(int i=0;i<n;i++){
        int j=locate_the_smallest(a,i,n-1);
        swap(a,i,j);

    }
}









int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    selection_sort(a,n);
    for(int k=0;k<n;k++){
        cout<<a[k]<<" ";

    }
    
    return 0;
}