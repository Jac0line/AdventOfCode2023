#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <regex>
#include <algorithm>
using namespace std;


int main() {
	fstream new_file;
    int dataCatagory=0;

    new_file.open("sampleInputDay5.txt",ios::in);
	if(new_file.is_open()){
		string sa;
		while(getline(new_file,sa)){
            if(sa.empty())
            { 
                dataCatagory++;
                cout << "dataCatagory: " << dataCatagory << endl;
            }
        }
	}

    
    new_file.open("sampleInputDay5.txt",ios::in);
	if(new_file.is_open()){
		string sa;
		while(getline(new_file,sa)){
            if(sa.empty())
            { 
                dataCatagory++;
                cout << "dataCatagory: " << dataCatagory << endl;
            }
        }
	}    
	return 0;
}
