#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define endl '\n'
#define MOD 1000000007//998244353

vi modinvprimelinear(ll m){
    //m must be prime
    vi inv(m);
    inv[1] = 1;
    for(int i = 2; i < m; ++i)
        inv[i] = m - (m/i) * inv[m%i] % m;
    return inv;
}
ll exteuclid(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;//can be anything
        return a;
    }
    ll x1,y1,g;
    g = exteuclid(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}
ll modinv(ll a,ll m){
    ll x,y,g;
    g = exteuclid(a,m,x,y);
    if(g!=1){
        cout<<"Mod inv do not exist"<<endl;
        return -1;
    }else{
        x = (x%m + m)%m;
        return x;
    }
}
ll power(ll a,ll n,ll m){
    //a is int, n>=0 and int, m>0 is int
    if(n==0) return 1;
    a%=m;
    ll ans = power(a,n/2,m);
    ans = (ans*ans)%m;
    if(n%2==1) ans=(ans*a)%m;
    return ans;
}
ll modinvprime(ll a,ll p){
    //p is prime && gcd(a,p)=1
    return power(a,p-2,p);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll a,m,x;
    cin>>a>>m;
    // a*x=1 (mod m),find x
    cout<<modinv(a,m)<<endl;
    //a^(m-2)=a^(-1)  (mod m), m->prime
    cout<<modinvprime(a,m)<<endl;
	return 0;
}