#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // ����������� ������ �� ������
    char*locale=setlocale(LC_ALL,"");
    system ("chcp1251&cls");
    double numbers[30];
    int i;
    double sum_positive = 0;
    int count_positive = 0;

    // ��� ������
    printf("������ 30 ������ �����:\n");
    for (i = 0; i < 30; i++) {
        scanf("%lf", &numbers[i]);

        // ���������� ���� �� ������� ������� �����
        if (numbers[i] > 0) {
            sum_positive += numbers[i];
            count_positive++;
        }
    }

    // ����� ���������� �� ���������� ��������
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

    // ���������� ���������� ������������� ������� ��������
    double average_positive = count_positive > 0 ? sum_positive / count_positive : 0;

    // ���� ������ ������ �� ������� 15 �������� ������
    for (i = 0; i < 15; i++) {
        double temp = numbers[i];
        numbers[i] = numbers[30 - 15 + i];
        numbers[30 - 15 + i] = temp;
    }

    // ��������� ����������
    printf("\n��������� �������: %lf\n", max);
    printf("��������� �������: %lf\n", min);
    printf("������ ����������� ������� ��������: %lf\n", average_positive);

    printf("\n����� ������� ������:\n");
    for (i = 0; i < 30; i++) {
        printf("%lf ", numbers[i]);
    }

    return 0;
}
