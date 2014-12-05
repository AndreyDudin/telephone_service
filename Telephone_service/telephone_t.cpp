
#include "telephone_t.h"


telephone_t::telephone_t()
{

}


telephone_t::~telephone_t()
{
}

telephone_t* telephone_t::copy() const
{
	telephone_t* service = new telephone_t();
	service->number_ = number_;
	service->time_ = time_;
	service->duraction_of_connection_ = duraction_of_connection_;
	return service;
}

std::string telephone_t::to_string() const
{
	std::ostringstream stream;
	stream << "Number:" << number_ << " " << "Time:" << time_ << " " << "Duraction of connection: " << duraction_of_connection_;
	return stream.str();
}

std::string telephone_t::serialize() const
{
	std::ostringstream stream;
	stream << number_ << " " << time_ << " " << duraction_of_connection_;
	return stream.str();
}


