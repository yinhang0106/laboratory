Running /home/ubuntu/dev/laboratory/build/profiler/test_benchmark
Run on (20 X 3494.4 MHz CPU s)
CPU Caches:
L1 Data 48 KiB (x10)
L1 Instruction 32 KiB (x10)
L2 Unified 2048 KiB (x10)
L3 Unified 24576 KiB (x1)
Load Average: 0.30, 0.19, 0.11
***WARNING*** Library was built as DEBUG. Timings may be affected.


-O0
---------------------------------------------------------------
Benchmark                     Time             CPU   Iterations
---------------------------------------------------------------
BM_IndexTraversal       2415155 ns      2415109 ns          244
BM_RangeTraversal       5484577 ns      5484589 ns          109
BM_IteratorTraversal   14135187 ns     14131321 ns           48
BM_PointerTraversal     1809913 ns      1809917 ns          386

-O1
---------------------------------------------------------------
Benchmark                     Time             CPU   Iterations
---------------------------------------------------------------
BM_IndexTraversal        213486 ns       213484 ns         3162
BM_RangeTraversal        202825 ns       202667 ns         3445
BM_IteratorTraversal     202467 ns       202237 ns         3453
BM_PointerTraversal      202544 ns       202544 ns         3444

-O2
---------------------------------------------------------------
Benchmark                     Time             CPU   Iterations
---------------------------------------------------------------
BM_IndexTraversal        208519 ns       208327 ns         3065
BM_RangeTraversal        203064 ns       203004 ns         3445
BM_IteratorTraversal     202421 ns       202421 ns         3464
BM_PointerTraversal      201561 ns       201561 ns         3429

-O3
---------------------------------------------------------------
Benchmark                     Time             CPU   Iterations
---------------------------------------------------------------
BM_IndexTraversal         61428 ns        60963 ns        11112
BM_RangeTraversal         59375 ns        59347 ns        11719
BM_IteratorTraversal      58248 ns        58249 ns        12206
BM_PointerTraversal       57666 ns        57666 ns        12571