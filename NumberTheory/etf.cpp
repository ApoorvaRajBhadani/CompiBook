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
ll phi(ll n){//O(sqrt(n))
    ll i,ans=n;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            ans-=ans/i;
        }
    }
    if(n>1){
        ans-=ans/n;
    }
    return ans;
}
const ll MAXN=1000000;
ll etf[MAXN+5];
void sieve(){//O(nloglogn)
    ll i,j;
    for(i=1;i<=MAXN;i++) etf[i]=i;
    for(i=2;i<=MAXN;i++){
        if(etf[i]==i){
            etf[i]=i-1;
            for(j=2*i;j<=MAXN;j+=i){
                etf[j]-=etf[j]/i;
            }
        }
    }
}
void findetf(){//O(nlogn)
    ll i,j;
    for(i=1;i<=MAXN;i++) etf[i]=i;
    for(i=1;i<=MAXN;i++){
        for(j=2*i;j<=MAXN;j+=i){
            etf[j]-=etf[i];
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
    sieve();
    //findetf();
	for(ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		//cout<<phi(i)<<endl;
        cout<<etf[i]<<endl;
	}
	return 0;
}