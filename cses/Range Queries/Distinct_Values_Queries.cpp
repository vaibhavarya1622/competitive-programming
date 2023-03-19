#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
 
struct Node
{
	ll val;
	Node *lchild, *rchild;
	Node():val(0),lchild(nullptr),rchild(nullptr)
	{}
	Node(ll x):val(x),lchild(nullptr),rchild(nullptr)
	{}
};
 
ll N, Q;
vl a;
 
Node* build ( Node* node, ll tl, ll tr)
{
	if ( node == nullptr )
		node = new Node();
 
	if ( tl == tr )
	{
		node -> val = 0;
		return node;
	}
	
	ll tm = (tl + tr) / 2;
	node -> lchild = build ( node -> lchild, tl, tm );
	node -> rchild = build ( node -> rchild, tm + 1, tr );
	node -> val = node -> lchild -> val + node -> rchild -> val;
	return node;
}
 
Node* upd (Node* node,ll tl, ll tr, ll pos, ll new_val)
{
	if ( pos < tl || tr < pos )
		return node;
	if ( tl == tr )
	{
		return new Node(new_val);
	}
	
	ll tm = (tl + tr) / 2;
	Node* tmp = new Node();
	tmp -> lchild = upd (node->lchild,tl,tm,pos,new_val);
	tmp -> rchild = upd (node->rchild,tm+1,tr,pos,new_val);
	tmp -> val = tmp -> lchild -> val + tmp -> rchild -> val;
	return tmp;
}
 
int qry (Node* node, ll tl, ll tr, ll l, ll r)
{
	if ( r < tl || tr < l )
		return 0;
	if ( l <= tl && tr <= r )
		return node -> val;
	
	ll tm = (tl + tr) / 2;
	return qry (node->lchild,tl,tm,l,r) + qry(node->rchild,tm+1,tr,l,r);
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>Q;
	a.resize(N+1);
	for(int i=1;i<=N;i++)
		cin>>a[i];
	
	unordered_map<int,int> freq;
	Node* roots[N+1];
	roots[1] = new Node();
	roots[1] = build (roots[1],1,N);
	roots[1] = upd (roots[1],1,N,1,1);
	freq[a[1]] = 1;
	for ( int i=2;i<=N;i++)
	{
		roots[i] = roots[i-1];
		if (freq.find(a[i]) != freq.end())
			roots[i] = upd(roots[i],1,N,freq[a[i]],0);
		roots[i] = upd(roots[i],1,N,i,1);
		freq[a[i]] = i;
	}
	
	int l, r;
	for (int i=0;i<Q;i++)
	{
		cin>>l>>r;
		cout<<qry(roots[r],1,N,l,r)<<"\n";
	}
	return 0;
}