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
void dijkstra(){
    //O(V^2)
    const ll INF = INT_MAX;
    ll i,j,n,m;
    cin>>n>>m;//no of nodes & no of edges
    vector<vector<pii>> graph(n);
    fo(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;//considering 0 indexed nodes
        //u--;v--;
        graph[u].pbb(mpp(v,w));
        //if undirected use this next statement
        //graph[v].pbb(mpp(u,w));
    }
    vi dist(n,INF),parent(n,-1);
    vb vis(n,false);
    dist[0]=0;//replace dist[0] by dist[src]
    for(ll tt=0;tt<n-1;tt++){
        //select starting vertex
        ll u=-1,distu=INF;
        for(i=0;i<n;i++){
            if(!vis[i] && (u==-1 || dist[i]<distu)){
                u=i;distu=dist[i];
            }
        }
        //visit u
        vis[u]=true;
        //relax all edges of u
        for(auto vn:graph[u]){
            ll v = vn.ff,w=vn.ss;
            if(!vis[v] && (dist[u]+w<dist[v])){
                dist[v] = dist[u]+w;
                parent[v]=u;
            }
        }
    }
    fo(i,0,n) cout<<dist[i]<<' ';cout<<endl;
    //construct SPG using the parent array
}
void dijkstra_set(){
    //O(ElogV)
    const ll INF = INT_MAX;
    ll i,j,n,m;
    cin>>n>>m;//no of nodes & no of edges
    vector<vector<pii>> graph(n);
    fo(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;//considering 0 indexed nodes
        //u--;v--;
        graph[u].pbb(mpp(v,w));
        //if undirected use this next statement
        //graph[v].pbb(mpp(u,w));
    }
    vi dist(n,INF),parent(n,-1);
    vb vis(n,false);
    dist[0]=0;//replace dist[0] by dist[src]
    set<pii> st;
    st.insert(mpp(dist[0],0));//mpp(dist[s],s)
    while(!st.empty()){
        //select starting vertex
        ll u = st.begin()->ss;
        st.erase(st.begin());
        //visit u
        vis[u]=true;
        //relax all edges of u
        for(auto vn:graph[u]){
            ll v = vn.ff,w=vn.ss;
            if(!vis[v] && (dist[u]+w<dist[v])){
                st.erase(mpp(dist[v],v));//if not present will not throw exception so no problem
                dist[v] = dist[u]+w;
                parent[v]=u;
                st.insert(mpp(dist[v],v));
            }
        }
    }
    fo(i,0,n) cout<<dist[i]<<' ';cout<<endl;
    //construct SPG using the parent array
}
void dijkstra_pq(){
    //O(ElogV)
    const ll INF = INT_MAX;
    ll i,j,n,m;
    cin>>n>>m;//no of nodes & no of edges
    vector<vector<pii>> graph(n);
    fo(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;//considering 0 indexed nodes
        //u--;v--;
        graph[u].pbb(mpp(v,w));
        //if undirected use this next statement
        //graph[v].pbb(mpp(u,w));
    }
    vi dist(n,INF),parent(n,-1);
    vb vis(n,false);
    dist[0]=0;//replace dist[0] by dist[src]
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mpp(dist[0],0));//mpp(dist[s],s)
    while(!pq.empty()){
        //select starting vertex
        ll u = pq.top().ss,distu=pq.top().ff;
        pq.pop();
        if(distu!=dist[u]) continue;
        //visit u
        vis[u]=true;
        //relax all edges of u
        for(auto vn:graph[u]){
            ll v = vn.ff,w=vn.ss;
            if(!vis[v] && (dist[u]+w<dist[v])){
                dist[v] = dist[u]+w;
                parent[v]=u;
                pq.push(mpp(dist[v],v));
            }
        }
    }
    fo(i,0,n) cout<<dist[i]<<' ';cout<<endl;
    //construct SPG using the parent array
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    dijkstra();
	return 0;
}