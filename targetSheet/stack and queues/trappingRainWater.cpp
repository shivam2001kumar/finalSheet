#include<bits/stdc++.h>
using namespace std;
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int height[], int n){
        // Code here
        
        int maxLeft=0;
        int maxRight=0;
        int l=0,h=n-1;
        int ans=0;
        while(l<=h)
        {
            if(height[l]<=height[h])
            {
                if(height[l]>maxLeft)
                    maxLeft=height[l];
                else
                {
                    ans+=(maxLeft-height[l]);
                }
                l++;
            }
            else
            {
                if(height[h]>maxRight)
                    maxRight=height[h];
                else
                {
                    ans+=(maxRight-height[h]);
                }
                h--;
            }
        }
        return ans;
    }
};