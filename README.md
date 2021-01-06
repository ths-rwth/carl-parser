Parser for carl data structures
--------------------------------------

This is an [ANTLR](http://www.antlr.org)-based parser which is meant as an extension to [CArL](https://github.com/smtrat/carl).

### Requirements

The parser requires the following tools:
- CArL
- Maven

### Building

To build, first [install CArL](https://smtrat.github.io/carl/). Then build carl-parser with

```bash
mkdir build
cd build
cmake ..
make
```

You can run tests with

```bash
test/carl-parser-test
```

or simply with

```bash
make test
```

### Frequent errors

On MacOSX, there is a known problem with the rpath, which might lead to an error when executing the tests.
The problem can be alleviated by re-running both

```bash
cmake ..
make
```

### Authors:

- Harold Bruintjes
- Sebastian Junges
- Gereon Kremer
