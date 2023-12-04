#include <iostream>
using namespace std;

// 用结构体来表示二元关系
typedef struct
{
    char a;
    char b;
} BR;

int n, m; // n 表示集合 A 中的元素个数，m 表示二元关系 R 中的元素个数

// 创建集合 A 并初始化
void init_aggregation(char*& A)
{
    cout << "请输入集合 A 中的元素个数(正整数)，按回车键输入下一项：" << endl;
    cin >> n;
    A = new char[n];
    cout << "请依次输入集合 A 中的";
    cout << n; // n 是集合 A 中的元素个数
    cout << "个元素(形如：a b c d ......这样的格式)，按回车键输入下一项：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

// 创建集合 A 的二元关系 R 的集合并初始化
void init_BinaryRelation(BR*& R)
{
    cout << "请输入二元关系 R 中的元素个数(正整数)，按回车键输入下一项：" << endl;
    cin >> m;
    R = new BR[m];
    cout << "请依次输入 R 中的";
    cout << m; // m 是 R 中的元素个数
    cout << "个元素，一行是一个元素" << endl;
    cout << "(形如：" << endl
        << "a b" << endl;
    cout << "b c" << endl;
    cout << "c d" << endl;
    cout << "......" << endl;
    cout << "这样的格式)，按回车键输入下一项：" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> R[i].a;
        cin >> R[i].b;
    }
}

int fun(char ch, char*& A)
{
    for (int i = 0; i < n; i++)
    {
        if (ch == A[i])
        {
            return i;
        }
    }
    return -1;
}

// Warshall 算法的核心部分
void Warshall(char*& A, BR*& R, bool**& tR)
{
    int i, j, k;
    int x, y;
    // 用关系矩阵表示二元关系 R
    for (i = 0; i < m; i++)
    {
        x = fun(R[i].a, A);
        y = fun(R[i].b, A);
        tR[x][y] = 1;
    }
    // 计算传递闭包的过程
    for (i = 0; i < n; i++)
    { // 检索列
        for (j = 0; j < n; j++)
        { // 检索行
            if (tR[j][i] == 1)
            {
                for (k = 0; k < n; k++)
                {
                    tR[j][k] = tR[j][k] + tR[i][k];
                }
            }
        }
    }
}

// 将传递闭包 t(R)的关系矩阵表示转化为集合表示
void translation_output(char*& A, bool**& tR)
{
    cout << endl;
    cout << "R 的传递闭包(集合形式)为：" << endl;
    cout << "t(R) = {";
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (tR[i][j] == 1)
            {
                cout << "<" << A[i] << "," << A[j] << ">";
                if (j != n - 1 || i != n - 1)
                {
                    cout << ",";
                }
            }
        }
    }
    cout << "}" << endl;
}

// 主函数
int main()
{
    char* A;
    init_aggregation(A); // 初始化集合 A
    BR* R;
    init_BinaryRelation(R); // 初始化二元关系
    bool** tR; // 传递闭包矩阵
    // 动态开辟 bool 类型的二维数组
    tR = new bool* [n];
    for (int i = 0; i < n; i++)
    {
        tR[i] = new bool[n * n];
    }
    // 初始化二维数组(全部赋值为 0)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tR[i][j] = 0;
        }
    }
    Warshall(A, R, tR);        // 调用 Warshall 算法函数
    translation_output(A, tR); // 将传递闭包 t(R)的关系矩阵表示转化为集合表示
    return 0;
}
