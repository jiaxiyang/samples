#include <algorithm>
#include <chrono>
// #include <execution>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  vector<int> v{5, 10, 11, 1, 8, 3, 7};
  auto start = chrono::system_clock::now();
  // sort(execution::par, v.begin(), v.end());
  for (auto& t : v) {
    cout << t << " " << endl;
  }
  auto end = chrono::system_clock::now();
  cout << "total time : "
       << (chrono::duration_cast<chrono::microseconds>(end - start)).count() /
              1000000
       << endl;

  return 0;
}
