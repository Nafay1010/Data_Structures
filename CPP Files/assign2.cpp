//#include <iostream>
//#include <string> 
//#include <sstream> 
//
//using namespace std; 
//
//string int_to_string(int v) { 
//    stringstream ss;
//    ss << v;
//    return ss.str();
//}
//
//// Address class here 
//class Address
//{
//	public:
//		int HouseNumber;
//		int Street;
//		string City;
//		string Country;
//	string get_full_address()
//	{
//		string a="H. No."+int_to_string(HouseNumber)+", Street "+int_to_string(Street)+", "+City+" "+Country;
//		//cout<<"H. No."<<HouseNumber<<", Street "<<Street<<", "<<City<<" "<<Country<<endl;
//		return a;
//	}
//};
//
//// Employee class here 
//
//class Employee
//{
//	private:
//		string employee_name;
//		Address current_address;
//		Address permanent_address;
//	public:
//		void set_current_address(int h, int s, string ci, string co)
//		{
//			current_address.HouseNumber=h;
//			current_address.Street=s;
//			current_address.City=ci;
//			current_address.Country=co;
//		}	
//		void set_permanent_address(int h, int s, string ci, string co)
//		{
//			permanent_address.HouseNumber=h;
//			permanent_address.Street=s;
//			permanent_address.City=ci;
//			permanent_address.Country=co;
//		}
//		void print_addresses()
//		{
//			cout<<current_address.get_full_address()<<endl;;
//			cout<<permanent_address.get_full_address()<<endl;
//		}
//		
//};
//// Wheel class here
//
//class Wheel
//{
//	private:
//		string wheel_state;
//	public:
//		void set_wheel_state(string s)
//		{
//			wheel_state=s;
//		}
//		string get_wheel_state()
//		{
//			return wheel_state;
//		}
//}; 
//
//// Car class here 
//
//class Car
//{
//	private:
//		Wheel W[4];
//	public:
//		void set_car_to_moving()
//		{
//			for(int i=0;i<4;i++)
//			{
//				W[i].set_wheel_state("Turning");
//			}
//		}
//		void set_car_to_stopped()
//		{
//			for(int i=0;i<4;i++)
//			{
//				W[i].set_wheel_state("Stopped");
//			}
//		}
//		void  print_car_wheels_state()
//		{
//			cout<<"Car State: "<<endl;
//			for(int i=0;i<4;i++)
//			{
//				cout<<"Wheel "<<i<<" is "<<W[i].get_wheel_state()<<endl;
//			}
//		}
//		
//	
//};
//
//
//int main() { 
//
//    // Start of PART - 1  -----------------------
//     Address a; 
//
//     a.HouseNumber = 4; 
//     a.Street = 25; 
//     a.City = "Peshawar"; 
//     a.Country = "Pakistan";
//
//     cout<<a.get_full_address()<<endl;
//
//    // End of Part - 1    -----------------------
//
//
//    // Start of PART - 2  -----------------------
//
//     Employee e1; 
//
//     e1.set_current_address(4, 25, "Peshawar", "Pakistan"); 
//     e1.set_permanent_address(14, 9, "Lahore", "Pakistan"); 
//     e1.print_addresses();  
//
//    // End of Part - 2     -----------------------
//
//
//    // Start of PART - 3   -----------------------
//
//     Wheel w1; 
//
//     w1.set_wheel_state("Turning"); 
//     cout << w1.get_wheel_state() << endl; 
//
//    // End of Part - 3     -----------------------
//
//
//    // Start of PART - 4   -----------------------
//
//     Car c; 
//    
//     c.set_car_to_moving(); 
//     c.print_car_wheels_state(); 
//
//     c.set_car_to_stopped(); 
//     c.print_car_wheels_state();
//
//    // End of Part - 4     -----------------------
//
//
//    return 0; 
//}


#include<iostream>
using namespace std;

class website
{
	private:
		string username;
		string password;
	public:
		website(string username, string password)
		{}
		
		virtual void login()=0;
};

class checkLogin: public website
{
	public:
		checkLogin(string username, string password): website(username, password)
		{}
		
		void login()
		{
			//check if the login info is correct or not
		}
};

	
	void furnished(int no_of_rooms)
	{
		//checks whether room is furnished or not
	}
	bool status(bool status)
	{
		//returns whether property is available or not
	}
	string property_type()
	{
		//checks the type of property {apartment, house, condo and a single room}
	}
	string amenities()
	{
		//returns whether there are pool, gym and play areas.
	}

class sellers: public checkLogin{
	private:
		string propertyaddress;
		string propertyType;
		bool status;
		string filename;
		string filePath;
		bool verified;
		int no_of_rooms;
	
	public:
		sellers(string username,string password):checkLogin(username, password)
		{}
		
		void set_password(string password)
		{
			//sets the passwords
		}
		friend bool status(bool status);
		friend property_type(string propertyType);
		friend void furnished();
		friend string amenities();
		
		void Text_description(string propertyaddress, string propertyType, bool status)
		{
			// description of property
		}
		void generate_identifier(string username, string password)
		{
			//generates identifier of new user
		}
		void Upload_Images(string fileNames, string filePath)
		{
			//Uploads new images
		}
		void Image_path_size(string fileNames, string filePath)
		{
			//keeps track of path and filesize of the image
		}
		void Deletes_Images(string fileNames, string filePath)
		{
			//delete  images
		}
		
		void history()
		{
			//show all the sell history of that seller
		}
		
		float earning_seller()
		{
			//track sellers earning
		}
		
		void check_verification(bool verified)
		{
			//checks verification of seller
		}
};

class buyer: public checkLogin
{
	private:
	int accountNumber;
	string N_password;
	double creditcard_balance;
	string property_type;
	float area;
	double cost;
	int no_of_rooms;
	public:
		
		buyer(string username, string password, float area): checkLogin(username, password)
		{
			//sets area of property		
		}
		
		friend bool status(bool status);
		friend property_type(string propertyType);
		friend void furnished();
		friend string amenities();
		
		double property_cost(float area)
		{
			//calculates and returns cost 
		}
		
		void addCredit(double amount)
		{
			//adds balance to credit card
		}
		void change_password(string N_password)
		{
			//change password
		}
		
		void verfication(int accountNum, int pass)
		{
			//account verfication of buyer
		}
		
		int rate()
		{
			//buys the property and returns the rate
		}
};

int main()
{
	return 0;
}
