#include <future>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  auto fut = async([] { return 3 + 4; });
  cout << fut.get() << endl;
  return 0;
}
