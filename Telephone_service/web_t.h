#pragma once
#include "services_t.h"
#include <string>

class web_t :public services_t
{
public:
	web_t();
	virtual ~web_t();
	web_t(int number, int time, int duraction_of_connection, int input_traffic, int output_traffic);
//	friend std::ostream& operator<<(std::ostream& os, services_t& service);
//	friend std::istream& operator>>(std::istream& is, web_t& web);
	int get_output();
	int get_MB();
	web_t& set_input(int);
	web_t& set_output(int);
	web_t* copy() const override;
	std::ostream& show(std::ostream& os);
	std::istream& get(std::istream&);

	 std::string to_string() const override;
	 std::string serialize() const override;
private:
	int input_traffic_;
	int output_traffic_;
};