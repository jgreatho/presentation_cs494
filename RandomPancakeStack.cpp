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
  int d[251] = {0}, numcakes, t;

  if(argc != 1) { cerr << usge; return 1; }

  // Read all values
  numcakes = 0;
  while(getline(cin, tmp) ) {  
    if(cin.fail() ) { cerr << rdEr; return 1; }


    ss << tmp;
    while(ss >> t) {
      if(!ss.fail() ) {
        d[numcakes] = t;
        numcakes++;

      } else cerr << "Stringstream \"ss\" failed!" << endl;
    }

  }

  // Find Expected Deliciousness
  cout << expectedDeliciousness(d) << endl;

  (void) argv;
  return 0;
}
