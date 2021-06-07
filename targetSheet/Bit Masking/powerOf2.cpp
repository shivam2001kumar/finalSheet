#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        if(n==0) return false;
        if((n&(n-1))==0) return true; // == has higher precedence than & so enclose bit operation in parenthesis
        return false;
        
    }
};