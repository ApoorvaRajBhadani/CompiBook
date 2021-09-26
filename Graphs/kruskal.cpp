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
//dont use shifting for calculating large powers,use for loop instead
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
void kruskal(){
    //O(ElogE + ElogV)
    //O(mlogm + mlogn)
    ll n,m,i;
    cin>>n>>m;
    vector<Edge> edges(m);
    fo(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;//input is 1-based, we store 0-based
        edges[i] = {u,v,w};
    }
    sort(all(edges),comp);
    //makeSet
	vector<Subset> subsets(n);
    for ( i = 0; i < n; ++i) { 
        subsets[i].parent = i; 
        subsets[i].rank = 0; 
		subsets[i].size = 1;
    }
    ll mstw=0,msts=0;
    for(auto e:edges){
        if(findSet(subsets,e.u)!=findSet(subsets,e.v)){
            uniteSet(subsets,e.u,e.v);
            mstw+=e.w;
            msts++;
            cout<<e.u+1<<' '<<e.v+1<<endl;
        }
        if(msts==n-1) break;
    }
    cout<<mstw<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	kruskal();
	return 0;
}