#include <string>
#include "services_t.h"
#include "fax_t.h"
#include "web_t.h"


services_t::services_t(int number, int time, int duraction_of_connection)
	: number_(number)
	  , time_(time)
	  , duraction_of_connection_(duraction_of_connection)
{
}

services_t::~services_t()
{
}

services_t::services_t()
{

}
/*services_t* services_t::copy() const
{
	services_t* service = new services_t();
	(*service).number_ = number_;
	(*service).time_ = time_;
	(*service).duraction_of_connection_ = duraction_of_connection_;
	return service;
}
*/

int services_t::get_time()
{
	return time_;
}

services_t& services_t::set_time(int par)
{
	time_ = par;
	return *this;
}

std::ostream& services_t::show(std::ostream& os)
{
	os<< "Number:" << number_ << " " << "Time:" <<time_ << " " << "Duraction of connection:" <<duraction_of_connection_ << " ";
	return os;

}


std::ostream& operator<<(std::ostream& os, services_t const& service)
{
	return  os<<service.to_string();
}

std::istream& operator>>(std::istream& is, services_t & service)
{
	return service.get(is);

}
std::istream& services_t::get(std::istream& is)
{
	return is >> number_>> time_ >> duraction_of_connection_;
}

/*std::string type;
int time;
int number;
int duraction_of_connection;
int amount_of_information;
int input_traffic;
int output_traffic;

std::cout << "Enter the type of service" << std::endl;
std::cin >> type;
std::cout << "Enter the number of partner" << std::endl;
std::cin >> number;
std::cout << "Enter the time" << std::endl;
std::cin >> time;
std::cout << "Enter the duraction of connection" << std::endl;
std::cin >> duraction_of_connection;

if (type == "telephone")
{
services_t* new_service = new services_t(number, time, duraction_of_connection);
}
if (type == "fax")
{
std::cout << "Enter the amount of information" << std::endl;
std::cin >> amount_of_information;
services_t* new_service = new fax_t(number, time, duraction_of_connection, amount_of_information);
}
if (type == "web")
{
std::cout << "Enter the input traffic" << std::endl;
std::cin >> input_traffic;
std::cout << "Enter the output traffic" << std::endl;
std::cin >> output_traffic;
services_t* new_service = new web_t(number, time, duraction_of_connection, input_traffic, output_traffic);
}
*/