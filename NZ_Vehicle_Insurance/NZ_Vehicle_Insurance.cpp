// NZ_Vehicle_Insurance_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

//structure definition
struct Customer
{
	char first_name[20];
	char last_name[20];
	char dob[20];
	char gender[10];
	char contact_no[20];
	char email[30];
	char address[50];
	char vehicleRegNumber[20];
	char username[20];
	char password[20];



	Customer()
	{
		strcpy_s(first_name, " ");
		strcpy_s(last_name, " ");
		strcpy_s(dob, " ");
		strcpy_s(gender, " ");
		strcpy_s(contact_no, " ");
		strcpy_s(email, " ");
		strcpy_s(address, " ");
		strcpy_s(vehicleRegNumber, " ");
		strcpy_s(username, " ");
		strcpy_s(password, " ");
	}
};



struct Administrator
{
	string username;
	string password;
};



struct Policy
{
	int policy_no;
	int car_value;
	int monthly_cost;
	char first_name[20];
	char last_name[20];
	char dob[20];
	char gender[10];
	char contact_no[20];
	char email[30];
	char address[50];
	char vehicleRegNumber[20];
	char vehicle_name[20];
	char model[20];



	Policy()
	{
		policy_no = 0;
		car_value = 0;
		monthly_cost = 0;
		strcpy_s(first_name, " ");
		strcpy_s(last_name, " ");
		strcpy_s(dob, " ");
		strcpy_s(gender, " ");
		strcpy_s(contact_no, " ");
		strcpy_s(email, " ");
		strcpy_s(address, " ");
		strcpy_s(vehicleRegNumber, " ");
		strcpy_s(vehicle_name, " ");
		strcpy_s(model, " ");
	}
};



struct Claim
{
	int policy_no;
	char first_name[20];
	char last_name[20];
	char date[20];
	char time[20];
	char description[200];
	char detail[200];
	char contact_no[20];
	char email[30];



	Claim()
	{
		policy_no = 0;
		strcpy_s(first_name, " ");
		strcpy_s(last_name, " ");
		strcpy_s(date, " ");
		strcpy_s(time, " ");
		strcpy_s(description, " ");
		strcpy_s(detail, " ");
		strcpy_s(contact_no, " ");
		strcpy_s(email, " ");
	}
};



struct Renewal
{
	int policy_no;
	char new_policy[50];
	char full_name[41];
	char contact_no[20];
	char visa_card_no[20];



	Renewal()
	{
		policy_no = 0;
		strcpy_s(new_policy, " ");
		strcpy_s(full_name, " ");
		strcpy_s(contact_no, " ");
		strcpy_s(visa_card_no, " ");
	}
};



struct Discount
{
	int new_signup, multi, renewal, friends_family;
};

//function declaration
int main_menu();
void customerRegistration(struct Customer&);
void customerLogin(string, string);
void customerScreen();
void adminLogin();
void adminScreen();
void insurancePolicy();
void claimRegistration();
void renewalScreen();
void benefitScreen();
void policyRegistration(int, int, int);

int main()
{
	struct Customer customer;
	string username, password;

	cout << "\n\t\t\t\t\tWelcome to NZ Vehicle Insurance System\n";
	cout << "\n\t\t\t\t******************************************************\n";

	while (true)
	{
		int choice = main_menu();
		if (choice == 1) customerRegistration(customer);
		else if (choice == 2) customerLogin(username, password);
		else if (choice == 3) adminLogin();
		else if (choice == 4)
		{
			cout << "\n NZ Vehicle Insurance System have been helping New Zealanders with their insurance for more than 100 years.\n Today we manage around 900,000 policies for more than 400,000 Kiwis.\n In that time, we have worked hard to build up a pretty good understanding of New Zealanders' insurance needs.\n\n Contact us : 0800 802 424\n 8.00am - 6.00pm (Mon - Fri)\n 9.00am - 6.00pm (Sat - Sun & public holidays)\n\n";
		}
		else if (choice == 5) break;
	}

	cout << "\n\n";
	return 0;
}

