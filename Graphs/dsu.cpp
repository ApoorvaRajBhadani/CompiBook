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
#define custpq(E,cm,nm) priority_queue<E,vector<E>,decltype(&cm)> nm(cm);
//https://codeforces.com/contest/1213/problem/G
struct Edge{
	ll u,v,w;
};
bool comp(Edge a,Edge b){
	return a.w<b.w;
}
struct Subset{ 
    ll parent,rank,size;
};
ll findSet(vector<Subset> &subsets, ll i) {
    if (subsets[i].parent != i) 
        subsets[i].parent = findSet(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 
void uniteSet(vector<Subset> &subsets, ll x, ll y) { 
    ll xroot = findSet(subsets, x); 
    ll yroot = findSet(subsets, y); 
	if(xroot==yroot) return;
    if (subsets[xroot].rank < subsets[yroot].rank){ 
        subsets[xroot].parent = yroot; 
		subsets[yroot].size+=subsets[xroot].size;
    }else if (subsets[xroot].rank > subsets[yroot].rank){ 
        subsets[yroot].parent = xroot; 
		subsets[xroot].size+=subsets[yroot].size;
    }else{ 
        subsets[yroot].parent = xroot; 
		subsets[xroot].size+=subsets[yroot].size;
        subsets[xroot].rank++; 
    } 
}
ll nc2(ll n){
	ll ans = n*(n-1);
	ans/=2;
	return ans;
}
void solve(ll caseno){
    ll i,j,n,m;
	cin>>n>>m;
	vector<Edge> edges;
	vi qarr;
	fo(i,0,n-1){
		ll u,v,w;
		cin>>u>>v>>w;
		Edge e = {u,v,w};
		edges.pbb(e);
	}
	fo(i,0,m){
		ll q;cin>>q;
		qarr.pbb(q);
	}
	sort(all(edges),comp);
	vector<pii> ansarr;
	//makeSet
	vector<Subset> subsets(n);
    for ( i = 0; i < n; ++i) { 
        subsets[i].parent = i; 
        subsets[i].rank = 0; 
		subsets[i].size = 1;
    } 
	ll myans = 0;
	vi edgesw,myansarr;
	fo(i,0,n-1){
		Edge e = edges[i];
		edgesw.pbb(e.w);
		myans-=nc2(subsets[findSet(subsets,e.u-1)].size);
		myans-=nc2(subsets[findSet(subsets,e.v-1)].size);
		uniteSet(subsets,e.u-1,e.v-1);
		myans+=nc2(subsets[findSet(subsets,e.u-1)].size);
		myansarr.pbb(myans);
	}
	for(auto q:qarr){
		i = upper_bound(edgesw.begin(),edgesw.end(),q)-edgesw.begin();
		if(i==0) cout<<0<<" ";
		else cout<<myansarr[i-1]<<" ";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		solve(i);
	}
	return 0;
}