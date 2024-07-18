#include<bits/stdc++.h>
using namespace std;
#define int long long


class SGTree{
	vector<int> seg;
	public:
	SGTree(int n){
		seg.resize(4*n);
	}

	void build(int ind,int low ,int high,int arr[]){
      if(low==high){
          seg[ind] = arr[low];
		  return;
	  }

	  // left and right call 
      int mid = (low+high)/2;
	  build(2*ind+1,low,mid,arr);
	  build(2*ind+2,mid+1,high,arr);

	  seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

	int query(int ind,int low,int high,int l,int r){
		// no overlap
		// [low high] [l r]
		if(l>high || r<low){
			return INT_MAX;
		}

		// complete overlap 
		// l and r k Ander low or high dono aane chaiye  
		if(low>=l && high<=r){
			return seg[ind];
		}

		// partial overlap 
		int mid = (low+high)/2;
		int left = query(2*ind+1,low,mid,l,r);
		int right = query(2*ind+2,mid+1,high,l,r);

		return min(left,right);
	}

	void update(int ind,int low,int high,int i,int val){
		if(low==high){
			seg[ind] = val;
			return;
		}
		// 
		int mid = (low+high)>>1;

		if(i<=mid) update(2*ind+1,low,mid,i,val);
		else update(2*ind+2,mid+1,high,i,val);


		seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
	}
  
};

//int seg[4*n];

signed main(){
    int n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

    SGTree sg1(n);
	sg1.build(0,0,n-1,arr);

	while(q--){
		int type;
		cin>>type;
		if(type==1){
            int l,r;
			cin>>l>>r;
			cout << sg1.query(0,0,n-1,l,r) << "\n";
		}
		else {
			int i,val;
			cin>>i>>val;
			sg1.update(0,0,n-1,i,val);
			arr[i] = valreturn 0 ;
}