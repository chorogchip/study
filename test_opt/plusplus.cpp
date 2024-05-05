#include <cstdlib>
#include <cstdio>
#include <chrono>

void __attribute__((noinline)) f1(char *dest, char *str) {
    int count = 0;
    for (int i = 0; str[i]; ++i)
        if ('0' <= str[i] && str[i] <= '9')
        {
            dest[++count] = str[i];
        }
    dest[++count] = '\0';
}
void __attribute__((noinline)) f2(char *dest, char *str) {
    int count = 0;
    for (int i = 0; str[i]; ++i)
        if ('0' <= str[i] && str[i] <= '9')
        {
            dest[count++] = str[i];
        }
    dest[count++] = '\0';
}
void generate_rand_str(char *dest, int n)
{
    for (int i = 0; i < n; ++i) {
        int rand_num = rand() % 11;
        dest[i] = rand_num == 10 ? ' ' : rand_num + '0';
    }
    dest[n - 1] = '\0';
}

int main() {
    char dest1[100001], dest2[100001], str[100000];
    decltype(std::chrono::high_resolution_clock::now()) begin, end;
    decltype(std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()) f1_time = 0, f2_time = 0;
    for (int cnt = 0; cnt < 1000; ++cnt) {

        generate_rand_str(str, sizeof(str));

        begin = std::chrono::high_resolution_clock::now();
        f1(dest1, str);
        end = std::chrono::high_resolution_clock::now();
        f1_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        begin = std::chrono::high_resolution_clock::now();
        f2(dest2, str);
        end = std::chrono::high_resolution_clock::now();
        f2_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

        generate_rand_str(str, sizeof(str));

        begin = std::chrono::high_resolution_clock::now();
        f2(dest1, str);
        end = std::chrono::high_resolution_clock::now();
        f2_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        begin = std::chrono::high_resolution_clock::now();
        f1(dest2, str);
        end = std::chrono::high_resolution_clock::now();
        f1_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }

    printf("%ld %ld", f1_time, f2_time);
}