#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>

int get_int(const char *prompt);
void get_string(const char *prompt, char *buffer, size_t size);

#endif