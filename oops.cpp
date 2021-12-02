#include <iostream>
#include <math.h>
using namespace std;
class student{
    int roll_number;
    int age;
    int height;
    int student_id;

public :
    
    student(int roll_number,int age,int height,int student_id){
        this->roll_number=roll_number;
        this->age=age;
        this->height=height;
        this->student_id=student_id;

    }
    
    
    
    
    void information_provider(){
        cout<<"this is student's roll_number "<<roll_number<<endl;
        cout<<"this is student's age " <<age<<endl;
        cout<<"this is student's height "<<height<<endl;
        cout<<"this is student's student id  " << student_id<<endl;
    }


    ~student(){
        cout<<"the deconstructor was called";
    }


    

};
int fibonacci(int n){
    if(n==0){
       return 0;
    }
    else if(n==1){
        return 1;
    }
    else if(n==2){
        return 1;
    }
    else if(n>2){
        return fibonacci(n-1)+ fibonacci(n-2);
    }
}
int array_sum(int a[],int size){
    
    if(size==0){
        return 0;
    }
    if(size==1){
        return a[0];
    }
    if(size>=2){
        return array_sum(a,size-1)+ a[size-1];
    }
    
}
bool array_checher(int a[],int size,int check_on){

    if(size==0){
        return true;

    }
    else if(size ==1){
        if(a[size-1]==check_on){
            return true;
        }else{
            return false;
        }
    }
    else if(size>1){
        return array_checher(a,size-1,check_on)||(a[size-1]==check_on);
    }
    
}
int first_occurence(int a[],int size ,int current_index,int check_this){
    if(current_index==0){
        return 0;
    }
    else if (a[current_index]==check_this)
    {
        return current_index;
    }
    else{
        
        return first_occurence(a,size,current_index-1,check_this);
    }
    
}
int lenght(int n){
    if(n=0){
        return 0;
    }
    else{
        return lenght(n/10);
    }
   
}



int main(){
    /*student s1(21,12,178,20103085);
    s1.information_provider();
    student s2=s1;
    s2.information_provider();
    student*s3=new student(12,13,14,15);
    s3->information_provider();
    */
    /*int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<fibonacci(i)<<" ";
    }*/
    int a[5]={1,3,3,7,3};
    cout<<"this is arrays sum "<< array_sum(a,5)<<endl;
    cout<<"this is for cheching "<<array_checher(a,5,6)<<endl;
    cout<<"first occurence is "<<first_occurence(a,5,5,3)<<endl;
    

    
    return 0;

    
}