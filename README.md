Parser for carl data structures
--------------------------------------

This is an [ANTLR](http://www.antlr.org)-based parser which is meant as an extension to [CArL](https://github.com/smtrat/carl).

### Building

To build, first install CArL. Then build carl-parser with

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

### Authors:

Harold Bruintjes
Sebastian Junges
Gereon Kremer
