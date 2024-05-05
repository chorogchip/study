#include <bits/stdc++.h>


constexpr static int CSH_SZ = 64;
constexpr static int CSH_LIN = 4;
constexpr static int CSH_SET = 32;

int cache[CSH_SET][CSH_LIN];
int cache_miss = 0;

int MAT_SZ = 64;

bool fetch(int address)
{
    int address_beg = address / CSH_SZ;
    int set_num = address_beg % CSH_SET;
    for (int i = 0; i < CSH_LIN; ++i)
    {
        if (cache[set_num][i] == address_beg)
        {
            std::swap(cache[set_num][0], cache[set_num][i]);
            return false;
        }
    }
    for (int i = CSH_LIN - 1; i > 0; --i)
    {
        cache[set_num][i] = cache[set_num][i - 1];
    }
    cache[set_num][0] = address_beg;
    ++cache_miss;
    printf("%3d %3d ", set_num, address_beg);
    return true;
}

void use_mem(int x, int y)
{
    if (fetch((x * MAT_SZ + y) * sizeof(double)))
        printf("%2d %2d\n", x, y);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "put 1 element\n";
        exit(1);
    }
    MAT_SZ = atoi(argv[1]);

    memset(cache, -1, sizeof(cache));
    for (int r = 1; r < MAT_SZ; ++r)
        for (int c = 0; c < r; ++c)
            use_mem(r, c),
            use_mem(c, r);
    std::cout << "cache miss : " << cache_miss;
}