#include "Polynominal.h"
#include <iostream>
#include <vector>
#include <sstream>


bool is_zero_condition(std::vector<float> part)
{
	return part[1] == 0;
}

Polynominal::Polynominal(vov parts)
{
	for (auto part : parts)
	{	
		elements_.push_back(part);
	}
}

vov Polynominal::get_elements()
{
	return elements_;
}

void Polynominal::set_elements(vov new_elements)
{
	elements_.clear();
	for (auto& part : new_elements)
	{
		elements_.push_back(part);
	}
	//elements_ << new_elements;
}

float Polynominal::get_element(float factor)
{
	for (auto& part : elements_)
	{
		if (part[0] == factor) return part[1];
	}
	return 0;
}

int Polynominal::set_element(float factor, float new_value)
{
	for (auto& part : elements_)
	{
		if (part[0] == factor)
		{
			part[1] = new_value;
			if (new_value == 0)
			{
				elements_.erase(std::remove(elements_.begin(), elements_.end(), part), elements_.end());
			}
			return 0;
		}
	}
	std::vector<float> new_part = { factor, new_value };
	elements_.emplace_back(new_part);
	return 0;
}

Polynominal operator+(Polynominal expression1, float number)
{
	vov new_elements;
	for (auto& part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	Polynominal new_polynominal(new_elements);
	float new_value = new_polynominal.get_element(0) + number;
	new_polynominal.set_element(0, new_value);
	return new_polynominal;
}

Polynominal operator-(Polynominal expression1, float number)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	Polynominal new_polynominal(new_elements);
	float new_value = new_polynominal.get_element(0) - number;
	new_polynominal.set_element(0, new_value);
	return new_polynominal;
}

Polynominal operator*(Polynominal expression1, float number)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	for (auto& part : new_elements)
	{
		part[1] *= number;
	}
	Polynominal new_polynominal(new_elements);
	return new_polynominal;
}

Polynominal operator/(Polynominal expression1, float number)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	for (auto& part : new_elements)
	{
		part[1] /= number;
	}
	Polynominal new_polynominal(new_elements);
	return new_polynominal;
}

Polynominal operator+=(Polynominal& expression1, float number)
{
	expression1.set_element(0, expression1.get_element(0) + number);
	return expression1;
}

Polynominal operator-=(Polynominal& expression1, float number)
{
	expression1.set_element(0, expression1.get_element(0) - number);
	return expression1;
}

Polynominal operator*=(Polynominal& expression1, float number)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	for (auto& part : new_elements)
	{
		part[1] *= number;
	}
	expression1.set_elements(new_elements);
	return expression1;
}

Polynominal operator/=(Polynominal& expression1, float number)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	for (auto& part : new_elements)
	{
		part[1] /= number;
	}
	expression1.set_elements(new_elements);
	return expression1;
}

std::ostream& operator<<(std::ostream& os, Polynominal expression)
{
	vov elements;
	for (auto part : expression.get_elements())
	{
		elements.push_back(part);
	}
	bool is_first = true;
	for (auto part : elements)
	{
		if (is_first)
		{
			if (part[0] == 0)
			{
				os << part[1] << ' ';
			}
			else
			{
				os << part[1] << "x^" << part[0] <<' ';
			}
			is_first = false;
		}
		else
		{
			if (part[1] >= 0)
			{
				os << '+' << ' ';
			}
			if (part[0] == 0)
			{
				os << part[1] << ' ';
			}
			else
			{
				os << part[1] << "x^" << part[0] << ' ';
			}

		}

	}
	os << std::endl;
	return os;

}

float operator<<(Polynominal& expression1, float number)
{
	float exp_value = 0;
	float exp_part_value = 1;
	for (auto part : expression1.get_elements())
	{
		float exp_part_value = 1;
		if (part[0] == 0)
		{
			exp_part_value = part[1];
		}
		else
		{
			for (int i = 0; i < part[0]; i++)
			{
				exp_part_value *= number;
			}
			exp_part_value *= part[1];
		}
		exp_value += exp_part_value;
		
	}
	return exp_value;
}

