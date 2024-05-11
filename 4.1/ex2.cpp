#include "ex2.h"

// Вспомогательная функция для преобразования числа в строку
void intToStr(int n, char *str) {
    int i = 0;
    int isNegative = 0;

    // Обработка отрицательных чисел
    if (n < 0) {
        isNegative = 1;
        n = -n;
    }

    // Преобразование числа в строку в обратном порядке
    do {
        str[i++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    // Перевернуть полученную строку
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}

// Функция для добавления длины слов после каждого слова в строке
void appendWordLengths(char *input, char *output) {
    int i = 0, j = 0, wordLength = 0;
    char numStr[11]; // Достаточно для хранения чисел в пределах int

    while (input[i] != '\0') {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
            output[j++] = input[i];
            wordLength++;
        } else {
            if (wordLength > 0) {
                intToStr(wordLength, numStr);
                for (int k = 0; numStr[k] != '\0'; k++) {
                    output[j++] = numStr[k];
                }
                wordLength = 0;
            }
            output[j++] = input[i];
        }
        i++;
    }

    if (wordLength > 0) {
        intToStr(wordLength, numStr);
        for (int k = 0; numStr[k] != '\0'; k++) {
            output[j++] = numStr[k];
        }
    }
    output[j] = '\0';
}
