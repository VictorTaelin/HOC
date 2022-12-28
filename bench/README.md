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

Runtime | Run time
------- | --------
GCC     | TODO 
GHC     | TODO
V8      | TODO
HVM-1   | TODO
HVM-8   | TODO
HVM-16  | TODO
HVM-24  | TODO
HVM-32  | TODO
HVM-40  | TODO
HVM-48  | TODO
HVM-56  | TODO
HVM-64  | TODO
