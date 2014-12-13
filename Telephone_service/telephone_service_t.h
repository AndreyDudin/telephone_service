#pragma once
#include <string>
//#include "subscriber_t.h"
#include "subscriber_table_t.h"


class telephone_service_t
{
public:
	virtual ~telephone_service_t();
	telephone_service_t();
	telephone_service_t(std::string name, int payment, int minute_rate, int MB_rate) :
		name_(name),
		payment_(payment),
		minute_rate_(minute_rate),
		MB_rate_(MB_rate)
	{};
	telephone_service_t& add(subscriber_t sub);
	subscriber_t& search(int n);
	void show_table();
//	telephone_service_t& add_service(services_t &service, int n);
	telephone_service_t& read_from_file();
	void write_to_file();
	double get_payment();
	double get_minute_rate();
	double get_MB_rate();
//	int total_information(int n);
	int service_time();
	//web_t& set_input(int n);
	int total_payment();
	//subscriber_t& modify_information(int n);

private:
	subscriber_table_t table_;
	std::string name_;
	int payment_;
	int minute_rate_;
	int MB_rate_;
};

