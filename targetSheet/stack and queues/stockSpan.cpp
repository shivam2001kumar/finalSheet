#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    void ngl(int arr[],int t[],int n)
    {
        t[0]=-1;
        stack<int>s;
        s.push(0);
        for(int i=1;i<n;i++)
        {
            while(s.size()>0 and arr[s.top()]<=arr[i])
                s.pop();
            if(s.size()==0) t[i]=-1;
            else t[i]=s.top();
            s.push(i);
        }
    }
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       int t[n];
       ngl(price,t,n);
       vector<int>v;
       for(int i=0;i<n;i++)
       {
           v.push_back(i-t[i]);
       }
       return v;
       
    }
};