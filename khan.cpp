#include <iostream>

#include <vector>

using namespace std;

// Structure to store an edge of a graph
struct Edge{
    int from, to;
};

// A class that represents a graph
class Graph{
public:
    // Each element of an adjacency list contains a node and every other node it points to.
    vector<vector<int>> adjacencyList;

    // To store indegree of a node
    vector<int> indegree;

    // Constructing a graph
    Graph(vector<Edge> const &Edges, int allNodes){

        // Resizing the vector to hold all nodes
        adjacencyList.resize(allNodes);

        // Initializing indegree of all nodes to zero
        indegree.assign(allNodes, 0);

        // Adding directed edges to the graph start node-->end node
        for (auto &edge : Edges){

            // Adding an edge from start node to end node
            adjacencyList[edge.from].push_back(edge.to);
            // Incrementing in-degree of end node by 1
            indegree[edge.to]++;
        }
    }
};

bool topologicalSort(Graph const &inputGraph, vector<int> &sorted, int allNodes){

    vector<int> indegree = inputGraph.indegree;

    // Storing all the nodes with no incoming edges
    vector<int> zeroIndegreeNodes;

    for (int i = 0; i < allNodes; i++){
        if (indegree[i] == 0){
            zeroIndegreeNodes.push_back(i);
        }
    }
    while (!zeroIndegreeNodes.empty()){
        // Deleting fromNode from zeroIndegreeNodes
        int fromNode = zeroIndegreeNodes.back();
        zeroIndegreeNodes.pop_back();

        // Pushing fromNode into sorted
        sorted.push_back(fromNode);
        for (int toNode : inputGraph.adjacencyList[fromNode]){
            // Deleting from the graph the edge from fromNode to toNode
            indegree[toNode] -= 1;
            // If the updated in-degree of toNode is now zero, inserting toNode into zeroIndegreeNodes
            if (indegree[toNode] == 0){
                zeroIndegreeNodes.push_back(toNode);
            }
        }
    }

    // A cycle was encountered if the sorting is done for all zero in-degree nodes in the loop above, but not all input nodes have been sorted
    if ((int)sorted.size() != allNodes){
        return false;
    }
    return true;
}

int main(){
    // Count of all the nodes in the graph
    int allNodes = 9;
    // All the edges of the graph
    vector<Edge> edges ={{1, 4}, {1, 2}, {4, 2}, {4, 3}, {3, 2}, {5, 2}, {3, 5}, {8, 2}, {8, 6}};

    // A vector to store elements in the sorted order
    vector<int> sorted;

    // Building a graph, given the number of nodes and all it edges
    Graph inputGraph(edges, allNodes);

    // Topological sorting. Printing the topologically sorted order if one exists.
    if (topologicalSort(inputGraph, sorted, allNodes)){
        for (int i; i < (int)sorted.size(); i++){
            cout << sorted[i] << " "  << endl;
        }
    }
    else{
        cout << "Sandro fails." << endl;
    }
    return 0;
}