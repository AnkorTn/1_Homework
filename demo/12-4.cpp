#include<bits/stdc++.h>
using namespace std;

/*
 * define the classes here that you infer from the main function
 */
#include<cstring>
class Employee{
	public:
		char *Given_Name;
		char *Family_Name;
		char *id;
		Employee(const char *name1, const char *name2, const char *id0){
			int l = strlen(name1);		Given_Name 		= new char[l+1];
			for(int i = 0; i < l; i++)	Given_Name[i] 	= name1[i];			Given_Name[l] 	= '\0';
			l = strlen(name2);			Family_Name 	= new char[l+1];
			for(int i = 0; i < l; i++)	Family_Name[i] 	= name2[i];			Family_Name[l] 	= '\0';
			l = strlen(id0);			id 				= new char[l+1];
			for(int i = 0; i < l; i++)	id[i] 			= id0[i];			id[l] 			= '\0';
		}

		virtual int earnings()=0;
		virtual void   print()=0;
		virtual void virtualViaPointer(){
			print();
   			cout << "\nearned $" << earnings() << "\n\n";
		}
		virtual void virtualViaReference(){
			print();
   			cout << "\nearned $" << earnings() << "\n\n";
		}
		virtual ~Employee(){
			delete[]Given_Name;
			delete[]Family_Name;
			delete[]id;
		}
};
class SalariedEmployee:public Employee{
	public:
		int salary;
		SalariedEmployee(const char *name1, const char *name2, const char *id0,int wage):Employee(name1,name2,id0){	salary = wage;	}
		int earnings(){	return salary;	}
		void print(){
			cout<<"salaried employee: "<<Given_Name<<" "<<Family_Name<<endl;
			cout<<"social security number: "<<id<<endl;
			cout<<"weekly salary: "<<salary;
		}

		~SalariedEmployee(){}
};

class HourlyEmployee:public Employee{
	public:
		double salary;
		int hour;
		HourlyEmployee(const char *name1, const char *name2, const char *id0,double wage, int h):Employee(name1,name2,id0){	salary = wage;	hour = h;	}
		int earnings(){	return int(salary*hour);	}
		void print(){
			cout<<"hourly employee: "<<Given_Name<<" "<<Family_Name<<endl;
			cout<<"social security number: "<<id<<endl;
			cout<<"hourly wage: "<<salary<<"; hours worked: "<<hour;
		}
		~HourlyEmployee(){}
};

class CommissionEmployee:public Employee{
	public:
		int sumary;
		double rate;
		CommissionEmployee(const char *name1, const char *name2, const char *id0, int s, double r):Employee(name1,name2,id0){	sumary = s;	rate = r;	}
		int earnings(){	return int(sumary*rate);	}
		void print(){
			cout<<"commission employee: "<<Given_Name<<" "<<Family_Name<<endl;
			cout<<"social security number: "<<id<<endl;
			cout<<"gross sales: "<<sumary<<"; commission rate: "<<rate;
		}
		~CommissionEmployee(){}
};

class BasePlusCommissionEmployee:public Employee{
	public:
		int sumary;
		int base;
		double rate;
		BasePlusCommissionEmployee(const char *name1, const char *name2, const char *id0, int s, double r, int b):Employee(name1,name2,id0){	sumary = s;	rate = r; base = b;	}
		int earnings(){	return int(sumary*rate+base);	}
		void print(){
			cout<<"base-salaried commission employee: "<<Given_Name<<" "<<Family_Name<<endl;
			cout<<"social security number: "<<id<<endl;
			cout<<"gross sales: "<<sumary<<"; commission rate: "<<rate<<"; base salary: "<<base;
		}
		~BasePlusCommissionEmployee(){}
};

void virtualViaPointer(Employee *i){
	i->virtualViaPointer();
	return;
}

void virtualViaReference(Employee &i){
	i.virtualViaReference();
	return;
}
/*
void virtualViaReference(Employee i)*/

int main(){
   // create derived-class objects
   SalariedEmployee salariedEmployee( "John", "Smith", "111-11-1111", 800 );
   HourlyEmployee hourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40 );
   CommissionEmployee commissionEmployee( "Sue", "Jones", "333-33-3333", 10000, .06 );
   BasePlusCommissionEmployee basePlusCommissionEmployee( "Bob", "Lewis", "444-44-4444", 5000, .04, 300 );

   cout << "Employees processed individually using static binding:\n\n";

   // output each Employee's information and earnings using static binding
   salariedEmployee.print();
   cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
   hourlyEmployee.print();
   cout << "\nearned $" << hourlyEmployee.earnings() << "\n\n";
   commissionEmployee.print();
   cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
   basePlusCommissionEmployee.print();
   cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

   // create array of four base-class pointers
   Employee * employees[4];

   // initialize array with Employees
   employees[0] = &salariedEmployee;
   employees[1] = &hourlyEmployee;
   employees[2] = &commissionEmployee;
   employees[3] = &basePlusCommissionEmployee;

   cout << "Employees processed polymorphically via dynamic binding:\n\n";

   // call virtualViaPointer to print each Employee's information
   // and earnings using dynamic binding
   cout << "Virtual function calls made off base-class pointers:\n\n";

   for ( int i = 0; i < 4; i++ )
      virtualViaPointer( employees[ i ] );

   // call virtualViaReference to print each Employee's information
   // and earnings using dynamic binding
   cout << "Virtual function calls made off base-class references:\n\n";

   for ( int i = 0; i < 4; i++ )
        virtualViaReference( *employees[ i ] ); // note dereferencing

   return 0;
}
