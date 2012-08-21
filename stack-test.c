#include <stdio.h> // puts
#include <stdlib.h> // exit, EXIT_FAILURE, EXIT_SUCCESS
#include <string.h> // strcmp

#include "stack.h" // s_create, s_length, s_push, s_pop, s_peek, s_destroy

void fail(char* msg) {
  puts(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  char* a = "abc";
  char* d = "def";
  char* g = "ghijklmnopqrstuvwxyz";

  int len = 0;
  struct Stack* s = NULL;


  //
  // Test initialized condition
  //
  if (!(s = s_create())) {
    fail("stack did not init properly");
  }

  if (0 != s_length(s)) {
    fail("stack is not length 0 after init");
  }

  if (NULL != (char*) s_peek(s)) {
    fail("empty stack should peek a NULL pointer");
  }

  if (NULL != s_pop(s)) {
    fail("empty stack should pop a NULL pointer");
  }


  //
  // Test edge case of just 1 element
  //
  if (1 != s_push(s, (void*) a)) {
    fail("stack length is not 1");
  }

  if (1 != s_length(s)) {
    fail("stack is not length 1 after adding 1 item");
  }

  if (0 != strcmp(a, (char*) s_peek(s))) {
    fail("stack item 1 doesn't match peek");
  }


  //
  // Test that stack can hold any number of elements
  //
  len = 1;
  while (len < 99) {
    len += 1;

    if (len != s_push(s, (void*) d)) {
      fail("len doesn't match expected after push");
    }

    if (len != s_length(s)) {
      fail("stack is not the correct length");
    }

    if (0 != strcmp(d, (char*) s_peek(s))) {
      fail("item inserted doesn't match peek");
    }
  }


  //
  // Test edge case of last element inserted and removed
  //
  if (100 != s_push(s, (void*) g)) {
    fail("stack length is not 100");
  }

  if (100 != s_length(s)) {
    fail("stack is not length 100 after adding 100 items");
  }

  if (0 != strcmp(g, (char*) s_peek(s))) {
    fail("stack item 100 doesn't match peek");
  }

  if (0 != strcmp(g, (char*) s_pop(s))) {
    fail("stack item 1 doesn't match peek");
  }

  if (99 != s_length(s)) {
    fail("stack is not length 99 after removing 1 item");
  }


  //
  // Test that the stack can be emptied as it was filled
  //
  len = 99;
  while (len > 1) {
    len -= 1;

    if (0 != strcmp(d, (char*) s_peek(s))) {
      fail("item peek doesn't match expected");
    }

    if (0 != strcmp(d, (char*) s_pop(s))) {
      fail("removed item doesn't match expected value");
    }

    if (len != s_length(s)) {
      fail("stack is not the correct length");
    }
  }


  //
  // Test edge case of removing first item
  //
  if (0 != strcmp(a, (char*) s_pop(s))) {
    fail("stack item 1 doesn't match pop");
  }

  if (0 != s_length(s)) {
    fail("stack is not length 0 after removing all items");
  }

  if (NULL != (char*) s_peek(s)) {
    fail("emptied stack should peek a NULL pointer");
  }

  if (NULL != s_pop(s)) {
    fail("emptied stack should pop a NULL pointer");
  }


  //
  // Test destruction
  //
  s_destroy(s);
  s = NULL;

  puts("ALL TESTS PASSED!");
  return EXIT_SUCCESS;
}
