#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;


class Graph {
public:   
    Graph() {}


    void addEdge(const string& node1, const string& node2) {
        adjacencyList[node1].push_back(node2);
        adjacencyList[node2].push_back(node1);
    }


    void DFS(const string& startNode) {
        unordered_set<string> visited;
        stack<string> s;

        s.push(startNode);

        while (!s.empty()) {
            string currentNode = s.top();
            s.pop();

            if (visited.find(currentNode) == visited.end()) {
                cout << currentNode << " ";
                visited.insert(currentNode);

                for (const string& neighbor : adjacencyList[currentNode]) {
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }


    void BFS(const string& startNode) {
        unordered_set<string> visited;
        queue<string> q;

        q.push(startNode);

        while (!q.empty()) {
            string currentNode = q.front();
            q.pop();

            if (visited.find(currentNode) == visited.end()) {
                cout << currentNode << " ";
                visited.insert(currentNode);

                for (const string& neighbor : adjacencyList[currentNode]) {
                    if (visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }

private:
    map<string, vector<string>> adjacencyList;
};

int main() {

    Graph mapGraph;


    mapGraph.addEdge("College", "Park");
    mapGraph.addEdge("College", "Library");
    mapGraph.addEdge("Park", "Market");
    mapGraph.addEdge("Library", "Cafe");
    mapGraph.addEdge("Cafe", "Market");


    cout << "DFS starting from College: ";
    mapGraph.DFS("College");


    cout << "BFS starting from College: ";
    mapGraph.BFS("College");

    return 0;
}
