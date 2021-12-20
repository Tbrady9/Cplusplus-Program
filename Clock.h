/*
* Clock.h
*
* Date: November 10, 2021
* Author: Tim Brady
*
*/

#include<iostream>
using namespace std;

// create a class for clock
class Clock {
	// declaring private variables
private:
	int hours;
	int minutes;
	int seconds;

	// declaring public functions, setters and getters
public:
	Clock();
	Clock(int hour, int minute, int second);
	void setHours(int hours);
	int getHours();
	void setMinutes(int minutes);
	int getMinutes();
	void setSeconds(int seconds);
	int getSeconds();
	void display24();
	void display12();
	void incrementHour();
	void incrementMinute();
	void incrementSecond();
	void timer();
};