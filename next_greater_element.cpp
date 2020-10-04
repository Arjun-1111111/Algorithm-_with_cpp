/*   Author - Anshul Pandey (https://github.com/Anshul275)   */
#include <bits/stdc++.h>
using namespace std;

void print_NGE(int arr[], int n){
    stack <int> solu;
    
    //Pushing first element to stack
    solu.push(arr[0]);
    
    for(int i=1; i<n; i++){
        //If stack is empty, pushing the element into stack and continue
        if(solu.empty()){
            solu.push(arr[i]);
            continue;
        }
        
        /*
        If stack is not empty, then check whether the top element is less than the current element
            1. Print the pair and pop the element from stack
            2. Check the condition again and pop the element until stack is not empty
               and condition is true 
        */
        while(!solu.empty() && solu.top() < arr[i]){
            cout<<"Next Greater Element of "<<solu.top()<<" --- "<<arr[i]<<"\n";
            solu.pop();
        }
        
        //Pushing the current element in stack (For finding next greater element for it)
        solu.push(arr[i]);
    }
    
    //After iteration, the remaining elements in stack do not have next greater element
    //So -1 is printed
    while(!solu.empty()){
        cout<<"Next Greater Element of "<<solu.top()<<" --- -1\n";
        solu.pop();
    }
}

int main(){
    
    //Input the size of the array
    int n;
    cin>>n;
    int A[n];
    
    //Input the elements of the array
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    
    //Printing the NEXT GREATER ELEMENT of each element in the array
    print_NGE(A, n);
    return 0;
}

/*
SAMPLE INPUT - 
    5
    1 2 3 4 5
SAMPLE OUTPUT - 
    Next Greater Element of 1 --- 2
    Next Greater Element of 2 --- 3
    Next Greater Element of 3 --- 4
    Next Greater Element of 4 --- 5
    Next Greater Element of 5 --- -1
*/