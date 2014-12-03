#include "fax_t.h"


fax_t::fax_t(int number, int time, int duraction_of_connection, int amount_of_information)
	: services_t(number, time, duraction_of_connection)
{
	amount_of_information_ = amount_of_information;
}
fax_t::fax_t()
{
	
}

fax_t::~fax_t()
{
}
std::ostream& fax_t::show(std::ostream& os)
{
	os<< "Number:" << number_ << " " << "Time:" << time_ << " " << "Duraction of connection:" << duraction_of_connection_ << " "<<"Amount of information"<<amount_of_information_<<std::endl;
	return os;
}

int fax_t::get_amount_of_information()
{
	return amount_of_information_;
}

fax_t* fax_t::copy() const
{
	fax_t* service = new fax_t();
	service->number_ = number_;
	service->time_ = time_;
	service->duraction_of_connection_ = duraction_of_connection_;
	service->amount_of_information_ = amount_of_information_;
	return service;
}


fax_t& fax_t::set_amount_of_information(int n)
{
	amount_of_information_ = n;
	return *this;
}

/*std::istream& operator>>(std::istream& is, fax_t& fax)
{
	is >> fax.number_ >> fax.time_ >> fax.duraction_of_connection_>>fax.amount_of_information_;
	return is;
}
*/
std::istream& fax_t::get(std::istream& is)
{
	return is >> number_ >> time_ >> duraction_of_connection_ >> amount_of_information_;
}
