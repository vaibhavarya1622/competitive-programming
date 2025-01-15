// In this problem, we're asked the minimum number of rooms needed to accommodate
// $n$ customers, who arrive and leave on set days. Let's sort each customer by
// their start time so that we do not have a customer arriving at say, time 3,
// occupying a room before a customer that arrives at time 2.

// Now, we can iterate through the customers while maintaining a minimum priority
// queue that stores the departure times of customers we've already processed. For
// each customer, we check to see if the minimum element in the priority queue is
// less than the arrival time of the new customer.

// If this is true, that means a room previously occupied has opened up, so we
// remove the minimum element from the priority queue and replace it with the new
// customer's departure time. The new customer will be allocated to the same room
// as the customer who departed.
// Otherwise, all the rooms are full, so we need to allocate another room for the
// customer and add it to the priority queue.

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ar array
template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    int n;
    cin>>n;
    vector<int> ans(n);
    oset<ar<int,2>> s;
    vector<ar<int,3>> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i][0]>>a[i][1],a[i][2] = i;
    }
    sort(a.begin(), a.end(),[](const ar<int,3>& x,const ar<int,3>& y){
        return (x[0]<y[0])||(x[0] == y[0] && x[1]<y[1]);
    });
    int rooms = 0;
    for(int i=0;i<n;++i){
        int pos = s.order_of_key({a[i][0],-1});
        pos-=1;
        if(pos<0){
            ++rooms;
            s.insert({a[i][1],rooms});
            ans[a[i][2]] = rooms;
        }
        else{
                auto it = s.find_by_order(pos);
                ans[a[i][2]] = (*it)[1];
                s.erase(it);
                s.insert({a[i][1],ans[a[i][2]]});
        }
    }
    cout<<s.size()<<'\n';
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}