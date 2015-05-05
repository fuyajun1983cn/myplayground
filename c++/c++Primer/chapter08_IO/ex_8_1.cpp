
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/**
 * IO Library Types and Headers
 * iostream: istream, wistream
 *           ostream, wostream
 *           iostream, wiostream
 * fstream: ifstream, wifstream
 *          ofstream, wofstream
 *          fstream, wfstream
 * sstream: istringstream, wistringstream
 *          ostringstream, wostringstream
 *          stringstream, wstringstream
 *          
 *   no copy or Assign for IO Objects
 */

/**
 * test io state
 */
istream& read_input(istream& in)
{
    string word;
    while (in >> word) {
	cout<<word<<endl;
    }

    if (in.eof())
	cout<<"EOF"<<endl;

    if (in.fail())
	cout<<"FAIL"<<endl;

    if (in.bad())
	cout<<"BAD"<<endl;

    if (in.good())
	cout<<"GOOD"<<endl;

    in.clear();

    return in;
}
void test_io()
{
    ifstream in(string("Makefile"));
    read_input(in);

}

int main(int argc, const char *argv[])
{
    test_io();

    return 0;
}
