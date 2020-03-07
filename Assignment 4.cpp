//FILE: Assignment 4.cpp
//PROGRAMMER: Rynn Tee
//PURPOSE: Allows user to buy tickets, by picking a seat directly, or by ticket price

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// globar variables
const int NUM_ROW = 11;			// number of rows in price array
const int NUM_AISLE = 11;		// number of aisles in price array

// function prototypes
void displaySeats(int price[NUM_ROW][NUM_AISLE]);
void chooseMethod(int price[NUM_ROW][NUM_AISLE]);
void pickBySeat(int price[NUM_ROW][NUM_AISLE]);
void pickByPrice(int price[NUM_ROW][NUM_AISLE]);

int main()
{
	// initialize array, NUM_ROW & NUM_AISLE values at 0 are filler
	int price[NUM_ROW][NUM_AISLE] = {   { 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0 },			
										{ 0, 30, 40, 50, 50, 50, 50, 50, 50, 40, 30 },
										{ 0, 30, 40, 50, 50, 50, 50, 50, 50, 40, 30 },
										{ 0, 20, 30, 30, 40, 50, 50, 40, 30, 30, 20 },
										{ 0, 20, 20, 30, 30, 40, 40, 30, 30, 20, 20 },
										{ 0, 10, 10, 20, 20, 20, 20, 20, 20, 10, 10 },
										{ 0, 10, 10, 20, 20, 20, 20, 20, 20, 10, 10 },
										{ 0, 10, 10, 20, 20, 20, 20, 20, 20, 10, 10 },
										{ 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 },
										{ 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 },
										{ 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 } };
	
	char again;							// variable to hold if user wants to buy another ticket


	do
	{
		displaySeats(price);						// function call - display seating/price chart

		chooseMethod(price);						// function call - choose by seat or price?

		cout << endl << "Do you want to purchase another ticket? (Y/N) ";		// does user want to buy another ticket?
		cin >> again;
		cout << endl << endl;

	} while (again == 'Y' || again == 'y');					// while post-test loop for repeating program

	cout << "<<Thank you, and enjoy the show!>>" << endl << endl << endl;

return 0;
}



//*********************************************************************************************
// Function displaySeats - displays seating chart with prices				                  *
//*********************************************************************************************

void displaySeats(int price[NUM_ROW][NUM_AISLE])
{
	// display seats, with headings
	cout << endl;
	cout << left << setw(5) << "<AISLE> " << setw(5) << "1" << setw(5) << "2" << setw(5) << "3" << setw(5) << "4";
	cout << setw(5) << "5" << setw(5) << "6" << setw(5) << "7" << setw(5) << "8" << setw(5) << "9" << setw(5) << "10" << endl;
	cout << "<ROW>   " << "_____________________________________________________" << endl << endl;
	for (int rowIndex = 1; rowIndex < NUM_ROW; rowIndex++)					// rowIndex and aisleIndex start at 1, values at 0 are filler
	{										
		cout << setw(8) << rowIndex;
		
		for (int aisleIndex = 1; aisleIndex < NUM_AISLE; aisleIndex++)
		{
			cout << setw(5) << left << price[rowIndex][aisleIndex];
		}
		cout << endl << endl;
	}
}

//*********************************************************************************************
// Function chooseMethod - pick by seat or price?							                  *
//*********************************************************************************************
void chooseMethod(int price[NUM_ROW][NUM_AISLE])
{
	// menu choice constants
	const int METHOD_SEAT = 1;		// pick by seat
	const int METHOD_PRICE = 2;		// pick by price
	const int METHOD_EXIT = 3;		// exit
	int methodChoice;				// variable to hold user's choice input

	// menu
	cout << "<Buy a ticket>" << endl;
	cout << "1. [Pick by seat]" << endl;
	cout << "2. [Pick by price]" << endl;
	cout << "3. [Exit]" << endl << endl;

	cout << "Enter your choice: ";
	cin >> methodChoice;
	cout << endl;

	while (methodChoice != 1 && methodChoice != 2 && methodChoice != 3)					// input validation
	{
		cout << "You have entered an invalid choice. Please enter 1, 2 or 3: ";
		cin >> methodChoice;
		cout << endl;
	}

	if (methodChoice == METHOD_SEAT)									
	{
		cout << "You have chosen [pick by seat]." << endl << endl;
		pickBySeat(price);									// function call - pick by seat
	}
		

	else if (methodChoice == METHOD_PRICE)
	{
		cout << "You have chosen [pick by price]." << endl << endl;
		pickByPrice(price);					// function call - pick by price

	}

	else if (methodChoice == METHOD_EXIT)
	{
		cout << "You have chosen to [Exit]." << endl << endl;
	}

}

