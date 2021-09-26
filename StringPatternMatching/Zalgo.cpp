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

vi getz(string &s){
    ll n=s.size();
    vi z(n);
    if(n==0) return z;
    z[0]=0;
    ll l=0,r=0,i;
    for(i=1;i<n;i++){
        if(i>r){//i outside the l to r range
            //z value is not already stored hence to be calculated
            l=i;r=i;
            while(r<n && s[r]==s[r-l]) r++;
            z[i]=r-l;
            r--;
        }else{//i in the l to r range
            ll k = i-l;
            if(z[k]+i<=r){
                z[i]=z[k];
            }else{
                l=i;
                while(r<n && s[r]==s[r-l]) r++;
                z[i]=r-l;
                r--;
            }
        }
    }
    return z;
}

bool zsearch(string &s,string &p){
    string t = p+'#'+s;
    vi z = getz(t);
    ll lens=s.size(),lenp=p.size(),i;
    bool ans=false;
    for(i=lenp+1;i<t.size();i++){
        if(z[i]==lenp){
            ans=true;
            cout<<i-lenp-1<<endl;//0 indexed
        }
    }
    return ans;
}

int main(){
    string s,p;
    cout<<"Enter the string where pattern is to be searched"<<endl;
    cin>>s;
    cout<<"Enter the pattern to be searched"<<endl;
    cin>>p;
    vi lps = getz(p);
    for(ll i=0;i<p.size();i++){
        cout<<i<<' '<<lps[i]<<endl;
    }
    bool patternFound = zsearch(s,p);
    if(patternFound) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}