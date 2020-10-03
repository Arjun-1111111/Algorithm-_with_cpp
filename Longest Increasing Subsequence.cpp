Example:
Input: arr[] = {50, 3, 8, 7, 40, 85}
Output: Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 85}


#include<bits/stdc++.h>  
using namespace std; 
    

int lis( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in  
       bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
}  
    
/* Driver program to test above function */
int main()  
{  
    int arr[] = { 50, 3, 8, 7, 40, 85 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Length of lis is %d\n", lis( arr, n ) );  
  
    return 0;  
}
