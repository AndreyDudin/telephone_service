#pragma once
#include "services_t.h"

class fax_t :public services_t
{
public:
	fax_t();
	virtual ~fax_t();
	fax_t(int number, int time, int duraction_of_connection, int amount_of_information);
	int get_amount_of_information();
	fax_t& set_amount_of_information(int n);
	fax_t* copy() const override;
	std::ostream& show(std::ostream& os);
	std::istream& get(std::istream&);

	std::string to_string() const override;
	std::string serialize() const override;
//	friend std::istream& operator>>(std::istream& is, fax_t& fax);
private:
	int amount_of_information_;
};
