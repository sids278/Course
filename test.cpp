#include <iostream>
#include <string>
using namespace std;

/*int get_bucketindx(string key){
        int numbuckets=20;
        int bucket_indx=0;
        int start=1;
        for(int i=19;i>=0;i--){
            bucket_indx+=(int(key[i])*start)%numbuckets;
            start*=31;
            start=start%numbuckets;
        }
        return bucket_indx%numbuckets;
}
int main(){
    int x=get_bucketindx("abc");
    cout<<x;
}*/
int is_palindrome(string s){
    static int i=sizeof(s)-1;
    
    static int j=0;
    cout<<j;
    if(s[i]!=s[j]){
        return 0;
    }
    
    if(j>=i){
        return 1;
    }
    j++;
    i--;
    is_palindrome(s);
}
int main(){
    is_palindrome("bab");
    
}