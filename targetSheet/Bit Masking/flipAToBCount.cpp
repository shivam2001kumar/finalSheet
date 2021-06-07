#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int flipped = (a^b);
        int count=0;
        while(flipped) // karnigham algo to count set bits
        {
            int rsbm = (flipped & -flipped);
            flipped= (flipped-rsbm);
            count++;
        }
        return count;
        
    }
};