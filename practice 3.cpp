#include<iostream>
using namespace std;
template <typename k, typename v>
  
// Hashnode class
class hashNode {
public:
    v value;
    k key;
  
    // Constructor of hashnode
    hashNode(k key, v value)
    {
        this->value = value;
        this->key = key;
    }
};
class ourmap(){
  public:
  int count;
  hashNode<k,v>** buckets;
  int numbuckets;
  ourmap(int n){
    buckets=new hashNode<k,v>*[n];
    numbuckets=n;
  }
  private:
  int hashcode(k key){
    int bucket_indx=0;
    int start=1;
    for(int i=19;i>=0;i--){
        bucket_indx+=(int(key[i])*start)%numbuckets;
        start*=31;
        start=start%numbuckets;
    }
    return bucket_indx%numbuckets;
  }
  public:
  void insert(k key,v value){
    int bucket_indx=hashcode(key)
  }

  
}