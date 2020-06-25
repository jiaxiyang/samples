#include <google/protobuf/util/message_differencer.h>

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
  if (argc < 3) {
    cout << "usage: compare_proto <proto_file> <proto_file>" << endl;
  }

  auto msg1 = get_msg(argv[1]);
  auto msg2 = get_msg(argv[2]);

  cout << "compare " << argv[1] << " and " << argv[2] << ":" << endl;
  cout << argv[1] << " and " << argv[2] << " are "
       << (google::protobuf::util::MessageDifferencer::Equals(msg1, msg2)
               ? "same"
               : "diff")
       << endl;

  return 0;
}
