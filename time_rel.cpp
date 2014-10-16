#include <iostream>
#include <time.h>

using namespace std;

void print_time()
{
	struct tm *ptr;
	time_t now;
	
	time(&now);
	ptr = localtime(&now);
	
	cout << "time:" << asctime(ptr) << endl;
}

int get_weekday(int year, int month, int day)
{
	struct tm when= {0}, *ptr;
	time_t tt;
	
	when.tm_year = year - 1900;
	when.tm_mon  = month - 1;
	when.tm_mday = day;	
	
	tt = mktime(&when);
	ptr = gmtime(&tt);
	
	return ptr->tm_wday;	
}

int main()
{
	std::string a[] = {"Monday", "Tuesday", "Wednesday", "Thursday",
	"Friday", "Saturday", "Sunday"};

	print_time();

	cout << "1990.1.1 is " << a[get_weekday(1990,1,1)] << endl;
	cout << "2014.10.16 is " << a[get_weekday(2014,10,16)] << endl;

	return 0;
}
