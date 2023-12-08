#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;


int main() {
	fstream new_file;
	new_file.open("inputDay2.txt",ios::in);
    int maxRed = 12;
    int maxGreen = 13;
    int maxBlue = 14;
    int total=0;
    int powerOfGame=0;
    if(new_file.is_open()){
        string sa;
        string substring;
        list<int> gameNrs;
        const char* colors[3]={"blue", "red", "green"};
        string segement;
        while(getline(new_file,sa)){


            substring=sa.substr(sa.find(" ")+1,1);
            gameNrs.push_back(stoi(sa.substr(sa.find(" ")+1,sa.find(":")-(sa.find(" ")+1))));
            cout << gameNrs.back() << "\n";

            string colorsString = sa.substr(sa.find(":")+2);
            int nrOfDraws=1;
            for(int i =0; i<sa.size(); i++)
            {
                if(sa[i] == ';')
                {
                    nrOfDraws++;
                }
            }
            cout << "nrOfDraws: " << nrOfDraws << "\n";
            int nrOfRed=0;
            int nrOfGreen=0;
            int nrOfBlue=0;
            sa = sa.substr(sa.find(":")+2);
            for(int i=0; i< nrOfDraws; i++)
            {
                string currentDraw = sa.substr(0, sa.find(";"));
                cout << "currentDraw: " << currentDraw << endl;
                int nrOfColors=1;
                for(int i =0; i<currentDraw.size(); i++)
                {
                    if(currentDraw[i] == ',')
                    {
                        nrOfColors++;
                    }
                }
                for(int i = 0; i < nrOfColors; i++)
                {
                    int nrOfCubes = stoi(currentDraw.substr(0,currentDraw.find(" ")));
                    cout << "nrOfCubes: " << nrOfCubes << endl;
                    string colorName = currentDraw.substr(currentDraw.find(" ")+1, currentDraw.find(",")-(currentDraw.find(" ")+1));
                    cout << "colorName: " << colorName << endl;
                    if(colorName == "red"){
                        if(nrOfRed < nrOfCubes){
                            nrOfRed = nrOfCubes;
                            cout << "nrOfRed updated to: " << nrOfRed << "\n";
                        }
                    }
                    if(colorName == "green"){
                        if(nrOfGreen < nrOfCubes){
                            nrOfGreen = nrOfCubes;
                            cout << "nrOfGreen updated to: " << nrOfGreen << "\n";
                        }
                    }
                    if(colorName == "blue"){
                        if(nrOfBlue < nrOfCubes){
                            nrOfBlue = nrOfCubes;
                            cout << "nrOfBlue updated to: " << nrOfBlue << "\n";
                        }
                    }

                    currentDraw = currentDraw.substr(currentDraw.find(",")+2);
                    cout << "rest of current draw: " << currentDraw << endl; 
                }
                sa = sa.substr(sa.find(";")+2);
                cout << "rest of sa: " << sa << endl;

                cout << "nrOfRed: " << nrOfRed << "\n";
                cout << "nrOfGreen: " << nrOfGreen << "\n";
                cout << "nrOfBlue: " << nrOfBlue << "\n";
            }
            powerOfGame = nrOfRed * nrOfGreen * nrOfBlue;
            cout << "powerOfGame: " << powerOfGame << endl;
            total = total + powerOfGame;
            cout << "------ total: " << total << endl;
        }
    }
	return 0;
}    