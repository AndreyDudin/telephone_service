#pragma once
#include "services_t.h"

class telephone_t:public services_t
{
public:
	std::string to_string() const override;
	std::string serialize() const override;
	telephone_t* copy() const override;
	telephone_t();
	~telephone_t();

};