HVM Pitch Benchmark
===================

This demo benchmark performs parallel radix sort using immutable trees on 4
languages/runtimes. It stress-tests a runtime's performance regarding immutable
datatype allocation, pattern-matching and recursion, and it also highlights
HVM's ability to parallelize recursive algorithms without annotations, which is
not a feature offered by classic runtimes. The tests were performed on a 
Intel(R) Xeon(R) Platinum 8375C CPU @ 2.90GHz processor. 
The algorithms used are identical, the files are available on this
directory, and the commands to replicate these results are shown below. This
isn't a cherry-picked example: similar results are observed for a wide class of
different problems and algorithms, including map-reduce, fourier transform,
graph search, n-body and so on. A more extensive suite is on development.

## C (Clang)

Version:

```
gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
```

Command:

```
gcc -O3 main.c -o main_c
time ./main_c
```

## Haskell (GHC)

Version:

```
The Glorious Glasgow Haskell Compilation System, version 8.8.4
```

Command:

```
ghc -O3 main.hs -o main_hs
time ./main_hs
```

## JavaScript (V8)

Version:

```
v12.22.9
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
cargo run --release -- run -t NUMBER_OF_THREADS -c true "(Main 0)"
```

# Results

Runtime | Run time
------- | --------
GCC     | 15.054s
GHC     | 3.970s
V8      | 9.350s
HVM-1   | 17.23s
HVM-8   | 2.62s
HVM-16  | 1.45s
HVM-24  | 1.21s
HVM-32  | 0.97s
HVM-40  | 0.95s
HVM-48  | 0.94s
HVM-56  | 0.93s
HVM-64  | 0.92s
