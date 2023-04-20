#include<iostream>
class Cdate {
	private:
		int year;
		int month;
		int day;
	private:
		int check(const Cdate& date);
	public:
		Cdate();
		Cdate(int y, int m, int d);
		Cdate(const Cdate& date);
		Cdate(char* date);

		~Cdate();

		Cdate& operator=(const Cdate& date);	// операция присваивания
		Cdate& operator+=(const Cdate& date);	// операция присваивания
		Cdate& operator-=(const Cdate& date);	// операция присваивания
		

		Cdate operator+(const Cdate& date);	
		Cdate operator-(const Cdate& date);	
		

		bool operator==(const Cdate& date) const;	// операция сравнения
		bool operator!=(const Cdate& date) const;	// операция сравнения
		bool operator> (const Cdate& date) const;	// операция сравнения
		bool operator< (const Cdate& date) const;	// операция сравнения
		bool operator<=(const Cdate& date) const;	// операция сравнения
		bool operator>=(const Cdate& date) const;	// операция сравнения

		friend std::ostream& operator<<(std::ostream& out, const Cdate& date);
		friend std::istream& operator>>(std::istream& in, Cdate& date);
};


std::ostream& operator<<(std::ostream& out, const Cdate& date);
std::istream& operator>>(std::istream& in, Cdate& date);