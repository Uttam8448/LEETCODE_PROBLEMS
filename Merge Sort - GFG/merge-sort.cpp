//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[],int temp[], int s, int mid, int e)
    {
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{       //inversion count case
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    while(s<=e){
        arr[s]=temp[s];
        s++;
    }
         
    }
    public:
    void mergeSort(int arr[],int s, int e)
    {
        //code here
        if(s>=e){
        return;
        }
        int mid=s+(e-s)/2;
        int temp[e+1];
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,temp,s,mid,e);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends