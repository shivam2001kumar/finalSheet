#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> v;
        int oxor=0;
        for(int i=0;i<nums.size();i++) oxor=(oxor^nums[i]);
        int rsbm= (oxor & -oxor); //-oxor= (2s complement of xor --> (ones complement of xor+1)
        int num1=0,num2=0;
        for(int i=0;i<nums.size();i++)
        {
            if((rsbm & nums[i]) !=0)
            {
                num1=(num1^nums[i]);
            }
            else num2=(num2^nums[i]);
        }
        if(num1<num2)
        {
            v.push_back(num1);
            v.push_back(num2);
        }
        else
        {
            v.push_back(num2);
            v.push_back(num1);
        }
        return v;
    }
};
