#include<iostream>
using namespace std;
void reverseString(string &s){
int i = 0,j = s.size()-1;
while(i<=j){
    swap(s[i],s[j]);
    i++;
    j--;
}
}
int main(){
 string s;
 cin>>s;
 reverseString(s);
 cout<<s;
}
