#include <iostream>
#include <vector>

using namespace std;

const int N = 13;

struct TreeNode {
    int num;
    TreeNode* Lnode;
    TreeNode* Rnode;

    TreeNode(int value) : num(value), Lnode(nullptr), Rnode(nullptr) {}
};

vector<TreeNode*> fp(N); // 保存结点
char s[2 * N];          // 放前缀码

void initNode(int f[], int n) {
    for (int i = 0; i < n; i++) {
        TreeNode* pt = new TreeNode(f[i]);
        fp[i] = pt;
    }
}

void sort(vector<TreeNode*>& array, int n) {
    for (int i = N - n; i < N - 1; i++) {
        if (array[i]->num > array[i + 1]->num) {
            swap(array[i], array[i + 1]);
        }
    }
}

TreeNode* constructTree(int f[], int n) {
    for (int i = 1; i < N; i++) {
        TreeNode* pt = new TreeNode(0);
        pt->num = fp[i - 1]->num + fp[i]->num;
        pt->Lnode = fp[i - 1];
        pt->Rnode = fp[i];
        fp[i] = pt;
        sort(fp, N - i);
    }
    return fp[N - 1];
}

void preorder(TreeNode* p, int k, char c) {
    if (p != nullptr) {
        if (c == '1') {
            s[k] = '0';
        }
        else {
            s[k] = '1';
        }
        if (p->Lnode == nullptr) {
            cout << p->num << ": ";
            for (int j = 0; j <= k; j++) {
                cout << s[j];
            }
            cout << endl;
        }
        preorder(p->Lnode, k + 1, '1');
        preorder(p->Rnode, k + 1, 'r');
    }
}

int main() {
    int n;
    cout << "请输入节点个数(必须是正整数):";
    cin >> n;

    int f[80];
    cout << "请输入节点(以空格分隔):";
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    TreeNode* head;
    initNode(f, N);
    head = constructTree(f, N);

    s[0] = 0;
    preorder(head, 0, '1');

    return 0;
}
