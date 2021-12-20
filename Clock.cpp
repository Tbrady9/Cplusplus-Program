/*
* Clock.cpp
* 
* Date: November 10, 2021
* Author: Tim Brady
* 
*/

#include "clock.h"
#include <Windows.h>

// constructor
Clock::Clock() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

// constructor with parameters
Clock::Clock(int hour, int minute, int second) {
    setHours(hour);
    setMinutes(minute);
    setSeconds(second);
}

// setters and getters
// hours
void Clock::setHours(int hour) {
	if (hours < 24) {
		hours = hour;
	}
	else hours = 0;
}
int Clock::getHours() {
	return hours;
}

// minutes
void Clock::setMinutes(int minute) {
	if (minutes < 60) {
		minutes = minute;
	}
	else {
		minutes = 0;
		if (hours < 24) {
			++hours;
		}
		else {
			hours = 0;
		}
	}
}
int Clock::getMinutes() {
	return minutes;
}

// seconds
void Clock::setSeconds(int second) {
	if (seconds < 60) {
		seconds = second;
	}
	else {
		seconds = 0;
		if (minutes < 59) {
			++minutes;
		}
		else {
			minutes = 0;
			if (hours < 23) {
				++hours;
			}
			else {
				hours = 0;
			}
		}
	}
}
int Clock::getSeconds() {
	return seconds;
}

// functions to display both clocks
// 24 hour clock
void Clock::display24() {
	printf("%02d:%02d:%02d", hours, minutes, seconds);
}

// 12 hour clock
void Clock::display12() {
	if (hours > 12 && hours > 0) {
		printf("%02d:%02d:%02d", hours - 12, minutes, seconds);
		cout << " PM";
	}
	else if (hours == 12) {
		printf("%02d:%02d:%02d", hours, minutes, seconds);
		cout << " PM";
	}
	else if (hours == 0) {
		printf("%02d:%02d:%02d", hours + 12, minutes, seconds);
		cout << " AM";
	}
	else {
		printf("%02d:%02d:%02d", hours, minutes, seconds);
		cout << " AM";
	}
}

// increment hours
void Clock::incrementHour() {
	hours += 1;
	setHours(hours);
}

// increment minutes
void Clock::incrementMinute() {
	minutes += 1;
	setMinutes(minutes);
}

// increment seconds
void Clock::incrementSecond() {
	seconds += 1;
	setSeconds(seconds);
}

// timer to constantly update the clock
void Clock::timer() {
	Sleep(1000);
	if (seconds < 59) {
		++seconds;
	}
	else {
		if (minutes < 59) {
			++minutes;
			seconds = 0;
		}
		else {
				++hours;
			minutes = 0;
			seconds = 0;
		}
	}
}

// function to display time in 12 hour and 24 hour format
void display(Clock clock) {
	cout << "******************************  ******************************" << endl;
	cout << " *     12 - Hour Clock       *  *       24 - Hour Clock      *" << endl;
	cout << " *        ";
	clock.display12();
	cout << "        *  *          ";
	clock.display24();
	cout << "          *" << endl;
	cout << " *****************************  ******************************" << endl;
}

// function to display menu and read user input
int menu() {
		int opt;
		cout << endl << endl;
		cout << "                ******************************" << endl;
		cout << "                * 1 - Add One Hour           *" << endl;
		cout << "                * 2 - Add One Minute         *" << endl;
		cout << "                * 3 - Add One Second         *" << endl;
		cout << "                * 4 - Exit Program           *" << endl;
		cout << "                ******************************" << endl;
		cin >> opt;
		return opt;
}
