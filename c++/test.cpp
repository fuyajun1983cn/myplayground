#include <iostream>
#include <vector>

using namespace std;

class Example {
public:
  static double rate ;
  static constexpr int vecSize = 20;
  static vector<double> vec;
};


double Example::rate;
vector<double> Example::vec;

int main(int argc, char *argv[])
{
  Example e;
  
  return 0;
}
