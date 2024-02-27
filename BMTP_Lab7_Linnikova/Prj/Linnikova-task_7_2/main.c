#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // Ініціалізація масиву та змінних
    char*locale=setlocale(LC_ALL,"");
    system ("chcp1251&cls");
    double numbers[30];
    int i;
    double sum_positive = 0;
    int count_positive = 0;

    // Ввід масиву
    printf("Введіть 30 дійсних чисел:\n");
    for (i = 0; i < 30; i++) {
        scanf("%lf", &numbers[i]);

        // Обчислення суми та кількості додатніх чисел
        if (numbers[i] > 0) {
            sum_positive += numbers[i];
            count_positive++;
        }
    }

    // Пошук найбільшого та найменшого елементів
    double max = numbers[0];
    double min = numbers[0];

    for (i = 1; i < 30; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    // Обчислення середнього арифметичного додатніх елементів
    double average_positive = count_positive > 0 ? sum_positive / count_positive : 0;

    // Зміна місцями перших та останніх 15 елементів масиву
    for (i = 0; i < 15; i++) {
        double temp = numbers[i];
        numbers[i] = numbers[30 - 15 + i];
        numbers[30 - 15 + i] = temp;
    }

    // Виведення результатів
    printf("\nНайбільший елемент: %lf\n", max);
    printf("Найменший елемент: %lf\n", min);
    printf("Середнє арифметичне додатніх елементів: %lf\n", average_positive);

    printf("\nМасив змінений місцями:\n");
    for (i = 0; i < 30; i++) {
        printf("%lf ", numbers[i]);
    }

    return 0;
}
