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
    std::cout << "**        欢迎进入逻辑运算程序       **\n";
    std::cout << "**                                   **\n";
    std::cout << "***************************************\n\n";

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

    a[0] = p && q;  //与运算
    a[1] = p || q;  //或运算
    a[2] = (!p) || q;  //蕴含运算，将其转化为与或非形式
    a[3] = ((!p) || q) && ((!p) || q);  //等值运算，将其转化为与或非形式

    std::cout << "\n\n  合取:\n       P/\\Q = " << a[0] << "\n";
    std::cout << "  析取:\n       P\\/Q = " << a[1] << "\n";
    std::cout << "  条件:\n       P->Q = " << a[2] << "\n";
    std::cout << "  双条件:\n       P<->Q = " << a[3] << "\n";

    std::cout << "\n是否继续运算?（y/n）";
bb:
    std::cin >> s;
    if (s == 'y' || s == 'Y') {
        std::cout << std::endl;
        goto tt;
    }
    else if(s=='N'||s=='n') {
        std::cout << "欢迎下次再次使用!" << std::endl;
        return 0;
    }
    else {
        std::cout << "输入错误,请重新输入";
        goto bb;
    }
}