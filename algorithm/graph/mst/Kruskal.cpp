// 給定最多100個節點以內的無向圖，每個節點編號由0開始編號，且節點編號皆不相同，每個邊的權重為正整數，相同起點與終點的邊只有一個，請找出最小生成樹的邊權重和。
// https://sites.google.com/site/zsgititit/home/jin-jiec-cheng-shi-she-ji-2/zui-xiao-sheng-cheng-shu
// edge 由權重小排到大
// parent記錄節點的上一層節點編號，有相同根節點的節點編號，表示同一個集合
// !!!若parent上的值不同，表示兩端點不在同一個集合內，加入此邊不會形成循環!!!
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class disjointset {
  public:
    disjointset(int);
    int find(int);
    void merge(int, int);
    bool equivalence(int, int);

  private:
    vector<int> parent;
};

disjointset::disjointset(int n) {
    parent = vector<int>(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}
int disjointset::find(int x) {
    // return x == parent[x] ? x : (parent[x] = find(parent[x]));
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}
void disjointset::merge(int x, int y) { parent[find(x)] = find(y); }
bool disjointset::equivalence(int x, int y) { return find(x) == find(y); }

struct edge {
    int to, from; //邊的2個端點
    int w;        // weight
    edge(int from, int to, int w) {
        this->from = from;
        this->to = to;
        this->w = w;
    }
};
bool cmp(const edge& e1, const edge& e2) { return e1.w < e2.w; }

vector<edge> kruskal(int n, vector<edge> edges) {
    disjointset ds(n);
    sort(edges.begin(), edges.end(), cmp);
    vector<edge> mst;
    for (int i = 0; i < edges.size(); i++) {
        edge e = edges[i];
        if (!ds.equivalence(e.from, e.to)) {
            ds.merge(e.from, e.to);
            mst.push_back(e);
        }
    }
    return mst;
}
int main() {
    // build
    int n = 4; // number of nodes
    vector<edge> edges;
    edges.push_back(edge(0, 1, 2));
    edges.push_back(edge(0, 2, 3));
    edges.push_back(edge(1, 2, 1));
    edges.push_back(edge(1, 3, 1));
    edges.push_back(edge(2, 3, 2));
    vector<edge> mst = kruskal(n, edges);
    // all edges in mst
    for (int i = 0; i < mst.size(); i++) {
        cout << "from: " << mst[i].from << " to: " << mst[i].to
             << " weight: " << mst[i].w << endl;
    }
    return 0;
}