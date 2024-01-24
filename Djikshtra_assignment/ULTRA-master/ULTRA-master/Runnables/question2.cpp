#include <bits/stdc++.h>
#include "../Algorithms/Dijkstra/DjikshtraModified.h"
// Include the appropriate header file that contains the Dijkstra's algorithm implementation from the repository

using namespace std;
using namespace std::chrono;

struct Edge {
    int target;
    int weight;
};

int main() {
    // Read the Florida graph from the DIMACS format
    ifstream file("../Helpers/Florida_graph/input.txt"); // Replace with the actual file path
    if (!file.is_open())
    {
        cerr << "Couldn't open the file." << endl;
        return 1;
    }

    unordered_map<int, vector<Edge>> adjacencyList;
    string line;
    int nodes,edges;
    string problemType;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        char type;
        ss >> type;

        if (type == 'c') {
            // Comment line, skip
            continue;
        } else if (type == 'p') {
            // int nodes, edges;
            ss >> problemType >> nodes >> edges;

            // Do something with the number of nodes and edges if needed
        } else if (type == 'a') {
            int u, v, w;
            ss >> u >> v >> w;

            // Store the edge in the adjacency list
            // Note: Adjusting for 1-based to 0-based index if needed
            adjacencyList[u-1].push_back({v-1, w});
        }
    }
    // Initialize graph, this part will depend on how the repository handles graph input
    // Seed for random number generator
    AStar<unordered_map<int, vector<Edge>>> dijkstra(adjacencyList);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, nodes - 1);

    auto start = high_resolution_clock::now();

    for (int i = 0; i < 200; ++i) {
        int source = distr(gen);
        int target = distr(gen);
        
        // Call Dijkstra's algorithm from the repository and store the result
        // You'll need to dig into the repository to know how to call this function
        // Also, consider checking if source != target, if needed
        dijkstra.run(source,target);
        // Print the shortest path and its length if you want to verify the results
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Total runtime in seconds for 200 random Dijkstra: " << duration.count() / 1e6 << endl;

    return 0;
}
