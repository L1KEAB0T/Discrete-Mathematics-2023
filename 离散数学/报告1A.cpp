#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits>

int main() {
    int a[4];
    int p = -1, q = -1;
    char s;

tt:
    std::cout << "***************************************\n";
    std::cout << "**                                   **\n";
    std::cout << "**        ��ӭ�����߼��������       **\n";
    std::cout << "**                                   **\n";
    std::cout << "***************************************\n\n";

    std::cout << "������P��ֵ��0��1�����Իس�����: ";
    std::cin >> p;
    while (std::cin.fail() || (p != 0 && p != 1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "P��ֵ������������������: ";
        std::cin >> p;
    }

    std::cout << "������Q��ֵ��0��1�����Իس�����: ";
    std::cin >> q;
    while (std::cin.fail() || (q != 0 && q != 1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Q��ֵ������������������: ";
        std::cin >> q;
    }

    a[0] = p && q;  //������
    a[1] = p || q;  //������
    a[2] = (!p) || q;  //�̺����㣬����ת��Ϊ������ʽ
    a[3] = ((!p) || q) && ((!p) || q);  //��ֵ���㣬����ת��Ϊ������ʽ

    std::cout << "\n\n  ��ȡ:\n       P/\\Q = " << a[0] << "\n";
    std::cout << "  ��ȡ:\n       P\\/Q = " << a[1] << "\n";
    std::cout << "  ����:\n       P->Q = " << a[2] << "\n";
    std::cout << "  ˫����:\n       P<->Q = " << a[3] << "\n";

    std::cout << "\n�Ƿ��������?��y/n��";
bb:
    std::cin >> s;
    if (s == 'y' || s == 'Y') {
        std::cout << std::endl;
        goto tt;
    }
    else if(s=='N'||s=='n') {
        std::cout << "��ӭ�´��ٴ�ʹ��!" << std::endl;
        return 0;
    }
    else {
        std::cout << "�������,����������";
        goto bb;
    }
}