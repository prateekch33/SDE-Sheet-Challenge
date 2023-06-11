#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

unordered_map<graphNode*,graphNode*> mp;

graphNode* dfs(graphNode* cur){
	if(mp.find(cur)!=mp.end())
		return mp[cur];
	graphNode* clone=new graphNode(cur->data);
	mp[cur]=clone;
	for(auto i:cur->neighbours) {
		clone->neighbours.push_back(dfs(i));
	}
	return clone;
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	graphNode* cur=new graphNode(node->data);
	if(node==NULL) {
		return NULL;
	}
	if(node->neighbours.size()==0) return cur;
	return dfs(node);
}