#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define endl '\n'
#define MOD 1000000007//998244353
// if both a & b are zero gcd in not defined(or infinity)
ll gcdrec(ll a,ll b){
    a=abs(a);
    b=abs(b);
    if(b==0) return a;
    else return gcdrec(b,a%b);
}
//binary euclid
// def gcd(a, b, res):
// 2 if a == b:
// 3 return res * a
// 4 elif (a % 2 == 0) and (b % 2 == 0):
// 5 return gcd(a // 2, b // 2, 2 * res)
// 6 elif (a % 2 == 0):
// 7 return gcd(a // 2, b, res)
// 8 elif (b % 2 == 0):
// 9 return gcd(a, b // 2, res)
// 10 elif a > b:
// 11 return gcd(a - b, b, res)
// 12 else:
// 13 return gcd(a, b - a, res)
ll gcd_binary_euclid(ll a,ll b){
    if(a==b){
        return a;
    }else if((a&1)==0 && (b&1)==0){
        return 2*gcd_binary_euclid(a/2,b/2);
    }else if((a&1)==0){
        return gcd_binary_euclid(a/2,b);
    }else if((b&1)==0){
        return gcd_binary_euclid(a,b/2);
    }else if(a>b){
        return gcd_binary_euclid(a-b,b);
    }else return gcd_binary_euclid(a,b-a);
}
ll gcd(ll a,ll b){
    a=abs(a);
    b=abs(b);
    while(b){
        ll temp = b;
        b=a%b;
        a=temp;
    }
    return a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b) * b;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll a,b;
    cin>>a>>b;
    cout<<gcdrec(a,b)<<endl;
    cout<<gcd(a,b)<<endl;
    cout<<gcd(a,b)<<endl;
    cout<<"lcm="<<lcm(a,b)<<endl;
	return 0;
}