#include<bits/stdc++.h>
using namespace std;
#define int long long

void merge(int arr[],int n,int low,int mid,int high){
    int left = low;
    int right = mid+1;

    vector<int> ans;

    // comparison
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else{
           ans.push_back(arr[right++]);
           count++;
        }
    }

    while(left<=mid){
           ans.push_back(arr[left]);
            left++;
    }
    while(right<=high){
           ans.push_back(arr[right++]);
    }

    for(int i=low;i<=high;i++){
        arr[i] = ans[i-low];
    }
}
void mergeSort(int *arr,int n,int low,int high){
    
    // this is recursive so base case likhna padega 
    if(low>=high){
        return;
    }

    int mid = (low+high)/2;
    mergeSort(arr,n,low,mid);
    mergeSort(arr,n,mid+1,high);

    // merge kar denge 
    merge(arr,n,low,mid,high);

}

signed main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   mergeSort(arr,n,0,n-1);

   for(int i=0;i<n;i++){
    cout << arr[i] << " ";
   }

   // Merge sort Algorithm
}