#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

struct CriticalData {
  mutex mut;
  int i;
};

// void dead_lock(CriticalData& c1, CriticalData& c2) {
//   // lock_guard<mutex> lk1(c1.mut);
//   c1.mut.lock();
//   cout << "Thread: " << this_thread::get_id() << " locking the first mutex"
//        << endl;
//   this_thread::sleep_for(chrono::milliseconds(1));
//   lock_guard<mutex> lk2(c2.mut);
//   cout << "Thread: " << this_thread::get_id() << " locking the second mutex"
//        << endl;
//   c1.mut.unlock();
// }

// void dead_lock(CriticalData& c1, CriticalData& c2) {
//   unique_lock<mutex> lk1(c1.mut, defer_lock);
//   cout << "Thread: " << this_thread::get_id() << " locking the first mutex"
//        << endl;

//   this_thread::sleep_for(chrono::milliseconds(1));

//   unique_lock<mutex> lk2(c2.mut, defer_lock);
//   cout << "Thread: " << this_thread::get_id() << " locking the second mutex"
//        << endl;

//   lock(lk1, lk2);  // 这里才是真正上锁的地方
//   cout << "lock both of them " << endl;

//   // do something
// }

void dead_lock(CriticalData& c1, CriticalData& c2) {
  std::scoped_lock(c1.mut, c2.mut);
  cout << this_thread::get_id() << " lock both of them" << endl;
}

int main(int argc, char* argv[]) {
  CriticalData c1;
  CriticalData c2;
  thread t1{[&] { dead_lock(c1, c2); }};
  thread t2{[&] { dead_lock(c2, c1); }};
  t1.join();
  t2.join();

  cout << endl;
  return 0;
}
