//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    // long long int merge(long long arr[],long long temp[],long long s,long long mid, long long e){
    //     int i=s,j=mid+1,k=s;
    //     long long c=0;
    //     while(i<=mid && j<=e){
    //         if(arr[i]<=arr[j]){
    //             temp[k++]=arr[i++];
    //         }
    //         else{
    //             temp[k++]=arr[j++];
    //             c+=mid-i+1;
    //         }
    //     }
    //     return c;
    // }
    // long long int mergeSort(long long arr[],long long temp[],long long s, long long e){
    //     if(s>=e){
    //         return 0;
    //     }
    //     long long mid=s+(e-s)/2;
    //     long long int c=0;
    //     c+=mergeSort(arr,temp,s,mid);
    //     c+=mergeSort(arr,temp,mid+1,e);
    //     c+=merge(arr,temp,s,mid,e);
    //     return c;
    // }
    long merge(long long arr[],long long temp[],int s,int mid,int e){
    int i=s,j=mid+1,k=s;
    long c=0;
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{       //inversion count case
            temp[k++]=arr[j++];
            c+=mid-i+1;
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
    return c;
}

long mergeSort(long long arr[],long long temp[],int s,int e){
    if(s>=e){
        return 0;
    }
    long c=0;
    int mid=s+(e-s)/2;
    c += mergeSort(arr,temp,s,mid);
    c += mergeSort(arr,temp,mid+1,e);
    c += merge(arr,temp,s,mid,e);
    return c;
}
    
    long long int inversionCount(long long arr[], long long N)
    {   
        // Your Code Here
       long long int c=0;
       long long temp[N];
       c=mergeSort(arr,temp,0,N-1);
       return c;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends