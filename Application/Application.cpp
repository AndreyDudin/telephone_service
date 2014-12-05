// Application.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "..\Telephone_service\telephone_service_t.h"
#include "../Telephone_service/telephone_t.h"
#include "../Telephone_service/web_t.h"

const char* MENU = "1.Add new abonent\n2.Show abonents table\n3.Add service\n4.Show abonent's services\n5.Total information\n6.Total service time\n7.Total Payment\n8.Modify services";

int _tmain(int argc, _TCHAR* argv[])
{
	std::string name;
	int p;
	int m;
	int mb;
	std::cout << "Enter the service's name" << std::endl;
	std::cin >> name;
	std::cout << "Enter the service's month payment" << std::endl;
	std::cin >> p;
	std::cout << "Enter the service's minute rate" << std::endl;
	std::cin >> m;
	std::cout << "Enter the service's MB rate" << std::endl;
	std::cin >> mb;
	char c;	
	telephone_service_t service(name,p,m,mb);
	subscriber_t* subscriber;

	for (;;)
	{
		std::cout << MENU << std::endl;
		c = _getch();
		switch (c)
		{
		case '1':
		{
			int n;
			client_t* client;
			std::string type;
			std::cout << "Enter the number" << std::endl;
			std::cin >> n;
			std::cout << "Enter the type of client" << std::endl;
			std::cin >> type;

			if (type == "Physical")
			{
				client = new client_t;
				std::cout << "Enter the data: Name, Address, Bank account" << std::endl;
				std::cin >> *client;
			}
			else
			{
				if (type == "Corporate")
				{
					client = new corporate_client_t;
					std::cout << "Enter the data: Name, Address, Bank account, Corporate name:" << std::endl;
					std::cin >> *client;
				}
				else
				{
					throw std::exception("Wrong type");
				}
			}
			subscriber = new subscriber_t(*client, n);
			service.add(*subscriber);
			break;
		}
		case '2':
			std::cout << "Table of abonents:" << std::endl;
			service.show_table();
			break;

		case'3':
		{
			int n;
			
			std::string type;
		//	services_t* services;
			std::cout << "Enter the number of abonent" << std::endl;
			std::cin >> n;
			do
			{
				std::cout << "Enter the type of service: telephone, fax,web" << std::endl;
				std::cin >> type;
				if (type == "telephone")
				{
					//services = new telephone_t;
					telephone_t services;
					std::cout << "Enter the data: Number, Time, Duraction of connection:" << std::endl;
					std::cin >> services;
					service.search(n).add_service(&services);//внутри метода создать копию услуги и передавать её и сдеать телефон статическим				
				}
				if (type == "fax")
				{
					//services = new fax_t;
					fax_t services;
					std::cout << "Enter the data: Number, Time, Duraction of connection, Amount of information:" << std::endl;
					std::cin >> services;
					service.search(n).add_service(&services);
				}
				if (type == "web")
				{
					//services = new web_t;
					web_t services;
					std::cout << "Enter the data: Number, Time, Duraction of connection, Input traffic,Output traffic:" << std::endl;
					std::cin >> services;
					service.search(n).add_service(&services);
				}
			} while (type != "telephone" && type != "fax" && type != "web");	
			break;
		}
		case'4':
		{
			int n;
			std::cout << "Enter the number of abonent:" << std::endl;
			std::cin >> n;
			service.search(n).show_services();
			break;
		}
		case'5':
		{
			int n;
			std::cout << "Enter the number of abonent:" << std::endl;
			std::cin >> n;
			std::cout <<"Total information: "<< service.search(n).total_output_information() << std::endl;
			break;
		}
		case'6':
		{
			std::cout << "Total service time:" << service.service_time() << std::endl;
			break;
		}
		case'7':
		{
			std::cout << "Total payment:" << service.total_payment() << std::endl;
			break;
		}
		case'8':
		{
			std::string type;
			int n;
			int pos;
			int data;
			std::cout << "Enter the number of abonent:" << std::endl;
			std::cin >> n;
			service.search(n).show_services();
			std::cout << "Choose service" << std::endl;
			std::cin >> pos;
			std::cout << "Which data you want to set?" << std::endl;
			std::cin >> type;
			std::cout << "Enter new data" << std::endl;
			std::cin >> data;

			if (type == "Input")
			{
				service.search(n).set_web_input(pos, data);
			}
			if (type == "Output")
			{
				service.search(n).set_web_output(pos, data);
			}
			if (type == "Amount")
			{
				service.search(n).set_fax_amount(pos, data);
			}
			break;
		}
		}
		if (c == '0')
		{
			service.write_to_file();
			break;
		}
	}
	return 0;
}