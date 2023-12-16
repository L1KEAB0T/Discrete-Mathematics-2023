#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 模板类定义二叉树节点
template <typename T, size_t N>
struct TreeNode {
    T num;           // 节点值
    TreeNode* Lnode;  // 左子树指针
    TreeNode* Rnode;  // 右子树指针

    // 构造函数初始化节点
    TreeNode(T value) : num(value), Lnode(nullptr), Rnode(nullptr) {}
};

// 初始化节点数组
template <typename T, size_t N>
void initNode(vector<TreeNode<T, N>*>& fp, const T f[]) {
    for (size_t i = 0; i < N; i++) {
        TreeNode<T, N>* pt = new TreeNode<T, N>(f[i]);
        fp[i] = pt;
    }
}

// 冒泡排序，用于构建哈夫曼树
template <typename T, size_t N>
void sort(vector<TreeNode<T, N>*>& array, size_t n) {
    for (size_t i = N - n; i < N - 1; i++) {
        if (array[i]->num > array[i + 1]->num) {
            swap(array[i], array[i + 1]);
        }
    }
}

// 构建哈夫曼树
template <typename T, size_t N>
TreeNode<T, N>* constructTree(vector<TreeNode<T, N>*>& fp) {
    for (size_t i = 1; i < N; i++) {
        TreeNode<T, N>* pt = new TreeNode<T, N>(0);
        pt->num = fp[i - 1]->num + fp[i]->num;
        pt->Lnode = fp[i - 1];
        pt->Rnode = fp[i];
        fp[i] = pt;
        sort(fp, N - i);
    }
    return fp[N - 1];
}

// 前序遍历二叉树，输出哈夫曼编码
template <typename T, size_t N>
void preorder(TreeNode<T, N>* p, size_t k, char c) {
    static char s[2 * N];
    if (p != nullptr) {
        if (c == '1') {
            s[k] = '0';
        }
        else {
            s[k] = '1';
        }
        if (p->Lnode == nullptr) {
            cout << p->num << ": ";
            for (size_t j = 0; j <= k; j++) {
                cout << s[j];
            }
            cout << endl;
        }
        preorder(p->Lnode, k + 1, '1');
        preorder(p->Rnode, k + 1, 'r');
    }
}

int main() {
    const size_t N = 13;
    int n;
    cout << "请输入节点个数(必须是正整数):";
    cin >> n;

    int f[N];
    cout << "请输入节点(以空格分隔):";
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<TreeNode<int, N>*> fp(N); // 保存结点
    initNode(fp, f);

    TreeNode<int, N>* head = constructTree(fp);

    preorder(head, 0, '1');

    return 0;
}
