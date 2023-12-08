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

	new_file.open("inputDay4.txt",ios::in);
	int nrOfLines=0;
	if(new_file.is_open()){
		string sa;
		while(getline(new_file,sa)){
            nrOfLines++;
        }
        cout << "nrOfCards: " << nrOfLines << endl;
		new_file.close();
	}

    int nrOFCardsArray[nrOfLines];
    for(int i = 0; i < nrOfLines; i++)
    {
        nrOFCardsArray[i]=1;
    }

    new_file.open("inputDay4.txt",ios::in);
	if(new_file.is_open()){
        int result=0;        
		string sa;
		while(getline(new_file,sa)){
            int cardNumber = stoi(sa.substr(sa.find(" ")+1,sa.find(":")-(sa.find(" ")+1)));
            cout << cardNumber << endl;

            string winningNumbers = sa.substr(sa.find(":")+2,sa.find("|")-(sa.find(":")+2));
            cout << winningNumbers << endl;
            if(winningNumbers[0]==' ')
            {
                winningNumbers.erase(0,1);
            }
            int nrOfWinningNumbers = count(winningNumbers.begin(), winningNumbers.end(), ' ');
            vector<int> winningNumbersVector;
            int i = 0;
            while(winningNumbers != "")
            {
                winningNumbersVector.push_back(stoi(winningNumbers.substr(0, winningNumbers.find(" "))));
                winningNumbers=winningNumbers.substr(winningNumbers.find(" ")+1);
                if(winningNumbers[0]==' ')
                {
                    winningNumbers.erase(0,1);
                }
                i++;
            }

            string myNumbers = sa.substr(sa.find("|")+2)+" ";
            if(myNumbers[0]==' ')
            {
                myNumbers.erase(0,1);
            }            
            int nrOfMyNumbers = count(myNumbers.begin(), myNumbers.end(), ' ')+1;
            vector<int> myNumbersVector;
            i = 0;
            while(myNumbers != "" && myNumbers != " ")
            {
                myNumbersVector.push_back(stoi(myNumbers.substr(0, myNumbers.find(" "))));
                myNumbers=myNumbers.substr(myNumbers.find(" ")+1);
                if(myNumbers[0]==' ')
                {
                    myNumbers.erase(0,1);
                }
                i++;
            }

            int nrOfMatches = 0;
            for(int i = 0; i < myNumbersVector.size(); i++)
            {
                for(int j = 0; j < winningNumbersVector.size(); j++)
                {
                    if(myNumbersVector[i]==winningNumbersVector[j])
                    {
                        cout << "Matched nr: " << winningNumbersVector[j] << endl;
                        nrOfMatches++;
                    }
                }
            }
            for(int i = 0; i < nrOfMatches; i++)
            {
                nrOFCardsArray[cardNumber+i]+=nrOFCardsArray[cardNumber-1];
                cout << "Added 1 to: " << cardNumber+i << " result is now: " << nrOFCardsArray[cardNumber+i] << endl;
            }
        }
        for(int i = 0; i < (sizeof(nrOFCardsArray)/sizeof(int)); i++)
        {
            cout << "nrOFCardsArray[i]: " <<  nrOFCardsArray[i] << " for: " << i << endl;
            result = result+nrOFCardsArray[i];
            cout << "result: " << result << endl;
        }
	}
	return 0;
}
