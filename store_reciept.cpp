// Copyright© 2021 AncientTides 

#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

using std::cout;using std::cin;using std::string;using std::stringstream;using std::vector;

// PROTOTYPES
string Convert_Int2String(int value);
string Date_Time();
void issue_receipt();
void dyn_issue_receipt();
void Live_Receipt();


// GLOBAL const VARIABLES
string STORE_NAME = "Hello World Stores";
string STORE_ADDRESS = "No 24, Hello-World Street, Lekki, Lagos, Nigeria";
string LOGO = "\n\n\n\t\t\t	   ..........\n\t\t\t	 ..............\n\t\t\t	................\n\t\t\t\t................\n\t\t\t	................\n\t\t\t	 ..............\n\t\t\t	   ..........\n\n\n\t\t";


//	-----------------------------------------------------------------------------------------------


void SAVE_RECEIPT(string data)
{
	ofstream fd("Receipt_printout.txt");
	fd << data;
	fd.close();
}


string Convert_Int2String(int value)
{
	string fs;
	stringstream ss;
	ss << value;
	ss >> fs;
	ss.clear();
	return fs;
}

string Date_Time()
{// requires #include <ctime>
    stringstream zz;
    string datetime, k;
    time_t ttime = time(0);
    char *dt = ctime(&ttime);
    zz << dt;zz >> k;zz.clear();
    // datetime = "The current local date and time is: " + k;
    return k;
}

void issue_receipt()
{
	string RECIEPT, product_name, number_of_items, product_amount, cashier_name, Local_Epoch;
	product_name = "Anti-Dimensional Particle Booster - X130";
	number_of_items = "7";
	product_amount = "$ 930,000,000.88";
	cashier_name = "Cassandra Z25XF";
	Local_Epoch = Date_Time();

	RECIEPT = "\n\n\n\n\n\n\n\n\n\n\n\n\t\t" + STORE_NAME + "\n" + STORE_ADDRESS + ".\n____________________________________________________________________\n\nPRODUCT NAME :\t" + product_name + "\n\nQUANTITY     :\t" + number_of_items + "\n\nAMOUNT PAID  :\t" + product_amount + "\n\nCASHIER	     :\t" + cashier_name + "\n\nDATE         :\t" + Local_Epoch + "\n\n\n\nThank you for shopping with us, See you soon" + LOGO;
	cout << RECIEPT << "\n\n";

	// SAVE_RECEIPT(RECIEPT);
}

void dyn_issue_receipt()
{
	string RECIEPT, product_name, number_of_items, product_amount, cashier_name, Local_Epoch;
	cout << "Enter Product Name: \n";cin >> product_name;
	cout << "Enter Number of products purchased: \n";cin >> number_of_items;
	cout << "Enter Product Amount: \n";cin >> product_amount;
	cout << "Enter Your Alias as our cashier: \n";cin >> cashier_name;
	Local_Epoch = Date_Time();

	RECIEPT = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t" + STORE_NAME + "\n" + STORE_ADDRESS + ".\n____________________________________________________________________\n\nPRODUCT NAME :\t" + product_name + "\n\nQUANTITY     :\t" + number_of_items + "\n\nAMOUNT PAID  :\t$" + product_amount + "\n\nCASHIER	     :\t" + cashier_name + "\n\nDATE         :\t" + Local_Epoch + "\n\n\n\nThank you for shopping with us, See you soon" + LOGO;
	cout << RECIEPT << "\n\n";

	// SAVE_RECEIPT(RECIEPT); 
}



void Live_Receipt()
{
	string RECIEPT, cashier_name, Local_Epoch, temp;
	vector<string> product_name;
	vector<int> product_cost;
	int num_of_products, temp2, TOTAL_COST = 0;
	cout << "Enter Your Alias as our cashier: \n";
	cin >> cashier_name;
	cout << "How many products would you like to process? : \n";
	cin >> num_of_products;

	int count = 0;
	while(count != num_of_products)
	{
	    cout << "Enter Product Name: \n";
	    cin >> temp; // input product name
	    product_name.push_back(temp); // store product name in vector container

	    cout << "Enter Product Price: \n";
	    cin >> temp2; // input product price
	    product_cost.push_back(temp2); // store amount in vector container

	    temp = ""; // reset temp variable
	    count++; // increment count variable
	}
	Local_Epoch = Date_Time();

	RECIEPT = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t" + STORE_NAME + "\n\t\t" + STORE_ADDRESS + ".\n______________________________________________________________________________\n" + "______________________________________________________________________________\n\n" + "\tITEM NAME\t\t($) PRICE\n" + "______________________________________________________________________________\n";

	for (int i = 0; i < num_of_products; ++i)
	{
		RECIEPT += "\n " + Convert_Int2String(i+1) + " |  \t" + product_name[i] + "\t\t\tPRICE : $" + Convert_Int2String(product_cost[i]) + ".00";
		TOTAL_COST += product_cost[i]; // calcualte total
	}
	RECIEPT += "\n\n______________________________________________________________________________\n\n\t\t\t\t\t\t\tTOTAL = $" + Convert_Int2String(TOTAL_COST) + ".00";
	RECIEPT += "\n______________________________________________________________________________\n";
	RECIEPT += "\nCASHIER	 :\t" + cashier_name + "\nDATE     :\t" + Local_Epoch + "\n\n\n\t\tThank you for shopping with us, See you soon" + LOGO;
	cout << RECIEPT << "\n\n";

	SAVE_RECEIPT(RECIEPT);
}



int main(int argc, char const *argv[])
{
	
	issue_receipt();
	// dyn_issue_receipt();
	// Live_Receipt();

	return 0;
}




