#pragma GCC target("avx2")
#include <immintrin.h>
#include <bits/stdc++.h>

constexpr int N = 128;

int main(void) {
    alignas(32) int psum1[N], psum2[N], psum3[N], arr1[N], arr2[N], arr3[N];

    psum1[0] = psum2[0] = psum3[0] = arr1[0] = arr2[0] = arr3[0] = 0;
    for (int i = 1; i < N; ++i) {
        psum1[i] = psum2[i] = psum3[i] = rand();
        arr1[i] = arr2[i] = arr3[i] = rand();
    }

    for (int i = 1; i < N; ++i) psum1[i] ^= psum1[i - 1];
    for (int i = 1; i < N; ++i) psum1[i] ^= arr1[i];
    for (int i = 1; i < N; ++i) psum1[i] ^= psum1[i - 1];

    int arr_sum = 0;
    int p_sum = 0;
    int pp_sum = 0;
    for (int i = 0; i < N; ++i) {
        arr_sum ^= arr2[i];
        p_sum ^= psum2[i];
        pp_sum ^= p_sum;
        psum2[i] = pp_sum ^ arr_sum;
    }

    __m256i arr_sum_v = _mm256_setzero_si256();
    int p_sum_v = 0;
    int pp_sum_v = 0;
    for (int i = 0; i < N; i += 8) {
        psum2[i + 0] = pp_sum_v ^= p_sum_v ^= psum2[i + 0];
        psum2[i + 1] = pp_sum_v ^= p_sum_v ^= psum2[i + 1];
        psum2[i + 2] = pp_sum_v ^= p_sum_v ^= psum2[i + 2];
        psum2[i + 3] = pp_sum_v ^= p_sum_v ^= psum2[i + 3];
        psum2[i + 4] = pp_sum_v ^= p_sum_v ^= psum2[i + 4];
        psum2[i + 5] = pp_sum_v ^= p_sum_v ^= psum2[i + 5];
        psum2[i + 6] = pp_sum_v ^= p_sum_v ^= psum2[i + 6];
        psum2[i + 7] = pp_sum_v ^= p_sum_v ^= psum2[i + 7];

        __m256i arr_new_v = _mm256_loadu_si256((__m256i*)(arr3 + i));
        __m256i arr_xor_v = _mm256_xor_si256(arr_sum_v, arr_new_v);
        __m256i p_res_v = _mm256_xor_si256(arr_xor_v, _mm256_loadu_si256((__m256i*)(psum3 + i)));
        _mm256_storeu_si256((__m256i*)(psum3 + i), p_res_v);

        __m128i arr_high_4 = _mm256_extracti128_si256(arr_new_v, 1);
        __m128i arr_low_4 = _mm256_castsi256_si128(arr_new_v);
        arr_low_4 = _mm_xor_si128(arr_low_4, arr_high_4);
        
        long long arr_high_2 = _mm_extract_epi64(arr_low_4, 1);
        long long arr_low_2 = _mm_extract_epi64(arr_low_4, 0);

        arr_low_2 ^= arr_high_2;
        arr_low_2 ^= arr_low_2 >> 32;
        
        arr_sum_v = _mm256_xor_si256(arr_sum_v, _mm256_set1_epi32((int)arr_low_2));
    }

    int i;
    for (i = 0; i < N; ++i)
        if (psum1[i] != psum2[i] || psum1[i] != psum3[i])
            goto FAILED;

    puts("succeed");
    return 0;
FAILED:
    printf("failed in %d\n", i);

    for (int j = 0; j <= i; ++j) {
        printf("%10d%10d%10d\n", psum1[j], psum2[j], psum3[j]);
    }
}