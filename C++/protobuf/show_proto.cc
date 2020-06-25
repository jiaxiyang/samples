#include <fstream>
#include <iostream>
#include <string>

#include "test.pb.h"
using namespace std;

todo::Todo get_msg(const string file) {
  todo::Todo msg;
  fstream input(file, ios::in | ios::binary);
  if (!input) {
    cerr << file << ": File not found." << endl;
    abort();
  } else if (!msg.ParseFromIstream(&input)) {
    cerr << "Failed to parse " << file << endl;
  }

  return msg;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "usage: show_proto <proto_file>" << endl;
  }
  cout << "show " << argv[1] << ": " << endl;
  cout << get_msg(argv[1]).DebugString() << endl;
  return 0;
}
