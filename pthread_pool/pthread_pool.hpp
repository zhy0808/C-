#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
using namespace std;

class Task {
public:
  int base;
  Task() {

  }
  Task(int b)
    :base(b) {

    }
  void run() {
    cout << "thread is["<< pthread_self() << "]"<< "task running... base is : " << base << " pow is :" << pow(base, 2) << endl;
  }
  ~Task() {

  }
};

class thread_pool {

private:
  pthread_mutex_t lock;
  pthread_cond_t cond;
  int cap;
  queue<Task*> q;
public:
  void LockQueue() {
    pthread_mutex_lock(&lock);
  }
  void UnlockQueue() {
    pthread_mutex_unlock(&lock);
  }
  void wait() {
    pthread_cond_wait(&cond, &lock);
  }
  bool isEmpty() {
    return q.size() == 0;
  }
  void WakeUpOne() {
    pthread_cond_signal(&cond);
  }
public:
  thread_pool(int _c)
    :cap(_c){

    }
  void thread_pool_init() {
    pthread_mutex_init(&lock, nullptr);
    pthread_cond_init(&cond, nullptr);
    pthread_t t;
    for(int i = 0; i < cap; ++i) {
      pthread_create(&t, nullptr, Routine, (void*)this);
    }
  } 
  static void* Routine(void* arg) {
    thread_pool* tp = (thread_pool*)arg;
    while(1) {
      tp->LockQueue();
      while(tp->isEmpty()) {
        tp->wait();
      }
      Task t;
      tp->Get(t);
      tp->UnlockQueue();
      t.run();
    }
  }
  void Put(Task& in) {
    LockQueue();
    q.push(&in);
    WakeUpOne();
    UnlockQueue();
  }
  void Get(Task& out) {
    Task* tmp = q.front();
    q.pop();
    out = *tmp;   
  }
  
  ~thread_pool() {
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
  }
};
