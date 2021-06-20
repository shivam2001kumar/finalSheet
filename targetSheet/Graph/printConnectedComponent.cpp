#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int, int>> adj[], int s, int d, int w)
{
  adj[s].push_back({d, w});
  adj[d].push_back({s, w});
}
void dfs(int s, vector<pair<int, int>> adj[], vector<int>& path, bool visited[])
{

  visited[s] = true;
  path.push_back(s);
  for (auto i : adj[s])
  {
    if (visited[i.first] == false)
    {
      dfs(i.first, adj, path, visited);
    }
  }

}
int main()
{
  int v, e;
  cin >> v >> e;
  vector<pair<int, int>> adj[v];
  for (int i = 0; i < e; i++)
  {
    int s, d, w;
    cin >> s >> d >> w;
    addEdge(adj, s, d, w);
  }

  bool visited[v];
  vector<vector<int >> paths;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < v; i++)
  {
    if (visited[i] == false)
    {
      vector<int>path;
      dfs(i, adj, path, visited);
      paths.push_back(path);
    }
  }
  int n = paths.size();
  cout << "[";
  for (int i = 0; i < paths.size() - 1; i++) {
    cout << "[";
    for (int j = 0; j < paths[i].size() - 1; j++)
      cout << paths[i][j] << ", ";
    cout << paths[i][paths[i].size() - 1] << "], ";
  }
  cout << "[";
  for (int j = 0; j < paths[n - 1].size() - 1; j++)
    cout << paths[n - 1][j] << ", ";
  cout << paths[n - 1][paths[n - 1].size() - 1];

  cout << "]";
  cout << "]";
  return 0;
}