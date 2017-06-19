#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include "Chapter9Problems.h"

//Function Prototypes

int main() {
	chapter9Problems *p1 = new chapter9Problems;
	p1->case_Study_Modifications();
	system("pause");
	return 0;
}

void chapter9Problems::arrayAllocator() {
	
	//This program will dynamically allocate an array of integers

	int *numbers = nullptr;
	int amountInt;
	
	//Get amount of integers from user input
	std::cout << "Please enter the amount of integers you would like to input? ";
	std::cin >> amountInt;

	//Input Validation: Amount of integers cannot be less than 0
	while (amountInt < 0) {
		std::cout << "Value cannot be less than 0. Try again. \n";
		std::cin >> amountInt;
	}

	//Dynamically allocate an array large enough to hold the amount of integers
	numbers = new int[amountInt];

	//Get integers from user input
	for (int count = 0; count < amountInt; count++) {
		std::cout << "Enter an integer you would like to store in the array: ";
		std::cin >> numbers[count];
	}

	//Display array contents
	std::cout << std::endl;
	std::cout << "The integers in the order you have typed them are: ";
	for (int count = 0; count < amountInt; count++)
		std::cout << *(numbers + count) << " ";
	std::cout << std::endl;

	//Free dynamically allocated memory
	delete [] numbers;
	numbers = nullptr;
}

void chapter9Problems::testScores1() {

	//This program will dynamically allocate an array to store test scores and calculate the average score

	double *testscores = nullptr;
	int amountScores;
	double total = 0, average;

	//Get amount of test scores from user input 
	std::cout << "Please enter the amount of integers you would like to input? ";
	std::cin >> amountScores;

	//Input Validation: Amount of test scores cannot be less than 0
	while (amountScores < 0) {
		std::cout << "Amount of test scores cannot be less than 0. Re-enter value: ";
		std::cin >> amountScores;
	}

	//Dynamically allocate an array large enough to hold the amount of integers
	testscores = new double[amountScores];

	//Get test scores from user input and store into array
	for (int count = 0; count < amountScores; count++) {
		std::cout << "Enter a test score you would like to store in the array: ";
		std::cin >> testscores[count];

		//Input Validation: Test scores cannot be less than 0
		while (testscores[count] < 0) {
			std::cout << "Value cannot be less than 0. Try again. \n";
			std::cin >> testscores[count];
		}

	}

	//Display the values in the order they were typed
	std::cout << "The integers in the order you have typed them are: ";
	for (int count = 0; count < amountScores; count++) {
		std::cout << *(testscores + count) << " ";
	}
	std::cout << std::endl;

	//Selection Sort in ascending order
	std::cout << "Selection Sort: ";
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (amountScores - 1); startScan++) {
		minIndex = startScan;
		minValue = testscores[startScan];
		for (int index = startScan + 1; index < amountScores; index++) {
			if (testscores[index] < minValue) {
				minValue = testscores[index];
				minIndex = index;
			}
		}
		testscores[minIndex] = testscores[startScan];
		testscores[startScan] = minValue;
	}

	//Display array contents after being sorted
	for (int count = 0; count < amountScores; count++) {
		std::cout << *(testscores + count) << " ";
		total = total + *(testscores + count);
	}
	std::cout << std::endl;

	//Calculate average score and display its value
	average = total / amountScores;
	std::cout << "The average score is: " << average << std::endl;

	//Free dynamically allocated array
	delete [] testscores;
	testscores = nullptr;
}

