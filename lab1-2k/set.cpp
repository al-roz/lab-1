#include "set.hpp"

int Set::find_str_in_setarray(std::string elem)
{
	for (int i = 0; i < size; i++)
		if (setarray[i] == elem)return i;

	return -1;
		
}

std::string Set::find_zero_elem(void)
{
	for (int i = 0; i < size; i++)
		if (plus(setarray[0], setarray[i]) == setarray[0]) return setarray[i];
	std::cout << "set without zero elem";
	exit(2);
}

std::string Set::find_unit_elem(void)
{
	int k = 0;
	if (setarray[0] == zero_elem)k++;
	for (int i = 0; i < size; i++)
		if (mult(setarray[k], setarray[i]) == setarray[k]) return setarray[i];
	std::cout << "set without unit elem";
	exit(2);
}

bool Set::comutotivity_for_plus(void)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (mas_rule_for_plus[i][j] != mas_rule_for_plus[j][i])return false;
		}
	}

	return true;
}

bool Set::associativity_for_plus(void)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if (plus(plus(mas_rule_for_plus[i][j],mas_rule_for_plus[i][k]),mas_rule_for_plus[j][k]) != 
					plus(mas_rule_for_plus[i][j], plus(mas_rule_for_plus[i][k], mas_rule_for_plus[j][k]))) return false;
			}
		}
	}
	return true;
}

bool Set::check_zero_elem(void)
{
	for (int i = 0; i < size; i++)
		if (plus(setarray[i], zero_elem) != setarray[i]) return false;
	return true;
}

bool Set::back_for_plus(void)
{
	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		for (int j = 0; j < size; j++)
		{
			if (plus(setarray[i],setarray[j]) == zero_elem) flag = true;
		}
		if (flag == false) return false;
	}
	return true;
}

bool Set::comutotivity_for_mult(void)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (mas_rule_for_mult[i][j] != mas_rule_for_mult[j][i])return false;
		}
	}

	return true;
}

bool Set::associativity_for_mult(void)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if (mult(mult(mas_rule_for_mult[i][j], mas_rule_for_mult[i][k]), mas_rule_for_mult[j][k]) !=
					mult(mas_rule_for_mult[i][j], mult(mas_rule_for_mult[i][k], mas_rule_for_mult[j][k]))) return false;
			}
		}
	}
	return true;
}

bool Set::check_unit_elem(void)
{
	for (int i = 0; i < size; i++)
		if (setarray[i] != zero_elem)
			if (mult(setarray[i], unit_elem) != setarray[i]) return false;
	return true;
}

bool Set::back_for_mult(void)
{
	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		if (setarray[i] != zero_elem)
		{
			for (int j = 0; j < size; j++)
			{
				if (mult(setarray[i], setarray[j]) == unit_elem) flag = true;
			}
			if (flag == false) return false;
		}
	}
	return true;
}

bool Set::distributiveness(void)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if (mult(plus(setarray[i], setarray[j]), setarray[k]) != plus(mult(setarray[i], setarray[k]), mult(setarray[j], setarray[k]))) return false;
			}
		}
	}
	return true;
}



Set::Set(std::string filename)
{
	std::ifstream input;
	input.open(filename);
	std::string str; 
	std::getline(input, str);
	this->size = atoi(str.c_str());

	for (int i = 0; i < size; i++)
	{
		input >> str;
		this->setarray.push_back(str);
	}
	for (int i = 0; i < size; i++)
	{
		std::vector<std::string> mas_str;
		for (int j = 0; j < size; j++)
		{
			input >> str;
			mas_str.push_back(str);
		}
		mas_rule_for_plus.push_back(mas_str);
	}
	
	for (int i = 0; i < size; i++)
	{
		std::vector<std::string> mas_str;
		for (int j = 0; j < size; j++)
		{
			input >> str;
			mas_str.push_back(str);
		}
		mas_rule_for_mult.push_back(mas_str);
	}
	zero_elem = find_zero_elem();
	unit_elem = find_unit_elem();

}

//TODO
bool Set::chek_on_field(void)
{
	std::cout << "comutotivity " << comutotivity_for_plus() << std::endl;
	std::cout << "associativity " << associativity_for_plus() << std::endl;
	std::cout << "zero_elem " << check_zero_elem() << std::endl;
	std::cout << "back_elem "<< back_for_plus() << std::endl;
	std::cout << "comutotivity " << comutotivity_for_mult() << std::endl;
	std::cout << "associativity " << associativity_for_mult() << std::endl;
	std::cout << "unit_elem " << check_unit_elem() << std::endl;
	std::cout << "back_elem " << back_for_mult() << std::endl;
	std::cout << "distributiveness " << distributiveness() << std::endl;
	return true;
}

void Set::output()
{
	std::cout << "size : " <<size << std::endl;
	std::cout << "array for plus" << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			std::cout << mas_rule_for_plus[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "array for mult" << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			std::cout << mas_rule_for_mult[i][j] << " ";
		std::cout << std::endl;
	}
}

std::string Set::plus(std::string first_elem, std::string second_elem)
{	
	std::pair<int, int> pos;
	pos.first = find_str_in_setarray(first_elem);
	pos.second = find_str_in_setarray(second_elem);
	if (pos.first == -1 || pos.second == -1)
	{
		std::cout << "uncorrect elem";
		exit(1);
	}
	return mas_rule_for_plus[pos.first][pos.second];
}

std::string Set::mult(std::string first_elem, std::string second_elem)
{
	std::pair<int, int> pos;
	pos.first = find_str_in_setarray(first_elem);
	pos.second = find_str_in_setarray(second_elem);
	if (pos.first == -1 || pos.second == -1)
	{
		std::cout << "uncorrect elem";
		exit(1);
	}
	return mas_rule_for_mult[pos.first][pos.second];
}
