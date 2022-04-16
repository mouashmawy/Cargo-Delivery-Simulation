#include "Time.h"

Time::Time() : day(0), hour(0) {}

Time::Time(int d, int h) {

	try {
		if (d < 0) throw std::string("Days cannot be negative");
		if (h < 0 || h >= 24) throw std::string("Invalid Hour");
		this->day = d;
		this->hour = h;
	}
	catch (std::string e)
	{
		std::cout << "Value Error: " << e << std::endl;
		exit(1);
	}

}

int Time::GetDay() const { return this->day; }
int Time::GetHour() const { return this->hour; }

void Time::SetDay(int d) {
	try {
		if (d < 0) throw std::string("Days cannot be negative");
		this->day = d;
	}
	catch (std::string e)
	{
		std::cout << "Value Error: " << e << std::endl;
		exit(1);
	}
}

void Time::SetHour(int h) {
	try {
		if (h < 0 || h >= 24) throw std::string("Invalid Hour");
		this->hour = h;
	}
	catch (std::string e)
	{
		std::cout << "Value Error: " << e << std::endl;
		exit(1);
	}
}


Time Time::operator-(Time other) {

	try {
		if ((this->day < other.day) || (this->day == other.day && this->hour < other.hour)) { throw std::string("Invalid operands!"); }

		int newDay, newHour;
		if (this->hour < other.hour) {
			newDay = this->day - other.day - 1;
			newHour = 24 - (other.hour - this->hour);
		}
		else {
			newDay = this->day - other.day;
			newHour = this->hour - other.hour;
		}
		Time t(newDay, newHour);
		return t;
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(1);
	}
}


Time Time::operator+(Time other) {
	int newDay, newHour;
	if (this->hour + other.hour >= 24) {
		newDay = this->day + other.day + 1;
		newHour = this->hour + other.hour - 24;
	}
	else {
		newDay = this->day + other.day;
		newHour = this->hour + other.hour;
	}

	Time t(newDay, newHour);
	return t;
}