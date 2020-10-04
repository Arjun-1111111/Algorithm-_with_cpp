/* 
  Given an array, print the Next Greater Element for every element. The Next greater Element for an element x is the first greater element on the right side
  of x in array. Elements for which no greater element exist, consider next greater element as -1.
  Example:
           Input-  6 1 5 7 10
           Output- 7 5 7 10 -1
           
           Here I have used simple brute force approach by taking two for loops and checking next greater element for every element one by one.
           Time complexity : O(N^2)
*/

#include<iostream>
using namespace std;

void print_next_greater_element(int* arr,int n){
     int next_element=-1;     // next_element variable stores just next greater element to arr[i] , if we didn't get any next greater element then we print next_element -1
     for(int i=0;i<n;i++){
         next_element=-1;
         for(int j=i+1;j<n;j++){
             if(arr[i]<arr[j]){
                next_element=arr[j];
                break;
             }
         }
         cout<<arr[i]<<" -> "<<next_element<<endl;
     }
}

int main(){
    int size;
    cin>>size;
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    print_next_greater_element(arr,size);
}
