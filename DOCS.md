DOCS
====

At this point we have many docs spread through many different places. Eventually
we'll get them all organized. For now, I made this file to point to them.

### HVM

- [HOW.md](https://github.com/HigherOrderCO/HVM/blob/master/guide/HOW.md): great read that explains in simple terms the main insights behind the HVM

- [PARALLELISM.md](https://github.com/HigherOrderCO/HVM/blob/master/guide/PARALLELISM.md): explains how to better exploit HVM's parallelism

- [Interaction Combinators](https://pdf.sciencedirectassets.com/272575/1-s2.0-S0890540100X00600/1-s2.0-S0890540197926432/main.pdf?X-Amz-Security-Token=IQoJb3JpZ2luX2VjEBwaCXVzLWVhc3QtMSJHMEUCIGJXyvH9RUXhmlpNUPVH5dtR6fnNGEVMzYnFU3E0GOa6AiEApU5Tt2Ok1HY%2FMn2JfEXpKbrJmqLJBVWauyuydAL4wc0q1QQIpP%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAFGgwwNTkwMDM1NDY4NjUiDJvS2%2BoODTzpKMqviSqpBF7CNsVOM7pmz2uqsC2qiZGwpjUlPfhFWFoT2CYduLn%2FhPbG8eRp0BD%2BSmizhbqLuPqHVQLN6uOXKpfr6CFfMR0bPotAdOGefkI4vy%2BK2ltl0VyEoFelwpy01XBm0ohMqoMTkrQs%2BFpf78jaJbvyfQ%2BdmT5ZBuhDbn2BiOqo9Mm%2Fe2%2FMpAeKHhuQcAn6c7rtyuBECh7HIVmgNkV2qao54aSUwS2YVofI1ctM%2FCn10WBvU6GZfHCwCW2Rjnb1Z8uWU1MkHsJ0b9LEBiu4u68R9xuCLpWM0ldnN7DVNVzuYTzIi7KEHg7tB62xVnCCDX5f4BJb%2FDAwSk7EFWVMspoGWzSVmMpr6m%2BnWRt384l7jT%2B20fgUa2Y5oS5%2FCLN44k2nOMfd%2FtVNHZC63UK54P6FR2rB49SbZ7pMT1gYx9WVhlm0rmspE7bu2H1QIb%2F6NTgnd6QRGxJMJWz7s17U6smZs%2B0%2F3HUCFsMTh4LLyZqgTrdj8we2q3cOiOkeoPri8SH0g8Krn6FWZBWomBIAWh%2BAEm7BgYiwKYXWzLAkHJkwLUclj4%2BtI5mUbjn%2Bp3zMDx0B4KYdbX85rI16obibnN1ZowmdBryZZf8JPZHc897W1Cx0Z64pBERJvdPPauxyXcofbYCxudQqJrZc7ZJ2FUOzIkjE%2ByZ9G2Vqg4h%2FXkiXLH3dtYB8rJS8bUyEz3a1yhPXDLljA2rFR2YrxjYHrgJyjL1f3PvVKDkKQYYwkdCYnwY6qQGRS%2F8I44JT8OC7nF3w%2B5RtrJC6j9NdliXsjh1lqRUnd7jEDbfGHOKcc5cVMQsfmOGAm1YhcQs4dxlZ8Ku56lN0UgzTxZrrV5H2rXpQ62RuLHa3B5rFXAqGFZOKSxS6KIX5V2UGCJORfoniFX%2FDo3RxVtMMOMxP0xXluU4vNRp%2BbWd8r9cI46rmB%2BToPamoU7glUzpsvkkpNmJ4wJxvO900EhucvO344%2B1b&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20230210T115422Z&X-Amz-SignedHeaders=host&X-Amz-Expires=300&X-Amz-Credential=ASIAQ3PHCVTYZUKRMJGM%2F20230210%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=f6b36b52f15d7a51dd966c62d01e3dee03be9f2929b95036d772fdcd0e237a5a&hash=f06685c5a24a94cd84dbad0c67b5473722c280ea5540dc789a8a002470dc415c&host=68042c943591013ac2b2430a89b270f6af2c76d8dfd086a07176afe7c76c2c61&pii=S0890540197926432&tid=spdf-221c3264-2dd9-42b3-8d95-2cc0fe02e833&sid=e68cb21458a43148a16be1309fe8d20ccb2agxrqa&type=client&tsoh=d3d3LnNjaWVuY2VkaXJlY3QuY29t&ua=1814575f54510f555a5755&rr=7974a651186700e9&cc=br): Lafont's 1997 paper introducing this new model of computation

- [IC.kind2](https://github.com/HigherOrderCO/Wikind/blob/master/IC/_.kind2): the Interaction Calculus, the "optimization" of Interaction Combinators that reduced memory footprint and resulted on HVM

- [memory.rs](https://github.com/HigherOrderCO/HVM/blob/master/src/runtime/base/memory.rs): has a long comment detailing HVM's memory layout

- [Benchmarks](https://github.com/higherorderco/functional-benchmarks): benchmarks comparing languages to HVM and Kind (runtime and checker) - outdated

### Kind

- [Kind Book](https://naoehsavio.github.io/learning/book/index.html): a translation of the classical Software Foundations book to Kind

- [Wikind](https://github.com/HigherOrderCO/Wikind): a vast library of Kind programs and proofs; good place to learn its syntax

### Kindelia

Note: **Kindelia documents are outdated**. Many things should change, including:

1. Kindelia will be a modular execution layer instead of a complete network;

2. We'll use the actual HVM instead of a modified version made just for Kindelia;

3. It will mostly likely have a native token;

4. Some changes on the state manager, async contract messaging, and a few more.

That said, reading these can give you an idea of what is about to come.

- [WHITEPAPER.md](https://github.com/HigherOrderCO/Kindelia/blob/master/WHITEPAPER.md): a short summary of the network, its design and highlights

- [WHITEBOOK.md](https://github.com/HigherOrderCO/Kindelia/blob/master/WHITEBOOK.md): a much longer, detailed overview and spec of the entire protocol

### ThreadBender

No documents yet: ThreadBender is still on the early development stage.

### Higher Order Company

- [ROADMAP](https://github.com/VictorTaelin/HOC/blob/master/ROADMAP.md): a text explaining each project, their goals, and the roadmap

- [Pitch Deck](https://github.com/VictorTaelin/HOC/raw/master/pitch/higher_order_company.pdf): the pitch deck we've presented to potential investors

- [Benchmarks](https://github.com/VictorTaelin/HOC/tree/master/bench): the benchmarks included on the pitch deck specifically
