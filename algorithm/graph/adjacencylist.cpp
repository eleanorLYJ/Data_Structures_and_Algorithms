#include <iostream>
#include <vector>
using namespace std;
// 實現adjacency list
// 另外也可以用vector<vector<int>>去實現

struct node {
    int val, weight;
    node* next;
    node(int val, int weight) {
        this->val = val;
        this->weight = weight;
        this->next = nullptr;
    }
};
class Graph {
  public:
    void add_edge(int, int, int);
    void printGraph();
    Graph(int);

  private:
    vector<node*> adj_list;
    int num_vertex;
};

Graph::Graph(int num_vertex) {
    this->num_vertex = num_vertex;
    this->adj_list = vector<node*>(num_vertex, nullptr);
}

void Graph::add_edge(int src, int dest, int weight) {
    if (adj_list[src] == nullptr) {
        adj_list[src] = new node(dest, weight);
    } else {
        // pointer to the last node
        node* ptr = adj_list[src];
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = new node(dest, weight);
    }
    return;
}

void Graph::printGraph() {
    for (int i = 0; i < num_vertex; i++) {
        node* ptr = adj_list[i];
        cout << "src: " << i << " | ";
        while (ptr) {
            cout << "d: " << ptr->val << " w: " << ptr->weight << " | ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main() {
    // 初始化時須告知有多少節點數
    Graph a(3);
    // vertex0 到 vertex1 其weight為5
    a.add_edge(0, 1, 5);
    // vertex0 到 vertex2 其weight為3
    a.add_edge(0, 2, 3);
    // vertex1 到 vertex2 其weight為2
    a.add_edge(1, 2, 2);
    a.printGraph();
    return 0;
}