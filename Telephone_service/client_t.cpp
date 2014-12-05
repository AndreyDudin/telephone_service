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

std::ostream& operator<<(std::ostream& os, client_t const& client)
{
	return os << client.to_string();
}

std::istream& client_t::get(std::istream& is)
{
	return is >> name_ >> address_ >> bank_account_;
}


std::istream& operator>>(std::istream& is, client_t& client)
{
	return client.get(is);
}

std::string client_t::to_string() const
{
	std::ostringstream stream;
	stream << "Name: " << name_ << " " << "Adress: " << address_ << " " << "Bank account: " << bank_account_;
	return stream.str();
}

std::string client_t::serialize() const
{
	std::ostringstream stream;
	stream<<"client"<<" " << name_ << " " << address_ << " " << bank_account_;
	return stream.str();
}

