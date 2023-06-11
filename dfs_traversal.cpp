void dfs(int node, vector<bool> &visited, vector<int> adj[],
         vector<int> &temp) {
  if (visited[node])
    return;
  visited[node] = true;
  temp.push_back(node);
  for (auto i : adj[node]) {
    if (!visited[i]) {
      dfs(i, visited, adj, temp);
    }
  }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
  // Write your code here
  vector<int> adj[V];
  for (auto i : edges) {
    adj[i[0]].push_back(i[1]);
    adj[i[1]].push_back(i[0]);
  }
  vector<bool> visited(V,false);
  vector<vector<int>> ans;
  vector<int> temp;
  for(int i=0;i<V;i++) {
      if(!visited[i]) {
          temp.clear();
          dfs(i,visited,adj,temp);
          ans.push_back(temp);
      }
  }
  return ans;
}