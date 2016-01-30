#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Automatic Type Deduction and decltype
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    auto x = 0;
    auto c = 'a';
    auto d = 0.5;
    auto national_debt = 1440000000000LL;

    const vector<int> vi;
    typedef decltype (vi.begin()) CIT;
    CIT another_const_iterator;
}
