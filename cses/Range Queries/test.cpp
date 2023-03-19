#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int arr[N];
int st[4*N],lazy[4*N];

void build(int si,int ss,int se)
{
    if(ss==se)
        st[si]=arr[ss];
    else
    {
        int mid=(ss+se)/2;
        build(2*si,ss,mid);
        build(2*si+1,mid+1,se);
        st[si]=st[2*si]+st[2*si+1];
    }
}

void propagate(int si,int ss,int se)
{
    if(lazy[si]!=0)
    {
        st[si]+=(se-ss+1)*lazy[si];
        if(ss!=se)
        {
            lazy[2*si]+=lazy[si];
            lazy[2*si+1]+=lazy[si];
        }
        lazy[si]=0;
    }
}

void updateRange(int si,int ss,int se,int us,int ue,int diff)
{
    propagate(si,ss,se);
    if(ss>ue || se<us)
        return;
    if(ss>=us && se<=ue)
    {
        st[si]+=(se-ss+1)*diff;
        if(ss!=se)
        {
            lazy[2*si]+=diff;
            lazy[2*si+1]+=diff;
        }
        return;
    }
    int mid=(ss+se)/2;
    updateRange(2*si,ss,mid,us,ue,diff);
    updateRange(2*si+1,mid+1,se,us,ue,diff);
    
    st[si]=st[2*si]+st[2*si+1];
}

int querySum(int si,int ss,int se,int qs,int qe)
{
    propagate(si,ss,se);
    if(ss>qe || se<qs)
        return 0;
    if(ss>=qs && se<=qe)
        return st[si];
    int mid=(ss+se)/2;
    return querySum(2*si,ss,mid,qs,qe)+querySum(2*si+1,mid+1,se,qs,qe);
}


int main()
{
    int n,q,c,a,b,x;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(1,0,n-1);
    while(q--)
    {
        cin>>c;
        if(c==1)
        {
            cin>>a>>b>>x;
            updateRange(1,0,n-1,a-1,b-1,x);
        }
        else if(c==2)
        {
            cin>>a>>b>>x;
            updateRange(1,0,n-1,a-1,b-1,x-arr[a-1]);
        }
        else if(c==3)
        {
            cin>>a>>b;
            cout<<querySum(1,0,n-1,a-1,b-1)<<endl;
        }
    }

    return 0;
}
