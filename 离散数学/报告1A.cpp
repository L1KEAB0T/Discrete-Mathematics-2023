#include <iostream>
#include <limits>

// �߼����㺯��
void performLogicalOperations(int p, int q);

int main() {
    int p = -1, q = -1;
    char userInput;

    std::cout << "***************************************\n";
    std::cout << "**                                   **\n";
    std::cout << "**        ��ӭ�����߼��������       **\n";
    std::cout << "**                                   **\n";
    std::cout << "***************************************\n\n";

    do {
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

        performLogicalOperations(p, q);

        std::cout << "\n�Ƿ��������?��y/n��";
        std::cin >> userInput;
        while (userInput != 'y' && userInput != 'Y' && userInput != 'n' && userInput != 'N') {
            std::cout << "����������������루y/n��: ";
            std::cin >> userInput;
        }

    } while (userInput == 'y' || userInput == 'Y');

    std::cout << "��ӭ�´��ٴ�ʹ��!" << std::endl;

    return 0;
}

// �߼����㺯��
void performLogicalOperations(int p, int q) {
    int conjunction = p && q;         // ������
    int disjunction = p || q;         // ������
    int implication = (!p) || q;      // �̺����㣬����ת��Ϊ������ʽ
    int biconditional = (!p || q) && (!p || q); // ��ֵ���㣬����ת��Ϊ������ʽ

    std::cout << "\n\n  ��ȡ:\n       P/\\Q = " << conjunction << "\n";
    std::cout << "  ��ȡ:\n       P\\/Q = " << disjunction << "\n";
    std::cout << "  ����:\n       P->Q = " << implication << "\n";
    std::cout << "  ˫����:\n       P<->Q = " << biconditional << "\n";
}
