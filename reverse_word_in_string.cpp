/* Reverse word in a string
   Input : cat is so cute
   Output : cute so is cat
   I used simple approach in which I first reverse word one by one in given string then reverse complete string and we got our desired output.
*/   

#include<bits/stdc++.h>
using namespace std;

void reverse(string& word,int i,int j){    // Reverse function to reverse word eg: cute -> etuc
      while(i<j){
         int temp=word[i];
         word[i]=word[j];
         word[j]=temp;
         i++;
         j--;
      }
}

void reverse_word(string& str){
   int i,prev=-1;            //prev variable helps to store starting point of our word
   for(i=0;i<str.size();i++){
       if(str[i]==' '){    // when we get space character(' ') that means we found one word in a string so call reverse function on that word
           reverse(str,prev+1,i-1);
           prev=i;
       }
   }
   reverse(str,prev+1,i-1);
   reverse(str,0,str.size()-1);
}

int main(){
   string str;
   getline(cin,str);
   reverse_word(str);
   cout<<str;
}
