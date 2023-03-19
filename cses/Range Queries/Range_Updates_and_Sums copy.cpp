#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

struct node
{
    ll sum;
    ll setAll;
    ll increment;
    bool setAllValid;
    node()
    {
       sum = 0;
       setAllValid = 0;
       increment = 0;
    }
    void Reset()
    {
       setAllValid = increment = 0;
    }
};

class segtree
{
    int range;
    vector<node> tree;
public:
    void build(vector<int>& a)
    {
        range = a.size();
        tree.assign(4*range, node());
        build_recur(a, 0, range-1, 1);
    }
    void build_recur(vector<int>& a, int tl, int tr, int v)
    {
        if(tl>tr) return;
        if(tl == tr){
            tree[v].sum = a[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build_recur(a, tl, tm, 2*v);
        build_recur(a, tm + 1, tr, 2*v + 1);
        tree[v].sum = tree[2*v].sum + tree[2*v + 1].sum;
    }

    void incUpdate_recur(int v, int tl, int tr, int l, int r, int new_val)
    {
        if(l>r) return;
        if(l <= tl && r >= tr)
        {
            tree[v].increment += new_val;
            return;
        }
        applyAggr(v,tl,tr);
        int tm = (tl+tr)/2;
        incUpdate_recur(2*v,tl,tm,l,min(r,tm),new_val);
        incUpdate_recur(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        applyAggr(2*v, tl, tm);
        applyAggr(2*v+1, tm+1, tr);
        tree[v].sum = tree[2*v].sum + tree[2*v+1].sum;
    }

    void incUpdate(int l, int r, int new_val)
    {
        incUpdate_recur(1,0,range-1,l,r,new_val);
    }

    void setUpdate_recur(int v, int tl, int tr, int l, int r, int new_val)
    {
        if(l>r) return;
        if(l <= tl && r >= tr)
        {
            tree[v].setAllValid = 1;
            tree[v].setAll = new_val;
            tree[v].increment = 0;
            return;
        }
        applyAggr(v,tl,tr);
        int tm = (tl+tr)/2;
        setUpdate_recur(2*v,tl,tm,l,min(r,tm),new_val);
        setUpdate_recur(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        applyAggr(2*v, tl, tm);
        applyAggr(2*v+1, tm+1, tr);
        tree[v].sum = tree[2*v].sum + tree[2*v+1].sum;
    }

    void setUpdate(int l, int r, int new_val)
    {
        setUpdate_recur(1,0,range-1,l,r,new_val);
    }

    void compose(int par, int child)
    {
        if(tree[par].setAllValid){
            tree[child].setAllValid = 1;
            tree[child].setAll = tree[par].setAll;
            tree[child].increment = tree[par].increment;
        }
        else tree[child].increment += tree[par].increment;
    }

    void applyAggr(int v, int l, int r)
    {
        if(tree[v].setAllValid)
            tree[v].sum = (r-l+1)*tree[v].setAll;

        tree[v].sum += (r-l+1)*tree[v].increment;

        if(l != r){
            compose(v, 2*v);
            compose(v, 2*v + 1);
        }

        tree[v].Reset();
    }

    ll range_query(int L, int R)
    {
        return range_query_recur(1, 0, range - 1, L, R);
    }

    ll range_query_recur(int v, int tl, int tr, int l, int r)
    {
        if(l>r) return 0;
        applyAggr(v, tl, tr);
        if(l <= tl && r >= tr)
            return tree[v].sum;
        int tm = (tl+tr)/2;
        return range_query_recur(2*v , tl, tm, l, min(r,tm)) + range_query_recur(2*v + 1, tm+1, tr, max(l,tm+1), r);
    }
};

int main() {
   fast_io;
   int n,q;
   cin >> n >> q;

   vector<int> v(n);
   for(int i = 0; i < n; i++)
        cin >> v[i];

   segtree sg;
   sg.build(v);

   while(q--)
   {
        int t;
        cin >> t;
        if(t == 1){
            int a,b,x;
            cin >> a >> b >> x;
            sg.incUpdate(a-1,b-1,x);
        }
        else if(t == 2){
            int a,b,x;
            cin >> a >> b >> x;
            sg.setUpdate(a-1,b-1,x);
        }
        else {
            int a,b;
            cin >> a >> b;
            cout << sg.range_query(a-1,b-1) <<'\n';
        }
   }
   return 0;
}
