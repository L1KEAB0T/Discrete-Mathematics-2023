#include <iostream>
using namespace std;

// �ýṹ������ʾ��Ԫ��ϵ
typedef struct
{
    char a;
    char b;
} BR;

int n, m; // n ��ʾ���� A �е�Ԫ�ظ�����m ��ʾ��Ԫ��ϵ R �е�Ԫ�ظ���

// �������� A ����ʼ��
void init_aggregation(char*& A)
{
    cout << "�����뼯�� A �е�Ԫ�ظ���(������)�����س���������һ�" << endl;
    cin >> n;
    A = new char[n];
    cout << "���������뼯�� A �е�";
    cout << n; // n �Ǽ��� A �е�Ԫ�ظ���
    cout << "��Ԫ��(���磺a b c d ......�����ĸ�ʽ)�����س���������һ�" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

// �������� A �Ķ�Ԫ��ϵ R �ļ��ϲ���ʼ��
void init_BinaryRelation(BR*& R)
{
    cout << "�������Ԫ��ϵ R �е�Ԫ�ظ���(������)�����س���������һ�" << endl;
    cin >> m;
    R = new BR[m];
    cout << "���������� R �е�";
    cout << m; // m �� R �е�Ԫ�ظ���
    cout << "��Ԫ�أ�һ����һ��Ԫ��" << endl;
    cout << "(���磺" << endl
        << "a b" << endl;
    cout << "b c" << endl;
    cout << "c d" << endl;
    cout << "......" << endl;
    cout << "�����ĸ�ʽ)�����س���������һ�" << endl;
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

// Warshall �㷨�ĺ��Ĳ���
void Warshall(char*& A, BR*& R, bool**& tR)
{
    int i, j, k;
    int x, y;
    // �ù�ϵ�����ʾ��Ԫ��ϵ R
    for (i = 0; i < m; i++)
    {
        x = fun(R[i].a, A);
        y = fun(R[i].b, A);
        tR[x][y] = 1;
    }
    // ���㴫�ݱհ��Ĺ���
    for (i = 0; i < n; i++)
    { // ������
        for (j = 0; j < n; j++)
        { // ������
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

// �����ݱհ� t(R)�Ĺ�ϵ�����ʾת��Ϊ���ϱ�ʾ
void translation_output(char*& A, bool**& tR)
{
    cout << endl;
    cout << "R �Ĵ��ݱհ�(������ʽ)Ϊ��" << endl;
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

// ������
int main()
{
    char* A;
    init_aggregation(A); // ��ʼ������ A
    BR* R;
    init_BinaryRelation(R); // ��ʼ����Ԫ��ϵ
    bool** tR; // ���ݱհ�����
    // ��̬���� bool ���͵Ķ�ά����
    tR = new bool* [n];
    for (int i = 0; i < n; i++)
    {
        tR[i] = new bool[n * n];
    }
    // ��ʼ����ά����(ȫ����ֵΪ 0)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tR[i][j] = 0;
        }
    }
    Warshall(A, R, tR);        // ���� Warshall �㷨����
    translation_output(A, tR); // �����ݱհ� t(R)�Ĺ�ϵ�����ʾת��Ϊ���ϱ�ʾ
    return 0;
}
