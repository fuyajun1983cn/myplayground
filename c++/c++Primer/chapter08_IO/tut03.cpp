#include <iostream>
#include <fstream>
/**
 * 文件输入输出练习
 *
 */

using namespace std;

int main(int argc, const char *argv[])
{
        ifstream in(argv[1]);
	if (in.fail()) {
	    cout<<"open file failed"<<endl;
	    return -1;
	}


	ofstream out;
	out.open(string(argv[1]) + ".copy");

	string line;
	while(in>>line) {
	    cout<<line;
	    out<<line;
	}

	if (in.eof()) {
	    cout<<"EOF"<<endl;
	} else if (in.fail()) 
	    cout<<"FAIL"<<endl;
	else if (in.bad())
	    cout<<"BAD"<<endl;
	else
	    cout<<"GOOD"<<endl;

	in.close();
	out.close();

	return 0;
}
