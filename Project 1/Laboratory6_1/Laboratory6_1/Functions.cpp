//Functions.cpp_Jeremy Martin_3/10/16
//this program demonstrates the use of three different functions
#include <iostream>

using namespace std;

double sum_of_numbers(double firstnumber, double secondnumber)  //this function takes two numbers input through the program and returns their sum
{
	double number1 = firstnumber;
	double number2 = secondnumber;
	double sum = number1 + number2;
	return sum;
}

double mean_of_integers(int n)  //this function asks for the user to provide n, it then asks for n numbers and totals them
{
	int number;
	double total = 0;
	for (double i = 0; i < n; i++)  //this for loop asks the user to provide numbers n times and adds them together
	{
		cout << "Please enter a number: ";
		cin >> number;
		total += number;
	}
	double mean = total / n;  //to provide the mean the total is then divided by n
	return mean;
}

double max_of_numbers(double firstnumber, double secondnumber)  //this function takes two numbers and determines which is bigger
{
	double max;
	if (firstnumber > secondnumber)
	{
		max = firstnumber;
	}
	else
	{
		max = secondnumber;
	}
	return max;
}

int main()
{
	double first;
	double second;
	int totalnumber;
	double max1;
	double max2;
	cout << "Please enter two numbers to calculate the sum" << endl;
	cin >> first >> second;
	double sum = sum_of_numbers(first, second);
	cout << "The sum of your entered numbers is:" << sum << endl;
	cout << "Please enter the max amount of numbers to calculate the mean" << endl;
	cin >> totalnumber;
	double mean = mean_of_integers(totalnumber);
	cout << "The mean is: " << mean << endl;
	cout << "Please enter two numbers to determine the max" << endl;
	cin >> max1 >> max2;
	double max = max_of_numbers(max1, max2);
	cout << "The maximum number is:" << max << endl;
	return 0;
}