#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define endl '\n'
#define MOD 1000000007//998244353

ll gcd_exteuclid_rec(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;//can be any real number
        return a;
    }
    ll x1,y1,g;
    g=gcd_exteuclid_rec(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}
ll gcd_exteuclid(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    ll a,b,x,y,g;
    cin>>a>>b;
    g=gcd_exteuclid_rec(a,b,x,y);
    // a*x + b*y = g = gcd(a,b)
    cout<<"x="<<x<<" y="<<y<<" g="<<g<<endl;
    g=gcd_exteuclid(a,b,x,y);
    // a*x + b*y = g = gcd(a,b)
    cout<<"x="<<x<<" y="<<y<<" g="<<g<<endl;
	return 0;
}