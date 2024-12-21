#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab.h"

void process_file(const char *filename, char **argv, int argc) {
    FILE *file = fopen(filename, "r+"); // Открыть файл для чтения и записи
    if (!file) {
        perror("Ошибка открытия файла");
        exit(1);
    }

    char line[1024];  // Буфер для хранения строк
    while (fgets(line, sizeof(line), file)) {
        // Применяем нужную операцию, например, замену текста
        if (argc > 1 && strcmp(argv[1], "-r") == 0) {
            // Заменить все вхождения старого текста на новый
            replace_text(line, argv[2], argv[3]);
        }
        // Добавьте здесь другие флаги, например, для удаления или добавления текста
        printf("%s", line);  // Выводим строку, для отладки
    }

    // После обработки закрываем файл
    fclose(file);

    // Теперь откроем его снова для записи, чтобы перезаписать с изменениями
    file = fopen(filename, "w"); // Открытие файла для записи
    if (!file) {
        perror("Ошибка открытия файла для записи");
        exit(1);
    }

    // Запишем обработанные данные обратно в файл
    // Для этого можно будет использовать переменную с изменёнными строками
    fprintf(file, "%s", line);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Использование: prog <имя файла> <флаг> <аргументы>\n");
        return 1;
    }

    process_file(argv[1], argv, argc);

    return 0;
}
