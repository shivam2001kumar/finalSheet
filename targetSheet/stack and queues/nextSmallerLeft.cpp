#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
         vector<int>nsl;
         nsl.push_back(-1);
         stack<int>s;
         s.push(a[0]);
         for(int i=1;i<n;i++)
         {
             while(s.size()>0 and s.top()>=a[i])
              {  s.pop();
              }
             if(s.size()==0)
                nsl.push_back(-1);
            else nsl.push_back(s.top());
            s.push(a[i]);
         }
         return nsl;
    }
};
