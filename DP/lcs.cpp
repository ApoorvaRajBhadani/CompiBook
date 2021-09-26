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

ll lcsrm_helper(ll i,ll j,string &s,string &t,vector<vector<ll>> &dp){
    if(i>=s.size()) return 0;
    if(j>=t.size()) return 0;
    if(dp[i][j]>=0) return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]=1+lcsrm_helper(i+1,j+1,s,t,dp);
    }else{
        return dp[i][j]=max(lcsrm_helper(i+1,j,s,t,dp),lcsrm_helper(i,j+1,s,t,dp));
    }
}
ll lcsrm(string s,string t){
    //Recursion with memoisation time=O(n*m) space=O(n*m + (n+m))
    vector<vector<ll>> dp(s.size()+1,vector<ll>(t.size()+1,-1));
    return lcsrm_helper(0,0,s,t,dp);
}

ll lcs2d(string s,string t){
    //tabulation time=O(n*m) space=O(n*m)
    ll n=s.size(),m=t.size(),i,j;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    for(i=n;i>=0;i--){
        for(j=m;j>=0;j--){
            if(i==n || j==m) dp[i][j]=0;
            else if(s[i]==t[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}

string lcs_string(string s,string t){
    //tabulation time=O(n*m) space=O(n*m)
    ll n=s.size(),m=t.size(),i,j;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    for(i=n;i>=0;i--){
        for(j=m;j>=0;j--){
            if(i==n || j==m) dp[i][j]=0;
            else if(s[i]==t[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
    ll len = dp[0][0],idx=0;
    string ans;
    i=0,j=0;
    while(i<n && j<m){
        if(s[i]==t[j]){
            ans.pbb(s[i]);
            i++;j++;
        }else{
            if(dp[i+1][j]>dp[i][j+1]){
                i++;
            }else{
                j++;
            }
        }
    }
    return ans;
}

ll lcs(string s,string t){
    //tabulation memory optimised time=O(n*m) space=O(min(n,m))
    ll n=s.size(),m=t.size(),i,j;
    if(m>n){
        swap(s,t);swap(n,m);
    }
    vector<ll> dp(m+1);
    for(i=n;i>=0;i--){
        ll h,p;//p stores previous value of dp[j+1]
        for(j=m;j>=0;j--){
            h=dp[j];
            if(i==n || j==m) dp[j]=0;
            else if(s[i]==t[j]) dp[j]=1+p;
            else dp[j] = max(dp[j],dp[j+1]);
            p=h;
        }
    }
    return dp[0];
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;
    cout<<lcs2d(s,t)<<endl;
    cout<<lcsrm(s,t)<<endl;
    cout<<lcs_string(s,t)<<endl;
}