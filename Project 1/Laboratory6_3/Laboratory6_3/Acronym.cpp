//Acronym.cpp_Jeremy Martin_3/10/16
//this program creates a function the creates an acronym of three user-input words
#include <iostream>
#include <string>

using namespace std;

string acronym_maker(string firstword, string secondword, string thirdword) //this function takes the first letter of three words and makes an acronym of them
{
	string word1 = firstword.substr(0, 1);
	string word2 = secondword.substr(0, 1);
	string word3 = thirdword.substr(0, 1);
	string acronym = word1 + "." + word2 + "." + word3 + ".";
	return acronym;
}

int main()
{
	string word1;
	string word2;
	string word3;
	cout << "Please enter three words to make into an acronym." << endl;
	cin >> word1 >> word2 >> word3;
	string acronym = acronym_maker(word1, word2, word3);
	cout << "Your acronym is: " << acronym << endl;
	return 0;
}