#pragma once
#include "subscriber_table_t.h"
#include "MyMap.h"

class subscriber_table_tIt
{
public:
	virtual ~subscriber_table_tIt();
	subscriber_table_tIt();
	subscriber_table_tIt(Mymap <int, subscriber_t>::Iterator ob):it(ob){};
	//subscriber_table_tIt(std::map<int, subscriber_t>);

	subscriber_t& operator *();
	subscriber_table_tIt& operator++();
	//subscriber_table_tIt operator++(int);
	bool operator !=(const subscriber_table_tIt&) const;

//	bool operator ==(const subscriber_table_tIt&) const;
private:
	Mymap <int, subscriber_t>::Iterator it;
};