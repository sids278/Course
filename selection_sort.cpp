#include <iostream>
using namespace std;
int locate_the_smallest(int a[],int s,int e){
    int i=s;
    int j=i;
    while(i<=e){
        if(a[i]<a[j]){
            j=i;
        }
        i=i+1;

    }
    return j;
}
 void swap_function(int a[],int i,int j){
     int temp=a[i];
     a[i]=a[j];
     a[j]=temp;

      
 }

 void selection_sort(int a[],int n){
     int i=0;
     while( i<n-1){
         int j=locate_the_smallest(a,i,n-1);
         swap_function(a,i,j);
         i++;
     }
 }
int main(){
    
    int n;
    cin>>n;
    
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    
    selection_sort(a,n);
    
    for(int k=0;k<n;k++){
        cout<<a[k]<<" ";
        
    }
    
    return 0;
}
/*
WORST CAE :-
Input:
6 5 4 3 2 1
Output:-
1 2 3 4 5 6

Time complexity:- O(n^2)[comprisons],O(n)[swaps]
Space complexity:-O(1)

AVERAGE CASE:-
Input:
2 3 6 5 4 1
Output:
1 2 3 4 5 6

Time complexity:- O(n^2)[comprisons],Omega(n)[swaps]
Space complexity:-O(1)


BEST CASE:-
INput:
1 2 3 4 5 6
Output:
1 2 3 4 5 6

Time complexity:- O(n^2)[comprisons],O(1)[swaps]
Space complexity:-O(1)
*/



