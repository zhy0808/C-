#include "pthread_pool.hpp"


void test() {
  thread_pool p(5);  
  p.thread_pool_init();
  
  while(1) {
    int base = rand() % 10 + 1;
    Task t(base);
    p.Put(t);
    sleep(1);
  }
}
int main() {
  test();
  return 0;
}
