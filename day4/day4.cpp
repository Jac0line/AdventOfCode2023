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
	if(new_file.is_open()){
        int result=0;        
		string sa;
		while(getline(new_file,sa)){
			cout << sa << "\n";
            string cardNumbers = sa.substr(sa.find(" ")+1,sa.find(":")-(sa.find(" ")+1));
            cout << cardNumbers << endl;

            string winningNumbers = sa.substr(sa.find(":")+2,sa.find("|")-(sa.find(":")+2));
            cout << winningNumbers << endl;
            if(winningNumbers[0]==' ')
            {
                winningNumbers.erase(0,1);
            }
            int nrOfWinningNumbers = count(winningNumbers.begin(), winningNumbers.end(), ' ');
            cout << nrOfWinningNumbers << endl;
            vector<int> winningNumbersVector;
            cout << "nrOfWinningNumbers:" << nrOfWinningNumbers << endl;
            int i = 0;
            while(winningNumbers != "")
            {
                cout << "i: " << i << endl;
                winningNumbersVector.push_back(stoi(winningNumbers.substr(0, winningNumbers.find(" "))));
                winningNumbers=winningNumbers.substr(winningNumbers.find(" ")+1);
                cout << "rest: " << winningNumbers << "End" << endl;
                cout << "Added to array: " << winningNumbersVector.back() << endl;
                if(winningNumbers[0]==' ')
                {
                    winningNumbers.erase(0,1);
                }
                i++;
            }

            string myNumbers = sa.substr(sa.find("|")+2)+" ";
            cout << myNumbers << endl;
            if(myNumbers[0]==' ')
            {
                myNumbers.erase(0,1);
            }            
            int nrOfMyNumbers = count(myNumbers.begin(), myNumbers.end(), ' ')+1;
            cout << nrOfMyNumbers << endl;
            vector<int> myNumbersVector;
            cout << "nrOfMyNumbers:" << nrOfMyNumbers << endl;
            i = 0;
            while(myNumbers != "" && myNumbers != " ")
            {
                cout << "i: " << i << endl;
                myNumbersVector.push_back(stoi(myNumbers.substr(0, myNumbers.find(" "))));
                myNumbers=myNumbers.substr(myNumbers.find(" ")+1);
                cout << "rest: " << myNumbers << "End" << endl;
                cout << "Added to array: " << myNumbersVector.back() << endl;
                if(myNumbers[0]==' ')
                {
                    myNumbers.erase(0,1);
                }
                i++;
            }

            int nrOfMatches = 0;
            int cardResult = 0;
            for(int i = 0; i < myNumbersVector.size(); i++)
            {
                for(int j = 0; j < winningNumbersVector.size(); j++)
                {
                    if(myNumbersVector[i]==winningNumbersVector[j])
                    {
                        cout << "Matched nr: " << winningNumbersVector[j] << endl;
                        nrOfMatches++;
                        cardResult = (cardResult==0) ? 1 : cardResult*2;
                    }
                }
            }
            result = result + cardResult;
            cout << "result: " << result << endl;
        }
	}
	return 0;
}
