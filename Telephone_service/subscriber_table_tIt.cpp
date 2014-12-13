
#include "subscriber_table_tIt.h"


subscriber_table_tIt::subscriber_table_tIt()
{
}
subscriber_t& subscriber_table_tIt::operator *()
{
	return (*it).second;
}
subscriber_table_tIt::~subscriber_table_tIt()
{
}
subscriber_table_tIt& subscriber_table_tIt::operator++()
{
	++it;
	return *this;
}
bool subscriber_table_tIt::operator!=(const subscriber_table_tIt& ob) const
{
	return it != ob.it;
}


