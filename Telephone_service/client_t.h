#pragma once
#include <string>
#include <iostream>

class client_t
{
public:
	client_t();

	virtual ~client_t();

	client_t(std::string name, std::string addres, std::string bank_account);

	virtual std::ostream& show_client(std::ostream& os);
	virtual std::istream& get(std::istream&);

	friend std::ostream& operator<<(std::ostream& os, client_t& client);
	friend std::istream& operator>>(std::istream& is, client_t& client);
protected:
	std::string name_;
	std::string address_;
	std::string bank_account_;
};