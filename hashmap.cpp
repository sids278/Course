#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename v>

class mapnode{
    public:
    v data;
    string key;
    mapnode* next;
    mapnode(string key,v value){
        this->key=key;
        this->data=value;
        this->next=NULL;
    }
};
template<typename v>
class ourmap{
  
  mapnode<v>**buckets;
  int numBuckets;
  int count;
  
  public:
  
  ourmap(){
    numBuckets = 5;
    count = 0;
    buckets = new mapnode<v>*[numBuckets];
    for(int i = 0;i<numBuckets;i++){
      buckets[i] = NULL;
    }
  }
  private:
  int hashcode(string key){
      int bucket_indx=0;
      current=1;
      for(int i=sizeof(key)-1,i>=0,i--){
           bucket_indx+=int(key[i])*current%numBuckets;
           current*=31;
           current=current%numbuckets;
      }
      return bucket_indx%numBuckets;
  }
  void insert(string key, int value){
    int bucket_indx=hashcode(key);
    mapnode<v>* head=buckets[bucket_indx];
    while(head!=NULL){
        if(head->key=key){
            head->data=value;
        }
    }
    mapnode<v>* head=buckets[bucket_indx];
    mapnode<v>*new_mapnode= new mapnode<v>(key,value);
    new_mapnode->next=head;
    head=new_mapnode;
    }
v delete_mapnode(string key){
    int bucket_indx=hashcode(key);
    mapnode<v>* head=buckets[bucket_indx];
    mapnode<v>* prev=NULL;
    while(head!=NULL){
        if(head->key=key){
           if(prev==NULL){
               head=head->next;
           }
           else{
               prev->next=head->next;
               int value= head->data;
               delete head;
               return value;
           }
        }
        prev=head;
        head=head->next;
    }

}
// if load factor >0.7 then we do rehashing load factor is very imp it is basically tyhe load at evrry node of the buckets array
void rehashing(){
    int old_bucketcount=numBuckets;
    numBuckets=numBuckets*2;
    mapnode<v>**temp=buckets;
    buckets= new mapnode<v>*[numBuckets];

    for(int i=0;i<numBuckets;i++){
       buckets[i]=NULL;
    }
    for(int i=0;i<old_bucketcount;i++){
        mapnode<v>* head= temp[i];
        while(head!=NULL){
            string key=head->key;
            v data=head->data;
            insert(key,data);
            head=head->next;
        }
    }
    for(int j=0;j<old_bucketcount;j++){
        mapnode<v>* head=temp[i];
        delete head;

    }
    delete temp;
    
}
};
int main(){
    
}
