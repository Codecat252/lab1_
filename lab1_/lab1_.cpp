#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <Windows.h>


int zadanie() {
    int size, sum{};
    printf("Введите размер матрицы: ");
    scanf("%d", &size);


    int** arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        arr[i] = (int*)malloc(size * sizeof(int));
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = rand() % 2;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


  
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < i; j++) {
                    sum += arr[i][j];
                   // if (i == j)
                     //   sum -= arr[i][j];
                }
            }
    
    printf("\n %d Сумма ниже диагонали\n", sum);

    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}



int func1() {
    int mas[10] = { 10, 20, 11, 2, 3, 4, 5, 89, 1, 5 };
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i <= 9; i++) {
        if (mas[i] > max)
            max = mas[i];
        if (mas[i] < min)
            min = mas[i];
    }
    printf("Максимальное /  Минимальное: %d / %d", max, min);
    printf("\n\n");
    return 0;
}


int func2() {
    srand(time(NULL));
    int mas[10];
    for (int i = 0; i < 10; i++) {
        mas[i] = rand() % 100;
        printf(" %d ", mas[i]);
    }
    printf("\n\n");
    return 0;
}

int func3() {
    srand(time(NULL));
    int a;
    printf("Введите мерность массива: ");
    scanf("%d", &a);
    int* arr = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        arr[i] = rand() % 2;
        printf(" %d ", arr[i]);
    }
    free(arr);
    printf("\n\n");
    return 0;
}

int func4() {
    srand(time(NULL));
    int mas[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mas[i][j] = rand() % 100;
            printf(" %d ", mas[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        int sum = mas[i][0] + mas[i][1] + mas[i][2];
        printf("Сумма в строке %d: %d\n", i, sum);
    }
    return 0;
}

struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

int find_student(struct student students[], int size, const char* fam, const char* name, const char* facult, int nomzach) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].famil, fam) == 0 &&
            strcmp(students[i].name, name) == 0 &&
            strcmp(students[i].facult, facult) == 0 &&
            students[i].Nomzach == nomzach) {
            return i;
        }
    }
    return -1;
}
    int func5() {
        struct student stud[3];

        // Заполнение массива студентами
        strcpy(stud[0].famil, "Иванов");
        strcpy(stud[0].name, "Иван");
        strcpy(stud[0].facult, "ФВТ");
        stud[0].Nomzach = 123;

        strcpy(stud[1].famil, "Петров");
        strcpy(stud[1].name, "Пётр");
        strcpy(stud[1].facult, "ФВТ");
        stud[1].Nomzach = 456;

        strcpy(stud[2].famil, "Беглов");
        strcpy(stud[2].name, "Иван");
        strcpy(stud[2].facult, "ФВТ");
        stud[2].Nomzach = 789;

 
        char fam[20], name[20], facult[20];
        int zach;

        printf("Введите фамилию студента: ");
        scanf("%19s", fam);
        printf("Введите имя студента: ");
        scanf("%19s", name);
        printf("Введите название факультета: ");
        scanf("%19s", facult);
        printf("Введите номер зачэтной книжки: ");
        scanf("%d", &zach);

       
        int found_index = find_student(stud, 3, fam, name, facult, zach);

        if (found_index != -1) {
            printf("Студент найден!\n");
            printf("Фамилия: %s\n", stud[found_index].famil);
            printf("Имя: %s\n", stud[found_index].name);
            printf("Факультет: %s\n", stud[found_index].facult);
            printf("Номер зачётной книжки: %d\n", stud[found_index].Nomzach);
        }
        else {
            printf("Студент не найден.\n");
        }

        return 0;
}

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        printf("Выберите функцию:\n");
        printf("1 - Функция 1 (Макс / мин)\n");
        printf("2 - Функция 2 (Массив случайных чисел)\n");
        printf("3 - Функция 3 (Массив любого размера)\n");
        printf("4 - Функция 4 (Сумма в строке)\n");
        printf("5 - Функция 5 (Поиск студента)\n");

        scanf("%d", &choice);  // Чтение целого числа

        switch (choice) {
        case 1:
            func1();
            break;
        case 2:
            func2();
            break;
        case 3:
            func3();
            break;
        case 4:
            func4();
            break;
        case 5:
            func5();
            break;
        case 6:
            zadanie();
            break;
        default:
            printf("Неверный выбор\n");
        }

        printf("Хотите продолжить? (1 - да, 0 - нет)\n");
        scanf("%d", &choice);

    } while (choice == 1);
}

