#pragma once
#include "subscriber_t.h"
#include "subscriber_table_tIt.h"
#include <fstream>
#include "MyMap.h"

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

	typedef subscriber_table_tIt Iterator;
	Iterator begin();
	Iterator end();
	Iterator find(int k);
	int table_time();
	int table_MB();

private:
	Mymap <int, subscriber_t> table;
	
};