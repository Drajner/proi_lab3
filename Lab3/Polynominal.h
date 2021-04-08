#pragma once
#include <vector>
#include <sstream>
#include <array>

typedef std::vector<std::vector<float>> vov; // abbreviation from vector of vectors, used to not write the same formula over and over

vov operator<<(vov first_vov, vov second_vov); // overloading operator so I can set value of one vov to other one

class Polynominal
{
	private:
		vov elements_;
	public:
		Polynominal(vov parts);
		float get_element(float factor);
		int set_element(float factor, float new_value);
		vov get_elements();
		void set_elements(vov new_elements);


};

std::ostream& operator<<(std::ostream& os, Polynominal expression);

Polynominal operator+(Polynominal expression1, Polynominal expression2);
Polynominal operator-(Polynominal expression1, Polynominal expression2);
Polynominal operator*(Polynominal expression1, Polynominal expression2);
Polynominal operator+=(Polynominal& expression1, Polynominal expression2);
Polynominal operator-=(Polynominal& expression1, Polynominal expression2);
Polynominal operator*=(Polynominal& expression1, Polynominal expression2);

Polynominal operator+(Polynominal expression1, float number);
Polynominal operator-(Polynominal expression1, float number);
Polynominal operator*(Polynominal expression1, float number);
Polynominal operator/(Polynominal expression1, float number);
Polynominal operator+=(Polynominal& expression1, float number);
Polynominal operator-=(Polynominal& expression1, float number);
Polynominal operator*=(Polynominal& expression1, float number);
Polynominal operator/=(Polynominal& expression1, float number);

float operator<<(Polynominal& expression1, float number); // this is oprerator for getting value from polynominal like this : value = polynominal << number