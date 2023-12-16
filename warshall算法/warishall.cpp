#include <iostream>
#include <vector>

// �ýṹ������ʾ��Ԫ��ϵ
struct BinaryRelation {
    char a;
    char b;
};

void initAggregation(std::vector<char>& A);
void initBinaryRelation(std::vector<BinaryRelation>& R);
int findIndex(char ch, const std::vector<char>& A);
void Warshall(const std::vector<char>& A, const std::vector<BinaryRelation>& R, std::vector<std::vector<bool>>& tR);
void translationOutput(const std::vector<char>& A, const std::vector<std::vector<bool>>& tR);

int main() {
    std::vector<char> A;
    initAggregation(A); // ��ʼ������ A
    std::vector<BinaryRelation> R;
    initBinaryRelation(R); // ��ʼ����Ԫ��ϵ
    std::vector<std::vector<bool>> tR(A.size(), std::vector<bool>(A.size(), false)); // ���ݱհ�����

    Warshall(A, R, tR); // ���� Warshall �㷨����
    translationOutput(A, tR); // �����ݱհ� t(R) �Ĺ�ϵ�����ʾת��Ϊ���ϱ�ʾ

    return 0;
}

void initAggregation(std::vector<char>& A) {
    std::cout << "�����뼯�� A �е�Ԫ�ظ���(������)�����س���������һ�" << std::endl;
    int n;
    std::cin >> n;
    A.resize(n);
    std::cout << "���������뼯�� A �е�" << n << "��Ԫ��(���磺a b c d ......�����ĸ�ʽ)�����س���������һ�" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
}

void initBinaryRelation(std::vector<BinaryRelation>& R) {
    std::cout << "�������Ԫ��ϵ R �е�Ԫ�ظ���(������)�����س���������һ�" << std::endl;
    int m;
    std::cin >> m;
    R.resize(m);
    std::cout << "���������� R �е�" << m << "��Ԫ�أ�һ����һ��Ԫ��" << std::endl;
    std::cout << "(���磺" << std::endl
        << "a b" << std::endl;
    std::cout << "b c" << std::endl;
    std::cout << "c d" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "�����ĸ�ʽ)�����س���������һ�" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cin >> R[i].a;
        std::cin >> R[i].b;
    }
}

int findIndex(char ch, const std::vector<char>& A) {
    for (size_t i = 0; i < A.size(); i++) {
        if (ch == A[i]) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void Warshall(const std::vector<char>& A, const std::vector<BinaryRelation>& R, std::vector<std::vector<bool>>& tR) {
    int x, y;
    // �ù�ϵ�����ʾ��Ԫ��ϵ R
    for (const auto& relation : R) {
        x = findIndex(relation.a, A);
        y = findIndex(relation.b, A);
        tR[x][y] = true;
    }
    // ���㴫�ݱհ��Ĺ���
    for (int i = 0; i < static_cast<int>(A.size()); i++) { // ������
        for (int j = 0; j < static_cast<int>(A.size()); j++) { // ������
            if (tR[j][i]) {
                for (int k = 0; k < static_cast<int>(A.size()); k++) {
                    tR[j][k] = tR[j][k] || tR[i][k];
                }
            }
        }
    }
}

void translationOutput(const std::vector<char>& A, const std::vector<std::vector<bool>>& tR) {
    std::cout << std::endl;
    std::cout << "R �Ĵ��ݱհ�(������ʽ)Ϊ��" << std::endl;
    std::cout << "t(R) = {";
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < A.size(); j++) {
            if (tR[i][j]) {
                std::cout << "<" << A[i] << "," << A[j] << ">";
                if (j != A.size() - 1 || i != A.size() - 1) {
                    std::cout << ",";
                }
            }
        }
    }
    std::cout << "}" << std::endl;
}
