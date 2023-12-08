#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <regex>
using namespace std;


int main() {
	fstream new_file;
	new_file.open("inputDay3.txt",ios::in);
	int nrOfLines=0;
    int sum=0;
	if(new_file.is_open()){
		string sa;
		while(getline(new_file,sa)){
            nrOfLines++;
        }
        cout << "nrOfLines: " << nrOfLines << endl;
		new_file.close();
	}

    vector<vector<int>> digitLocations; //for each match save matched value, start position, end position and rownr    
    vector<vector<int>> specialCharLocations; //for each match save matched value, start position, end position and rownr    

    new_file.open("inputDay3.txt",ios::in);
	if(new_file.is_open()){
		string sa;
        int rowNr=0;
		while(getline(new_file,sa)){
			cout << sa << "\n";

            regex digitRegex("(\\d+)");
            auto line_begin = sregex_iterator(sa.begin(),sa.end(),digitRegex);
            auto line_end = sregex_iterator();
            int nrOfMatches = distance(line_begin, line_end);
            cout << "nrOfMatches: " << nrOfMatches << endl;
            for(sregex_iterator i = line_begin; i != line_end; i++)
            {
                smatch match = *i;
                cout << match.position() << endl;
                cout << match.length() << endl;
                string match_str = match.str();
                cout << match_str << endl;
                digitLocations.push_back({ stoi(match_str), match.position(), (match.position()+match.length()-1), rowNr});
            }
            cout << "Digits: " << endl;
            for(auto x : digitLocations)
            {
                cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
            }

            regex specialCharRegex("([^\\d.])");
            auto line_begin_special = sregex_iterator(sa.begin(),sa.end(),specialCharRegex);
            for(sregex_iterator i = line_begin_special; i != line_end; i++)
            {
                smatch match = *i;
                cout << match.position() << endl;
                cout << match.length() << endl;
                string match_str = match.str();
                cout << match_str << endl;
                if(match.str() == "*")
                {
                    specialCharLocations.push_back({ 1, match.position(), (match.position()+match.length()-1), rowNr});
                }
                else
                {
                    specialCharLocations.push_back({ -1, match.position(), (match.position()+match.length()-1), rowNr});
                }
            }
            cout << "Special characters: " << endl;
            for(auto x : specialCharLocations)
            {
                cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
            }  
            rowNr++;

        }
    	new_file.close();
        int result=0;
        for(auto y: specialCharLocations)
        {
            int nrOfMatches=0;
            int matchedGear[2];
            for(auto x : digitLocations)
            {
                if(y[0]==1){
                    cout <<"Digit: " << x[0] << " spec char: " << y[0] << " y[1]: " << y[1] << " x[2]: " << x[2] << " x[1]: " << x[1] << " y[3]: " << y[3] << " x[3]: " << x[3] << endl;
                    if(x[2] >= y[1]-1 && x[1] <= y[1]+1 && x[3] >= y[3]-1 && x[3] <= y[3]+1)
                    {
                        cout << "Good digit:" << x[0] << endl;
                        matchedGear[nrOfMatches]=x[0];
                        nrOfMatches++;
                    }
                }
            }
            if(nrOfMatches==2)
            {
                cout << "two matches for special char" << y[0] << y[1] << y[2] << y[3] << endl;
                cout << "matched" << matchedGear[0] << " and " << matchedGear[1] << endl;           
                result=result+(matchedGear[0]*matchedGear[1]);
                cout<< "Result: " << result << endl;
                nrOfMatches=0; 
            }
        }
	}

	return 0;
}


