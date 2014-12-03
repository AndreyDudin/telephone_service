#pragma once
#include "client_t.h"

class corporate_client_t : public client_t
{
public:
	corporate_client_t();
	virtual ~corporate_client_t();
	std::ostream& show_client(std::ostream& os);
	corporate_client_t(std::string name, std::string addres, std::string bank_account, std::string company_name);
//	friend std::ostream& operator<<(std::ostream& os, client_t& client);
	//friend std::istream& operator>>(std::istream& is, corporate_client_t& client);
	std::istream& get(std::istream&);
private:
	std::string company_name_;
};

