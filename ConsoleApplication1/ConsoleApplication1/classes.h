/*classes.h*/

//
// Classes for use with Chicago Crime Analysis program, e.g. "CrimeReport" 
// and "CrimeCode".
//
// Joshua Herman
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

/**
* CrimeCode class. Stores data of the IUCR code, PrimaryDescription, SecondaryDescription, and
* number of crimes committed. Has getters for all of this data and a method that updates the number
* of times the crime was committed by incrementing.
**/
class CrimeCode
{
private:
	string Code; //IUCR code
	string PrimaryDescription;
	string SecondaryDescription;
	int NumCrimes; //Number of times the crime was committed 

public:
	CrimeCode(string code, string primaryDesc, string secondaryDesc, int numbcrimes)
		: Code(code), PrimaryDescription(primaryDesc), SecondaryDescription(secondaryDesc), NumCrimes(numbcrimes)
	{}

	//Gets and Returns IUCR Code
	string GetCode() const
	{
		return Code;
	}

	//Gets and Returns PrimaryDescription
	string GetPrimaryDescription() const
	{
		return PrimaryDescription;
	}

	//Gets and Returns SecondaryDescription
	string GetSecondaryDescription() const
	{
		return SecondaryDescription;
	}

	//Gets and Returns NumCrimes
	int GetNumCrimes() const
	{
		return NumCrimes;
	}

	//Updates the number of crimes committed by incrementing by 1. 
	void UpdateNumCrimes()
	{
		NumCrimes = NumCrimes + 1;
	}

};

/**
* CrimeReport class. Stores data of DateTime, IUCR Code, arrested, domestic violence, beat, district,
* ward, community, and year. Has getters for all of this data.
**/
class CrimeReport
{
private:
	string DateTime;
	string Code; //IUCR code 
	bool Arrested;
	bool Domestic;
	int Beat;
	int District;
	int Ward;
	int Community;
	int Year;
public:

	CrimeReport(string dateTime, string code, bool arrest, bool domestic, int beat, int dist, int ward, int commun, int yr)
		: DateTime(dateTime), Code(code), Arrested(arrest), Domestic(domestic), Beat(beat), District(dist), Ward(ward), Community(commun), Year(yr)
	{}

	//Gets and returns DateTime
	string GetDateTime() const
	{
		return DateTime;
	}

	//Gets and returns Code
	string GetCode() const
	{
		return Code;
	}

	//Gets and returns Arrested
	bool GetArrested() const
	{
		return Arrested;
	}

	//Gets and returns Domestic
	bool GetDomestic() const
	{
		return Domestic;
	}

	//Gets and returns Beat
	int GetBeat() const
	{
		return Beat;
	}

	//Gets and returns District
	int GetDistrict() const
	{
		return District;
	}

	//Gets and returns Ward
	int GetWard() const
	{
		return Ward;
	}

	//Gets and returns Comnunity
	int GetCommunity() const
	{
		return Community;
	}

	//Gets and returns Year
	int GetYear() const
	{
		return Year;
	}
};
