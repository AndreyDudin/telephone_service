#include "client_t.h"

client_t::client_t()
{
}


client_t::~client_t()
{
}

client_t::client_t(std::string name, std::string addres, std::string bank_account)
	: name_(name)
	, address_(addres)
	, bank_account_(bank_account)
{
}

std::ostream& client_t::show_client(std::ostream& os)
{
	 os<< "Name:" << name_ << " " << "Adress:" << address_ << " " << "Bank account:" << bank_account_ << " ";
	return os;
}

std::ostream& operator<<(std::ostream& os, client_t& client)
{
	return client.show_client(os);
}

std::istream& client_t::get(std::istream& is)
{
	return is >> name_ >> address_ >> bank_account_;
}


std::istream& operator>>(std::istream& is, client_t& client)
{
	return client.get(is);
}