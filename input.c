#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int get_int(const char *prompt) {

    char input[100];
    char *endptr;
    long value;

    while (1) {

        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 0;
        }

        value = strtol(input, &endptr, 10);

        if (endptr == input) {
            printf("Ungültige Eingabe.\n");
            continue;
        }

        if (*endptr != '\n' && *endptr != '\0') {
            printf("Ungültige Eingabe.\n");
            continue;
        }

        if (value < 0) {
            printf("Ungültige Eingabe.\n");
            continue;
        }

        return (int)value;
    }
}

void get_string(const char *prompt, char *buffer, size_t size) {

    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    if (strchr(buffer, '\n') != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
}
