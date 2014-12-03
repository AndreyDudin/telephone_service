#pragma once
#include <map>
#include "subscriber_table_t.h"

class subscriber_table_tIt
{
public:
	virtual ~subscriber_table_tIt();
	subscriber_table_tIt();
	subscriber_table_tIt(std::map<int, subscriber_t>::iterator ob):it(ob){};
	//subscriber_table_tIt(std::map<int, subscriber_t>);

	subscriber_t& operator *()const;
	subscriber_table_tIt& operator++();
	//subscriber_table_tIt operator++(int);
	bool operator !=(const subscriber_table_tIt&) const;

//	bool operator ==(const subscriber_table_tIt&) const;
private:
	std::map<int, subscriber_t>::iterator it;
};