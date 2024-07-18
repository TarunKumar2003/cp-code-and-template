#include<bits/stdc++.h>
using namespace std;
#define int long long

void build(int ind,int low,int high,int arr[],int seg[],int orr){

    if(low==high){
        seg[ind] = arr[low];
        return;
    }

    int mid = (low+high)/2;
    build(2*ind+1,low,mid,arr,seg,!orr);
    build(2*ind+2,mid+1,high,arr,seg,!orr);

    if(orr){
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    }
    else {
        seg[ind] = seg[2*ind+1]^seg[2*ind+2];
    }

}

void update(int ind,int low,int high,int i,int val,int seg[],int orr){
    if(low==high){
        seg[ind] = val;
        return;
    }
    int mid = (low+high)/2;

    if(i<=mid){
        update(2*ind+1,low,mid,i,val,seg,!orr);
    }else{
          update(2*ind+2,mid+1,high,i,val,seg,!orr);
    }

    if(orr){
        seg[ind] = seg[2*ind+1]|seg[2*ind+2];
    }
    else{
         seg[ind] = seg[2*ind+1]^seg[2*ind+2];
    }

}
void solve(){
    int n,m;
    cin>>n>>m;
    int size = pow(2,n);
    int arr[size];
    for(int i=0;i<size;i++) cin>>arr[i];
    int seg[4*size];
    if(n%2){
        build(0,0,size-1,arr,seg,1);
    }
    else {
         build(0,0,size-1,arr,seg,0);
    }
   // cout << seg[0];
    while(m--){
        int i,val;
        cin>>i>>val;
        i--;
        if(n%2){
             update(0,0,size-1,i,val,seg,1);
        }
        else {
             update(0,0,size-1,i,val,seg,0);
        }
        arr[i] = val;
        cout << seg[0] << "\n";
        
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
    
}