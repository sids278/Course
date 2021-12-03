#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// here we are implementing priority queues using vector
class min_priorityqueue{
    vector<int>pq;
    public:
    priorityqueue(){

    }
    bool is_empty(){
        return pq.size()==0;
    }
    int get_size(){
        return pq.size();
    }
    int get_min(){
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int child_indx=pq.size()-1;
        int parent_indx=(child_indx-1)/2;
        while(child_indx>0){
            if(pq[child_indx]<pq[parent_indx]){
               int temp=pq[parent_indx];
               pq[parent_indx]=pq[child_indx];
               pq[child_indx]=temp;
            }
            else{
                break;
            }
            child_indx=parent_indx;
            parent_indx=(child_indx-1)/2;
        }
    }

    int  remove_min(){
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        // down hipify-->
        int parent_indx=0;
        int left_indx=parent_indx*2 +1;
        int right_indx=parent_indx*2+2;
        int min_indx=0;
        while(left_indx<pq.size()){
            if(pq[min_indx]>pq[left_indx]){
                min_indx=left_indx;
            }
            if(right_indx<pq.size() && pq[right_indx]<pq[min_indx]){
                min_indx=right_indx;
            }
            if(min_indx!=parent_indx){
                int temp=pq[min_indx];
                pq[min_indx]=pq[parent_indx];
                pq[parent_indx]=temp;
            }
            if(min_indx==parent_indx){
                break;
            }
            parent_indx=min_indx;
            left_indx=parent_indx*2+1;
            right_indx=parent_indx*2+2;
        }
        return ans;
    }

};

class max_priorityqueue{
    vector<int>pq;
    public:
    void insert(int element){
        pq.push_back(element);
        int child_indx=pq.size()-1;
        int parent_indx=(child_indx-1)/2;
        while(parent_indx>=0){
            if(pq[parent_indx]<pq[child_indx]){
                int temp=pq[parent_indx];
                pq[parent_indx]=pq[child_indx];
                pq[child_indx]=temp;
            }
            else{
                break;
            }
            child_indx=parent_indx;
            parent_indx=(child_indx-1)/2;
        }

    }
    int get_max(){
        return pq[0];
    }
    bool is_empty(){
        return pq.size()==0;
    }
    int remove_max(){
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parent_indx=0;
        int left_indx=parent_indx*2+1;
        int right_indx=parent_indx*2+2;
        int max_indx=parent_indx;
        while(left_indx<pq.size()){
            if(pq[left_indx]>pq[max_indx]){
                max_indx=left_indx;
            }
            if(right_indx<pq.size()|| pq[right_indx]>pq[max_indx]){
                max_indx=right_indx;
            }
            if(max_indx!=parent_indx){
                int temp=pq[max_indx];
                pq[max_indx]=pq[parent_indx];
                pq[parent_indx]=temp;
            }
            if(max_indx==parent_indx){
                break;
            }
            parent_indx=max_indx;
            left_indx=parent_indx*2+1;
            right_indx=parent_indx*2+2;
        }
    }
    int get_size(){
        return pq.size();
    }
    
};
// heap sort==performed on a array by makin a heap from it and then remove max/min depending on the type of heap(min/max heap)
void heap_sort(int pq[],int n){
    min_priorityqueue p1;
    for(int i=0;i<n;i++){
        p1.insert(pq[i]);
    }
    for(int i=0;i<n;i++){
        cout<<p1.remove_min()<<" ";
    }
}
void actual_heap_sort(int pq[],int n){
    //  building a heap directly from our given array-->
    
    for(int i=1;i<n;i++){
        int child_indx = i;
        while(child_indx>0){
            int parent_indx=(child_indx-1)/2;
            if(pq[child_indx]<pq[parent_indx]){
                int temp=pq[child_indx];
                pq[child_indx]=pq[parent_indx];
                pq[parent_indx]=temp;
            }
            else{
                break;
            }
            child_indx=parent_indx;
        }
    }
    // now making the remove min element part for our heap made from array-->
    // we swap kasta nd first considering first is in right place and the reduce size --> 
    //this is essentially the vector(not a actual vector ffs!!!) for the heap we are wirking on -->
    //just like when we call remove min in actual priority queue,instead here we reduce or workspacee(on which we perform our swaps)
    int size=n;
    while(size>0){
        int temp=pq[size-1];
        pq[size-1]=pq[0];
        pq[0]=temp;
        size--;
        int parent_indx=0;
        int left_indx=parent_indx*2 +1;
        int right_indx=parent_indx*2+2;
        int min_indx=0;
        while(left_indx<size){
            if(pq[min_indx]>pq[left_indx]){
                min_indx=left_indx;
            }
            if(right_indx<size && pq[right_indx]<pq[min_indx]){
                min_indx=right_indx;
            }
            if(min_indx!=parent_indx){
                int temp=pq[min_indx];
                pq[min_indx]=pq[parent_indx];
                pq[parent_indx]=temp;
            }
            if(min_indx==parent_indx){
                break;
            }
            parent_indx=min_indx;
            left_indx=parent_indx*2+1;
            right_indx=parent_indx*2+2;
        }        
    }
    for(int i=0;i<n;i++){
        cout<<pq[i]<<" ";
    }

}

