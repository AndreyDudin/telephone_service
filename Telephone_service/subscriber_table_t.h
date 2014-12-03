#pragma once
#include <map>
#include "subscriber_t.h"
#include "subscriber_table_tIt.h"
#include <fstream>

//class subsriber_table_tIt;

class subscriber_table_t
{
public:
	friend class subscriber_table_tIt;
	subscriber_table_t();
	~subscriber_table_t();
	
	subscriber_table_t& add_element(subscriber_t& sub);
	subscriber_t& search(int n);
	void show_table();
	void write_to_file();
	subscriber_table_t& read_from_file();

	typedef subscriber_table_tIt iterator;
	iterator begin();
	iterator end();
	iterator find(int k);
	int table_time();
	int table_MB();

private:
	std::map<int, subscriber_t> table;
	
};