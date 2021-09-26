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
class TrieNode{
    public:
    TrieNode *child[26];
    bool we;//wordEnd?
    TrieNode(){
        memset(child,NULL,sizeof(child));
        we=false;
    }
};
void insert(TrieNode *root,string &s){
    TrieNode *node = root;
    for(ll i=0;i<s.size();i++){
        if(!node->child[s[i]-'a'])
            node->child[s[i]-'a']=new TrieNode();
        node=node->child[s[i]-'a'];
    }
    node->we=true;
}
bool search(TrieNode *root,string &s){
    TrieNode *node = root;
    for(ll i=0;i<s.size();i++){
        if(!node->child[s[i]-'a'])
            return false;
        node=node->child[s[i]-'a'];
    }
    return node->we;
}
int main(){
	TrieNode *root = new TrieNode();
    ll q;
    string s;
    cin>>q;
    while(q--){
        cin>>s;
        insert(root,s);
    }
    cin>>s;
    cout<<(search(root,s)?"Yes":"No")<<endl;
	return 0;
}