void chapter9Problems::dropLowestScore() {

	//This program will modify the testscores1() code to drope the lowest test score and recalculate the average

	double *testscores = nullptr;
	int amountScores;
	double total = 0, average;

	//Get amount of test scores from user input 
	std::cout << "Please enter the amount of integers you would like to input? ";
	std::cin >> amountScores;

	//Input Validation: Amount of test scores cannot be less than 0
	while (amountScores < 0) {
		std::cout << "Amount of test scores cannot be less than 0. Re-enter value: ";
		std::cin >> amountScores;
	}

	//Dynamically allocate an array large enough to hold the amount of integers
	testscores = new double[amountScores];

	//Get test scores from user input and store into array
	for (int count = 0; count < amountScores; count++) {
		std::cout << "Enter a test score you would like to store in the array: ";
		std::cin >> testscores[count];

		//Input Validation: Test scores cannot be less than 0
		while (testscores[count] < 0) {
			std::cout << "Value cannot be less than 0. Try again. \n";
			std::cin >> testscores[count];
		}
	}

	//Display the values in the order they were typed
	std::cout << "The integers in the order you have typed them are: ";
	for (int count = 0; count < amountScores; count++) {
		std::cout << *(testscores + count) << " ";
	}
	std::cout << std::endl;

	//Selection Sort in ascending order
	std::cout << "Selection Sort (with the lowest score dropped): ";
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (amountScores - 1); startScan++) {
		minIndex = startScan;
		minValue = testscores[startScan];
		for (int index = startScan + 1; index < amountScores; index++) {
			if (testscores[index] < minValue) {
				minValue = testscores[index];
				minIndex = index;
			}
		}
		testscores[minIndex] = testscores[startScan];
		testscores[startScan] = minValue;
	}

	//Display array contents after being sorted with the dropped lowest average
	for (int count = 1; count < amountScores; count++) {
		std::cout << *(testscores + count) << " ";
		total = total + *(testscores + count);
	}
	std::cout << std::endl;

	//Calculate average score after dropping the lowest test score and display its value
	average = total / (amountScores - 1);
	std::cout << "The average score is: " << average << std::endl;

	//Free dynamically allocated array
	delete[] testscores;
	testscores = nullptr;
}

void chapter9Problems::testScores2() {

	//This program will modify testscores1() code to include string user names

	double *testscores = nullptr;
	std::string *students = nullptr;
	int amountScores;
	double total = 0, average;

	//Create a duplicate array to hold test scores to identify each student
	double *testscoresDup = nullptr;

	//Get amount of test scores from user input 
	std::cout << "Please enter the amount of test scores you would like to input: ";
	std::cin >> amountScores;

	//Input Validation: Amount of test scores cannot be less than 0
	while (amountScores < 0) {
		std::cout << "Amount of test scores cannot be less than 0. Re-enter value: ";
		std::cin >> amountScores;
	}

	//Dynamically allocate an array large enough to hold the amount of integers and student names
	testscores = new double[amountScores];
	testscoresDup = new double[amountScores];
	students = new std::string[amountScores];

	//Get student names and test scores from user input and store into seperate arrays
	for (int count = 0; count < amountScores; count++) {

		//Student names
		std::cout << "Enter a student's name: ";
		std::cin.get();
		std::getline(std::cin, students[count]);

		//Test scores
		std::cout << "Enter the following student's test score: ";
		std::cin >> testscores[count];
		std::cout << std::endl;

		//Input Validation: Test scores cannot be less than 0
		while (testscores[count] < 0 || testscores[count] > 100) {
			std::cout << "Value cannot be less than 0 or greater than 100. Try again. \n";
			std::cin >> testscores[count];
		}
	}

	//Duplicate test scores array
	for (int count = 0; count < amountScores; count++) {
		testscoresDup[count] = testscores[count];
	}

	//Selection Sort in ascending order of test scores
	int startScan, minIndex;
	int minValueNum;
	for (startScan = 0; startScan < (amountScores - 1); startScan++) {
		minIndex = startScan;
		minValueNum = testscores[startScan];
		for (int index = startScan + 1; index < amountScores; index++) {
			if (testscores[index] < minValueNum) {
				minValueNum = testscores[index];
				minIndex = index;
			}
		}
		testscores[minIndex] = testscores[startScan];
		testscores[startScan] = minValueNum;
	}

	//Display the sorted test scores array with each scores' respective student name
	for (int count = 0; count < amountScores; count++) 
	{
		for (int count2 = 0; count2 < amountScores; count2++) 
		{
			if (*(testscores + count) == *(testscoresDup + count2)) 
			{
				std::cout << *(students + count2) << ": " << *(testscores + count) << std::endl;
			}
		}
		total = total + *(testscores + count);
	}
	std::cout << std::endl;

	//Calculate average score and display its value
	average = total / amountScores;
	std::cout << "The average score is: " << average << std::endl;

	//Free dynamically allocated array
	delete[] testscores;
	delete[] testscoresDup;
	delete[] students;
	testscores = nullptr;
	testscoresDup = nullptr;
	students = nullptr;
}

int chapter9Problems::pointerRewrite(int *x, int *y) 
{

	//This program will demonstrate the user of pointers as function parameters

	/*	
		Enter this code into the main function to test run:

		int a = 20, b = 30;
		std::cout << p1->pointerRewrite(&a, &b) << std::endl;
	*/

	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}

