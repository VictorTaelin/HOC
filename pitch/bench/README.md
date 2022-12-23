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
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
```

Command:

```
gcc -O3 main.c -o main_c
time ./main_c
```

## Haskell (GHC)

Version:

```
The Glorious Glasgow Haskell Compilation System, version 8.6.5
```

Command:

```
ghc -O3 main.hs -o main_hs
time ./main_hs
```

## JavaScript (V8)

Version:

```
v10.19.0
```

Command:

```
node main.js
```

## Kind (HVM)

Version:

```
hvm 1.0.19-beta
```

Command:

```
hvm compile main.hvm
cd main
cargo run --release -t NUMBER_OF_THREADS
```

// these were tested in a EPYC 7571. reason: amazon limits were in 48cores (96 vcpus) at the time.

// actual 64 core (128vcpu) benchmark will be made as soon as amazon increases the vcpu limit (1 hour ~ 2 days)

# Results

Runtime | Run time
------- | --------
GCC     | 25.356s 
GHC     | 7.338s
V8      | 16.110s
HVM-1   | 31.559s
HVM-8   | 12.41s
HVM-16  | 9.88s
HVM-24  | 9.11s
HVM-32  | 8.66s
HVM-40  | 8.35s
HVM-48  | 8.10s
HVM-56  | 8.09s
HVM-64  | 5.84s
