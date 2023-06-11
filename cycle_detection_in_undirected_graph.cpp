#include <bits/stdc++.h>
bool bfs(int src, vector<int> adj[], vector<bool> &vis) {
  queue<pair<int, int>> q;
  q.push({src, -1});
  vis[src] = true;
  while (!q.empty()) {
    int node = q.front().first;
    int parentNode = q.front().second;
    q.pop();
    for (auto i : adj[node]) {
      if (!vis[i]) {
        vis[i] = true;
        q.push({i, node});
      } else if (parentNode != i) {
        return true;
      }
    }
  }
  return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m) {
  // Write your code here.
  vector<int> adj[n + 1];
  for (auto i : edges) {
    adj[i[0]].push_back(i[1]);
    adj[i[1]].push_back(i[0]);
  }
  vector<bool> vis(n + 1, false);
  for(int i=1;i<=n;i++) {
      if(!vis[i]) {
          if(bfs(i,adj,vis)) {
              return "Yes";
          }
      }
  }
  return "No";
}
