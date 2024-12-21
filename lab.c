#include "lab.h"
#include <string.h>

void replace_text(char *line, const char *old_text, const char *new_text) {
    char buffer[1024];
    char *pos;

    while ((pos = strstr(line, old_text)) != NULL) {
        // Копируем всё до найденного текста в buffer
        strncpy(buffer, line, pos - line);
        buffer[pos - line] = '\0';

        // Добавляем новый текст
        strcat(buffer, new_text);

        // Добавляем оставшуюся часть строки
        strcat(buffer, pos + strlen(old_text));

        // Копируем в исходную строку
        strcpy(line, buffer);
    }
}
