#include "telephone_service_t.h"


telephone_service_t::telephone_service_t()
{
}


telephone_service_t::~telephone_service_t()
{
}
void telephone_service_t::show_table()
{
	table_.show_table();
}

void telephone_service_t::write_to_file()
{
	std::ofstream f("service.dat");
	f << name_<<" ";
	f << payment_<<" ";
	f << minute_rate_<<" ";
	f << MB_rate_<<" ";
	f.close();
	table_.write_to_file();

}

telephone_service_t& telephone_service_t::read_from_file()
{
	std::ifstream f("service.dat");
	f >> name_;
	f >> payment_;
	f >> minute_rate_;
	f >> MB_rate_;
	f.close();
	table_.read_from_file();
	return *this;
}


telephone_service_t& telephone_service_t::add(subscriber_t sub)
{
	table_.add_element(sub);
	return *this;
}

double telephone_service_t::get_MB_rate()
{
	return MB_rate_;
}
double telephone_service_t::get_payment()
{
	return payment_;
}

double telephone_service_t::get_minute_rate()
{
	return minute_rate_;
}

/*int telephone_service_t::total_information(int n)
{
	return this.search(n).total_information();
}
*/

subscriber_t& telephone_service_t::search(int n)
{
	return table_.search(n);
}
/*telephone_service_t& telephone_service_t::add_service(services_t *service, int n)
{
	table_.search(n).add_service(service);
	return *this;
}
*/
int telephone_service_t::service_time()
{
	return table_.table_time();
}
int telephone_service_t::total_payment()
{
	return table_.table_time()*minute_rate_ + table_.table_MB()*MB_rate_;
}


