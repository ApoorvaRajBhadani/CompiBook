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
ll arr[MAXN+5];
ll tree[4*MAXN+5];
ll ltree[4*MAXN+5];
void buildTree(ll s,ll e,ll ni){
	if(s==e){
		tree[ni]=arr[s];//same as arr[e]
		return;
	}
	ll m = s +(e-s)/2;
	buildTree(s,m,ni*2);
	buildTree(m+1,e,ni*2+1);
	tree[ni] = min(tree[ni*2],tree[ni*2+1]);//build logic
}
void updTree(ll s,ll e,ll ni,ll l,ll r,ll v){
	//invalid case if(s>e) return;
	//update lazy values
	if(ltree[ni]!=0){
		tree[ni]+=ltree[ni];
		if(s!=e){
			ltree[2*ni]+=ltree[ni];
			ltree[2*ni+1]+=ltree[ni];
		}
		ltree[ni]=0;
	}
	//no overlap
	if(l>e || r<s){
		return;
	}
	//complete overlap
	if(s>=l && e<=r){
		tree[ni]+=v;//Logic for update
		if(s!=e){//pass pending values to children if available
			ltree[ni*2]+=v;
			ltree[ni*2+1]+=v;
		}
		return;
	}
	//partial overlap
	ll m = s + (e-s)/2;
	updTree(s,m,ni*2,l,r,v);
	updTree(m+1,e,ni*2+1,l,r,v);
	tree[ni] = min(tree[ni*2],tree[ni*2+1]);//build logic
}
ll queryTree(ll s,ll e,ll ni,ll l,ll r){
	//invalid case if(s>e) return INT_MAX;
	//update pending lazy values
	if(ltree[ni]!=0){
		tree[ni]+=ltree[ni];
		if(s!=e){//pass on to children if available
			ltree[ni*2]+=ltree[ni];
			ltree[ni*2+1]+=ltree[ni];
		}
		ltree[ni]=0;
	}
	//no overlap
	if(s>r || e<l){
		return INT_MAX;
	}
	//complete overlap
	if(s>=l && e<=r){
		return tree[ni];
	}
	//partial overlap
	ll m = s + (e-s)/2;
	ll lt = queryTree(s,m,ni*2,l,r);
	ll rt = queryTree(m+1,e,ni*2+1,l,r);
	return min(lt,rt);
}
void solve(ll caseno){
	ll i,j,n,q;
	cin>>n;
	fo(i,0,n) cin>>arr[i];
	buildTree(0,n-1,1);
	mset(ltree,0);//initialize lazy tree with 0
	cin>>q;
	fo(i,0,q){
        ll qtype,lf,rg,v;
        cin>>qtype;
		if(qtype==2){
			//range min query (in [lf,rg])
            cin>>lf>>rg;
			cout<<queryTree(0,n-1,1,lf,rg)<<endl;//lf<=rg(assumption)
		}else if(qtype==1){
			//inc (all values in [lf,rg] by v)
            cin>>lf>>rg>>v;
		    updTree(0,n-1,1,lf,rg,v);//lf<=rg(assumption)
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}