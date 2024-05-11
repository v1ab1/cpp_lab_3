#include <iostream>
#include "ex1.h"

int main() {
    char text1[256];
    char text2[256];
    char words1[10][20];
    char words2[10][20];
    int count1 = 0, count2 = 0;

    std::cout << "Введите первое предложение: ";
    std::cin.getline(text1, 256);

    std::cout << "Введите второе предложение: ";
    std::cin.getline(text2, 256);

    splitWords(text1, words1, count1);
    splitWords(text2, words2, count2);

    printCommonWords(words1, count1, words2, count2);

    return 0;
}
