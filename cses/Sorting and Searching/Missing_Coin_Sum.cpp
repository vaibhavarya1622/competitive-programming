// At any index i in a sorted array a, currSum represents sum(a[ 0...i ]).
// We can form every possible sum from 1...currSum, when we are at index i. So the next possible smallest sum at index i can be currSum+1.
// We can get currSum+1 as the answer if and only if a[i+1] > currSum + 1, otherwise we would be able to form subsets with sums from 1...(currSum + a[i+1])
// ( just add a[i+1] to all subsets which give sum 1...currSum to get subsets giving sum 1...currSum+a[i+1]).

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll arr[], int n){
    sort(arr,arr+n);
    ll currSum = 0;
    for(int i=0;i<n;++i){
        if(arr[i]>currSum+1)
            return currSum+1;
        currSum += arr[i];
    }
    return currSum + 1;
}
int main(){
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    cout<<solve(arr,n);
}