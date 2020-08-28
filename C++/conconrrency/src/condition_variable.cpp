#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using namespace std;

vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
int index = 0;
queue<int> buffer;
mutex mtx_buffer;
condition_variable cv_buffer;
bool finish = false;

void preprocess() {
  while (true) {
    if (index >= input.size()) {
      finish = true;
      // cout << "preprocess break;  finish : " << finish << endl;
      break;
    }
    this_thread::sleep_for(1s);

    lock_guard<mutex> lg{mtx_buffer};
    cout << "get input: " << input[index] << endl;

    buffer.push(input[index]);
    index++;
    // cv_buffer.notify_all();
  }
}

void process() {
  while (true) {
    {
      lock_guard<mutex> lg{mtx_buffer};
      // cv_buffer.wait(lg, [] { return !buffer.empty(); });
      if (buffer.empty()) {
        // cout << this_thread::get_id() << "  empty? : " << buffer.empty()
        // << "  finish: " << finish << endl;

      if (finish)
          break;
        else
          continue;
      }
      cout << this_thread::get_id() << "    result: " << buffer.front() * 10
           << endl;
      buffer.pop();
      // lg.unlock();
    }
    this_thread::sleep_for(4s);
  }
}

int main(int argc, char *argv[]) {
  auto start = chrono::system_clock::now();
  thread t1(preprocess);
  thread t2(process);
  thread t3(process);
  thread t4(process);
  thread t5(process);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  auto end = chrono::system_clock::now();
  cout << "total time : "
       << (chrono::duration_cast<chrono::microseconds>(end - start)).count() /
              1000000
       << endl;
  return 0;
}
