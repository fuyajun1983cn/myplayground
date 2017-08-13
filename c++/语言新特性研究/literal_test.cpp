#include <iostream>
#include <string>

using namespace std;

// C++ 11:
/** user defined literals
 * add constexpr to reduce runtime cost
 * Restriction: it can only work with following parameters:
   char const*
   unsigned long long
   long double
   char const*, std::size_t
   wchar_t const*, std::size_t
   char16_t const*, std::size_t
   char32_t const*, std::size_t
   Note: return value can be of any types.
*/
constexpr long double operator"" _cm(long double x) { return x * 10; }
constexpr long double operator"" _m(long double x) { return x * 1000; }
constexpr long double operator"" _mm(long double x) { return x; }

int operator"" _bin(const char* str, size_t l)
{
  int ret = 0;
  for (size_t i = 0;i < l; i++) {
    if (str[i] == '1')
      ret += 1 << (l-i-1);
  }
  return ret;
}

int main(int argc, char *argv[])
{
  long double height = 3.4_cm;
  cout << height  << endl;              // 34
  cout << (height + 13.0_m)  << endl;   // 13034
  cout << (130.0_mm / 13.0_m)  << endl; // 0.01


  cout<<"110"_bin<<endl;
  cout<<"111"_bin<<endl;
  
  return 0;
}