int main_menu()
{
	int choice;

	cout << "\n\n\tMain Menu\n\t---------\n";
	cout << "\n 1 Customer registration";
	cout << "\n 2 Customer login";
	cout << "\n 3 Administrator login";
	cout << "\n 4 Insurance company info and contact details";
	cout << "\n 5 Exit";
	cout << "\n\n Please select an option from the menu : ";
	cin >> choice;
	return choice;
}

void customerRegistration(struct Customer& customer)
{
	fstream file;
	cin.ignore();

	cout << "\n\n\tCustomer Registration\n\t---------------------\n";
	cout << "\n Enter your first name : ";
	cin.getline(customer.first_name, 20);
	cout << "\n Enter your last name : ";
	cin.getline(customer.last_name, 20);
	cout << "\n Enter your date of birth : ";
	cin.getline(customer.dob, 20);
	cout << "\n Enter your gender : ";
	cin.getline(customer.gender, 10);
	cout << "\n Enter your contact number : ";
	cin.getline(customer.contact_no, 20);
	cout << "\n Enter your email : ";
	cin.getline(customer.email, 30);
	cout << "\n Enter your physical address : ";
	cin.getline(customer.address, 50);
	cout << "\n Enter your vehicle registration number : ";
	cin.getline(customer.vehicleRegNumber, 20);
	cout << "\n Enter your username: ";
	cin.getline(customer.username, 20);
	cout << "\n Enter your password: ";
	cin.getline(customer.password, 20);


	//write into file
	file.open("Customer_Registration.dat", ios::out | ios::app | ios::binary);
	file.write(reinterpret_cast<char*>(&customer), sizeof(customer));
	file.close();
}

void customerLogin(string username, string password)
{
	Customer customer;
	int chance = 3;
	fstream file;

	while (chance > 0)
	{
		chance--;
		cout << "\n\n\tCustomer Login\n\t--------------\n";
		cout << "\n Enter your username: ";
		cin >> username;
		cout << "\n Enter your password: ";
		cin >> password;

		//opening the file in read mode
		file.open("Customer_Registration.dat", ios::in | ios::binary);

		bool loginSucceeded = false;
		while (file.read(reinterpret_cast<char*>(&customer), sizeof(customer)))
		{

			//checking whether the login is successful by username and password
			if (username == customer.username && password == customer.password)
			{
				loginSucceeded = true;
				break;
			}
		}
		file.close();

		if (loginSucceeded == false && chance == 0)
		{
			cout << "\n Username or password is wrong, you can't login again. Please try it again after 30 minutes";
			return;
		}
		else if (loginSucceeded == false && chance > 0)
		{
			cout << "\n Username or password is wrong, please enter again.";
			continue;
		}
		else
		{
			cout << "\n Login successfully!\n";
			break;
		}

	}

	//display customer screen if the login is successful
	customerScreen();
}

void adminLogin()
{
	fstream file;
	string username, password;
	string u_username, p_password;
	int chance = 3;

	while (chance > 0)
	{
		chance--;
		cout << "\n\n\tAdministrator Login\n\t--------------\n";
		cout << "\n Enter your username: ";
		cin >> username;
		cout << "\n Enter your password: ";
		cin >> password;

		//opening the file in read mode
		file.open("administrators.txt", ios::in | ios::binary);

		bool loginSucceeded = false;
		if (file.is_open())
		{
			while (!file.eof())
			{
				// reading the content from the file
				file >> u_username;
				file >> p_password;

				//checking whether the login is successful by username and password
				if (username == u_username && password == p_password)
				{
					loginSucceeded = true;
					break;
				}
			}
		}
		else
		{
			cout << "\n File unable to access...";

		}
		file.close();

		if (loginSucceeded == false && chance == 0)
		{
			cout << "\n Username or password is wrong, you can't login again. Please try it again after 30 minutes";
			return;
		}
		else if (loginSucceeded == false && chance > 0)
		{
			cout << "\n Username or password is wrong, please enter again.";
			continue;
		}
		else
		{
			cout << "\n Login successfully!";
			break;
		}
	}

	//display admin screen if the login is successful
	adminScreen();
}

