/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
list to perform BFS. Use the map of the area around the college as the graph. Identify
the prominent land marks as nodes and perform DFS and BFS on that.*/
#include <iostream>
using namespace std;

#define max 20

class queue {
    int qarr[max];
    int f, r;

public:
    queue() {
        f = r = -1;
    }

    bool empty() {
        return (r == -1);
    }

    void insert(int data) {
        if (empty()) {
            r = f = 0;
            qarr[r] = data;
        } else if (r != max - 1) {
            r = r + 1;
            qarr[r] = data;
        }
    }

    int del() {
        int data = qarr[f];
        if (f == r) {
            f = r = -1;
        } else {
            f = f + 1;
        }
        return data;
    }
};

class graph {
    int arr[max][max];
    int vist[max];
    int no;

public:
    graph() {
        no = 0;
    }

    void getdata();
    void bfs(int startVertex);
};

void graph::getdata() {
    cout << "\nEnter the number of points: ";
    cin >> no;

    cout << "\nEnter the time for travelling\n";
    for (int i = 0; i < no; i++) {
        for (int j = 0; j < no; j++) {
            cout << "\nEnter the time required for " << i << " and " << j << ": ";
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < no; i++) {
        vist[i] = 0;
    }

    bfs(0);
}

void graph::bfs(int startVertex) {
    queue q;
    q.insert(startVertex);
    vist[startVertex] = 1;

    cout << "BFS Traversal starting from vertex " << startVertex << " : ";

    while (!q.empty()) {
        int currentVertex = q.del();
        cout << currentVertex << " ";

        for (int j = 0; j < no; j++) {
            if (arr[currentVertex][j] != 0 && !vist[j]) {
                q.insert(j);
                vist[j] = 1;
            }
        }
    }
    cout << endl;
}

int main() {
    graph g;
    g.getdata();
    return 0;
}
