#include <stdio.h>

#define DATAS\
    DATA_ARG(APPLE)\
    DATA_ARG(BANANA)\
    DATA_ARG(ORANGE)\
    DATA_ARG(GRAPE)

enum eFruits {
#define DATA_ARG(x) x,
    DATAS
#undef DATA_ARG
};

const char *ToString(eFruits e) {
    switch (e) {
#define DATA_ARG(x) case x: return #x;
    DATAS
    default: return "Null";
#undef DATA_ARG
    }
}

int main() {
    eFruits my_fruit = APPLE;
    puts(ToString(my_fruit));  // APPLE
}