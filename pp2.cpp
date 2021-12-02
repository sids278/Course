#include <iostream>
using namespace std;
char *removeSpaces(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
           str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<removeSpaces(s);

    for (int i=0;i<n;i=i+2){
        cout<<s[i+2];
        cout<<" s";
    }
    

    return 0;
}