#include<bits/stdc++.h>
using namespace std;
    static bool comp(pair<int,int>a, pair<int,int> b)
    {
        if(a.second==b.second)
        return a.first<b.first;
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int> >v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        int c=1;
        sort(v.begin(),v.end(),comp);
        int i=0,j=1;
        while(j<n)
        {
            if(v[j].first > v[i].second)
            {
                c++;
                i=j;
                j++;
            }
            else j++;
        }
        return c;
    }
