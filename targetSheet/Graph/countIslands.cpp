#include<bits/stdc++.h>
using namespace std;

void dfs(int arr[][1001],bool visited[][1001],int sr,int sc,int m,int n)
{
    if(sr<0 or sr>=m or sc<0 or sc>=n or arr[sr][sc]==1 or visited[sr][sc]==true) return;
    visited[sr][sc]=true;
    dfs(arr,visited,sr+1,sc,m,n);
    dfs(arr,visited,sr-1,sc,m,n);
    dfs(arr,visited,sr,sc+1,m,n);
    dfs(arr,visited,sr,sc-1,m,n);
    
}
int main()
{
    int m,n;
    cin>>m>>n;
    int arr[1001][1001];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    bool visited[1001][1001];
    int count=0;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==false and arr[i][j]==0)
            {
                dfs(arr,visited,i,j,m,n);
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}