#include <iostream>
#include <string>

#include "test.pb.h"

using namespace std;

int main(int argc, char *argv[]) {
  todo::Todo test;
  test.set_name("make breakfast");
  test.set_description("buy some bread and make some vegetable");
  auto &time = *test.mutable_time();
  time.set_schedule("2020.06.25");
  time.set_deadline("2020.06.30");
  cout << test.DebugString() << endl;

  return 0;
}
