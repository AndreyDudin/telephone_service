#include "subscriber_table_t.h"

subscriber_table_t::subscriber_table_t()
{
}

subscriber_table_t& subscriber_table_t::add_element(subscriber_t& sub)
{
	//auto it = table.find(sub.get_number());
	if (table.find(sub.get_number())==table.end())
	{
		table.insert(sub.get_number(),sub);
	}
	else
	{
		throw std::exception("Error insert");
	}
	return *this;
}
void subscriber_table_t::write_to_file()
{
	std::ofstream f("service.dat", std::ios_base::ate | std::ios_base::app);
	f << table.size()<<" ";
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		f<< (*it).second.serialize()<<std::endl;
	}
	f.close();
}
subscriber_table_t& subscriber_table_t::read_from_file()
{
	std::string trash;

	std::ifstream f("service.dat");
	int n;
	
	f >> trash;
	f >> trash;
	f >> trash;
	f >> trash;
	f >> n;
	for (int i = 0; i < n;i++)
	{
		subscriber_t sub;
		f >> sub;
		table.insert(sub.get_number(), sub);

	}
	f.close();
	return *this;
	
}


subscriber_table_t::~subscriber_table_t()
{

}

subscriber_table_t::Iterator subscriber_table_t::find(int k)//����������� �����������
{
	auto it = table.find(k);
	return subscriber_table_tIt(it);
}

subscriber_table_t::Iterator subscriber_table_t::begin()
{
	return subscriber_table_tIt(table.begin());
}

subscriber_table_t::Iterator subscriber_table_t::end()
{
	return subscriber_table_tIt(table.end());
}

void subscriber_table_t::show_table()
{
	subscriber_table_tIt it;
	for (it = table.begin(); it != table.end();++it)
	{
		std::cout << (*it) << std::endl;///?????
	}
}
subscriber_t& subscriber_table_t::search(int n)
{
	return (*table.find(n)).second;
	
}


int subscriber_table_t::table_time()
{
	int t = 0;
	subscriber_table_tIt it;
	for (it = table.begin(); it != table.end(); ++it)
	{
		t += (*it).total_time();
	}
	return t;
}

int subscriber_table_t::table_MB()
{
	int MB = 0;
	subscriber_table_tIt it;
	for (it = table.begin(); it != table.end(); ++it)
	{
		MB += (*it).total_MB();
	}
	return MB;
}