void customerScreen()
{
	int choice;

	while (true)
	{
		cout << "\n\n\tCustomer Screen\n\t---------------\n";
		cout << "\n 1. Policy and insurance application process";
		cout << "\n 2. Claim";
		cout << "\n 3. Renewal";
		cout << "\n 4. Benefits of NZ insurance";
		cout << "\n 5. Exit";
		cout << "\n\n Please select an option from the menu: ";
		cin >> choice;

		if (choice == 1) insurancePolicy();
		else if (choice == 2) claimRegistration();
		else if (choice == 3) renewalScreen();
		else if (choice == 4) benefitScreen();
		else if (choice == 5) break;
	}
}

void benefitScreen()
{
	int choice;

	fstream file;

	Discount d;

	file.open("discounts.dat", ios::binary | ios::in);

	file.read(reinterpret_cast<char*> (&d), sizeof(d));


	do
	{
		cout << "\n\n\tBenefits Screen\n\t---------------\n";
		cout << "\n 1. New sign-up discounts";
		cout << "\n 2. Multi policy discount";
		cout << "\n 3. Renewal discount";
		cout << "\n 4. Discount for reviewing the insurance and introducing friends or family discount";
		cout << "\n 5. Exit";
		cout << "\n\n Please select an option from the menu : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n If you are a new registered user and purchase insurance from our company\n for the first time, you will be able to enjoy a " << d.new_signup << "% discount.\n";
			break;
		}
		case 2:
		{
			cout << "\n Enjoy a multi-policy discount of up to " << d.multi << "%. When you take out more than\n one type of vehicle insurance with us, you may qualify for our multi policy discount.\n";
			break;
		}
		case 3:
		{
			cout << "\n There are also certain discounts for renewal policies. This discount is based on\n the driving situation and the risk situation in the previous year.\n You can get a " << d.renewal << "% discount if you are in a good condition after evaluation.\n";
			break;
		}
		case 4:
		{
			cout << "\n Regarding policy review and introducing family and friends to purchase our vehicle insurance,\n you can get an additional " << d.friends_family << "% discount provided by our company.\n";
			break;
		}
		case 5: break;
		default:
		{
			cout << "\n Please enter a valid choice";
		}
		}
	} while (choice != 5);

	file.close();
}

void policyRegistration(int policy_num, int carvalue, int monthlycost)
{
	Policy p;
	fstream policies;
	int temp_num = 100 + policy_num;
	bool check = true;

	policies.open("policies.dat", ios::in | ios::binary);

	while (check == true)
	{
		check = false;
		while (policies.read(reinterpret_cast<char*>(&p), sizeof(p)))
		{
			if (p.policy_no = temp_num)
			{
				temp_num += 100;
				check = true;
			}
		}
	}
	policies.close();

	p.policy_no = temp_num;

	cin.ignore();
	cout << "\n\n\tPolicy Registration\n\t-------------------\n";
	cout << "\n Enter your first name : ";
	cin.getline(p.first_name, 20);
	cout << "\n Enter your last name : ";
	cin.getline(p.last_name, 20);
	cout << "\n Enter your date of birth (dd/mm/yyyy) : ";
	cin.getline(p.dob, 20);
	cout << "\n Enter your gender : ";
	cin.getline(p.gender, 10);
	cout << "\n Enter your phone number : ";
	cin.getline(p.contact_no, 20);
	cout << "\n Enter your email address : ";
	cin.getline(p.email, 30);
	cout << "\n Enter your home address : ";
	cin.getline(p.address, 50);
	cout << "\n Enter your vehicle registration number : ";
	cin.getline(p.vehicleRegNumber, 20);
	cout << "\n Enter your vehicle name : ";
	cin.getline(p.vehicle_name, 20);
	cout << "\n Enter your vehicle model : ";
	cin.getline(p.model, 20);

	p.monthly_cost = monthlycost;
	p.car_value = carvalue;

	cout << "\n Policy saved";

	cout << "\n Policy number is : " << p.policy_no;

	policies.open("policies.dat", ios::out | ios::app | ios::binary);

	policies.write(reinterpret_cast<char*>(&p), sizeof(p));

	policies.close();
}

