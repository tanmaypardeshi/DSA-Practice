// Write a program to do a depth first search over a graph
#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

void print_raw(unordered_map<int, vector<int>>&);
void dfs(int, unordered_map<int, vector<int>>&, vector<int>&);

int main() {
    int n, source;
    unordered_map<int, vector<int>> graph;
    
    cout<<"Enter the value of n:- ";
    cin>>n;

    vector<int> visited(n, 0);
    
    for(int i = 0; i < n; i++) {
        int temp, temp_n;
        vector<int> temp_arr;
        cout<<"Enter vertex "<<i+1<<":- ";
        cin>>temp;
        cout<<"Enter the number of edges for "<<temp<<":- ";
        cin>>temp_n;
        for(int j = 0; j < temp_n; j++) {
            int temp_arr_num;
            cout<<"Enter connection "<<j + 1<<":- ";
            cin>>temp_arr_num;
            temp_arr.push_back(temp_arr_num);
        }
        graph.insert({temp, temp_arr});
    }
    
    // print_raw(graph);

    cout<<"Enter the source vertex:- ";
    cin>>source;

    if(graph.find(source) == graph.end()) {
        cout<<source<<" is not a vertex in the graph"<<endl;
        return 0;
    }

    dfs(source, graph, visited);
    cout<<endl;

    return 0;
}

void print_raw(unordered_map<int, vector<int>>& graph) {
    for(const auto& g: graph) {
        cout<<"Vertex: "<<g.first;
        cout<<", Edges: ";
        for(const auto& e: g.second) {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}

void dfs(int node, unordered_map<int, vector<int>>& graph, vector<int>& visited) {
    stack<int> dfs_stack;

	dfs_stack.push(node);

	while(!dfs_stack.empty()) {
		int node = dfs_stack.top();
		dfs_stack.pop();

		if(visited[node] == 1) {
			continue;
		}

		visited[node] = 1;
		cout<<node<<" ";

		for(const auto & v: graph[node]) {
			if(visited[v] == 0) {
				dfs_stack.push(v);
			}
			
		}
	}
}