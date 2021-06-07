#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        if(intervals.size()<1) return v;
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>v.back()[1]) // no overlapping
            {
                v.push_back(intervals[i]);
            }
            else
            {
                v.back()[1]=max(v.back()[1],intervals[i][1]);
                
            }
        }
        return v;
    }
};