void claimRegistration()
{
	char restart, end;
	fstream policies, claims;
	Claim claim;
	bool policy_found;

	do
	{
		Claim claim;
		Policy p;
		policy_found = false;

		cout << "\n\n\tClaim Registration\n\t------------------\n";
		cout << "\n Enter your policy number : ";
		cin >> claim.policy_no;

		policies.open("policies.dat", ios::in | ios::binary);

		while (policies.read(reinterpret_cast<char*>(&p), sizeof(p)))
		{
			if (p.policy_no == claim.policy_no)
			{
				policies.read(reinterpret_cast<char*>(&p), sizeof(p));
				strcpy_s(claim.first_name, p.first_name);
				strcpy_s(claim.last_name, p.last_name);
				strcpy_s(claim.email, p.email);
				strcpy_s(claim.contact_no, p.contact_no);
				policy_found = true;
			}
		}
		policies.close();

		if (policy_found)
		{
			cout << "\n Enter the date of the incident : ";
			cin.ignore();
			cin.getline(claim.date, 20);
			cout << "\n Enter the time of the incident : ";
			cin.getline(claim.time, 20);

			cout << "\n Enter the incident description (200 character limit) : ";
			cin.getline(claim.description, 200);
			cout << "\n Enter the complaint details (200 character limit) : ";
			cin.getline(claim.detail, 200);


			cout << "\n\tSummary of Claim\n\t----------------\n";
			cout << "\n Policy Number : " << claim.policy_no;
			cout << "\n Name : " << claim.first_name << " " << claim.last_name;
			cout << "\n Date of incident : " << claim.date;
			cout << "\n Time of incident : " << claim.time;
			cout << "\n Claim Description : " << claim.description;
			cout << "\n Complaint detail : " << claim.detail;
			cout << "\n Phone number : " << claim.contact_no;
			cout << "\n Email address : " << claim.email;

			cout << "\n\n Is this information correct? (y/n) : ";
			cin >> restart;
			if (tolower(restart) != 'y')
			{
				cout << "\n Would you like to re-enter your details (y/n) : ";
				cin >> end;
				if (tolower(end) != 'y')
				{
					break;
				}
			}
		}
		else
		{
			cout << "\n Policy number not found\n";
			return;
		}

	} while (tolower(restart) != 'y');

	if (tolower(restart) == 'y')
	{
		claims.open("claims.dat", ios::out | ios::app | ios::binary);
		claims.write(reinterpret_cast<char*>(&claim), sizeof(claim));
		claims.close();
	}
}

