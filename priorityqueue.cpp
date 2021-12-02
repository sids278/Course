#include <iostream>
#include <vector>
using namespace std;

// here we are implementing priority queues using vector
class priorityqueue{
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
int main(){
    priorityqueue p1;
    p1.insert(100);
    p1.insert(90);
    cout<<p1.get_size()<<endl;
    cout<<p1.get_min()<<endl;
}