#include <chrono>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>

int counter = 0;
std::mutex mtx;  // 保护counter

void increase(int time) {
  for (int i = 0; i < time; i++) {
    // mtx.lock();  // 当前线程休眠1毫秒
    // std::lock_guard lk(mtx);
    std::scoped_lock lk(mtx);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    counter++;
    // mtx.unlock();
  }
}

int main(int argc, char** argv) {
  std::thread t1(increase, 1000);
  std::thread t2(increase, 1000);
  t1.join();
  t2.join();
  std::cout << "counter:" << counter << std::endl;
  return 0;
}
