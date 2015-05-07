#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, const char *argv[])
{
        ifstream in(argv[1]);
	if (in.fail()) {
	    cout<<"open file failed"<<endl;
	    return -1;
	}

        string line, word;
        vector<PersonInfo> people;
        while (getline(in, line)) {
              PersonInfo info;		  
	      istringstream record(line);
	      record>>info.name;
	      while (record >> word)
		  info.phones.push_back(word);
	      people.push_back(info);
	}
	      
	return 0;
}


