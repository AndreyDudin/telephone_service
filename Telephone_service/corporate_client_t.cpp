
#include "corporate_client_t.h"


corporate_client_t::corporate_client_t()
{
}
corporate_client_t::corporate_client_t(std::string name, std::string addres, std::string bank_account, std::string company_name):
		client_t( name, addres,bank_account)
{
	company_name_ = company_name;
}

corporate_client_t::~corporate_client_t()
{
}
std::ostream& corporate_client_t::show_client(std::ostream& os)
{
	os << "Name:" << name_ << " " << "Adress:" << address_ << " " << "Bank account:" << bank_account_ << " "<<"Company name"<<company_name_<<std::endl;
	return os;
}
/*std::istream& operator>>(std::istream& is, corporate_client_t& client)
{
	is >> client.name_ >> client.address_ >> client.bank_account_ >> client.company_name_;
	return is;
}
*/
std::istream& corporate_client_t::get(std::istream& is)
{
	return is >> name_ >> address_ >> bank_account_ >>company_name_;
}

std::string corporate_client_t::to_string() const
{
	std::ostringstream stream;
	stream << "Name: " << name_ << " " << "Adress: " << address_ << " " << "Bank account: " << bank_account_<<" "<<"Company name: "<<company_name_;
	return stream.str();
}

std::string corporate_client_t::serialize() const
{
	std::ostringstream stream;
	stream << name_ << " " << address_ << " " << bank_account_ << " "<< company_name_;
	return stream.str();
}

