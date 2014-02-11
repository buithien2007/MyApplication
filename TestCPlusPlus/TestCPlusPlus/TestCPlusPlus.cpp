// TestCPlusPlus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////
//1. Get num of test case
int N;
bool CheckInput(int input)
{
	if(input<1 || input>100)
		return false;
	return true;
}

void GetNumOfTestCase()
{
	cout<<endl<<"Input num of test case: ";
	cin>>N;
	if(CheckInput(N))
	{
		return;
	}
	else
	{
		cout<<"Invalid input	'1' <= 'Num of test case' <= '100'	please try again";
		GetNumOfTestCase();
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//2. Get num of integers
int X;
void GetNumOfIntergers()
{
	cout<<endl<<"Input num of integer: ";
	cin>>X;
	if(CheckInput(X))
	{
		return;
	}
	else
	{
		cout<<"Invalid input	'1' <= 'Num of integer' <= '100'	please try again";
		GetNumOfIntergers();
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//3. Get test case
string strTestCase;
vector<int> output;

void StrTok(string str)//split string by white space
{
    int pos = str.find(" ");
    if(pos!=-1)
    {
        string strResult;
        strResult = str.substr(0,pos);
        output.push_back(atoi(strResult.c_str()));
        str = str.substr(pos+1);//pos+1 because str.at[pos] is white space so will skip it
        StrTok(str);   
    }
    else if(str.size()>0)
    {
        output.push_back(atoi(str.c_str()));
    }
}

void GetTestCase()
{
    cout<<"Input test case: ";
	flushall();
    getline(cin,strTestCase);
    StrTok(strTestCase);
    if(output.size()!=X)
    {
        cout<<"Test case must be contain "<<X<<" number of integer please try again"<<endl;
        strTestCase="";
        output.clear();
        GetTestCase();
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//4. Sum of square integer
int result;
vector<int> arrResult;
void SumOfSquareInts()
{
	X--;
	int x = output.at(X);
	if(x>0 && x<100)
		result+=x*x;
	if(X>0)
		SumOfSquareInts();
}

void RefreshTestCase()
{
	strTestCase="";
	output.clear();
	result = 0;
}

void HandleTestCase()
{
	if(N>0)
	{
		GetNumOfIntergers();
		GetTestCase();
		SumOfSquareInts();
		arrResult.push_back(result);
		N--;
		RefreshTestCase();
		HandleTestCase();
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//5. Print result
int count = 0;
void PrintResult()
{
	if(count<arrResult.size())
	{
		cout<<arrResult.at(count)<<endl;
		count++;
		PrintResult();
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//6. Main

int _tmain(int argc, _TCHAR* argv[])
{
	GetNumOfTestCase();
	HandleTestCase();
	PrintResult();
	return 0;
}