void adminScreen()
{
	int choice;
	fstream file;
	Customer customer;
	Claim claim;
	Renewal r;
	Discount d;

	do
	{
		int i = 1;
		cout << "\n\n\tAdmin Screen\n\t------------\n";
		cout << "\n 1. Customer report/search";
		cout << "\n 2. Weekly claim report";
		cout << "\n 3. Weekly renewal report";
		cout << "\n 4. Weekly new registration report";
		cout << "\n 5. Update policy information and publish the special discounts";
		cout << "\n 6. Exit";

		cout << "\n\n Please select an option from the menu : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			bool found = false;

			char sname[20];
			cout << "\n\nEnter the first name of person to retrieve the records: ";
			cin.ignore();
			cin.getline(sname,20);

			
			file.open("Customer_Registration.dat", ios::in | ios::binary);


			if (file.is_open())
			{
				cout << "\n\tList of customers\n\t-----------------\n";

				

				while (file.read(reinterpret_cast<char*>(&customer), (sizeof(customer))))
				{
					if (strcmp(customer.first_name, sname) == 0)
					{
						cout << "\n Customer " << i << " : ";
						cout << "\n Name : " << customer.first_name << " " << customer.last_name;
						cout << "\n Date of birth : " << customer.dob;
						cout << "\n Gender : " << customer.gender;
						cout << "\n Contact Number : " << customer.contact_no;
						cout << "\n Email : " << customer.email;
						cout << "\n Address : " << customer.address;
						cout << "\n Vehicle registration number : " << customer.vehicleRegNumber;
						cout << "\n Username : " << customer.username;
						cout << "\n\n";
						i++;
						found = true;
					}
				}
				if (found == false)
				{
					cout << "\n\nNo record found in the file for the search key provided!\n\n";
				}

			}
			else {
				cout << "\n\nFile not found\n\n";
			}

			//close file
			file.close();
			system("pause");
			break;

		}
		case 2:
		{
			cout << "\n\tWeekly claim report\n\t---------------------\n";
			file.open("claims.dat", ios::binary | ios::in);
			while (file.read(reinterpret_cast<char*>(&claim), sizeof(claim)))
			{
				cout << "\n Claim number " << i << " : ";
				cout << "\n Policy number : " << claim.policy_no;
				cout << "\n Full Name : " << claim.first_name << " " << claim.last_name;
				cout << "\n Date of incident : " << claim.date;
				cout << "\n Time of incident : " << claim.time;
				cout << "\n Incident description : " << claim.description;
				cout << "\n\n Complaint Details : " << claim.detail;
				cout << "\n\n Contact Number : " << claim.contact_no;
				cout << "\n Email : " << claim.email;
				cout << "\n\n";
				i++;
			}
			file.close();
			break;
		}
		case 3:
		{
			cout << "\n\tList of renewals\n\t-----------------\n";
			file.open("renewals.dat", ios::in | ios::binary);

			while (file.read(reinterpret_cast<char*>(&r), sizeof(r)))
			{
				cout << "\n Policy number : " << r.policy_no;
				cout << "\n Full name : " << r.full_name;
				cout << "\n Policy changes : " << r.new_policy;
				cout << "\n Contact number : " << r.contact_no;
				cout << "\n Visa card number : " << r.visa_card_no;
				cout << "\n\n";
			}
			break;

		}
		case 4:
		{
			cout << "\n\tList of customers\n\t-----------------\n";
			file.open("Customer_Registration.txt", ios::in | ios::binary);

			while (file.peek() != EOF)
			{

				cout << "\n Customer " << i << " : ";
				file >> customer.first_name;
				file >> customer.last_name;
				cout << "\n Name : " << customer.first_name << " " << customer.last_name;
				file >> customer.dob;
				cout << "\n Date of birth : " << customer.dob;
				file >> customer.gender;
				cout << "\n Gender : " << customer.gender;
				file >> customer.contact_no;
				cout << "\n Contact Number : " << customer.contact_no;
				file >> customer.email;
				cout << "\n Email : " << customer.email;
				file >> customer.address;
				cout << "\n Address : " << customer.address;
				file >> customer.vehicleRegNumber;
				cout << "\n Vehicle registration number : " << customer.vehicleRegNumber;
				file >> customer.username;
				cout << "\n Username : " << customer.username;
				file >> customer.password;
				cout << "\n\n";

				i++;
			}
			break;
		}
		case 5:
		{
			int choice_discounts = 1;

			do
			{
				file.open("discounts.dat", ios::binary | ios::in);
				file.read(reinterpret_cast<char*> (&d), sizeof(d));

				cout << "\n\n Current Discounts : \n";
				cout << "1. Multi Policy = " << d.multi << "%\n";
				cout << "2. New Signups = " << d.new_signup << "%\n";
				cout << "3. Renewal = " << d.renewal << "%\n";
				cout << "4. Friends and Family " << d.friends_family << "%\n";
				cout << "5. Exit\n\n";

				file.close();

				cout << "Please enter a discount to change or press 5 to exit : ";
				cin >> choice_discounts;

				switch (choice_discounts)
				{
				case 1:
				{
					cout << "\nMulti Policy = ";
					cin >> d.multi;
					break;
				}
				case 2:
				{
					cout << "\nNew Signups = ";
					cin >> d.new_signup;
					break;
				}
				case 3:
				{
					cout << "\nRenewal = ";
					cin >> d.renewal;
					break;
				}
				case 4:
				{
					cout << "\nFriends and Family = ";
					cin >> d.friends_family;
					break;
				}
				case 5: break;
				default:
				{
					cout << "\nEnter a valid value\n\n";
					break;
				}

				}

			} while (choice_discounts != 5);


			file.open("discounts.dat", ios::binary | ios::out);
			file.write(reinterpret_cast<char*> (&d), sizeof(d));
			file.close();
			break;
		}
		case 6: break;
		default:
			cout << "\n Please enter a valid choice"; break;
		}
	} while (choice != 6);
}

