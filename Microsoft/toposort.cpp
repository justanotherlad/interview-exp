/*1 -> {2,3}
2 -> {4,5}
3 -> {4,5}
4 -> {5}
5- > {}
 
Topological :
1 2  3 4 5*/

#include<bits/stdc++.h>

using namespace std;

void toposort(int src, stack<int> &s, vector<vector<int>> adj, vector<bool> &visited){
	visited[src] = true;

	for(int node:adj[src]){
		if(!visited[node]){
			toposort(node,s,adj,visited);
		}
	}
	s.push(src);
}

int main(){

	vector<vector<int>> adj;

	vector<bool> visited(adj.size(),0);

	stack<int> s;

	for(int i=0;i<adj.size();i++){
		if(!visited[i])
			toposort(i,s,adj,visited);
	}

	vector <int> ans;

	while(!s.empty()){
		int top = s.top();
		ans.push_back(top);
		s.pop();
	}

	for(int x:ans)
			cout<<x<<" ";
	cout<<'\n';

}


