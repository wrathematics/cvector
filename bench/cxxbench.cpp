#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
  const int TOP = (int) atof(argv[1]);
  
  vector<double> x;
  for (int i=0; i<TOP; i++)
    x.push_back((double) i+1);
  
  cout << x[x.size()-1] << endl;
  
  return 0;
}