void renewalScreen() {

	fstream file, r_file;
	Policy p;
	Renewal r;
	int choice;
	int policy_num;
	char change;

	do
	{
		bool found = false;
		cout << "\n\n\tPolicy Renewal / Changes\n\t------------------------\n";
		cout << "\n 1. Renewal";
		cout << "\n 2. Policy change";
		cout << "\n 3. Exit";
		cout << "\n\n Please enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\n Please enter your policy number : ";
			cin >> policy_num;
			cout << "\n\n\tCurrent Policy";
			file.open("policies.dat", ios::binary | ios::in);
			while (file.read(reinterpret_cast<char*>(&p), sizeof(p)))
			{
				if (p.policy_no == policy_num)
				{
					cout << "\n First name : " << p.first_name;
					cout << "\n Last name : " << p.last_name;
					cout << "\n Date of birth : " << p.dob;
					cout << "\n Gender : " << p.gender;
					cout << "\n Phone number : " << p.contact_no;
					cout << "\n Email address : " << p.email;
					cout << "\n Home address : " << p.address;
					cout << "\n Vehicle registration number : " << p.vehicleRegNumber;
					cout << "\n Vehicle name : " << p.vehicle_name;
					cout << "\n Vehicle model : " << p.model;
					cout << "\n Monthly cost : " << p.monthly_cost;
					cout << "\n Car value : " << p.car_value;
					found = true;
					cout << "\n\n Would you like to renew this policy (y/n) : ";
					cin >> change;
					if (tolower(change) == 'y')
					{
						r_file.open("renewals.dat", ios::binary | ios::out | ios::app);

						r.policy_no = policy_num;
						strcpy_s(r.full_name, p.first_name);
						strcat_s(r.full_name, " ");
						strcat_s(r.full_name, p.last_name);
						cin.ignore();
						cout << "\n Enter the Enxtended policy date : ";
						cin.getline(r.new_policy, 50);
						strcpy_s(r.contact_no, p.contact_no);
						cout << "\n Enter your visa card number : ";
						cin.getline(r.visa_card_no, 20);

						r_file.write(reinterpret_cast<char*>(&r), sizeof(r));
						r_file.close();

						cout << "\n One of our staff will contact you to confirm these changes\n\n";
						break;
					}
				}

			}
			if (!found)
			{
				cout << "\n Policy number not found\n";
			}
			file.close();
			break;
		case 2:
		{
			cout << "\n Please enter your policy number : ";
			cin >> policy_num;
			cout << "\n\n\tCurrent Policy";
			file.open("policies.dat", ios::binary | ios::in);
			while (file.read(reinterpret_cast<char*>(&p), sizeof(p)))
			{
				if (p.policy_no == policy_num)
				{
					cout << "\n First name : " << p.first_name;
					cout << "\n Last name : " << p.last_name;
					cout << "\n Date of birth : " << p.dob;
					cout << "\n Gender : " << p.gender;
					cout << "\n Phone number : " << p.contact_no;
					cout << "\n Email address : " << p.email;
					cout << "\n Home address : " << p.address;
					cout << "\n Vehicle registration number : " << p.vehicleRegNumber;
					cout << "\n Vehicle name : " << p.vehicle_name;
					cout << "\n Vehicle model : " << p.model;
					cout << "\n Monthly cost : " << p.monthly_cost;
					cout << "\n Car value : " << p.car_value;
					found = true;

					cout << "\n\n Would you like to change this policy (y/n) : ";
					cin >> change;
					if (tolower(change) == 'y')
					{
						r_file.open("renewals.dat", ios::binary | ios::out | ios::app);

						r.policy_no = policy_num;
						strcpy_s(r.full_name, p.first_name);
						strcat_s(r.full_name, " ");
						strcat_s(r.full_name, p.last_name);
						cin.ignore();
						cout << "\n Enter the policy change : ";
						cin.getline(r.new_policy, 50);
						strcpy_s(r.contact_no, p.contact_no);
						cout << "\n Enter your visa card number : ";
						cin.getline(r.visa_card_no, 20);

						r_file.write(reinterpret_cast<char*>(&r), sizeof(r));
						r_file.close();
						cout << "\n\n One of our staff will contact you to confirm these changes\n\n";
						break;
					}
				}
			}
			if (!found)
			{
				cout << "\n Policy number not found\n";
			}
			file.close();
			break;

		}
		case 3: break;
		default: cout << "\n Invalid Input\n"; break;
		}
	} while (choice != 3);

}

