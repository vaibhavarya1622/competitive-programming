#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define sz(x) x.size()
#define FOR(i,a,b) for(int i=a;i<b;++i)

const int maxN = 5e3+5,sigma = 26;
ll sz = 1;
vector<int> adj[maxN];
ll ans[maxN];

//Here fail shows the maximum suffix length, as in KMP
struct node{
    int fail, ch[26]={},cnt = 0;
    vector<int> word;
} T[maxN];

void add_string(string& s,int pos){
    int cur = 0;
    for(auto c:s){
        if(!T[cur].ch[c-'a']){
            T[cur].ch[c-'a'] = sz++;
        }
        cur = T[cur].ch[c-'a'];
    }
    T[cur].word.pb(pos);
}

void push_links(){
    queue<ll> Q;
    int cur = 0;
    FOR(c,0,sigma){
        if(T[cur].ch[c]){
            T[T[cur].ch[c]].fail = cur,Q.push(T[cur].ch[c]);
        }
        else{
            T[cur].ch[c] = 0;
        }
    }
    while (!Q.empty()) {
        cur = Q.front(),Q.pop();
        int U = T[cur].fail;
        FOR(c,0,sigma){
            if(T[cur].ch[c]){
                T[T[cur].ch[c]].fail = T[T[cur].fail].ch[c],Q.push(T[cur].ch[c]);
            }
            else{
                T[cur].ch[c] = T[U].ch[c];
            }
        }
    }
    FOR(i,1,sz+1){
        adj[T[i].fail].pb(i);
    }
}

void run(string& txt){
    for(int i=0,cur = 0;i<(int)txt.length();++i){
        cur = T[cur].ch[txt[i]-'a'];
        T[cur].cnt++;
    }
}

int dfs(int u){
    int res = T[u].cnt;
    for(int v:adj[u]){
        res += dfs(v);
    }
    cout<<u<<' '<<res<<'\n';
    for(int w:T[u].word){
        ans[w] = res;
    }
    return res;
}

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    string s;cin>>s;
    int q;cin>>q;
    
    for(int i=0;i<q;++i){
        string t;cin>>t;
        add_string(t,i);
    }       
    push_links();
    run(s);
    dfs(0);
    FOR(i,0,q){
        if(ans[i]) cout<<"YES"<<'\n';
        else cout<<"NO\n";
    }
    // for(int i=0;i<sz;++i){
    //     for(int j=0;j<26;++j)
    //         cout<<to[i][j]<<' ';
    //     cout<<'\n';
    // }
    // cout<<'\n';
    // for(int i=0;i<sz;++i){
    //     if(sz(term[i])) cout<<i<<' ';
    // }
    // cout<<'\n';
    // for(int i=0;i<sz;++i){
    //     cout<<suffix_link[i]<<" ";
    // }
    return 0;
}