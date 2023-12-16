#include <iostream>
#include <vector>

// 用结构体来表示二元关系
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
    initAggregation(A); // 初始化集合 A
    std::vector<BinaryRelation> R;
    initBinaryRelation(R); // 初始化二元关系
    std::vector<std::vector<bool>> tR(A.size(), std::vector<bool>(A.size(), false)); // 传递闭包矩阵

    Warshall(A, R, tR); // 调用 Warshall 算法函数
    translationOutput(A, tR); // 将传递闭包 t(R) 的关系矩阵表示转化为集合表示

    return 0;
}

void initAggregation(std::vector<char>& A) {
    std::cout << "请输入集合 A 中的元素个数(正整数)，按回车键输入下一项：" << std::endl;
    int n;
    std::cin >> n;
    A.resize(n);
    std::cout << "请依次输入集合 A 中的" << n << "个元素(形如：a b c d ......这样的格式)，按回车键输入下一项：" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
}

void initBinaryRelation(std::vector<BinaryRelation>& R) {
    std::cout << "请输入二元关系 R 中的元素个数(正整数)，按回车键输入下一项：" << std::endl;
    int m;
    std::cin >> m;
    R.resize(m);
    std::cout << "请依次输入 R 中的" << m << "个元素，一行是一个元素" << std::endl;
    std::cout << "(形如：" << std::endl
        << "a b" << std::endl;
    std::cout << "b c" << std::endl;
    std::cout << "c d" << std::endl;
    std::cout << "......" << std::endl;
    std::cout << "这样的格式)，按回车键输入下一项：" << std::endl;
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
    // 用关系矩阵表示二元关系 R
    for (const auto& relation : R) {
        x = findIndex(relation.a, A);
        y = findIndex(relation.b, A);
        tR[x][y] = true;
    }
    // 计算传递闭包的过程
    for (int i = 0; i < static_cast<int>(A.size()); i++) { // 检索列
        for (int j = 0; j < static_cast<int>(A.size()); j++) { // 检索行
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
    std::cout << "R 的传递闭包(集合形式)为：" << std::endl;
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
