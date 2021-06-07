#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int rsbm= n & -n; // rightmost set bit is 1 rest 0
        return log2(rsbm)+1;
        
    }
};