// k smallest integers
void k_smallest_elements(int a[],int k,int n){
    priority_queue<int> p1;
    
    for(int i=0;i<k;i++){
        p1.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(p1.top()>a[i]){
            p1.pop();
            p1.push(a[i]);
        }
    }
    while(!p1.empty()){
        cout<<p1.top()<<" ";
        p1.pop();

    }
}
// k largest elements
void k_largest_elements(int a[],int k,int n){
    priority_queue<int,vector<int>,greater<int>> p3;
    for(int i=0;i<k;i++){
        p3.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(a[i]>p3.top()){
            p3.pop();
            p3.push(a[i]);
        }
    }
    while(!p3.empty()){
        cout<<p3.top()<<" ";
        p3.pop();
    }
}
// check if max heap or not
bool max_heap_check(int a[],int n){
    int parent_indx=0;
    int left=2*parent_indx+1;
    int right=2*parent_indx+2;
    int max_indx=parent_indx;
    while(left<n){
        if(a[max_indx]<a[left]){
            return false;
        }
        if(right<n && a[max_indx]<a[right]){
            return false;
        }
        parent_indx+=1;
        int left=2*parent_indx+1;
        int right=2*parent_indx+2;
        int max_indx=parent_indx;
    }

    return true;
}
// kth largest element
void kth_largest_element(int a[],int k,int n){
    priority_queue<int,vector<int>,greater<int>> p3;
    for(int i=0;i<k;i++){
        p3.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(a[i]>p3.top()){
            p3.pop();
            p3.push(a[i]);
        }
    }
    
    cout<<p3.top();
}
// fun hoga aaj
// upi id-> 98149..@ybl


int main(){
// inbulit priority queue--> using the stl queue -->here it is max priority queue by default , for min priority queue go down !!
   priority_queue<int> p;
/* top==get_max
   pop=remove_max
   push=insert
   size=get_size
   empty=is_empty
*/
// now heres how u implement a min priority queue using inbuilt stl queue
    priority_queue<int,vector<int>,greater<int>> p3;
    // here the vector has to be specified for the same data type and greater is like a function we use to make the heap in a way such that parent is smaller than its children
    //here top gives min so top()==get_max()
    //int a[8]={42,20,18,6,14,11,9,4};
    //k_smallest_elements(a,3,5);
    //k_largest(a,3,5);
    //cout<<endl;
    //cout<<max_heap_check(a,8);
    int a[8]={2,6,10,11,13,4,1,20};
    //kth_largest_element(a,4,8);

}