Polynominal operator+(Polynominal expression1, Polynominal expression2)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	bool it_got_added = false;
	for (auto& second_part : expression2.get_elements())
	{
		it_got_added = false;
		for (auto& first_part : new_elements)
		{
			if (second_part[0] == first_part[0])
			{
				first_part[1] += second_part[1];
				it_got_added = true;
				break;
			}
		}
		if (!it_got_added)
		{
			new_elements.emplace_back(second_part);
		}
	}
	new_elements.erase(std::remove_if(new_elements.begin(), new_elements.end(), is_zero_condition), new_elements.end());
	Polynominal new_polynominal(new_elements);
	return new_polynominal;
}
Polynominal operator-(Polynominal expression1, Polynominal expression2)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	bool it_got_added = false;
	std::vector<float> temporary_part = { 0, 0 };
	for (auto& second_part : expression2.get_elements())
	{
		it_got_added = false;
		for (auto& first_part : new_elements)
		{
			if (second_part[0] == first_part[0])
			{
				first_part[1] -= second_part[1];
				
				it_got_added = true;
				break;
			}
		}
		if (!it_got_added)
		{
			temporary_part[1] = -second_part[1];
			temporary_part[0] = second_part[0];
			new_elements.emplace_back(temporary_part);
		}
	}
	new_elements.erase(std::remove_if(new_elements.begin(), new_elements.end(), is_zero_condition), new_elements.end());
	Polynominal new_polynominal(new_elements);
	return new_polynominal;
}
Polynominal operator*(Polynominal expression1, Polynominal expression2)
{
	vov even_newer_elements;
	for (auto part : expression1.get_elements())
	{
		even_newer_elements.push_back(part);
	}
	Polynominal returning_polynominal(even_newer_elements);
	Polynominal temporary_polynominal(even_newer_elements);
	bool first_expression = true;
	for (auto& second_part : expression2.get_elements())
	{
		even_newer_elements.clear();
		for (auto part : expression1.get_elements())
		{
			even_newer_elements.push_back(part);
		}
		for (auto& first_part : even_newer_elements)
		{
			first_part[0] += second_part[0];
			first_part[1] *= second_part[1];
		}
		if (first_expression)
		{
			returning_polynominal.set_elements(even_newer_elements);
			first_expression = false;
		}
		else
		{
			temporary_polynominal.set_elements(even_newer_elements);
			returning_polynominal += temporary_polynominal;
		}
	}
	even_newer_elements.erase(std::remove_if(even_newer_elements.begin(), even_newer_elements.end(), is_zero_condition), even_newer_elements.end());
	return returning_polynominal;
}
Polynominal operator+=(Polynominal& expression1, Polynominal expression2)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	bool it_got_added = false;
	for (auto& second_part : expression2.get_elements())
	{
		it_got_added = false;
		for (auto& first_part : new_elements)
		{
			if (second_part[0] == first_part[0])
			{
				first_part[1] += second_part[1];
				it_got_added = true;
				break;
			}
		}
		if (!it_got_added)
		{
			new_elements.emplace_back(second_part);
		}
	}
	new_elements.erase(std::remove_if(new_elements.begin(), new_elements.end(), is_zero_condition), new_elements.end());
	expression1.set_elements(new_elements);
	return expression1;
}
Polynominal operator-=(Polynominal& expression1, Polynominal expression2)
{
	vov new_elements;
	for (auto part : expression1.get_elements())
	{
		new_elements.push_back(part);
	}
	bool it_got_added = false;
	std::vector<float> temporary_part = { 0, 0 };
	for (auto& second_part : expression2.get_elements())
	{
		it_got_added = false;
		for (auto& first_part : new_elements)
		{
			if (second_part[0] == first_part[0])
			{
				first_part[1] -= second_part[1];
				it_got_added = true;
				break;
			}
		}
		if (!it_got_added)
		{
			temporary_part[1] = -second_part[1];
			temporary_part[0] = second_part[0];
			new_elements.emplace_back(temporary_part);
		}
	}
	new_elements.erase(std::remove_if(new_elements.begin(), new_elements.end(), is_zero_condition), new_elements.end());
	expression1.set_elements(new_elements);
	return expression1;
}
Polynominal operator*=(Polynominal& expression1, Polynominal expression2)
{
	vov even_newer_elements;
	for (auto part : expression1.get_elements())
	{
		even_newer_elements.push_back(part);
	}
	Polynominal returning_polynominal(even_newer_elements);
	Polynominal temporary_polynominal(even_newer_elements);
	bool first_expression = true;
	for (auto& second_part : expression2.get_elements())
	{
		even_newer_elements.clear();
		for (auto part : expression1.get_elements())
		{
			even_newer_elements.push_back(part);
		}
		for (auto& first_part : even_newer_elements)
		{
			first_part[0] += second_part[0];
			first_part[1] *= second_part[1];
		}
		if (first_expression)
		{
			returning_polynominal.set_elements(even_newer_elements);
			first_expression = false;
		}
		else
		{
			temporary_polynominal.set_elements(even_newer_elements);
			returning_polynominal += temporary_polynominal;
		}
	}
	even_newer_elements.erase(std::remove_if(even_newer_elements.begin(), even_newer_elements.end(), is_zero_condition), even_newer_elements.end());
	expression1.set_elements(returning_polynominal.get_elements());
	return expression1;
}
