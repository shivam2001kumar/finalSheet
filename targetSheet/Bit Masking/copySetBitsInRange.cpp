// Copy set bits of y in x
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        
        int m1=(r-l+1)==32?(1<<31):(1<<(r-l+1)); // 1<<32 might go out of range so avoid it
        m1=m1-1;
        m1=(m1<<(l-1));
        int m2=(y&m1);
        x=(x|m2);
        return x;
        
    }
};