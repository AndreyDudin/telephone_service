#include "subscriber_t.h"
#include "telephone_t.h"


subscriber_t::subscriber_t()
{
	client_ = nullptr;
	number_ = 0;
	amount_of_sessions_ = 0;
}


subscriber_t::~subscriber_t()
{
}

subscriber_t::subscriber_t(client_t& client, int n)
{
	client_ = &client;
	number_ = n;
	amount_of_sessions_ = 0;
	
}

void subscriber_t::show_services()
{
	std::cout << "Services:"<<std::endl;
	for (int i = 0; i < services_.size();i++)
	{
		std::cout <<i<<"." << *services_[i] << std::endl;
	}
}

subscriber_t& subscriber_t::set_web_input(int pos, int n)
{
	web_t* web = dynamic_cast<web_t*>(services_[pos]);
	(*web).set_input(n);
	return *this;

}

subscriber_t& subscriber_t::set_web_output(int pos, int n)
{
	web_t* web = dynamic_cast<web_t*>(services_[pos]);
	(*web).set_output(n);
	return *this;
}

::subscriber_t& ::subscriber_t::set_fax_amount(int pos, int n)
{
	fax_t* fax = dynamic_cast<fax_t*>(services_[pos]);
	(*fax).set_amount_of_information(n);
	return *this;
}


subscriber_t& subscriber_t::add_service(services_t *service)
{
	services_.push_back(service->copy());
	amount_of_sessions_++;
	return *this;
}


client_type subscriber_t::get_type() const
{
	if (corporate_client_t* corporate_client=dynamic_cast<corporate_client_t*>(this->client_))
	{
		return law_client;
	}
	else
	{
		return phys_client;
	}
}

services_t* subscriber_t::get_service(int n) const
{
	return services_[n];
}
int subscriber_t::get_number()
{
	return number_;
}
std::ostream& operator<<(std::ostream& os, const subscriber_t const& sub)
{
	return os << sub.to_string();
}
int subscriber_t::get_amount_of_sessions()
{
	return amount_of_sessions_;
}


int subscriber_t::total_output_information()
{
	int information = 0;
	for (int i = 0; i < services_.size(); i++)
	{
		if (web_t* serv = dynamic_cast<web_t*>(services_[i]))
		{
			information += (*serv).get_output();
		}
	}
	return information;

}

int subscriber_t::total_time()
{
	int time=0;
	for (int i = 0; i < services_.size(); i++)
	{
		time += (*services_[i]).get_time();
	}
	return time;
}

int subscriber_t::total_MB()
{
	int MB = 0;
	for (int i = 0; i < services_.size(); i++)
	{
		if (web_t* serv = dynamic_cast<web_t*>(services_[i]))
		{
			MB += (*serv).get_MB();
		}
		if (fax_t* serv = dynamic_cast<fax_t*>(services_[i]))
		{
			MB += (*serv).get_amount_of_information();
		}
	}
	return MB;
}



std::string subscriber_t::to_string() const
{
	std::ostringstream stream;
	stream << "Number: " <<number_<<" "<< "Amount: " <<amount_of_sessions_<<" " << *client_;
	return stream.str();
}
std::string subscriber_t::serialize() const
{
	std::ostringstream stream;
	stream << number_ << " " << amount_of_sessions_ << " "<< client_->serialize()<<" ";
	for (int i = 0; i < amount_of_sessions_; i++)
	{
		stream << (get_service(i)->serialize())<<" ";
	}
	return stream.str();
}

std::istream& operator>>(std::istream& is, subscriber_t& sub)
{
	client_t* client;
	std::string client_type;
	is >> sub.number_ >> sub.amount_of_sessions_;
	is >> client_type;
	if (client_type=="corporate")
	{
		client = new corporate_client_t;
		is>> *client;
	}
	else
	{
		client = new client_t;
		is >> *client;
	}
	sub.client_ = client;


	int n = sub.amount_of_sessions_;
	sub.amount_of_sessions_ = 0;
	for (int i = 0; i < n;i++)
	{
		std::string type;
		if (type == "telephone")
		{
			telephone_t services;
			is >> services;
			sub.add_service(&services);				
		}
		if (type == "fax")
		{
			fax_t services;
			is >> services;
			sub.add_service(&services);
		}
		if (type == "web")
		{
			web_t services;
			is >> services;
			sub.add_service(&services);
		}
	}
	return is;
}