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
ll binexp_rec(ll a,ll n){
    //valid for n>=0 and n is int, a is int
    if(n==0) return 1;
    ll ans = binexp_rec(a,n/2);
    ans*=ans;
    if(n%2==1) ans*=a;
    return ans;
}

//Iterative
ll binexp(ll a,ll n){
    //valid for n>=0 and n is int, a is int
    ll ans=1;
    while(n>0){
        if(n&1) ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    ll a,n;
    cin>>a>>n;
    cout<<binexp(a,n)<<endl;
	return 0;
}