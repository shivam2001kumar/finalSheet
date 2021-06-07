// GFG Solution
// class Solution
// {
//     public:
//     set<vector<int> > m;
//     //Function to find all possible unique subsets.
//     vector<vector<int> > AllSubsets(vector<int> nums, int n)
//     {
//         // code here 
//         vector<vector<int> > allSubset;
//         sort(nums.begin(),nums.end());
//         int comb=(1<<(nums.size()));
//         for(int i=0;i<comb;i++) //for 2^n combinations
//         {
//             vector<int>subset;    
//             for(int j=0;j<nums.size();j++) // run for n bits
//             {
                
//                 if((i&(1<<j)) !=0) 
//                     subset.push_back(nums[j]);
//             }
//             if(m.find(subset)==m.end())
//             {
//                 allSubset.push_back(subset);
//                 m.insert(subset);
//             }
//         }
//         sort(allSubset.begin(),allSubset.end());
//         // due to this below line time exceeded error occurs
//         //allSubset.erase(unique(allSubset.begin(),allSubset.end()),allSubset.end());
        
//         return allSubset;
//     }
// };

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int> > ans;
    int subsetNum=(1<<n);
    for(int i=0;i<subsetNum;i++)
    {
        vector<int>temp;
        for(int j=0;j<n;j++)
        {
            if((i&(1<<j)) !=0)
            {
                temp.push_back(arr[j]);
            }
        }
        ans.push_back(temp);
    }

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
