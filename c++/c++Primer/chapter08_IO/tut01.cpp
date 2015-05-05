#include <iostream>
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
void process_input(istream& in)
{
    string word;
    while (in >> word) {
	if (word == "quit")
	    break;
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

    cin.clear();
}
void test_io_state()
{
    int ival;
    auto old_state = cin.rdstate();
    cin.clear(); //make cin valid
    process_input(cin);
    cin.setstate(old_state);//now reset cin to its old state

}

int main(int argc, const char *argv[])
{
    test_io_state();

    return 0;
}
