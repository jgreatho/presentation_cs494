#include <iostream>
#include <sstream>
using namespace std;

char usge[] = "Reads stdin: for deliciousness values\n";
char rdEr[] = "Error while reading went wrong!\n";

extern double expectedDeliciousness(int d[]);

int
main(int argc, char** argv) {
// Takes in values of pancake deliciousness
  string tmp;
  stringstream ss;
  int d[251] = {0}, i, numcakes, t;

  if(argc != 1) { cerr << usge; return 1; }

  // Read all values
  numcakes = 0;
  while(getline(cin, tmp) ) {  
    if(cin.fail() ) { cerr << rdEr; return 1; }

cout << tmp << endl;

    ss << tmp;
    while(ss >> t) {
      if(!ss.fail() ) {
        cout << t << endl;
        d[numcakes] = t;
        numcakes++;
      }
else cout << "Failed!" << endl;
    }

  }

  cout << expectedDeliciousness(d) << endl;

  (void) i;
  (void) d;
  (void) argv;
  return 0;
}
