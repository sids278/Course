#include <iostream>
using namespace std;
int h=19;

void value_changer_by_value(int i){
    i=12;
}

void value_changer_by_reference(int* pt){
    *pt=12;
}
void value_swapper_by_variable(int& i){
    i=7;
}
int using_two_functions_refrence(int*j){
      value_changer_by_reference(j);
      int  ans=1;
      for(int k=1;k<=*j;k++){
          ans=ans*k;
      }
    return ans;
}
int* fun(int& i){
    int m=10;
    return &i;
}

void increment(){
    h++;
}
int main(){
    /*
    int a[4]={1,2,3,4};
    cout<<&a<<endl;
    int i=10121;
    char s=i;
    cout << s<<endl;
    char c='abcde';
    ;
    cout<<c<<endl;
    cout<<pc;
    */

   /*float c=12.3;
   float*pc=&c;
   int*p=(int*)pc;
   cout<<p<<endl;
   cout<<pc<<endl;
   cout<<*pc<<endl;
   cout<<*p<<endl;
   */
   
   /*int i=19;
   int& j=i;
   cout<<j<<endl;
   i=i+11;
   cout<<i<<endl;
   cout<<j<<endl;
   int k=23;
   cout<<k<<endl;*/

   int l=10;
   int*j=&l;
   /*value_changer_by_value(l);
   cout<<l<<endl;
   value_changer_by_reference(&l);
   cout<<j<<endl;
   cout<<l<<endl;
   value_swapper_by_variable(j);
   cout<<l<<endl;
   cout<<j<<endl;*/
   //cout<<using_two_functions_refrence(j);
   /*int m=10;
   int&q=m;
   cout<<fun(q)<<endl;
   
   increment();
   cout<<h<<endl;
   */
   int a=10;
   int b=20;
   int c=(a>b) ? a:b;
   cout<<c<<endl;
   // in line fucntion ^^//
   const int d=10;
   int& y=d;
   
   d++;
   cout<<y<<endl;
   cout<<d<<endl;


   
   

   /* this shows that pass by rehrence is done either by using pointers or refrence variables and pass by value 
   is directly placing the varibale in the function parameter but this does not reflect changes to other function example is up*/


   
   

}
