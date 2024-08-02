#include <benchmark/benchmark.h>
#include <vector>

#define BASIC_SETUP \
    std::vector<int> arr; \
    arr.resize(1000000);  \
    for (int i = 0; i < arr.size(); i++) { \
        arr[i] = i % 100; \
    }

static void BM_IndexTraversal(benchmark::State &state) {
    BASIC_SETUP
    for (auto _ : state) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        benchmark::DoNotOptimize(sum);
    }
}
BENCHMARK(BM_IndexTraversal);

static void BM_RangeTraversal(benchmark::State &state) {
    BASIC_SETUP
    for (auto _ : state) {
        int sum = 0;
        for (auto const &i: arr) {
            sum += i;
        }
        benchmark::DoNotOptimize(sum);
    }
}
BENCHMARK(BM_RangeTraversal);

static void BM_IteratorTraversal(benchmark::State &state) {
    BASIC_SETUP
    for (auto _ : state) {
        int sum = 0;
        for (auto it = arr.begin(); it != arr.end(); it++) {
            sum += *it;
        }
        benchmark::DoNotOptimize(sum);
    }
}
BENCHMARK(BM_IteratorTraversal);

static void BM_PointerTraversal(benchmark::State &state) {
    BASIC_SETUP
    for (auto _ : state) {
        int sum = 0;
        int *p = arr.data();
        int *end = p + arr.size();
        while (p != end) {
            sum += *p;
            p++;
        }
        benchmark::DoNotOptimize(sum);
    }
}
BENCHMARK(BM_PointerTraversal);

BENCHMARK_MAIN();