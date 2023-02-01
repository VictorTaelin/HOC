HVM Pitch Benchmark
===================

HVM vs traditional runtimes
---------------------------

This demo benchmark performs parallel radix sort using immutable trees on 4
languages/runtimes. It stress-tests a runtime's performance regarding immutable
datatype allocation, pattern-matching and recursion, and it also highlights
HVM's ability to parallelize recursive algorithms without annotations, which is
not a feature offered by classic runtimes. The algorithms used are identical,
the files are available on the [radix_sort](radix_sort) dir, and the commands to
replicate these results are shown below. This isn't a cherry-picked example:
similar results are observed for a wide class of different problems and
algorithms, including map-reduce, fourier transform, graph search, n-body and so
on. A more extensive suite is on development.

### C (Clang)

#### Version:

```
Apple clang version 14.0.0 (clang-1400.0.29.102)
```

#### Command:

```
cd radix_sort
gcc -O3 main.c -o main_c
time ./main_c
```

### Haskell (GHC)

#### Version:

```
The Glorious Glasgow Haskell Compilation System, version 8.10.7
```

#### Command:

```
cd radix_sort
ghc -O3 main.hs -o main_hs
time ./main_hs
```

### JavaScript (V8)

#### Version:

```
v17.4.0
```

#### Command:

```
cd radix_sort
time node main.js
```

### Kind (HVM)

#### Version:

```
hvm 1.0.0
```

#### Command:

```
cd radix_sort
hvm compile main.hvm
cd main
time cargo run --release -- run -s 134217728 -t NUMBER_OF_THREADS
```

Results
-------

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

---

HVM vs blockchain runtimes
--------------------------

We've also compared HVM against blockchain VMs: EVM and Fuel. To stress test
each runtime, we implemented the traditional recursive Fib function in Solidity
(EVM), Sway (FuelVM) and Kind (HVM). We've then compiled to the respective
runtimes and ran it.

### Solidity (EVM)

For Ethereum, we implemented a simple recursive function in Solidity and tested
it on SputnickVM, which, to our knowledge, is the fastest implementation of the
EVM available.

#### Code:

```solidity
function fibonacci(uint n) public constant returns(uint result) {
  if (n <= 1) {
    return n;
  } else {
    return Fibonacci.fibonacci(n - 1) + Fibonacci.fibonacci(n - 2);
  }
}
```

#### Version:

```
TODO
```

#### Command:

```
TODO
```

### Sway (FuelVM)

Sadly, Sway doesn't have recursion, so we can't implement the Fibonacci function
directly. To solve that, we implemented it using a manual stack. Usually, this
actually improves performance, so, shouldn't be a problem. The algorithm and
amount of work is identical.

#### Code:

```rust
fn fib(n: u64) -> u64 {
  let mut stack : Vec<u64> = Vec::new();
  stack.push(n);
  let mut result = 0;
  while true {
    match stack.pop() {
      Option::Some(x) => {
        if x <= 1 {
          result += x;
        } else {
          stack.push(x - 1);
          stack.push(x - 2);
        }
      }
      Option::None => {
        return result;
      }
    }
  }
  return result;
}
```

#### Version:

```
forc 0.33.1
```

#### Command:

```
cd fibonacci/sway
forc test --release --offline
```

### Kind (HVM)

#### Code:

```
(Fib 0) = 0
(Fib 1) = 1
(Fib n) = (+ (Fib (- n 1)) (Fib (- n 2)))
```

#### Version:

```
hvm-1.0.0
```

#### Command:

```
cd fibonacci/kind
hvm compile Fibonacci.hvm
cd Fibonacci
cargo run --release -- run -c
```

Results
-------

  n |  FuelVM |     EVM |      HVM
--- | ------- | ------- | --------
10  |     8ms |  0.15ms | 0.0003ms
11  |    13ms |  0.25ms | 0.0004ms
12  |    21ms |  0.40ms | 0.0007ms
13  |    33ms |  0.66ms | 0.0012ms
14  |    54ms |  1.06ms | 0.0020ms
15  |    86ms |  1.73ms | 0.0033ms
16  |   140ms |  2.79ms | 0.0054ms
17  |   225ms |  4.53ms | 0.0088ms
18  |   365ms |  7.33ms | 0.0143ms
19  |   594ms | 11.86ms | 0.0231ms
... |     ... |     ... |      ...
42  | 10h30m* |  12m40s |     1.4s

* Projected value

Comments: on this test, EVM was 542x slower than the HVM, and FuelVM was 25714x
slower than the HVM, in an Apple M1 Max CPU. To us, it was very strange that
FuelVM performed so poorly, and it is possible that we've used some incorrect
configuration or optimization setting, although we did use the `--release` flag,
and the documentation doesn't seem to specify any other optimization flag. We're
looking into it.
