#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include<list>
#include <MMsystem.h>
using namespace std;

class MemoryMatchGame
{
public:

	MemoryMatchGame(void);
	void veryStart();
	void start(void);
	void play();
	void table(int rows);
	void end();


private:
	int size = 0;
	int timeInterval = 0;
	string cities[50] = { "Albany", "Ankara", "Berkeley", "Athens", "Baltimore", "Bangkok", "Berlin", "Cairo", "Chicago", "Delhi",
						 "Havana", "Helsinki", "Jerusalem", "Lisbon", "London", "Madrid", "Milan", "Moscow", "Mumbai", "Munich",
						 "Ottawa", "Oslo", "Paris", "Prague", "Santiago", "Stockholm", "Sydney", "Tokyo", "Toranto", "Venice",
						 "Vienna", "Washington", "Zurich", "Washington", "Tel Aviv", "Brussels", "Instanbul", "Granada", "Budapest", "Florence",
						 "cairo", "Athens", "Montreal", "Edinburgh", "Hanoi", "Dublin", "Krakow", "Kyoto", "Beijing", "Fes", };
	int horizontal1 = 0;
	int vertical1 = 0;
	int horizontal2 = 0;
	int vertical2 = 0;
	//int rows = 0;
	const int wordwidth = 11;
	const char initialSpace = ' ';
	int test = 0;
	int test2 = 0;
	int starting = 0;

};

