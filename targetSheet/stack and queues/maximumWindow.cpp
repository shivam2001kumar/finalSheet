// maximum of al subarray of size k
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void nextGreater(ll arr[],ll ngr[],ll n)
{
    stack<ll>s;
    s.push(n-1);
    ngr[n-1]=n;
    for(ll i=n-2;i>=0;i--)
    {
        while(s.size()>0 and arr[s.top()]<=arr[i])
            s.pop();
        if(s.size()==0)
            ngr[i]=n;
        else ngr[i]=s.top();
        s.push(i);
    }
}
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++) cin>>arr[i];
    ll k;
    cin>>k;
    ll ngr[n];
    nextGreater(arr,ngr,n);
    int j=0;
    for(ll i=0;i<=n-k;i++)
    {
        if(j<i) j=i;
        while(ngr[j]<(i+k))
        {
            j=ngr[j];
        }
        cout<<arr[j]<<"\n";
    }
    return 0;
}