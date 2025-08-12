// Write a program to do a breadth first search over a graph

#include<bits/stdc++.h>
using namespace std;

void print_raw(unordered_map<int, vector<int>>&);
void bfs(int, unordered_map<int, vector<int>>&);

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

    bfs(source, graph);

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

void bfs(int source, unordered_map<int, vector<int>>& graph) {
    int vertices = graph.size();
    queue<int> q;
    vector<int> visited(vertices, 0);

    q.push(source);
    visited[source] = 1;

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout<<vertex<<" ";
        for(const auto& v: graph[vertex]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    cout<<endl;
}