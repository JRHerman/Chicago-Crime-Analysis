// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*main.cpp*/

//
// Chicago Crime Analysis program in modern C++. 
// This program uses the container vector to store all of the data in 2 vectors. 
// A vector of CrimeCode and a vector of CrimeReport. Descriptions of all methods are 
// on top along with in line comments to aid understanding.
// This program input 2 files a file with crime codes and crime reports and outputs 
// the range of crime from beginning to end, the first and last 3 crime codes with descriptions,
// the first and last 3 crimes with descriptions and location data, the number of crimes and crime codes,
// and the top 5 crimes committed with descriptions and number of times they were committed. 
//
// Author: Joshua Herman
// Date: 7/10/2020
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "classes.h"


using namespace std;
//TODO: TOP N Crimes 
//TODO: TOP N Crimes per area
//TODO: N Crime Codes 
//TODO: Match area name to area if possible
//TODO: Crimes that lead to most arrests
//TODO: Crimes that lead to least arrests
//TODO: Refactoring
//TODO: Event driven loop
//TODO: Improve runtime speed 
//TODO: Improve user-interaction texts 
/**
* Inputs the crime codes into a vector. Parses the file for the IUCR code, primary
* description, and secondary description and then places that into a CrimeCode object using
* stringstream. This object is also initialized to 0 for its numCrimes counter.
* Takes in the filename as a string. Returns the vector that had the data inputted into it.
**/
vector<CrimeCode> InputCrimeCodes(string filename)
{
	ifstream file(filename); //ifstream for file
	string line;
	string code;
	string primaryDescription;
	string secondaryDescription;
	vector<CrimeCode> crimeCodes; //vector of crime codes 
	int numCrimes = 0; //number of crimes from the code initialized to 0 
	getline(file, line); //skip first line

	while (getline(file, line)) //iterates through file
	{
		stringstream ss(line); //stringstream

							   //comma seperated values for parsing 
		getline(ss, code, ',');
		getline(ss, primaryDescription, ',');
		getline(ss, secondaryDescription);

		//CrimeCode object
		CrimeCode CC(code, primaryDescription, secondaryDescription, numCrimes);

		//object is pushed to the back of the vector
		crimeCodes.push_back(CC);
	}
	//return the vector after file is parsed
	return crimeCodes;
}
/**
* Inputs the crime report into a vector. The file to be parsed is a csv file and contains the
* data of dateTime, IUCR code, arrested, domestic violence, beat, district, ward, community,
* and year. All of these will be placed in a CrimeReport object which will then be placed
* in a vector. Takes in the filename as a parameter. Return the crimereport vector.
*
**/
vector<CrimeReport> InputCrimeReport(string filename)
{
	ifstream file(filename); //ifstream for file 
	vector<CrimeReport> crimeReports; //vector of CrimeReport

	string dateTime;
	string code;
	string arrest;
	string domes;
	string beat;
	string district;
	string ward;
	string community;
	string year;
	string line;

	getline(file, line); //skip first line

	while (getline(file, line)) //iterates through file 
	{
		//used to see if user was arrested or did domestic violence
		bool arrested;
		bool domestic;

		stringstream ss(line); //stringstream

							   //parsing csvs
		getline(ss, dateTime, ',');
		getline(ss, code, ',');
		getline(ss, arrest, ',');
		getline(ss, domes, ',');
		getline(ss, beat, ',');
		getline(ss, district, ',');
		getline(ss, ward, ',');
		getline(ss, community, ',');
		getline(ss, year);

		//arrested or dometic violence can come in two ways all capitalized or non capitalized 
		// this converts it to a boolean after seeing the string that was inputted.
		if (domes == "true" || domes == "TRUE")
			domestic = true;
		if (domes == "false" || domes == "FALSE")
			domestic = false;
		if (arrest == "true" || arrest == "TRUE")
			arrested = true;
		if (arrest == "false" || arrest == "FALSE")
			arrested = false;

		//CrimeReport object with all of the data 
		CrimeReport CR(dateTime, code, arrested, domestic, stoi(beat), stoi(district), stoi(ward), stoi(community), stoi(year));

		//pushed the CrimeReport object to the back of the vector 
		crimeReports.push_back(CR);
	}
	return crimeReports; //returns the vector
}

