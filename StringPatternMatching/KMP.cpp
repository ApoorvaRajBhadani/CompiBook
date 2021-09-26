#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;

vi getLPS(string &s){
    ll n=s.size(),i,j;
    vi lps(n);
    if(n==0) return lps;
    lps[0]=0;
    i=0;j=1;
    while(j<n){
        if(s[j]==s[i]){
            lps[j++]=(i++)+1;
        }else{
            if(i!=0) i = lps[i-1];
            else lps[j++]=0;
        }
    }
    return lps;
}
bool kmpsearch(string &s,string &p){
    ll i,j,n,m;
    n=s.size();m=p.size();
    if(m==0) return true;
    vi lps = getLPS(p);
    i=0,j=0;
    bool ans=false;
    while(i<n && j<m){
        if(s[i]==p[j]){
            i++;j++;
        }else{
            if(j!=0) j=lps[j-1];
            else i++;
        }
        if(j==m){
            ans=true;//return true;
            cout<<i-1<<endl;
            j=lps[j-1];
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
    // vi lps = getLPS(p);
    // for(ll i=0;i<p.size();i++){
    //     cout<<i<<' '<<lps[i]<<endl;
    // }
    bool patternFound = kmpsearch(s,p);
    if(patternFound) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}