#include <iostream>
#include "ex2.h"

int main() {
    char text[256];
    char result[512]; // Вместо объявления двух массивов для слов достаточно одного для результата

    std::cout << "Введите строку: ";
    std::cin.getline(text, 256);

    appendWordLengths(text, result);
    std::cout << "Преобразованная строка: " << result << std::endl;

    return 0;
}
