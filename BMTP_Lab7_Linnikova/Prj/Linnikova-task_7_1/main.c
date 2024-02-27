#include <stdio.h>
#include <string.h>
#include <locale.h>
int main() {
    char word[50];
    char*locale=setlocale(LC_ALL, "");
    system ("chcp 1251 & cls");
    // Ввід слова від користувача
    printf("Введіть слово, яке закінчується '!' та має не менше 6 літер: ");
    scanf("%s", word);

    // Перевірка чи слово закінчується '!' та має не менше 6 літер
    if (word[strlen(word) - 1] == '!' && strlen(word) >= 6) {
        int count_ko = 0;

        // Підрахунок кількості складів "ко"
        for (int i = 0; i < strlen(word) - 1; i++) {
            if (word[i] == 'к' && word[i + 1] == 'о') {
                count_ko++;
            }
        }

        // Виведення результатів
        if (count_ko > 0) {
            printf("Кількість складів 'ко' у слові: %d\n", count_ko);
        } else {
            // Попарна зміна місцями літер
            for (int i = 0; i < strlen(word) - 1; i += 2) {
                char temp = word[i];
                word[i] = word[i + 1];
                word[i + 1] = temp;
            }
            printf("Слово з попарно зміненими місцями літер: %s\n", word);
        }
    } else {
        printf("Некоректне введення.\n");
    }

    return 0;
}

