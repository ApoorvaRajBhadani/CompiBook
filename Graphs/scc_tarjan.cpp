#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
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
void dfs_tarjan(ll u,vvi &graph,vi &disc,vi &low,vb &instack,stack<ll> &stk){
    static ll timer=0;
    disc[u]=low[u]=timer++;
    instack[u]=true;
    stk.push(u);
    for(auto v:graph[u]){
        if(disc[v]==-1){
            //v is not yet visited
            dfs_tarjan(v,graph,disc,low,instack,stk);
            low[u]=min(low[u],low[v]);
        }else{
            //v is visited
            if(instack[v]){
                //u->v is back edge
                low[u]=min(low[u],disc[v]);
            }else{
                //u->v is cross edge
            }
        }
    }
    if(disc[u]==low[u]){
        //u is head of a SCC
        cout<<"SCC : ";
        while(stk.top()!=u){
            cout<<stk.top()+1<<' ';
            instack[stk.top()]=false;
            stk.pop();
        }
        cout<<stk.top()+1<<endl;
        instack[stk.top()]=false;
        stk.pop();
    }
}
void scc_tarjan(vvi &graph){
    ll i,n=graph.size();
    vi disc(n,-1),low(n);
    vb instack(n,false);
    stack<ll> st;
    fo(i,0,n){
        if(disc[i]==-1) dfs_tarjan(i,graph,disc,low,instack,st);
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,m,i,j;
    cin>>n>>m;
    vvi graph(n);
    fo(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--,v--; //if in question nodes are 1-indexed
        graph[u].pbb(v);
    }
    scc_tarjan(graph);
	return 0;
}