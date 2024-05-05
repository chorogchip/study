
#include <stdio.h>
#include <stdbool.h>

#define PORT 3490

extern char input_buf[65536];

bool is_whitespace(char c);
void get_token(char* buf, int n);
