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
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd_exteuclid_rec(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
int main(){
    ll a,b,c,x,y,g;
    cin>>a>>b>>c;
    if(find_any_solution(a,b,c,x,y,g)){
        cout<<x<<' '<<y<<endl;
    }else cout<<"No integral solution exists"<<endl;
    //new x = x+k(b/g)
    //new y = y-k(a/g)
    return 0;
}