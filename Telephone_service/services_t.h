#pragma once
#include <iostream>
#include <sstream>

class services_t
{
public:
	services_t();
	services_t(int number, int time, int duraction_of_connection);
	virtual ~services_t();

	int get_time();
	services_t& set_time(int n);
	virtual services_t* copy() const =0;//��� ��������� �����

	virtual std::string to_string() const = 0;
	virtual std::string serialize() const = 0;

	virtual std::ostream& show(std::ostream& os);//������� ����, ��������� ��� ���� �������
	virtual std::istream& get(std::istream&);

	friend std::ostream& operator<<(std::ostream& os, services_t const& service);
	friend std::istream& operator>>(std::istream& is, services_t& service);
protected:
	int number_;
	int time_;
	int duraction_of_connection_;
};