//*********************************************************************************************
// Function pickBySeat - pick by seat										                  *
//*********************************************************************************************
void pickBySeat(int price[NUM_ROW][NUM_AISLE])
{
	int seatRow;			// variable to hold user's row choice
	int seatAisle;			// variable to hold user's aisle choice

	cout << "Please pick row number: ";
	cin >> seatRow;

	while (seatRow < 1 || seatRow > 10)		// input validation 
	{
		cout << "That is an invalid row. Please enter a number from 1 - 10: ";
		cin >> seatRow;
	}

	cout << "Please pick aisle number: ";
	cin >> seatAisle;

	while (seatAisle < 1 || seatAisle > 10)		// input validation
	{
		cout << "That is an invalid aisle. Please enter a number from 1 - 10: ";
		cin >> seatAisle;
	}

	if (price[seatRow][seatAisle] == 0)			// seats with value of 0 are considered taken
			cout << endl << "This seat is not available. " << endl;

	else
	{
		cout << endl << "You have picked a seat at row " << seatRow << " aisle " << seatAisle << "." << endl;
		cout << "Your total is $" << price[seatRow][seatAisle] << "." << endl;
		price[seatRow][seatAisle] = 0;			// seat bought by user is changed to 0, to show it is no longer available
	}
}

//*********************************************************************************************
// Function pickByPrice - pick by price												          *
//*********************************************************************************************
void pickByPrice(int price[NUM_ROW][NUM_AISLE])
{
	int seatPrice;		// variable to hold user's price choice

	cout << "Seats are available at <$10>, <$20>, <$30>, <$40>, <$50>." << endl;
	cout << "Please enter a price: $";
	cin >> seatPrice;

	while (seatPrice != 10 && seatPrice != 20 && seatPrice != 30 && seatPrice != 40 && seatPrice != 50) // input validation 
	{
		cout << "That is not a valid price." << endl << endl;
		cout << "Seats are available at <$10>, <$20>, <$30>, <$40>, <$50>." << endl;
		cout << "Please enter a price: $";
		cin >> seatPrice;
	}

	int rowIndex = 0;					// subscript index for row
	int aisleIndex = 0;					// subscript index for aisle			
	bool found = false;					// flag to indicate if seat is found
	char buy;							// variable to hold if user wants to buy the ticket offered

	do {
		while (rowIndex <= NUM_ROW && !found)
		{
			while (aisleIndex <= NUM_AISLE && !found)
			{
				if (price[rowIndex][aisleIndex] == seatPrice)
				{
					found = true;

					cout << endl;
					cout << "Seat is at row " << rowIndex << " aisle " << aisleIndex << "." << endl;
					cout << "Do you want to purchase this seat? (Y/N) ";		 	//does user want to buy this seat?
					cin >> buy;

					if (buy == 'N' || buy == 'n')
					{
						found = false;					// set found back to false, so search will continue where it left off
					}

					if (buy == 'Y' || buy == 'y')
					{
						price[rowIndex][aisleIndex] = 0;		// set value to 0, to show that seat is no longer available
					}
				}
				aisleIndex++;					// go to next aisle
			}
			rowIndex++;							// go to next row
			aisleIndex = 0;						// set to 0, so aisle search can begin again for new row
		}

		if (!found)							// if seats are not found
		{
			cout << endl << "There are no more seats available at this price." << endl;
			break;							// break back out to main
		}

	} while (buy == 'N' || buy == 'n');		// post-test loop - does user want to buy another ticket?
}
