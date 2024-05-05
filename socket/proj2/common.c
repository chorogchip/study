#include <stdio.h>

#include "common.h"

char input_buf[65536];

_Bool is_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\0';
}
void get_token(char* buf, int n) {
    int i = 0;
    for (; i < n - 1; ++i) {
        buf[i] = getchar();
        if (is_whitespace(buf[i]))
            break;
    }
    buf[i] = '\0';
}
