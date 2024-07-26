#include<iostream>
#include<fstream>
#include<istream>
#include<string.h>
#include<conio.h>

using namespace std;

#include "LinkList.h"
#include "SortList.h"

LinkList l1 = LinkList();
LinkList all_record = LinkList(2);



void menu() {
	system("CLS");
	cout << "-------------------- WELCOME TO DS PROJECT------------------------";
	cout << endl << endl << endl << endl << endl;
	cout << "1) Show All Records  [LINKED LIST + CSV + RUNTIME SORTING]" << endl;
	cout << "2) Add Record  [LINKED LIST + CSV + RUNTIME SORTING]" << endl;
	cout << "3) Delete Record  [BINARY_SEARCH + PATTERN_SEARCH]" << endl;
	cout << "4) Update Record  [BINARY_SEARCH + PATTERN_SEARCH]  " << endl;
	cout << "5) Show Sorted Record by field  [MERGE_SORT]" << endl; // further take input to find the sort field
	cout << "6) Search for Record [BINARY_SEARCH]" << endl; // further take input to find the sort field

	cout << "\n-1) EXIT" << endl;
	int choice;
	cout << "Enter Option : " << endl;
	cin >> choice;
	
	switch (choice) {
	case(-1): {
		exit(-1);
		break;
	}
	case(1): {

		system("CLS");
		cout << setw(80) << "---Displaying all Records---" << endl;
		l1.displayList();

		_getch();
		menu();
		break;
	}
	case(2): {
		bool ask = 1;
		while (ask) {

			if (ask == 1) {
				Node* rec = (Node*)l1.add();
				input(rec);
				cout << endl;
			}
			
				cout << "\nRecord added. Do you want to enter another record (Y/N) ? " << endl;
				fflush(stdin);
				char ch = _getch();

				if (ch != 'Y' && ch != 'y') {
					ask = 0;
				}
			}
		
		l1.saveAsCSV();
		cout << endl << "Link list saved. successfully." << endl;
		l1.sortData();
		menu();
		break;
	}
	case(3): {
		bool ask = 1;
		while (ask) {
			all_record.clear();
			string n;
			cout << "\n Enter Name : ";
			cin >> n;
			upperCase(const_cast<char*>(n.c_str()));
			int no_of_rec = l1.searchList_all(NAME, n, &all_record);

			if (no_of_rec <= 0) {
				cout << "\nNo Records exist with the name of  " << n;
				_getch();
				break;
			}
			else if (no_of_rec == 1) {
				all_record.displayList();
				cout << "\n here";
				if (l1.remove(all_record.head->recid) == 0) {
					cout << endl << "1 Record deleted Successfully ";
					l1.saveAsCSV();
				}
			}
			else if (no_of_rec > 1) {
				cout << no_of_rec << " Total records found & displayed below : " << endl;
				all_record.displayList();
				int target;
				cout << endl << "Enter Record id from list, you want to delete : ";
				cin >> target;
				if (l1.remove(target) == 0) {
					cout << endl << "\n RECORD DELETED SUCCESSFULLY !!!";
					l1.saveAsCSV();
				}
			}
			cout << "\nRecord REMOVED. Do you want to REMOVE another record (Y/N) ? " << endl;
			fflush(stdin);
			char ch = _getch();

			if (ch != 'Y' && ch != 'y') {
				ask = 0;
			}
		}
		_getch();
		menu();
		break;
	}
	case(4): {
		// update record :
		bool ask = 1;
		while (ask) {
			all_record.clear();
			string n;
			cout << "\n Enter Name : ";
			cin >> n;
			upperCase(const_cast<char*>(n.c_str()));
			int no_of_rec = l1.searchList_all(NAME, n, &all_record);

			if (no_of_rec <= 0) {
				cout << "\nNo Records exist with the name of  " << n;
				_getch();
				break;
			}
			else if (no_of_rec == 1) {
				all_record.displayList();
				if (l1.update_record(all_record.head->recid) == 0) {
					cout << endl << "\n RECORD UPDATED SUCCESSFULLY !!!";
					l1.saveAsCSV();
				}
			}
			else if (no_of_rec > 1) {
				cout << no_of_rec << " Total records found & displayed below : " << endl;
				all_record.displayList();
				int target;
				cout << endl << "Enter Record id from list, you want to Update : ";
				cin >> target;
				if (l1.update_record(target) == 0) {
					cout << endl << "\n RECORD UPDATED SUCCESSFULLY !!!";
					l1.saveAsCSV();
				}
			}
			cout << "\nRecord UPDATED. Do you want to Update another record (Y/N) ? " << endl;
			fflush(stdin);
			char ch = _getch();

			if (ch != 'Y' && ch != 'y') {
				ask = 0;
			}
		}
		//_getch();
		menu();
		break;
	}
	case(5): {
		bool ask = 1;
		while (ask) {
			
			tag : 
			system("CLS");
			int keyfield;
			cout << "SORT FIELDS : \n";
			cout << "1) NAME" << endl;
			cout << "2) BATCH" << endl;
			cout << "3) COMPANY" << endl;
			cout << "4) COUNTRY" << endl;
			cout << "5) JOBTITLE" << endl;
			cout << "6) CAMPUS" << endl;
			cout << "7) DEPARTMENT" << endl << endl;

			cout << "\n Enter the sort field <int>: ";
			cin >> keyfield;
			if (keyfield == NAME) {
				l1.displaySortedList(NAME);
			}
			else if (keyfield == BATCH) {
				l1.displaySortedList(BATCH);
			}
			else if (keyfield == COMPANY) {
				l1.displaySortedList(COMPANY);
			}
			else if (keyfield == COUNTRY) {
				l1.displaySortedList(COUNTRY);
			}
			else if (keyfield == JOBTITLE) {
				l1.displaySortedList(JOBTITLE);
			}
			else if (keyfield == CAMPUS) {
				l1.displaySortedList(CAMPUS);
			}
			else if (keyfield == DEPARTMENT) {
				l1.displaySortedList(DEPARTMENT);
			}
			else {
				cout << "\nWrong Entry, TRY AGAIN ";
				_getch();
				goto tag;
			}
			cout << "\nDo you want to Search another record (Y/N) ? " << endl;
			fflush(stdin);
			char ch = _getch();

			if (ch != 'Y' && ch != 'y') {
				ask = 0;
			}

		}
		//_getch();
		menu();
		break;
	}
	case(6): {
		bool ask = 1;
		while (ask) {
			all_record.clear();
			string n;
			cout << "\n Enter Name : ";
			cin >> n;
			upperCase(const_cast<char*>(n.c_str()));
			int no_of_rec = l1.searchList_all(NAME, n, &all_record);

			if (no_of_rec <= 0) {
				cout << "\nNo Records exist with the name of  " << n;
				_getch();
				break;
			}
			else if (no_of_rec >= 1) {
				cout << no_of_rec << " Total records found & displayed below : " << endl;
				all_record.displayList();
			}
			cout << "\nDo you want to Search another record (Y/N) ? " << endl;
			fflush(stdin);
			char ch = _getch();

			if (ch != 'Y' && ch != 'y') {
				ask = 0;
			}
		}
		_getch();
		menu();
		break;
	}

	default: {
		cout << "\nERROR Incorrect input";
		//menu();
		break;
	}
	}
}


	



int main() {

	/*
		try {
			l1.displayList();

			cout << endl << "Sorted List: " << endl;
			l1.displaySortedList(NAME);

			l1.saveAsCSV();
			cout << endl << "Link list saved. successfully." << endl;
		} catch (exception e) {
			cout << endl << "Link list saving failed with errors." << endl;
		}
	*/
//	cout << endl << "Search Imad uddin Muhammad:" << endl;
	//Node* n= l1.searchList(NAME,  "LIONEL MESSI");
	//Node* n= l1.searchList(JOBTITLE,  "CEO");
	//n->print();
	//int count = l1.searchList_all(NAME, "Imad uddin Muhammad", &all_record);
	//cout << "\n Count = " << count << endl;
	//all_record.displayList

	menu();

	return 0 ;
}