void chapter9Problems::case_Study_Modifications()
{

	/* This program will make modifications to Program 9-19 to dynamically allocate the donations array
	   and ask the user to input its values. Also, the array will be sorted in descending order. */

	//Get donations from user
	int numDonations;
	std::cout << "Enter the amount of donations: ";
	std::cin >> numDonations;

	//Input Validation: Number of donations cannot be negative
	while (numDonations < 0)
	{
		std::cout << "Value cannot be negative. Try again. " << std::endl;
		std::cin >> numDonations;
	}

	// Dynamically allocate memory for a new array
	double *donations = nullptr;
	donations = new double[numDonations];

	// Get donations input from user
	for (int count = 0; count < numDonations; count++)
	{
		std::cout << "Enter a donation: ";
		std::cin >> *(donations + count);

		//Input Validation: Donations cannot be negative
		while (*(donations + count) < 0)
		{
			std::cout << "Donations cannot be negative. Try again. " << std::endl;
			std::cin >> *(donations + count);
		}
	}

	//Display the original order array
	std::cout << "Original Array: ";
	for (int count = 0; count < numDonations; count++)
		std::cout << *(donations + count) << " ";
	std::cout << std::endl;

	//Sort the array in descending order
	int startScan, minIndex, minElem;

	for (startScan = 0; startScan < (numDonations - 1); startScan++)
	{
		minIndex = startScan;
		minElem = donations[startScan];
		for (int index = startScan + 1; index < numDonations; index++)
		{
			if ((donations[index]) > minElem)
			{
				minElem = donations[index];
				minIndex = index;
			}
		}
		donations[minIndex] = donations[startScan];
		donations[startScan] = minElem;
	}

	//Display the sorted array
	std::cout << "Sorted Array in Descending Order: ";
	for (int count = 0; count < numDonations; count++)
		std::cout << *(donations + count) << " ";
	std::cout << std::endl;
}


int chapter9Problems::mode(int *arr, const int arraySize) 
{

	//This program will find the mode of a given array

	/* 
	
	Enter this part of the code into the main function:

	int arraySize;
	int *arr = nullptr;

	//Ask user for the amount of integers that will be inputted
	std::cout << "Enter the amount of integers you would like to enter: ";
	std::cin >> arraySize;

	//Input Validation: Number of integers cannot be negative
	while (arraySize < 0)
	{
		std::cout << "The value cannot be negative. Try again." << std::endl;
			std::cin >> arraySize;
	}

	//Dynamically allocate memory for the array
	arr = new int[arraySize];

	//Ask user to input the integers
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Enter the integers into the array: ";
		std::cin >> *(arr + i);
	}
	p1->mode(arr, arraySize);

	*/

	//Create a duplicate, parallel array of the original integer array
	int *arrDup = nullptr;
	arrDup = new int[arraySize]; 

	for (int count = 0; count < arraySize; count++)
	{
		*(arrDup + count) = *(arr + count);
	}
	
	//Create another parallel array to determine which element is the mode
	int *mode = nullptr;
	mode = new int[arraySize];

	//Find how many times each element has repeated in the array and store that value in the mode array
	for (int i = 0; i < arraySize; i++)
	{
		*(mode + i) = 0;
		for (int j = 0; j < arraySize; j++)
		{
			if (*(arr + i) == *(arrDup + j))
				*(mode + i) += 1;
		}
	}

	//Determine which element is the mode and display it
	int largest = *(mode);
	for (int count = 0; count < arraySize; count++)
	{
		if (largest <= *(mode + count))
			largest = *(mode + count);
	}
	for (int count = 0; count < arraySize; count++)
	{
		//If largest == 1, then there is no mode in the array
		if (largest == 1)
		{
			std::cout << "There is no mode in the array. " << std::endl;

			//Free the dynamically allocated memory
			delete[] mode;
			delete[] arrDup;
			mode = nullptr;
			arrDup = nullptr;
			return 0;
		}

		//Otherwise, there is a mode in the array
		else if (*(mode + count) == largest)
		{
			std::cout << "The mode of the array is: " << *(arr + count) << std::endl;

			//Free the dynamically allocated memory
			delete[] mode;
			delete[] arrDup;
			mode = nullptr;
			arrDup = nullptr;
			return 0;
		}
	}
}

