# Collbr

An all-in-one collection of C libraries written completely from scratch, with the goal of eventually not depending on glibc/musl/any other standard C implementations.

## Progress

| Name | Description                               | Phase 1 | Phase 2 | Phase 3 | Phase 4 | Phase 5 |
|------|-------------------------------------------|---------|---------|---------|---------|---------|
| Ctx  | Context detection.                        | Done    | Done    | Done    | Done    | Done    |
| Defs | Primitive type definitions.               | Done    | Done    | Done    | Done    | Done    |
| Io   | File input and output operations.         | Done    | Active  |         |         |         |
| Heap | Dyanmic memory allocation to system heap. | Active  |         |         |         |         |

### Phases

Progress is broken down into 5 distinct phases

#### Phase 1

Implementation is being planned.

#### Phase 2

Implementation has started.

#### Phase 3

Implementation is complete but relies on standard library (i.e. glibc/musl/etc.) headers (stdlib.h, etc.).

#### Phase 4

Implementation is complete but relies on Os specific headers (Windows.h, unistd.h, etc.).

#### Phase 5

Implementation is complete and is compatible with -nostdlib flag.
