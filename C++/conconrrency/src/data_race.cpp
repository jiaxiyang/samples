#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  auto constexpr num = 1000;
  vector<thread> vt(num);
  // int i{0};
  atomic<int> i{};
  for (auto& t : vt) {
    t = thread([&i] {
      for (int j = 0; j < num; j++) {
        cout << ++i << " ";
      }
    });
  }
  cout << " jiaxiyang " << endl;
  while (1) {
    cout << "haozhi" << endl;
  }
  cout << endl;
  for (auto& t : vt) {
    t.join();
  }

  cout << "num * num: " << num * num << endl;
  cout << "i: " << i << endl;
  cout << "num * num -1: " << num * num - 1 << endl;

  return 0;
}
