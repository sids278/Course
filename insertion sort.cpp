#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    
    
    for (int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
     cout<<""<<endl;
    for (int i=1;i<n;i++){
        int current_element=a[i];
        int k=i-1;
        while (k>=0 && a[k]>current_element){
            a[k+1]=a[k];
            k--;
        }
        a[k+1]=current_element;
        }
    
    ///this is for display of array
    for (int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}