#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Graph {
public:
    int vertices;
    vector<pair<T, pair<int, int>>> edges;

    Graph(int vertices) : vertices(vertices) {}

    void addEdge(int u, int v, T weight) {
        edges.push_back({ weight, {u, v} });
    }

    int kruskalMinimumSpanningTree() {
        vector<int> parent(vertices + 1);
        int totalCost = 0;

        // 初始化每个节点的父节点为自己
        for (int i = 1; i <= vertices; i++) {
            parent[i] = i;
        }

        // 将边按权值升序排序
        sort(edges.begin(), edges.end());

        // 遍历每条边，加入最小生成树
        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            T weight = edge.first;

            // 检查加入该边是否形成环
            if (findParent(parent, u) != findParent(parent, v)) {
                // 如果不形成环，则加入最小生成树，并更新父节点
                totalCost += weight;
                unionSets(parent, u, v);
            }
        }

        return totalCost;
    }

private:
    int findParent(vector<int>& parent, int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent, parent[node]);
        }
        return parent[node];
    }

    void unionSets(vector<int>& parent, int u, int v) {
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        parent[rootU] = rootV;
    }
};

int main() {
    int numberOfVertices, numberOfEdges;
    int u, v;
    double weight;

    cout << "请输入图的顶点数和边数（用空格分隔），输入 0 0 退出:\n";

    while (cin >> numberOfVertices >> numberOfEdges) {
        if (numberOfEdges != 0 && numberOfVertices != 0) {
            Graph<double> graph(numberOfVertices);

            cout << "请输入两个边的顶点索引和它们的权值（用空格分隔）:\n";

            while (numberOfEdges--) {
                cin >> u >> v >> weight;
                graph.addEdge(u, v, weight);
            }

            double totalCost = graph.kruskalMinimumSpanningTree();

            cout << "Kruskal算法生成的最小生成树 (MST) 总权值为: " << totalCost << " 万元\n";

            cout << endl;
            cout << "请输入图的顶点数和边数（用空格分隔），输入 0 0 退出:\n";
        }
        else if (numberOfVertices == 0 && numberOfEdges == 0) {
            return 0;
        }
    }

    return 0;
}
