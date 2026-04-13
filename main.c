#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

/* ────────────────────────────────────────────
   1. 순환(반복) 방식  –  O(n)
   ──────────────────────────────────────────── */
long long fibo_iter(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;

    long long f1 = 1, f2 = 1, fn = 0;

    for (int i = 3; i <= n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}

/* ────────────────────────────────────────────
   2. 재귀 방식  –  O(2^n)
   ──────────────────────────────────────────── */
long long fibo_recur(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fibo_recur(n - 1) + fibo_recur(n - 2);
}

/* ────────────────────────────────────────────
   3. 메인 – 프로파일링
   ──────────────────────────────────────────── */
int main() {
    int test_cases[] = { 1, 5, 10, 15, 20, 25, 30, 35, 40, 45 };
    int count = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("%-5s | %-20s | %-16s | %-20s | %-16s\n",
        "N", "반복 결과", "반복 시간(ms)", "재귀 결과", "재귀 시간(ms)");
    printf("------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        int n = test_cases[i];

        /* 반복 시간 측정 */
        clock_t start = clock();
        long long iter_result = fibo_iter(n);
        clock_t end = clock();
        double iter_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

        /* 재귀 시간 측정 */
        start = clock();
        long long recur_result = fibo_recur(n);
        end = clock();
        double recur_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

        printf("%-5d | %-20lld | %-16.4f | %-20lld | %-16.4f\n",
            n, iter_result, iter_ms, recur_result, recur_ms);
    }

    return 0;
}
