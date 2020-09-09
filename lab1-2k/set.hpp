#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Set
{

private:
	int size;
	std::string zero_elem;
	std::string unit_elem;
	std::vector <std::vector<std::string>> mas_rule_for_plus;
	std::vector <std::vector<std::string>> mas_rule_for_mult;
	std::vector <std::string> setarray;
	int find_str_in_setarray(std::string);
	std::string find_zero_elem(void);
	std::string find_unit_elem(void);
	bool comutotivity_for_plus(void);
	bool associativity_for_plus(void);
	bool check_zero_elem(void);
	bool back_for_plus(void);
	bool comutotivity_for_mult(void);
	bool associativity_for_mult(void);
	bool check_unit_elem(void);
	bool back_for_mult(void);
	bool distributiveness(void);
public:
	Set(std::string filename);
	bool chek_on_field(void);
	void output();
	std::string plus(std::string, std::string);
	std::string mult(std::string, std::string);
	//~Set();
};

