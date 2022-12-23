Higher Order Company
====================

Fuck slides. I'm launching the pitch-gist.

Problem
=======

Since around 2006, Moore's Law stopped being driven by increased clock speeds,
and is now dominated by increasing core count: **hardware is becoming massively
parallel**. In 2023, Apple will ship a consumer processor with 40 CPU cores.
Sadly, **software has failed to catch up with that trend**. All programming
languages used by the market are single-threaded by default, with optional
parallelism features that are too complex and expensive to be widely adopted.

Solution
========

Leveraging a new model of computation called Intearction Nets, we built the
[HVM](https://github.com/kindelia/), a groundbreaking technology that makes
massive parallelism, on the software side, economically viable. This allows us
to solve problems in different markets of tech industry.

InteraCorp Inc. (temporary name) is a new tech startup launched with the goal
of leveraging HVM in order to build profitable businesses.

Market #1: Parallel Programming
===============================

"Imagine if every developer could instantly make their programs 100x faster?"

- Make parallelism accessible to regular developers

- Applications to big data, software engineering, gamedev, research, etc.

*[Show Mongo's map/reduce, CUDA, OpenCL and similar tech.]*

We will dominate that market by compiling the most popular programming
languages, including Elm, JavaScript, Python and Go to HVM. Developers will be
able to make existing code massively parallel in a single click. In no time,
companies all around the world will be using HVM on their tech stack, greatly
reducing their server costs, while increasing their throughput.

supply chain crunch in mfg, extreme demand growth for compute, skyrocketing energy costs, and breakdown of moore's law
seems you have the perfect storm of tailwinds for embedded HVM nodes at retail, maybe a path into mfg eventually

Market #2: Digitalization of Mathematics
========================================

The formal verification market is huge and has been growing.

*[Show evidence, including: the academic movement / crypto initiatives / gov usage.]*

Sadly the tools used for that purpose are slow, often experimental and not
production ready. On ICI, we built Kind, which is now the fastest proof
assistant in the world.

![](https://github.com/Kindelia/Functional-Benchmarks/raw/master/image/checker_tree_fold_.png)

We will dominate that market by improving Kind from the fastest, to the best
proof assistant in all aspects. We will build a language that mathematicians,
professors and software developers love all alike. We will unify mathematics and
programming in one single ecosystem, and pave way for the complete
digitalization of academic publication.

https://www.youtube.com/watch?v=Dp-mQ3HxgDE&t=2625s

Market #3: Peer-to-Peer computers
=================================

*talk about Kindelia - we all know what goes here*

*important: Kindelia will be no-premine, and will be used to leverage the brand*

Business Model
==============

Once HVM is widely across many fields of the tech industry, ICI will profit by:

- **Licensing:** we'll charge a license for the use of HVM

- **Consulting:** we'll provide services for companies wishing to use HVM

- **Cloud Computing:** we'll charge for the use of HVM chips in our cloud 

Technology
==========

*Show HVM charts vs V8, C, GHC Haskell.*

*Show academic and industry interest.*

Google:
- rentavel: AdSense
- usado:
  - google search engine
  - google chrome
  - google V8

ICorp:
- rentavel: HVM
- usado:
  - kindelia
  - kind-lang
  - HVMCC

Product
=======

- HVM: a massively parallel 

- Kind-Lang: to conquer the academia

- HVMCC: to conquer the software industry

- Kindelia: to conquer the blockchain industry

- HPU: to conquer the hardware industry

- HPU-Cloud: to conquer the cloud computing industry

Current Growth
==============

- HVM: Front Page on Hacker News, 5.5k stars on GitHub

- Kind: Front Page on Hacker News, 2.8k stars on GitHub

- Kindelia: not announced yet, already 400 stars on GitHub

Community keeps growing, even though we didn't release the main products.

Adoption Plan
=============

based on HVMCC, Kind-Lang, Kindelia

[discuss]

Seed Round
==========

We're raising $10m for 20%.

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
