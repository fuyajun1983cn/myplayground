#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/**
 * 将文件中读取的内容存储到vector，然后用istringstream从vector中一次读取一个向量
 */

using namespace std;

int main(int argc, const char *argv[])
{
        ifstream in(argv[1]);
	if (in.fail()) {
	    cout<<"open file failed"<<endl;
	    return -1;
	}

       vector<string> strs;         

	string line;
	while(getline(in, line)) { //Got one line a time
	    if (line.empty())
		continue;
	    strs.push_back(line);
	}
     
	istringstream iss;
	vector<string>::iterator iter = strs.begin();
	while (iter != strs.end()) {
	    iss.str(*iter++);
	    string word;
	    while (iss>>word)
	         cout<<word;
	    iss.clear();//should clear it for the next loop
            cout<<endl;
	    cout<<endl;
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

	return 0;
}