void chapter9Problems::median(int *arr, const int arraySize)
{

	//This program will find the mode of a given array

	/*

	Enter this part of the code into the main function:

	int arraySize;
	int *arr = nullptr;

	//Ask user for the amount of integers that will be inputted
	std::cout << "Enter the amount of integers you would like to enter: ";
	std::cin >> arraySize;

	//Input Validation: Number of integers cannot be negative
	while (arraySize < 0)
	{
	std::cout << "The value cannot be negative. Try again." << std::endl;
	std::cin >> arraySize;
	}

	//Dynamically allocate memory for the array
	arr = new int[arraySize];

	//Ask user to input the integers
	for (int i = 0; i < arraySize; i++)
	{
	std::cout << "Enter the integers into the array: ";
	std::cin >> *(arr + i);
	}
	p1->mode(arr, arraySize);

	//Delete dynamically allocated memory
	delete[] arr;
	arr = nullptr;
	*/

	//Sort the array into ascending order
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (arraySize - 1); startScan++) {
		minIndex = startScan;
		minValue = *(arr + startScan);
		for (int index = startScan + 1; index < arraySize; index++) {
			if (*(arr + index) < minValue) {
				minValue = *(arr + index);
				minIndex = index;
			}
		}
		*(arr + minIndex) = *(arr + startScan);
		*(arr + startScan) = minValue;
	}

	//Display sorted array
	std::cout << "The sorted array in ascending order: ";
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << *(arr + i) << " ";
	}
	std::cout << std::endl;

	//Variable to hold the median value
	double medianNumEven, medianNumOdd;
	
	//If the array has an even number of values, the median is the average of the two middle values
	if ((arraySize % 2) == 0)
	{
		int middleElement1 = (arraySize / 2) - 1;
		int middleElement2 = (arraySize / 2);
		medianNumEven = (*(arr + middleElement1) + *(arr + middleElement2)) / 2.0;
		std::cout << "The median of the array is: " << medianNumEven << std::endl;
	}

	//Otherwise, the array has an odd number of values, the median is the middle value
	else
	{
		int middleElement = ceil(arraySize / 2);
		medianNumOdd = *(arr + middleElement);
		std::cout << "The median of the array is: " << medianNumOdd << std::endl;
	}
}

void chapter9Problems::reverseArr(int *arr, int arraySize)
{
	//This program will display the input array in both the original and reverse order

	/*
	
	Enter this part of the code into the main function:

	int arraySize;
	int *arr = nullptr;

	//Ask user for the amount of integers that will be inputted
	std::cout << "Enter the amount of integers you would like to enter: ";
	std::cin >> arraySize;

	//Input Validation: Number of integers cannot be negative
	while (arraySize < 0)
	{
	std::cout << "The value cannot be negative. Try again." << std::endl;
	std::cin >> arraySize;
	}

	//Dynamically allocate memory for the array
	arr = new int[arraySize];

	//Ask user to input the integers
	for (int i = 0; i < arraySize; i++)
	{
	std::cout << "Enter the integers into the array: ";
	std::cin >> *(arr + i);
	}
	p1->median(arr, arraySize);
	system("pause");

	//Delete dynamically allocated memory
	delete[] arr;
	arr = nullptr;

	*/

	//Display original order
	std::cout << "The array in the original order is: ";
	for (int count = 0; count < arraySize; count++)
	{
		std::cout << *(arr + count) << " ";
	}
	std::cout << std::endl;

	//Display reverse order
	std::cout << "The array in the reverse order is: ";
	for (arraySize; arraySize > 0; arraySize--)
	{
		std::cout << *(arr + (arraySize - 1)) << " ";
	}
	std::cout << std::endl;
}

