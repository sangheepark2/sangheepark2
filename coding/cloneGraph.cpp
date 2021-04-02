/* Clone a Directed Graph */
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
//#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    list<Node*> neighbors;
    Node(int val, list<Node*> ne)
    {
        data = val;
        neighbors = ne;
    }
    Node(int val)
    {
        data = val;
    }
};

void createGraph(int nodes, int edges, vector<Node*> &vertices)
{
    for(int i = 0; i < nodes; i++)
        vertices.push_back(new Node(i, {}));

    vector<pair<int, int>> all_edges;
    for(int i = 0; i < vertices.size(); i++)
    {
        for(int j = i; j < vertices.size(); j++)
        {
            all_edges.push_back(pair<int, int>(i, j));
        }
    }

    random_shuffle(all_edges.begin(), all_edges.end());

    for(int i = 0; i < edges && i < all_edges.size(); i++)
    {
        pair<int, int> edge = all_edges[i];
        vertices[edge.first]->neighbors.push_back(vertices[edge.second]);
        // for un-directional graph, add next line
        //vertices[edge.second]->neighbors.push_back(vertices[edge.first]);
    }
}

void printGraph(Node *node, set<Node*> &visited)
{
    if(node == NULL || visited.find(node) != visited.end())
        return;

    visited.insert(node);

    printf("%d: { ", node->data);
    //for(int i = 0; i < node->neighbors.size(); i++)
    for(auto n : node->neighbors)
        printf("%d ", n->data);
    printf(" }\n");

    for(auto n : node->neighbors)
    {
        printGraph(n, visited);
    }
}

//void printGraph(vector<Node*> &graph)
void printGraph(Node* node)
{
    //unordered_sett<Node*> visited;
    set<Node*> visited;
    printGraph(node, visited);
}

Node* cloneGraph_bfs(Node *node, map<Node*, Node*> &copied)
{
    if(node == NULL)
        return NULL;

    queue<Node*> q;
    Node *newNode = new Node(node->data);
    copied[node] = newNode;
    q.push(node);

    while(!q.empty())
    {
        Node *cur = q.front();
        q.pop();

        for(Node *neighbor : cur->neighbors)
        {
            if(copied.find(neighbor) == copied.end())
            {
                copied[neighbor] = new Node(neighbor->data);
                q.push(neighbor);
            }
            copied[cur]->neighbors.push_back(copied[neighbor]);
        }
    }

    return newNode;
}

Node *cloneGraph_dfs(Node *node, map<Node*, Node*> &copied)
{
    if(node == NULL)
        return NULL;

    if(copied.find(node) == copied.end())
    {
        Node *newNode = new Node(node->data);
        copied[node] = newNode;
        for(auto ne : node->neighbors)
        {
            newNode->neighbors.push_back(cloneGraph_dfs(ne, copied));
        }
    }

    return copied[node];
}

Node *cloneGraph(vector<Node*> &graph)
{
   map<Node*, Node*> copied;
   //return cloneGraph_bfs(graph[0], copied); 
   return cloneGraph_dfs(graph[0], copied); 
}

int main()
{
    printf("Clone a Directed Graph\n");
    vector<Node*> graph;
    createGraph(7, 18, graph);
    printGraph(graph[0]);

    printf("\n=======================\n");
    printGraph(cloneGraph(graph));
    return 0;
}