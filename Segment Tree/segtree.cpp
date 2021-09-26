#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
//#define endl '\n'
#define MOD 1000000007//998244353
#define setbits(x) __builtin_popcountll(x)
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
//cout<<fixed<<setprecision(10)<<pi;
#define custpq(E,cm,nm) priority_queue<E, vector<E>, decltype(&cm)> nm(cm);

const ll MAXN = 1000000;
struct TreeNode{
	ll bit_or,sum;
};
ll arr[MAXN+5];
TreeNode tree[4*MAXN+5];//root node is at index 1
void buildTree(ll s,ll e,ll ni){
	if(s==e){
        //Logic(base case)
		tree[ni].bit_or=arr[s];//=arr[end] as well
        tree[ni].sum=arr[s];
		return;
	}
	ll mid = s + (e-s)/2;
	buildTree(s,mid,2*ni);
	buildTree(mid+1,e,2*ni+1);
    //Logic(find ans from children)
	tree[ni].bit_or = tree[ni*2].bit_or|tree[ni*2+1].bit_or;
    tree[ni].sum = tree[ni*2].sum+tree[ni*2+1].sum;
}
void updateTree(ll s,ll e,ll ni,ll idx,ll val){
	if(s==e){
        arr[idx]=val;
        //Logic(base case)
		tree[ni].bit_or=arr[s];
        tree[ni].sum=arr[s];
		return;
	}
	ll mid = s + (e-s)/2;
	if(idx<=mid){
		updateTree(s,mid,2*ni,idx,val);
	}else{
		updateTree(mid+1,e,ni*2 +1,idx,val);
	}
    //Logic(find ans from children)
	tree[ni].bit_or = tree[ni*2].bit_or|tree[ni*2+1].bit_or;
    tree[ni].sum = tree[ni*2].sum+tree[ni*2+1].sum;
}
TreeNode queryTree(ll s,ll e,ll ni,ll l,ll r){
	TreeNode myans;
	//completly outside
	if(l>e || r<s){
        //Logic(for zero elements)
		myans.bit_or=0;
        myans.sum=0;
		return myans;
	}
	//completely inside
	if(s>=l && e<=r){
		return tree[ni];
	}
    //partially inside
	ll mid = s + (e-s)/2;
	TreeNode lt = queryTree(s,mid,ni*2,l,r);
	TreeNode rt = queryTree(mid+1,e,ni*2+1,l,r);
    //Logic(from child tree ans)
	myans.bit_or = lt.bit_or|rt.bit_or;
    myans.sum = lt.sum+rt.sum;
	return myans;
}
int main(){
    ll i,j,n,q;
	cin>>n;
	fo(i,0,n) cin>>arr[i];
	buildTree(0,n-1,1);
	cin>>q;
	while(q--){
		ll tt;
		cin>>tt;
		if(tt==1){
            ll idx,val;
			cin>>idx>>val;
			updateTree(0,n-1,1,idx-1,val);
		}else if(tt==2){
            ll l,r;
			cin>>l>>r;
            TreeNode ans = queryTree(0,n-1,1,l-1,r-1);
            cout<<"Sum = "<<ans.sum<<endl;
			cout<<"Bitwise Or = "<<ans.bit_or<<endl;
		}
	}
	return 0;
}