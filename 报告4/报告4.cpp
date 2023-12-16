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

        // ��ʼ��ÿ���ڵ�ĸ��ڵ�Ϊ�Լ�
        for (int i = 1; i <= vertices; i++) {
            parent[i] = i;
        }

        // ���߰�Ȩֵ��������
        sort(edges.begin(), edges.end());

        // ����ÿ���ߣ�������С������
        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            T weight = edge.first;

            // ������ñ��Ƿ��γɻ�
            if (findParent(parent, u) != findParent(parent, v)) {
                // ������γɻ����������С�������������¸��ڵ�
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

    cout << "������ͼ�Ķ������ͱ������ÿո�ָ��������� 0 0 �˳�:\n";

    while (cin >> numberOfVertices >> numberOfEdges) {
        if (numberOfEdges != 0 && numberOfVertices != 0) {
            Graph<double> graph(numberOfVertices);

            cout << "�����������ߵĶ������������ǵ�Ȩֵ���ÿո�ָ���:\n";

            while (numberOfEdges--) {
                cin >> u >> v >> weight;
                graph.addEdge(u, v, weight);
            }

            double totalCost = graph.kruskalMinimumSpanningTree();

            cout << "Kruskal�㷨���ɵ���С������ (MST) ��ȨֵΪ: " << totalCost << " ��Ԫ\n";

            cout << endl;
            cout << "������ͼ�Ķ������ͱ������ÿո�ָ��������� 0 0 �˳�:\n";
        }
        else if (numberOfVertices == 0 && numberOfEdges == 0) {
            return 0;
        }
    }

    return 0;
}
