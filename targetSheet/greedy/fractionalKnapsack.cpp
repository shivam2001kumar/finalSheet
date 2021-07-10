#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    static bool comp(pair<double,int> a,pair<double,int> b)
    {
        return a.first>b.first;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int> > v;
        for(int i=0;i<n;i++)
        {
            double x=(arr[i].value *1.0)/(arr[i].weight*1.0);
            v.push_back({x,i});
        }
        sort(v.begin(),v.end(),comp);
        double p=0;
        int weightSum=0;
        for(int i=0;i<n;i++)
        {
            if(weightSum+arr[v[i].second].weight < W)
            {
                p+=arr[v[i].second].value;
                weightSum+=arr[v[i].second].weight;
            }
            else
            {
                double val = v[i].first*(W-weightSum);
                p+=val;
                break;
            }
        }
        return p;
    }
        
};
