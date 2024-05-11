#include <iostream>
#include "ex1.h"

bool myIsAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char myToLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

int myStrCmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}


void splitWords(char *text, char words[][20], int &count) {
    count = 0;
    int j = 0;
    bool inWord = false;

    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        if (myIsAlpha(c)) {
            c = myToLower(c);
            if (!inWord) {
                inWord = true;
                j = 0; 
            }
            words[count][j++] = c;
        } else if (inWord) {
            inWord = false;
            words[count][j] = '\0';
            count++;
        }
    }

    if (inWord) {
        words[count][j] = '\0';
        count++;
    }
}


void printCommonWords(char words1[][20], int count1, char words2[][20], int count2) {
    std::cout << "Общие слова: ";
    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (myStrCmp(words1[i], words2[j]) == 0) {
                std::cout << words1[i] << ' ';
                break;
            }
        }
    }
    std::cout << std::endl;
}