/**
*  Sort the crime codes ascending and prints the first 3 and the last 3 of the crime codes,
*  along with their IUCR, primaryDescription, and secondaryDescription.
*  Uses std::sort to sort the crime codes. Also prints the number of crime codes
*  No return. Inputs a vector of crime codes as input
**/
void sortCrimeCodesAndPrint(vector<CrimeCode>& CC)
{
	//sort the vector by IUCR codes ascending
	sort(CC.begin(), CC.end(),
		[](CrimeCode a, CrimeCode b)
	{
		if (a.GetCode() < b.GetCode())
			return true;
		else
			return false;
	});

	//size of the vector 
	int numofCrimeCodes = CC.size();

	cout << "# of crime codes: " << numofCrimeCodes << endl;

	//prints the first 3 codes with their code, primaryDescription, and secondaryDescription
	for (int i = 0; i < 3; i++)
	{
		cout << CC[i].GetCode() << ": \t" << CC[i].GetPrimaryDescription() << ":" << CC[i].GetSecondaryDescription() << endl;
	}

	cout << "..." << endl;

	//prints the last 3 codes with their code, primaryDescription, and secondaryDescription
	for (int i = numofCrimeCodes - 3; i < CC.size(); i++)
	{
		cout << CC[i].GetCode() << ": \t" << CC[i].GetPrimaryDescription() << ":" << CC[i].GetSecondaryDescription() << endl;
	}
	cout << endl;
	return;
}
/**
*  Prints the crime reports by printing the first 3 crimeReports and the last 3 crimeReports.
*  Also prints out the number of crimeReports. The data of the crimeReports being printed is
*  the IUCR code, the DateTime, the beat, the district, the ward, and the community. It
*  would also print out if domestic violence or an arrested occured or if both occured.
*  Takes in a vector of CrimeReport in that has the crimeReports and a paramter. No return.
**/
void printCrimeReports(vector<CrimeReport> crimeReports)
{
	int numOfCrimeReports = crimeReports.size(); //gets size of vector
	cout << "# of crimes: " << numOfCrimeReports << endl;

	/**
	* Prints the first 3 crimes along with IUCR code, the DateTime, the beat, the district, the ward, and
	* the community
	**/
	for (int i = 0; i < 3; i++)
	{
		cout << crimeReports[i].GetCode() << ": \t" << crimeReports[i].GetDateTime() << ", " << crimeReports[i].GetBeat() << ", " << crimeReports[i].GetDistrict() << ", " << crimeReports[i].GetWard() << ", " << crimeReports[i].GetCommunity();
		if (crimeReports[i].GetArrested() == true && crimeReports[i].GetDomestic() == true)
			cout << ", arrested, domestic violence";
		else if (crimeReports[i].GetDomestic() == true)
			cout << ", domestic violence";
		else if (crimeReports[i].GetArrested() == true)
			cout << ", arrested";
		cout << endl;
	}

	cout << "..." << endl;

	/**
	* Prints the last 3 crimes along with IUCR code, the DateTime, the beat, the district, the ward, and
	* the community
	**/

	for (int i = numOfCrimeReports - 3; i < numOfCrimeReports; i++)
	{
		cout << crimeReports[i].GetCode() << ": \t" << crimeReports[i].GetDateTime() << ", " << crimeReports[i].GetBeat() << ", " << crimeReports[i].GetDistrict() << ", " << crimeReports[i].GetWard() << ", " << crimeReports[i].GetCommunity();
		if (crimeReports[i].GetArrested() == true && crimeReports[i].GetDomestic() == true)
			cout << ", arrested, domestic violence";
		else if (crimeReports[i].GetDomestic() == true)
			cout << ", domestic violence";
		else if (crimeReports[i].GetArrested() == true)
			cout << ", arrested";
		cout << endl;
	}
	cout << endl;
	return;
}
/**
* Prints the top 5 crimes commited from the data. To do this the program for each crime in
* crimeReports get the code of the crime, for each crimeCode in crimeCodes if the foundCode
* is equal to the code from the crime reports than we will update the number one crimes
* incrementing by 1. Them we sort the crimCodes vector by the number of crimes descending.
* and print out the top 5. It also prints the number of times each crime was committed
* The parameters taken in are a vector of CrimeCode and a vector of CrimeReport. No return.
*
**/
void printTop5Crimes(vector<CrimeCode>& crimeCodes, vector<CrimeReport>& crimeReports)
{
	cout << "** Top-5 Crimes **" << endl;
	cout << "Code: \tTotal, Description" << endl;

	//for each crime report
	for (const CrimeReport& a : crimeReports)
	{
		string foundCode = a.GetCode(); //get the code 

		for (CrimeCode& b : crimeCodes) // for each code 
		{
			if (foundCode == b.GetCode()) //find if code is the crimeReports code. 
			{
				b.UpdateNumCrimes(); //increment the codes number of crimes.
			}
		}
	}

	//sort by the number of crimes descending. 
	sort(crimeCodes.begin(), crimeCodes.end(),
		[&](CrimeCode a, CrimeCode b)
	{
		if (a.GetNumCrimes() > b.GetNumCrimes())
			return true;
		else
			return false;
	});

	//iterate through the top 5 crimes and print them out along with their code and descriptions. 
	for (int i = 0; i < 5; i++)
	{
		cout << crimeCodes[i].GetCode() << ": \t" << crimeCodes[i].GetNumCrimes() << ", " << crimeCodes[i].GetPrimaryDescription() << ": " << crimeCodes[i].GetSecondaryDescription() << endl;
	}
	return;
}

int main()
{

	string  crimeCodesFilename, crimesFilename;

	//take in file names crimeCodes first then crimes file
	cin >> crimeCodesFilename;
	cout << crimeCodesFilename << endl;

	cin >> crimesFilename;
	cout << crimesFilename << endl;

	//ifstream
	ifstream  codesFile(crimeCodesFilename);
	ifstream  crimesFile(crimesFilename);

	cout << std::fixed;
	cout << std::setprecision(2);

	//check if both files are good if not quit program and give error 
	if (!codesFile.good())
	{
		cout << "**ERROR: cannot open crime codes file: '" << crimeCodesFilename << "'" << endl;
		return -1;
	}
	if (!crimesFile.good())
	{
		cout << "**ERROR: cannot open crimes file: '" << crimesFilename << "'" << endl;
		return -1;
	}

	//place the crime codes in a vector and return it
	auto crimeCodes = InputCrimeCodes(crimeCodesFilename);

	//place the crime reports in a vector and return it. 
	auto crimeReports = InputCrimeReport(crimesFilename);

	cout << "** Crime Analysis **" << endl << endl;

	//get the first and last day of crime reports by accesing front and back of the vector then print. 
	auto firstDay = crimeReports.front();
	auto lastDay = crimeReports.back();

	cout << "Date range: " << firstDay.GetDateTime() << " - " << lastDay.GetDateTime() << endl << endl;

	//sort by the crime codes then print first 3 and last 3 
	sortCrimeCodesAndPrint(crimeCodes);

	//print the crime reports 
	printCrimeReports(crimeReports);

	//print the top 5 crimes
	printTop5Crimes(crimeCodes, crimeReports);

	cout << endl << "** Done **";

	//return 0;
}


