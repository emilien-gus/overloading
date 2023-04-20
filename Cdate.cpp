#include"Cdate.h"
#include"cstdlib"

Cdate::Cdate(){
	year = 0;
	month = 0;
	day = 0;

}
Cdate::Cdate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

Cdate::Cdate(const Cdate& date) {
	year = date.year;
	month = date.month;
	day = date.day;
}

Cdate::Cdate(char* str) {
	int buf[3];
	int i = 0;
	char seps[] = ".";
	char* token1 = NULL;
	char* next_token1 = NULL;

	token1 = strtok_s(str, seps, &next_token1);

	while (token1 != NULL)
	{

		if (token1 != NULL)
		{
			buf[i++] = atoi(token1);
			token1 = strtok_s(NULL, seps, &next_token1);
		}

	}
	day = buf[0];
	month = buf[1];
	year = buf[2];
}

Cdate::~Cdate(){
}

Cdate& Cdate::operator=(const Cdate& date) {
	year = date.year;
	month = date.month;
	day = date.day;
}

Cdate& Cdate::operator+=(const Cdate & date) {
	year = year + (date.month + (day + date.day)/30)/12;
	month  = (date.month + (day + date.day) / 30) % 12 ;
	day = (day + date.day)%30;
}

Cdate& Cdate::operator-=(const Cdate& date) {
	year = year - (abs(month - abs(day - date.day)/30)/ 12);
	month = (month - (abs(month - abs(day - date.day)/30))) % 12;
	day = abs(day - date.day) % 30;
	
}

Cdate Cdate::operator+(const Cdate & date) {
	year = year + (date.month + (day + date.day)/30)/12;
	month  = (date.month + (day + date.day) / 30) % 12 ;
	day = (day + date.day)%30;
}

Cdate Cdate::operator-(const Cdate& date) {
	year = year - (abs(month - abs(day - date.day)/30)/ 12);
	month = (month - (abs(month - abs(day - date.day)/30))) % 12;
	day = abs(day - date.day) % 30;
	
}

int Cdate::check(const Cdate& date) { 	
	
	if (year > date.year)
		return 1;
	
	else if (year < date.year)
		return 2;
	
	else {
		if (month > date.month)
			return 1;
		
		else if (month < date.month)
			return 2;

		else {
			if (day > date.day)
				return 1;

			else if (day < date.day)
				return 2;

			else
				return 0;
		}
	}
}

bool Cdate::operator==(const Cdate& date) const {
	Cdate d1(year, month, day);
	if (d1.check(date) == 0)
		return true;
	return false;
}

bool Cdate::operator!=(const Cdate& date) const {
	Cdate d1(year, month, day);
	if (d1.check(date) > 0)
		return true;
	return false;
}

bool Cdate::operator>(const Cdate& date) const {
	Cdate d1(year, month, day);
	if (d1.check(date) == 1)
		return true;
	return false;
}

bool Cdate::operator<(const Cdate& date) const {
	Cdate d1(year, month, day);
	if (d1.check(date) == 2)
		return true;
	return false;
}

bool Cdate::operator>=(const Cdate& date) const {
	Cdate d1(year, month, day);
	if (d1.check(date) == 0 || d1.check(date) == 1)
		return true;
	return false;
}

bool Cdate::operator<=(const Cdate& date) const {
	Cdate d1(year, month, day);
	if (d1.check(date) == 0 || d1.check(date) == 2)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, const Cdate& date){
	out << date.day << "." << date.month << "." << date.year;
	return out;

}

std::istream& operator>>(std::istream& in, Cdate& date) {
	char* buf;
	in >> buf;
}