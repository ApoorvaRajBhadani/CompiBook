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

const ll MAXN = 10000,INF=1e9;
ll graph[MAXN+5][MAXN+5];
void prims(){
    //Dense graph
    //time-O(n^2) space-O(n^2)
    ll n,m,i,j,mstw=0;
    cin>>n>>m;
    mset(graph,-1);
    fo(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;//input is 1-based we store 0-based
        graph[u][v]=graph[v][u]=w;
    }
    vi par(n),val(n,INF);
    vb vis(n,false);
    par[0]=-1;
    val[0]=0;
    fo(i,0,n){
        ll u=-1;
        for(j=0;j<n;j++){
            if(!vis[j] && (u==-1||val[j]<val[u]) ) u=j;
        }
        mstw+=val[u];
        vis[u]=true;
        for(j=0;j<n;j++){
            if(graph[u][j]!=-1 && !vis[j] && graph[u][j]<val[j]){
                val[j]=graph[u][j];
                par[j]=u;
            }  
        }
    }
    cout<<mstw<<endl;
    fo(i,1,n){
        cout<<i+1<<' '<<par[i]+1<<endl;
    }
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	prims();
	return 0;
}