void insurancePolicy()
{
	int vehicle_type = 1, policy_type = 1, car_value, monthly_cost, choice = 1;
	char confirm;

	cout << "\n\n\tInsurance Policy\n\t----------------\n";


	do {
		cout << "\n\n1. Policy catagories\n";
		cout << "2. Policy descriptions\n";
		cout << "3. Policy quote / registration\n";
		cout << "4. Exit\n";

		cout << "Enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n\nWe offer Full, Comprehensive Cover and 3rd Party Fire and Theft policies\nfor cars and motorcycles with monthly payments.\n\n";
			break;
		}
		case 2:
		{
			cout << "\n\nFull, Comprehensive Cover : Full cover for accindetal damage or loss of vehicle as well as 3rd party cover\n";
			cout << "\n3rd Party Fire and Theft    : Cover for accidental damage to other peoples vehicles\n";
			break;
		}
		case 3:
		{
			do
			{
				cout << "\n Which type of vehicle would you like to insure?\n";
				cout << "\n 1. Car";
				cout << "\n 2. Motorcycle";
				if (vehicle_type != 1 && vehicle_type != 2)
				{
					cout << "\n\n Please select 1 or 2";
				}
				cout << "\n\n Please enter your choice : ";
				cin >> vehicle_type;
			} while (vehicle_type != 1 && vehicle_type != 2);


			do
			{
				cout << "\n\n Which type of insurance would you like?\n";
				cout << "\n 1. Full, Comprehensive Cover";
				cout << "\n 2. 3rd Party Fire and Theft";
				if (policy_type != 1 && policy_type != 2)
				{
					cout << "\n\n Please select 1 or 2\n\n";
				}
				cout << "\n\n Please enter your choice : ";
				cin >> policy_type;
			} while (policy_type != 1 && policy_type != 2);


			cout << "\n\n Please enter the value of your vehicle : $";
			cin >> car_value;

			monthly_cost = (car_value / 8) / 12;

			cout << "\n Summary : \n Vehicle type : ";

			switch (vehicle_type)
			{
			case 1:
			{
				cout << "Car\n Policy type : ";
				switch (policy_type)
				{
				case 1: {
					monthly_cost = monthly_cost * 1.8;
					cout << "Full, Comprehensive Cover";
					break;
				}
				case 2: {
					monthly_cost = monthly_cost * 1.7;
					cout << "3rd Party Fire and Theft";
					break;
				}
				default: cout << "\n Error\n"; return;
				}
				break;

			}
			case 2:
			{
				cout << "Motorcycle\n Policy type : ";

				switch (policy_type)
				{
				case 1: {
					monthly_cost = monthly_cost * 1.2;
					cout << "Full, Comprehensive Cover";
					break;
				}
				case 2: {
					monthly_cost = monthly_cost * 1.1;
					cout << "3rd Party Fire and Theft";
					break;
				}
				default: cout << "\n Error\n"; return;
				}
				break;
			}
			default: cout << "\n Error\n"; return;
			}
			cout << "\n Car value : $" << car_value;
			cout << "\n Monthly cost : $" << monthly_cost;

			cout << "\n\n Do you wish to purchase this policy? (y/n) : ";
			cin >> confirm;
			if (tolower(confirm) == 'y')
			{
				policyRegistration(vehicle_type * 10 + policy_type, car_value, monthly_cost);
			}
			break;
		}
		case 4: break;
		default:
			cout << "Enter a valid choice\n\n";
			break;
		}
	} while (choice != 4);

}