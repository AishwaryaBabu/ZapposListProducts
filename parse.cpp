#include <string>
#include <fstream>
#include<iostream>
using namespace std;


int main (int argc, char *argv[])
{
//    char url[1000] = "http://api.zappos.com/Search?term=boots&key=52ddafbe3ee659bad97fcce7c53592916a6bfd73";

//        vector<string> inputDataLines;
    string inputFilename = "data.json"; 
    fstream fs;
    fs.open(inputFilename.c_str(), fstream::in);

    string input;
    getline(fs, input);

    fs.close();


//    cout<<input<<endl;

   

    return 0;
}
