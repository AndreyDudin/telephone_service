
#include "web_t.h"


web_t::web_t(int number, int time, int duraction_of_connection, int input_traffic,int output_traffic)
	: services_t(number, time, duraction_of_connection)
{
	input_traffic_ = input_traffic;
	output_traffic_ = output_traffic;
}

web_t::web_t()
{
	
}
web_t::~web_t()
{

}

web_t* web_t::copy() const
{
	web_t* service = new web_t();
	service->number_ = number_;
	service->input_traffic_ = input_traffic_;
	service->time_ = time_;
	service->duraction_of_connection_ = duraction_of_connection_;
	service->output_traffic_ = output_traffic_;
	return service;
}

web_t& web_t::set_input(int n)
{
	input_traffic_ = n;
	return *this;
}

web_t& web_t::set_output(int n)
{
	output_traffic_ = n;
	return *this;
}

int web_t::get_MB()
{
	return output_traffic_ + input_traffic_;
}


int web_t::get_output()
{
	return output_traffic_;
}

std::ostream& web_t::show(std::ostream& os)
{
	os<< "Number:" << number_ << " " << "Time:" << time_ << " " << "Duraction of connection:" << duraction_of_connection_ << " "<<"Input traffic"<<input_traffic_<<" "<<"Output traffic"<<output_traffic_<<std::endl;
	return os;

}

/*std::istream& operator>>(std::istream& is, web_t& web)
{
	is >> web.number_ >> web.time_ >> web.duraction_of_connection_ >> web.input_traffic_>>web.output_traffic_;
	return is;
}
*/

std::istream& web_t::get(std::istream& is)
{
	return is >> number_ >> time_ >> duraction_of_connection_ >> input_traffic_ >> output_traffic_;
}

std::string web_t::to_string() const
{
	std::ostringstream stream;
	stream << "Number: " << number_ << " " << "Time: " << time_ << " " << "Duraction of connection: " << duraction_of_connection_ << " " << "Input traffic: " << input_traffic_ << " " << "Output traffic: " << output_traffic_;
	return stream.str();
}

std::string web_t::serialize() const
{
	std::ostringstream stream;
	stream<< "web"<<" " << number_ << " " << time_ << " " << duraction_of_connection_ << " " << input_traffic_ << " " << output_traffic_;
	return stream.str();
}