void chapter9Problems::arrayExpand(int *arr, int arraySize)
{
	//This program will expand an input array twice its size

	/*

	Enter this part of the code into the main function:

	int arraySize;
	int *arr = nullptr;

	//Ask user for the amount of integers that will be inputted
	std::cout << "Enter the amount of integers you would like to enter: ";
	std::cin >> arraySize;

	//Input Validation: Number of integers cannot be negative
	while (arraySize < 0)
	{
	std::cout << "The value cannot be negative. Try again." << std::endl;
	std::cin >> arraySize;
	}

	//Dynamically allocate memory for the array
	arr = new int[arraySize];

	//Ask user to input the integers
	for (int i = 0; i < arraySize; i++)
	{
	std::cout << "Enter the integers into the array: ";
	std::cin >> *(arr + i);
	}
	p1->median(arr, arraySize);
	system("pause");

	//Delete dynamically allocated memory
	delete[] arr;
	arr = nullptr;

	*/

	//Create a new array
	int *arrayExpanded = nullptr;

	//Create the newly, expanded array
	int arrayExpandSize = arraySize * 2;
	arrayExpanded = new int[arrayExpandSize];

	//Display original array
	std::cout << "Original Array: ";
	for (int count = 0; count < arraySize; count++)
	{
		std::cout << *(arr + count) << " ";
	}
	std::cout << std::endl;

	//Copy the original elements to the expanded array while initalizing the unused elements to 0.
	std::cout << "Expanded Array: ";
	for (int count = 0; count < arrayExpandSize; count++)
	{
		if (count < arraySize)
			*(arrayExpanded + count) = *(arr + count);
		else
			*(arrayExpanded + count) = 0;
		
		//Display the expanded array
		std::cout << *(arrayExpanded + count) << " ";
	}
	std::cout << std::endl;
	
	//Delete the dynamically allocated array
	delete[] arrayExpanded;
	arrayExpanded = nullptr;
}

void chapter9Problems::elementShifter(int *arr, int arraySize)
{
	//This program will shift the input array elements by an increase of one

	/*

	Enter this part of the code into the main function:

	int arraySize;
	int *arr = nullptr;

	//Ask user for the amount of integers that will be inputted
	std::cout << "Enter the amount of integers you would like to enter: ";
	std::cin >> arraySize;

	//Input Validation: Number of integers cannot be negative
	while (arraySize < 0)
	{
	std::cout << "The value cannot be negative. Try again." << std::endl;
	std::cin >> arraySize;
	}

	//Dynamically allocate memory for the array
	arr = new int[arraySize];

	//Ask user to input the integers
	for (int i = 0; i < arraySize; i++)
	{
	std::cout << "Enter the integers into the array: ";
	std::cin >> *(arr + i);
	}
	p1->median(arr, arraySize);
	system("pause");

	//Delete dynamically allocated memory
	delete[] arr;
	arr = nullptr;

	*/

	//Create new array
	int *arrayShift = nullptr;

	//Dynamically allocate memory for the shifted array
	int shifted = arraySize + 1;
	arrayShift = new int[shifted];

	//Display original array
	std::cout << "Original Array: ";
	for (int count = 0; count < arraySize; count++)
	{
		std::cout << *(arr + count) << " ";
	}
	std::cout << std::endl;

	//Shift elements from original array into new array by an increase of one
	std::cout << "Shifted Array: ";
	for (int count = 0; count < shifted; count++)
	{
		if (count == 0)
			*(arrayShift + count) = 0;
		else
			*(arrayShift + count) = *(arr + (count - 1));

		//Display the shifted array
		std::cout << *(arrayShift + count) << " ";
	}
	std::cout << std::endl;
}

void chapter9Problems::movieStatistics()
{
	//This program will calculate the average, median, and mode of movies watched from students

	//Create a new array based on number of students
	int *students = nullptr;
	int numStudents;

	//Ask user for the amount of students that will be inputted
	std::cout << "Enter the amount of students: ";
	std::cin >> numStudents;

	//Input Validation: Number of students cannot be negative
	while (numStudents < 0)
	{
		std::cout << "The value cannot be negative. Try again." << std::endl;
		std::cin >> numStudents;
	}

	//Dynamically allocate memory for the array
	students = new int[numStudents];

	//Ask user to input the number of movies watched by each student and calculate the average
	double total = 0;
	for (int i = 0; i < numStudents; i++)
	{
		int student = i + 1;
		std::cout << "Enter the amount of movies watched for Student " << student << " into the array: ";
		std::cin >> *(students + i);

		//Input Validation: Number of movies watched cannot be negative
		while (*(students + i) < 0)
		{
			std::cout << "The value cannot be negative. Try again." << std::endl;
			std::cin >> *(students + i);
		}

		//Running total
		total += *(students + i);
	}

	//Calculate average and display
	double average = total / numStudents;
	std::cout << "The average number of movies watched is " << average << "." << std::endl;

	//Get the median using the function that was defined earlier
	chapter9Problems *p2 = new chapter9Problems;
	p2->median(students, numStudents);

	//Get the mode using the function that was defined earlier
	p2->mode(students, numStudents);
}

chapter9Problems::chapter9Problems() 
{
}