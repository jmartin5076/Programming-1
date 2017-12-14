//Random.cpp_Jeremy Martin_3/10/16
//this program creates a function which will be used in conjunction with the rand fuction in order to generate pseudo-random numbers
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_number(int seed, int num1, int num2)  //this function calls a random number between num1 and num2 with the seed
{
	srand(seed);
	int random = rand() % (num2 - num1+1) + num1;
	return random;
}

int main()
{
	int num1;
	int num2;
	int num3;
	int num4;
	int user_seed;
	cout << "Please input the seed: " << endl;
	cin >> user_seed;
	cout << "Please enter the minimum and maximum bounds." << endl;
	cin >> num1 >> num2;
	int user_r = random_number(user_seed, num1, num2);
	cout << "The random number is: " << user_r << endl;
	cout << "Please enter the minimum and maximum bounds." << endl;
	cin >> num3 >> num4;
	int r = random_number(time(0), num3, num4);
	cout << "The random number is: " << r << endl;
	return 0;
}