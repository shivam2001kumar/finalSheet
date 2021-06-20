#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}
void dfs(vector<pair<int,int>> adj[],bool visited[],int s)
{
    
    visited[s]=true;
    for(auto i:adj[s])
    {
        if(visited[i.first]==false)
        {
            dfs(adj,visited,i.first);
        }
    }
    
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> adj[v];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        addEdge(adj,s,d,w);
    }
    int s,d;
    cin>>s>>d;
    bool visited[v];
    memset(visited,false,sizeof(visited));
    int count=0;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            dfs(adj,visited,i);
            count++;
        }
        
    }
    if(count==1)
    cout<<"true";
    else cout<<"false";
    return 0;
}