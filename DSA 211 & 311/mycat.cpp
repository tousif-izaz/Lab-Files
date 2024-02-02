/*
    Simple program to demonstrate file I/O and 
    how to access command line arguments.  For example:

        $ mycat myinput 

    "myinput" is specified on the command line when the program mycat is started.

    This string (called a command line argument) is available in the main() 

    This program is similar to the Linux cat program.  It accepts a single
    command line argument (the name of a file), then it opens the file and 
    reads each line from the file and writes that line to standard output

        $ cat myfile
        one
        two
        three
        $ mycat myfile
        one
        two
        three
        $

*/

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

// in order to access the command line arguments, declare main() like this
int main(int argc, char *argv[])
{
    // make sure a filename was specified on the command line
    // argc tells us how many command line arguments were given
    // "2" means that no command line arguments were given
    // (the first argument is the name of the executable)
    if (argc < 3)
    {
        // write to standar error (cerr)
        cerr << "Must specify input and output file." << endl;
        return 1; // 1 is error condition
    }
    if (argc > 3)
    {
        cerr << "Too many command line arguments specified." << endl;
        return 1;
    }

    // open the file specified in argv[1].  
    ifstream my_ifile(argv[1]);
    // the above line is the same as the following two statements
    //     ifstream ifile;
    //     ifile.open(argv[1]);

    // my_ifile is an ifstream object connected with the given filename
    // if the contructor failed (could not open file) then !my_file returns true
    // THE ! OPERATOR HAS BEEN OVER WRITTEN FOR THE IFSTREAM CLASS
    if (!my_ifile)
    {
        cerr << "Could not open input file <" << argv[1] << ">." << endl;
        return 1; // error
    }

    // buffer to hold input line
    string buffer;
    ofstream my_ofile(argv[2], ios::out);
    if(!my_ofile) {
        cerr << "Could not open output file <" << argv[2] << ">." << endl;
        return 1;
    }
    // as long as there is more input (not end of file), read a line
    while (getline(my_ifile, buffer, '\n'))
    {
        // write the line to standard output
        my_ofile << buffer << endl;
    }

    
    return 0; // everything is ok
}
