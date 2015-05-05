#include <iostream>

/**
 * Managing the Output Buffer
 *
 * There are several conditions that cause the buffer to be flushed:
 * 1. the program complete normally.
 * 2. the buffer become full.
 * 3. flush explicitly using a manipulator such as endl
 * 4. using unitbuf manipulator to set the stream's internal state to
 * empty the buffer. by default, unitbuf is set for cerr, so that
 * writes to cerr are flushed immediately.
 * 5. an output stream might be tied to another stream. in this case,
 * the buffer of the tied stream is fushed whenever the tied stream is
 * read or written. by default, cin and cerr are both tied to cout.
 */

using namespace std;

int main(int argc, const char *argv[])
{
    cout << "hi!" <<endl; //writes hi and a newline, then flushes the buffer
    cout << "hi!" << flush; //writes hi, then flushes the buffer; adds no data
    cout << "hi!" <<ends; //writes hi and a null, then flushes the buffer

    cout<<unitbuf;  //all writes will be flushed immediately
    cout << "hi!";
    cout << nounitbuf;  //restore to normal buffering

    //we can tie either an istream or an ostream object to another
    //ostream

    cin.tie(&cout); // the library ties cin and cout for us alread.
    ostream *old_tie = cin.tie(nullptr); //cin is no longer tied
    //ties cin and cerr;
    cin.tie(&cerr);
    cin.tie(old_tie); // reestablish normal tie between cin and cout

    return 0;
}
