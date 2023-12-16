#include <iostream>
#include <vector>

void output(const std::vector<std::vector<int>>& s);
void zifan(std::vector<std::vector<int>>& s2);
void duichen(std::vector<std::vector<int>>& s2);
void chuandi(std::vector<std::vector<int>>& s2);
void select();
void exitProgram();

int n, d;
std::vector<std::vector<int>> s;

int main() {
    select();
    return 0;
}

void select() {
    std::cout << "请输入矩阵的行数:";
    std::cin >> n;
    std::cout << "请输入矩阵的列数:";
    std::cin >> d;

    // 输入矩阵
    std::cout << "请输入关系矩阵:\n";
    s.resize(n, std::vector<int>(d));

    for (int i = 0; i < n; i++) {
        std::cout << "请输入矩阵的第" << i + 1 << "行元素(元素以空格分隔):";
        for (int j = 0; j < d; j++)
            std::cin >> s[i][j];
    }

    int choice;
    std::cout << "输入对应序号选择算法\n1:自反闭包\n2:传递闭包\n3:对称闭包\n4:退出\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            zifan(s);
            break;
        case 2:
            chuandi(s);
            break;
        case 3:
            duichen(s);
            break;
        case 4:
            exitProgram();
            break;
    }
}

void output(const std::vector<std::vector<int>>& s) {
    std::cout << "所求关系矩阵为:\n";
    for (const auto& row : s) {
        for (int element : row)
            std::cout << element;

        std::cout << "\n";
    }
}

void zifan(std::vector<std::vector<int>>& s2) {
    for (int i = 0; i < n; i++)
        s2[i][i] = 1;
    output(s2);
    select();
}

void duichen(std::vector<std::vector<int>>& s2) {
    std::vector<std::vector<int>> s1(d, std::vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++)
            s1[j][i] = s2[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++) {
            s2[i][j] = s2[i][j] + s1[i][j];
            if (s2[i][j] > 1)
                s2[i][j] = 1;
        }

    output(s2);
    select();
}

void chuandi(std::vector<std::vector<int>>& s2) {
    std::vector<std::vector<int>> m(n, std::vector<int>(d)), a(n, std::vector<int>(d));
    std::vector<std::vector<int>> t(n, std::vector<int>(d));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++) {
            a[i][j] = 0;
            t[i][j] = s2[i][j];
            m[i][j] = s2[i][j];
        }

    for (int h = 0; h < n; h++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < d; j++)
                if (m[i][j] == 1) {
                    for (int k = 0; k < n; k++)
                        if (s2[j][k] == 1)
                            a[i][k] = 1;
                }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < d; j++) {
                m[i][j] = a[i][j];
                t[i][j] += a[i][j];
                a[i][j] = 0;
                if (t[i][j] > 1)
                    t[i][j] = 1;
            }
    }

    output(t);
    select();
}

void exitProgram() {
    exit(0);
}
