#include <iostream>
using namespace std;
int locate_the_index(int a[],int s,int e){
    int i=s;
    int j=i;
    while(i<=e){
        if(a[j]>a[i]){
            j=i;
        }
        i++;
    }
    return j;

}
void swap(int a[],int i, int j){
    int current=a[i];
    a[i]=a[j];
    a[j]=current;
}

void selection_sort(int a[],int n){
    int i=0;
    while(i<n-1){
        int j=locate_the_index(a,i,n-1);
        swap(a,i,j);

    }
    
}
int main(){
    int a[]={2,1,4,3};
    selection_sort(a,4);
    for(int k=0;k<4;k++){
        cout<<a[k]<<" ";
    }

    return 0;
}