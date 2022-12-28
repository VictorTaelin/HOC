HVM Pitch Benchmark
===================

This demo benchmark performs parallel radix sort using immutable trees on 4
languages/runtimes. It stress-tests a runtime's performance regarding immutable
datatype allocation, pattern-matching and recursion, and it also highlights
HVM's ability to parallelize recursive algorithms without annotations, which is
not a feature offered by classic runtimes. The tests were performed on a (TODO)
processor. The algorithms used are identical, the files are available on this
directory, and the commands to replicate these results are shown below. This
isn't a cherry-picked example: similar results are observed for a wide class of
different problems and algorithms, including map-reduce, fourier transform,
graph search, n-body and so on. A more extensive suite is on development.

## C (Clang)

Version:

```
Apple clang version 14.0.0 (clang-1400.0.29.102)
```

Command:

```
gcc -O3 main.c -o main_c
time ./main_c
```

## Haskell (GHC)

Version:

```
The Glorious Glasgow Haskell Compilation System, version 8.10.7
```

Command:

```
ghc -O3 main.hs -o main_hs
time ./main_hs
```

## JavaScript (V8)

Version:

```
v17.4.0
```

Command:

```
time node main.js
```

## Kind (HVM)

Version:

```
hvm 1.0.20-beta
```

Command:

```
hvm compile main.hvm
cd main
time cargo run --release -- run -s 134217728 -t NUMBER_OF_THREADS
```

# Results

Runtime | AMD Ryzen 9 5900X | Apple M1 Max
------- | ----------------- | ------------
GCC     | 15.035            | 20.030
GHC     | 3.164             | 3.153
V8      | 5.794             | 7.588
HVM-1   | 9.851             | 9.690
HVM-2   | 5.928             | 5.528
HVM-4   | 3.274             | 3.057
HVM-6   | 2.347             | 2.207
HVM-8   | 1.754             | 1.807
HVM-10  | 1.475             | -
HVM-12  | 1.299             | -
