Stack (vanilla C)
===

Implement `stack.c` with the following methods (as defined in `include/stack.h`)

  * create
  * push
  * pop
  * peek
  * length
  * destroy

The underlying implementation may be

  * dynamically-sized array
  * linked-list
  * any other ordered data structure

The storage strategy may 

  * make copies of the original elements
  * store pointers to the original elements

The implementation must pass the following test suite `stack-test.c`

    tar xf stack.tar.gz -C ~/
    cd ~/stack
    mkdir -p build
    cd build
    cmake ../
    make
    ./stack-test

Prep
===

    rm -rf stack/stack.c
    touch stack/stack.c
    tar czf stack.tar.gz stack/
