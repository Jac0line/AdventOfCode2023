#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
using namespace std;


int main() {
	fstream new_file;
	new_file.open("inputDay1.txt",ios::in);
	int result=0;
	const char* numbersWriten[9]={"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	if(new_file.is_open()){
		string sa;
		map<int,int> myMap;
		while(getline(new_file,sa)){
			cout << sa << "\n";
			myMap.clear();//clear map values from last read line

			//find all writen numbers and add them to map<index><number> myMap
			for(int i = 0; i < 9; i++)
			{
				size_t found = sa.find(numbersWriten[i]);
				if(found<string::npos)
				{
					while(found != string::npos)
					{
						cout << "found:" << found << " writen nr: " << numbersWriten[i] << "\n";
						myMap.insert({found,i+1}); //index, value
						found = sa.find(numbersWriten[i], found+1);
					}
				}
			}

			//get first number
			int resultFirstNr;
			size_t indexFirstNr=sa.find_first_of("0123456789");
			if(indexFirstNr<200){
				resultFirstNr=stoi(sa.substr(indexFirstNr,1));
			}
			cout << "indexFirstNr: " << indexFirstNr << "\n"; 
			cout << "Result firstnr: " << resultFirstNr << "\n"; 
			for(auto it= myMap.cbegin(); it != myMap.cend(); ++it)
			{
				if(it->first < indexFirstNr)
				{
					resultFirstNr=it->second;
					cout << "Written number: "<< it->second << " at index: " << it->first << "\n";
					cout << "Result firstnr: " << resultFirstNr << "\n"; 
					indexFirstNr=it->first;
				}
			}

			//get last number
			int resultLastNr;
			size_t indexLastNr=sa.find_last_of("0123456789");
			if(indexLastNr > 200) { 
				indexLastNr=0;
			}
			else
			{
				resultLastNr=stoi(sa.substr(indexLastNr,1));
			}
			cout << "indexLastNr: " << indexLastNr << "\n"; 
			cout << "Result lastnr: " << resultLastNr << "\n"; 
			for(auto it= myMap.cbegin(); it != myMap.cend(); ++it)
			{
				if(it->first > indexLastNr)
				{
					resultLastNr=it->second;
					cout << "Written number: "<< it->second << " at index: " << it->first << "\n";
					cout << "Result lastnr: " << resultLastNr << "\n"; 
				}
			}

			//combine first and last number and add to total
			stringstream resultFirstAndLast;
			resultFirstAndLast << resultFirstNr;
			resultFirstAndLast << resultLastNr;
			cout << "resultFirstAndLast: " << resultFirstAndLast.str() << "\n";
			result = result + stoi(resultFirstAndLast.str());
			cout << "Total: " << result << "\n";
		}
		new_file.close();
	}

	return 0;
}

// onetwothree
// one1onetwo2twothree3three
// eightwo
