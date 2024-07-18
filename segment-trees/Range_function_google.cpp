#include<bits/stdc++.h>
using namespace std;
#define int long long

// 
class SGT{
    public:
    vector<int> seg;
    vector<int> lazy;

    SGT(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int ind,int low,int high,int arr[]){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind,int low,int high,int l,int r){
        if(l>high || r<low){
            return 0;
        }

        if(l<=low && r>=high){
            return seg[ind];
        }

        // partial overlap 
        int mid = (low+high)/2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
       
       return left+right;

    }

    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)/2;
        if(i<=mid){
            update(2*ind+1,low,high,i,val);
            
        }else{
            update(2*ind+2,low,high,i,val);
        }

        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
};
void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    SGT sg(n);
    sg.build(0,0,n-1,arr);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout << sg.query(0,0,n-1,l,r) << "\n";
        // After that find the sum between l-r
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    
}