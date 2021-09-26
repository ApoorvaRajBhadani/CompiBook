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

//Recursive
ll binexpmod(ll a,ll n,ll m){
    //a is int, n>=0 and int, m>0 is int
    if(n==0) return 1;
    a%=m;
    ll ans = binexpmod(a,n/2,m);
    ans = (ans*ans)%m;
    if(n%2==1) ans=(ans*a)%m;
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    ll a,n,m;
    cin>>a>>n>>m;
    cout<<binexpmod(a,n,m)<<endl;
	return 0;
}