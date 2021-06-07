#include<bits/stdc++.h>
using namespace std;

void nsr(int right[],int arr[],int n)
{
    right[n-1]=n;
    // cout<<right[n-1];
    stack<int>s;
    s.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(s.size()>0 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        
        if(s.size()==0)
        {
            right[i]=n;
        }
        else right[i]=s.top();
        s.push(i);
    }
}
void nsl(int left[],int arr[],int n)
{
    left[0]=-1;
    stack<int>s;
    s.push(0);
    for(int i=1;i<n;i++)
    {
        while(s.size()>0 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        
        if(s.size()==0)
        {
            left[i]=-1;
        }
        else left[i]=s.top();
        s.push(i);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int right[n]={0};
    int left[n]={0};
    nsr(right,arr,n); // next smaller index to right
    nsl(left,arr,n); // next smaller index to left
    // for(int i=0;i<n;i++) cout<<left[i]<<" ";
    int temp[n];
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        temp[i]=(right[i]-left[i]-1)*arr[i];
        mx=max(temp[i],mx);
    }
    cout<<mx;
}