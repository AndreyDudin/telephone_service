#pragma once
#include "client_t.h"
#include "corporate_client_t.h"
#include "services_t.h"
#include "fax_t.h"
#include "web_t.h"
#include <vector>
enum client_type
{
	phys_client,
	law_client
};
class subscriber_t
{
public:
	subscriber_t();
	//subscriber_t(const subscriber_t& ob);
	//subscriber_t& operator =(subscriber_t& ob);
	//subscriber_t& operator =(subscriber_t&& ob);
	//subscriber_t(subscriber_t&& p);
	subscriber_t(client_t& client, int n);

	virtual ~subscriber_t();//
	subscriber_t& add_service(services_t *service);
	client_type get_type(client_t client);
	services_t* get_service(int n);
	int get_amount_of_sessions();
	void show_services();
	int get_number();
	int total_output_information();
	int total_time();
	int total_MB();

	subscriber_t& set_fax_amount(int, int);
	subscriber_t& set_web_input(int, int);
	subscriber_t& set_web_output(int, int);

	friend std::ostream& operator<<(std::ostream& os, const subscriber_t& sub);
	friend std::istream& operator>>(std::istream& is, subscriber_t& sub);

private:
	int number_;
	int amount_of_sessions_;
	client_t* client_;
	std::vector<services_t *> services_;
};