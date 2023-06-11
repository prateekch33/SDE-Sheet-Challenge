#include <bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
  // Write your code here
  vector<set<int>> adj(vertex);
  for (auto i : edges) {
    adj[i.first].insert(i.second);
    adj[i.second].insert(i.first);
  }
  vector<bool> visited(vertex, false);
  vector<int> ans;
  for (int i = 0; i < vertex; i++) {
    if (visited[i])
      continue;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      if (visited[node])
        continue;
      visited[node] = true;
      ans.push_back(node);
      for (auto j : adj[node]) {
        if (!visited[j]) {
          q.push(j);
        }
      }
    }
  }
  return ans;
}