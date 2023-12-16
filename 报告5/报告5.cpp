#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ģ���ඨ��������ڵ�
template <typename T, size_t N>
struct TreeNode {
    T num;           // �ڵ�ֵ
    TreeNode* Lnode;  // ������ָ��
    TreeNode* Rnode;  // ������ָ��

    // ���캯����ʼ���ڵ�
    TreeNode(T value) : num(value), Lnode(nullptr), Rnode(nullptr) {}
};

// ��ʼ���ڵ�����
template <typename T, size_t N>
void initNode(vector<TreeNode<T, N>*>& fp, const T f[]) {
    for (size_t i = 0; i < N; i++) {
        TreeNode<T, N>* pt = new TreeNode<T, N>(f[i]);
        fp[i] = pt;
    }
}

// ð���������ڹ�����������
template <typename T, size_t N>
void sort(vector<TreeNode<T, N>*>& array, size_t n) {
    for (size_t i = N - n; i < N - 1; i++) {
        if (array[i]->num > array[i + 1]->num) {
            swap(array[i], array[i + 1]);
        }
    }
}

// ������������
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

// ǰ��������������������������
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
    cout << "������ڵ����(������������):";
    cin >> n;

    int f[N];
    cout << "������ڵ�(�Կո�ָ�):";
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<TreeNode<int, N>*> fp(N); // ������
    initNode(fp, f);

    TreeNode<int, N>* head = constructTree(fp);

    preorder(head, 0, '1');

    return 0;
}
