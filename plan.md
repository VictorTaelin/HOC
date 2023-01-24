The Higher Order Company: Roadmap
=================================

Up to 2022: Research and Prototype
----------------------------------

After decades of researching a new model of computation, the [Interaction
Net](https://www.semanticscholar.org/paper/Interaction-Combinators-Lafont/6cfe09aa6e5da6ce98077b7a048cb1badd78cc76),
and after a several engineering breakthroughs, Taelin, in 2022, developed the
prototype for HVM, the first massively parallel runtime in the world. In our
benchmarks, HVM has shown its ability to scale in performance horizontally with
cores. That is, by computing high-level primitives like lambdas,
pattern-matching and recursion in parallel, HVM can greatly speed up existing
programs, by using all the available cores in modern processors. Compared to GCC
(for C-language), V8 (for JavaScript) and GHC (for Haskell), in an unfavorable
benchmark, HVM outperforms all of them in a CPU with 4 or more cores:

![hvm_benchmark](hvm_benchmark.png)

2023: Seed Round and Build Applications
---------------------------------------

Now, in 2023, we are executing a Seed Round to found and incorporate the Higher
Order Company. Once this is done, we will hire a team of developers to turn this
exciting technology into 3 user-facing applications that can reach a much wider
audience: ThreadBender, Kind and Kindelia.

### ThreadBender

Since around 2006, processors are getting increasingly more parallel - AMD's next
ThreadRipper CPU has 96 cores - yet, software isn't catching up with that trend.
Most programming languages in use today are still single-threaded by default.
While some of them offer features capable of parallelizing software, doing so is
extremely hard and expensive, due to the overwhelming complexity of concurrent
synchronization and hard-to-debug non-deterministic behaviors.

Thanks to HVM's powerful parallelization primitives - beta-reduction,
pattern-matching, equational rewrites - ThreadBender is capable of transpiling
high-level languages such as Python, JavaScript and Go to HVM, allowing
developers to run existing code in dozens of cores. As processors become more
parallel, the pressure to parallelize software gets bigger. The programming
industry is due to a revolution on how we write code. By being as simple as
Python and as parallel as CUDA, ThreadBender has everything it takes to lead
this revolution.

### Kind

Mathematicians won't check proofs manually forever. There is a growing body of
mathematicians attemtping to [digitalize
mathematics](https://www.youtube.com/watch?v=Dp-mQ3HxgDE) right now. In a
future, all major theorems and proofs will be available in a giantic ecosystem
of proofs that you can import, modify and check automatically, just like package
managers of programming like JavaScript's npm or Rust's cargo.

For that to happen, we need something: a proof checker. All stablished proof
checkers (Coq, Lean, Agda, Idris) are extremely slow and have a sub-par UI/UX.
Thanks to HVM, we can proudly claim Kind is, by far, the [fastest proof
checker](https://github.com/kindelia/functional-benchmarks) in the world today.
It is not the **best** though: it is still missing important features, including
a package manager, a totality checker, tactics, among others. We will make
Kind-Lang the best proof-checker in the world. Once we do, we will be in a
privileged position to dominate this market, that will be huge in the future.

### Kindelia

The blockchain space is in dire need for a peer-to-peer computer that just
works. Layer 1 networks such as Ethereum, Cardano and Solana bought many
innovations to the field, but, from the end-user perspective, are still
underwhelming in several aspects: scalability, security, UX, as well as
economical and political centralization - all of which are important for
widespread adoption. It is hard to name a layer 1 that could be part of Linux's
kernel one day. Kindelia will be that.

Thanks to HVM, Kindelia's computate and space throughput can be 500x higher than
Ethereum, making it capable of hosting massive, real-time online worlds; and,
no, that's not relying on layer 2, increased centralization, or complex crypto
that greatly impact UX. Moreover, its contracts have their security backed by
mathematical proofs, making it the most trustworthy home for these assets.
These, combined with other design choices that abide to HoC's standard of
quality, make Kindelia the most efficient and secure layer 1 in the world. We
believe it has everything it takes to become the Bitcoin of peer-to-peer
computers, and the home of the massive metaverses of the future.

2024: Adoption and Business
---------------------------

On its current state, HVM is an advanced tool that can only be used by
experienced functional developers: it wasn't built with adoption in mind.
Despite that, it already reached 5.6k stars on GitHub - more than widely popular
projects, like Cardano. Once we build applications that apply to a much wider
audience: ThreadBender, for developers; Kind, for mathematicians; Kindelia, for
crypto enthusiasts - then, we'll be able to reach a much wider audience and be
widely recognized as a competent company capable of shipping groundbreaking
technology. Once we've stablished a respected name in the market, we will be in
a much stronger position to research ways to profit from our products.

Team
====

Title    | Project    | Skills         | Function                | Person 
-------- | ---------- | -------------- | ----------------------- | ------ 
CEO      | HoC        | Many           | Lead                    | Sipher 
CTO      | HoC        | Many           | Lead                    | Taelin 
Sr. Dev  | HVM        | Coq            | Correctness             | ?
Sr. Dev  | HVM        | Rust           | JIT Compiler            | ?
Sr. Dev  | HVM        | Rust           | Low-Level Optimizations | ?
Sr. Dev  | Thd.Bender | Haskell        | JS-HVM Transpiler       | ?
Mid Dev  | Thd.Bender | Haskell        | JS-HVM Transpiler       | Nicolas
Mid Dev  | Thd.Bender | Haskell        | JS-HVM Transpiler       | Santi 
Sr. Dev  | Kindelia   | Rust           | Networking              | ?
Mid Dev  | Kindelia   | Rust           | Tooling                 | Rheidner?
Mid Dev  | Kindelia   | Rust/Haskell   | Protocol                | Derenash?
Sr. Dev  | Kind-Lang  | Type Theory    | Research                | ?
Mid Dev  | Kind-Lang  | Haskell        | Kind Design             | Chiyoku
Mid Dev  | Kind-Lang  | Haskell        | Kind Package Manager    | Vicky?
Jr. Dev  | Kind-Lang  | Haskell        | ChatGPT + Wikind        | Sávio?
Jr. Dev  | Kind-Lang  | Haskell        | ChatGPT + Wikind        | Bonatto?
Sr. Dev  | TheHOC.com | Web Full-Stack | Landing Pages           | ?
Designer | TheHOC.com | UI / UX        | Landing Pages           | ?
Attorney | Legal      |                | Incorporation, Patents  | ?
