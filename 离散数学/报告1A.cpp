#include <iostream>
#include <limits>

// 逻辑运算函数
void performLogicalOperations(int p, int q);

int main() {
    int p = -1, q = -1;
    char userInput;

    std::cout << "***************************************\n";
    std::cout << "**                                   **\n";
    std::cout << "**        欢迎进入逻辑运算程序       **\n";
    std::cout << "**                                   **\n";
    std::cout << "***************************************\n\n";

    do {
        std::cout << "请输入P的值（0或1），以回车结束: ";
        std::cin >> p;
        while (std::cin.fail() || (p != 0 && p != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "P的值输入有误，请重新输入: ";
            std::cin >> p;
        }

        std::cout << "请输入Q的值（0或1），以回车结束: ";
        std::cin >> q;
        while (std::cin.fail() || (q != 0 && q != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Q的值输入有误，请重新输入: ";
            std::cin >> q;
        }

        performLogicalOperations(p, q);

        std::cout << "\n是否继续运算?（y/n）";
        std::cin >> userInput;
        while (userInput != 'y' && userInput != 'Y' && userInput != 'n' && userInput != 'N') {
            std::cout << "输入错误，请重新输入（y/n）: ";
            std::cin >> userInput;
        }

    } while (userInput == 'y' || userInput == 'Y');

    std::cout << "欢迎下次再次使用!" << std::endl;

    return 0;
}

// 逻辑运算函数
void performLogicalOperations(int p, int q) {
    int conjunction = p && q;         // 与运算
    int disjunction = p || q;         // 或运算
    int implication = (!p) || q;      // 蕴含运算，将其转化为与或非形式
    int biconditional = (!p || q) && (!p || q); // 等值运算，将其转化为与或非形式

    std::cout << "\n\n  合取:\n       P/\\Q = " << conjunction << "\n";
    std::cout << "  析取:\n       P\\/Q = " << disjunction << "\n";
    std::cout << "  条件:\n       P->Q = " << implication << "\n";
    std::cout << "  双条件:\n       P<->Q = " << biconditional << "\n";
}
