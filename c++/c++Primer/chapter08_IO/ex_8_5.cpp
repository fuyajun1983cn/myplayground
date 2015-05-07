#include <iostream>
#include <fstream>
#include <vector>

/**
 * 将一个文件的内容读入到一个字符串向量
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

	string word;
	while(in>>word) { //Got one word a time
	    if (word.empty())
		continue;
	    strs.push_back(word);
	}

	vector<string>::iterator iter = strs.begin();
	while (iter != strs.end()) {
	    cout<<*iter++;
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
