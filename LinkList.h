//File: LinkList.h (B)

#ifndef LINKLIST_H			//agr ye wala keyword define hua wa hai tw dobara redefine nhi krna
#define LINKLIST_H

#include "SortList.h"
#include<cctype>
#include<iomanip>
#include<string>

const string DATAFILE = "Table_Alumni.txt";

enum FIELDNAME {
	RECID,
	NAME,
	BATCH,
	COMPANY,
	COUNTRY,
	JOBTITLE,
	CAMPUS,
	DEPARTMENT,
};

class Node {

	public:
		int recid;
		char name[101];
		char batch[5];
		char company[101];
		char country[101];
		char jobtitle[101];
		char campus[101];
		char department[101];
		

		Node* next;
		Node* prev;

		Node() {
			this->recid = 0;
			next = NULL;
			prev = NULL;
		}

		void parseData(int recid, string name, string batch, string company, string country, string jobtitle, string campus, string department) {
			this->recid = recid;
			strcpy_s(this->name,name.c_str());
			strcpy_s(this->batch,batch.c_str());
			strcpy_s(this->company,company.c_str());
			strcpy_s(this->country, country.c_str());
			strcpy_s(this->jobtitle, jobtitle.c_str());
			strcpy_s(this->campus, campus.c_str());
			strcpy_s(this->department, department.c_str());
		}

		void parseData(string textRow) {
			this->recid = (int) atoi(textRow.substr(0, 10).c_str());
			strcpy_s(this->name, textRow.substr(0, 100).c_str());
			strcpy_s(this->batch, textRow.substr(111, 5).c_str());
			strcpy_s(this->company, textRow.substr(116, 100).c_str());
			strcpy_s(this->country, textRow.substr(216, 100).c_str());
			strcpy_s(this->jobtitle, textRow.substr(316, 100).c_str());
			strcpy_s(this->campus, textRow.substr(416, 100).c_str());
			strcpy_s(this->department, textRow.substr(516, 100).c_str());			
		}

		//"1","Imad uddin Muhammad","2023","huawei.com","RUSSIA","CEO","KARACHI","CS",

		void print() {
			cout << std::left << std::setw(20) << recid << std::setw(20) << name << std::setw(20) << batch << std::setw(20) << company << std::setw(20) << country << std::setw(20) << jobtitle << std::setw(20) << campus << std::setw(40) << department << endl;
			//cout << recid << "  " << name << "  " << batch << "  " << company << "  " << country << "  " << jobtitle << "  " << campus << "	" << department << endl;
		}
				
};

//// Input New Records in Table
void upperCase(char* a) {
	for (int x = 0; x < strlen(a); x++) {
		a[x] = toupper(a[x]);
	}
}


void input(Node* rec) {
	system("CLS");

	string st;
	cout << "\n--------------------- Entering A New RECORD -------------------------";
	cout << "\n Enter Name : " << endl;
	getline(cin >> ws, st);
	strcpy_s(rec->name, st.substr(0,99).c_str());
	upperCase(rec->name);

	cout << "\n Enter batch eg(2022): " << endl;
	getline(cin >> ws, st);
	strcpy_s(rec->batch, st.substr(0, 4).c_str());
	upperCase(rec->batch);

	cout << "\n Enter Company : " << endl;
	getline(cin >> ws, st);
	strcpy_s(rec->company, st.substr(0, 99).c_str());
	upperCase(rec->company);

	cout << "\n Enter Country : " << endl;
	getline(cin >> ws, st);
	strcpy_s(rec->country, st.substr(0, 99).c_str());
	upperCase(rec->country);

	cout << "\n Enter Designation : " << endl;
	getline(cin >> ws, st);
	strcpy_s(rec->jobtitle, st.substr(0, 99).c_str());
	upperCase(rec->jobtitle);

	cout << "\n Enter Campus : " << endl;
	getline(cin >> ws, st);
	strcpy_s(rec->campus, st.substr(0, 99).c_str());
	upperCase(rec->campus);

	cout << "\n Enter Department : " << endl;
	getline(cin >> ws, st);
	strcpy_s(rec->department, st.substr(0, 99).c_str());
	upperCase(rec->department);
}



class LinkList {
	private:
		SortList SL_name;
		SortList SL_batch;
		SortList SL_company;
		SortList SL_country;
		SortList SL_jobtitle;
		SortList SL_campus;
		SortList SL_department;



	public:
		int nCount = 0;
		Node* head = NULL;
		Node* tail = NULL;
		Node* cursor = head;
		string filename = DATAFILE;

		// 3 types of constructor

		LinkList() {
			LoadAsCSV();	// disk mai jo bhi last data tha usko wo load krle
			sortData();		// jitni bhi sortlist banni hai wo bana le
		}

		LinkList(char* CSVFilePath) {
			filename = string(CSVFilePath);
			LinkList();
		}

		LinkList(int a) {
		}

		//sort data list as per Name
		void sortData() {

			SL_name.clear();
			SL_batch.clear();
			SL_company.clear();
			SL_country.clear();
			SL_jobtitle.clear();
			SL_campus.clear();
			SL_department.clear();


			createSL(&SL_name, NAME);
			createSL(&SL_batch, BATCH);
			createSL(&SL_company, COMPANY);
			createSL(&SL_country, COUNTRY);
			createSL(&SL_jobtitle, JOBTITLE);
			createSL(&SL_campus, CAMPUS);
			createSL(&SL_department, DEPARTMENT);
		
		}

		void createSL(SortList* SL, int fieldname) {
			// If DATA EXISTS IN THE MAIN LIST
			//1. Copy all source data key (Node values) in this sorted list as nodes
			if(this->head != NULL) {

				if (fieldname == NAME) {
					cursor = this->head;
					while (cursor != NULL) {
						SL->add(cursor->name, cursor);
						cursor = cursor->next;
					}
					SL->updateSL();
				}
				if (fieldname == BATCH) {
					cursor = this->head;
					while (cursor != NULL) {
						SL->add(cursor->batch, cursor);
						cursor = cursor->next;
					} 
					SL->updateSL();
				}
				if (fieldname == COMPANY) {
					cursor = this->head;
					while (cursor != NULL) {
						SL->add(cursor->company, cursor);
						cursor = cursor->next;
					} 
					SL->updateSL();
				}
				if (fieldname == COUNTRY) {
					cursor = this->head;
					while (cursor != NULL) {
						SL->add(cursor->country, cursor);
						cursor = cursor->next;
					} 
					SL->updateSL();
				}
				if (fieldname == JOBTITLE) {
					cursor = this->head;
					while (cursor != NULL) {
						SL->add(cursor->jobtitle, cursor);
						cursor = cursor->next;
					} 
					SL->updateSL();
				}
				if (fieldname == CAMPUS) {
					cursor = this->head;
					while (cursor != NULL) {
						SL->add(cursor->campus, cursor);
						cursor = cursor->next;
					} 
					SL->updateSL();
				}
				if (fieldname == DEPARTMENT) {
					cursor = this->head;
					while (cursor != NULL) {
						SL->add(cursor->department, cursor);
						cursor = cursor->next;
					} 
					SL->updateSL();
				}
			} else {
				cout << "\n\ncould not sort !";
			}
		}

		Node* searchList(int data) {
			Node* tmp = binarySearch(head, data);

			if (tmp)
				return tmp;
			else
				return nullptr;
		}

		int searchList_all(int keyfield, string data, LinkList* ll) {
			SortList* SL;
			SortList node;
			// default open by name
			SL = &SL_name;

			//string a = "Imad uddin Muhammad";
			//SL->searchSL((char*)a.c_str());

			int cnt = 0;

			if (keyfield == NAME) {
				SL = &SL_name;
				cnt = SL->searchSL_all((char*)data.c_str(), &node);
			}
			if (keyfield == BATCH) {
				SL = &SL_batch;
				cnt = SL->searchSL_all((char*)data.c_str(), &node);
			}
			if (keyfield == COMPANY) {
				SL = &SL_company;
				cnt = SL->searchSL_all((char*)data.c_str(), &node);
			}
			if (keyfield == COUNTRY) {
				SL = &SL_country;
				cnt = SL->searchSL_all((char*)data.c_str(), &node);
			}
			if (keyfield == JOBTITLE) {
				SL = &SL_jobtitle;
				cnt = SL->searchSL_all((char*)data.c_str(), &node);
			}
			if (keyfield == CAMPUS) {
				SL = &SL_campus;
				cnt = SL->searchSL_all((char*)data.c_str(), &node);
			}
			if (keyfield == DEPARTMENT) {
				SL = &SL_department;
				cnt = SL->searchSL_all((char*)data.c_str(), &node);
			}


			if (node.count > 0) {
				node.cursor = node.head;
				// sirf add kara rahe count pehle se agaya
				do {
					ll->add(node.cursor->rec_ptr);
					node.cursor = node.cursor->next;
				} while (node.cursor != NULL);
				return cnt;
			}

			return cnt;
		}
		
		// 2 types of node

		Node* add() {
			cursor = head;
			Node* newnode = new Node();
			nCount++;
			newnode->recid = nCount;
			newnode->next = NULL;
			newnode->prev = NULL;

			if (head == NULL) {
				head = newnode;
				tail = newnode;
			}
			else {
				while (cursor->next != NULL) cursor = cursor->next; //move to last node
				cursor->next = newnode;
				newnode->prev = cursor;
				tail = newnode;
			}
			return newnode;
		};

		void add(Node* a) {
			cursor = head;
			Node* newnode = new Node();
			nCount++;

			newnode->next = NULL;
			newnode->prev = NULL;

			newnode->recid = a->recid;
			strcpy_s(newnode->batch, a->batch);
			strcpy_s(newnode->company, a->company);
			strcpy_s(newnode->country, a->country);
			strcpy_s(newnode->jobtitle, a->jobtitle);
			strcpy_s(newnode->name, a->name);
			strcpy_s(newnode->campus, a->campus);
			strcpy_s(newnode->department, a->department);


			if (head == NULL) {
				head = newnode;
				tail = newnode;
			}
			else {

				while (cursor->next != NULL) cursor = cursor->next; //move to last node

				cursor->next = newnode;
				newnode->prev = cursor;
				tail = newnode;
			}
			// addition;
			//saveAsCSV();
		};

		// binary search functions below
		// function to calculate the middle Node Element
		Node* middle(Node* head) {
			Node* slow = head;
			if (slow->next != NULL) {
				Node* fast = slow->next;
				while (!slow->next && !fast && !fast->next) {
					slow = slow->next;
					fast = fast->next->next;
				}
			}
			return slow;
		}


		Node* binarySearch(Node* head, int value) {
			Node* mid;
			Node* start = head;
			Node* last = NULL;

			do {
				mid = middle(start);
				if (mid == NULL) {
					return NULL;
				}

				if (mid->recid == value) {
					return mid;
					//success
				}
				else if (mid->recid < value) {
					start = mid->next;
				}
				else {
					last = mid;
				}
			} while (last == NULL || last != start);
			return NULL;
		}

		Node* search_bin(int a) {
			Node* element = NULL;
			if (a <= 0) {
				cout << "\n Wrong Entry" << endl;
				return nullptr;
			}
			else {
				element = binarySearch(head, a);
				return element;
			}
			return nullptr;
		}
		// above three are binary functions
		
		// update function
		int update_record(int recid) {
			cursor = head;

			if (head == NULL || recid <= 0) {
				return -1;
			}
			else {
				cursor = search_bin(recid);

				// now cursor is at desired node
				if (cursor->recid == recid && cursor != NULL) {
					cout << endl << "Confirm (Y/N) ";
					char ch = _getch();
					if (ch != 'Y' && ch != 'y') return -1;

					// found
					input(cursor);
					return 0;
				}
				else {
					cout << "\nNo Such Record found !!!!";
					return NULL;
				}

				return 0;
			}
		}

		int remove(int recid) {
			cursor = head;

			if (head == NULL || recid <= 0) {
				return -1;
			}
			else {

				cursor = search_bin(recid);

				// cursor at desired node
				if (cursor->recid == recid && cursor != NULL) {
					cout << endl << "Confirm (Y/N) ";
					fflush(stdin);
					char ch = _getch();

					if (ch != 'Y' && ch != 'y') {
						return -1;
					}
					// found at head
					if (cursor == head && cursor->recid == recid) {
						Node* tmp = cursor;

						cursor = cursor->next;
						cursor->prev = NULL;
						head = cursor;
						cout << "\n deleted only element";
						delete tmp;
					}
					// found at end
					else if (cursor == tail && cursor->recid == recid) {
						Node* tmp = cursor;

						cursor = cursor->prev;
						cursor->next = NULL;
						tail = cursor;

						delete tmp;
					}
					// found in middle
					else if (cursor->recid == recid) {
						Node* tmp = cursor;

						cursor = tmp->next;
						cursor->prev = tmp->prev;

						cursor = tmp->prev;
						cursor->next = tmp->next;

						delete tmp;
					}
				}
				else {
					cout << "\nNo Such Record found !!!!";
					return -1;
				}
				return 0;
			}
		};

		void displayList() {
			cout << std::left << std::setw(20) << "RECORD ID" << std::setw(20) << "NAME" << std::setw(20) << "BATCH" << std::setw(20) << "COMPANY" << std::setw(20) << "COUNTRY" << std::setw(20) << "JOBTITLE" << std::setw(20) << "CAMPUS" << std::setw(40) << "DEPARTMENT" << endl;
			cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------";
			cout << endl;
			
			cursor = head;
			if (cursor) {
				while (cursor != nullptr) {
					cursor->print();
					cursor = cursor->next;
				}
			}
		}

		void displaySortedList(int field) {
			// defaut name
			SortList* SL= &SL_name;

			if (field==NAME)
				SL = &SL_name;
			if (field==BATCH)
				SL = &SL_batch;
			if (field==COMPANY)
				SL = &SL_company;
			if (field==COUNTRY)
				SL = &SL_country;
			if (field==JOBTITLE)
				SL = &SL_jobtitle;
			if (field==CAMPUS)
				SL = &SL_campus;
			if (field==DEPARTMENT)
				SL = &SL_department;


			cout << "\nDISPLAYING SORTED LIST : " << endl;
			

			SL->cursor = SL->head;
			if (SL->cursor) {
				while (SL->cursor != nullptr) {
					Node* n = SL->cursor->rec_ptr;
					n->print();
					SL->cursor = SL->cursor->next;
				}
			}
		}


		void displaySortedNode(SortNode* a) {
			if (a == nullptr) {
				cout << "\n No ENTRY Found, SORRY !!! \n";
			} else {
				Node* n = a->rec_ptr;
				cout << "\n---------------------------------- RECORD FOUND ------------------------------------\n";
				n->print();
			}
		}


//Clear all list nodes
		void clear() {
			Node* cursor = tail;
			Node* tmp;
			while (cursor != nullptr) {
				tmp = cursor;
				cursor = cursor->prev;
				delete tmp;
			}
			this->head = NULL;
		}

//save list as csv/text file
		void saveAsCSV() {
			char buf[4096];
			ofstream outFile;
			Node* Ptr = this->head;

			outFile.open(filename.c_str());
			while (outFile && Ptr) {

				sprintf_s(buf, "\"%d\",", Ptr->recid);
				outFile << string(buf).c_str();
				

				sprintf_s(buf, "\"%s\",", (Ptr->name == NULL ? " " : Ptr->name));
				outFile << string(buf).c_str();

				sprintf_s(buf, "\"%s\",", (Ptr->batch == NULL ?" " : Ptr->batch));
				outFile << string(buf).c_str();

				sprintf_s(buf, "\"%s\",", (Ptr->company == NULL ?" ": Ptr->company));
				outFile << string(buf).c_str();

				sprintf_s(buf, "\"%s\",", (Ptr->country == NULL ?" ": Ptr->country));
				outFile << string(buf).c_str();

				sprintf_s(buf, "\"%s\",", (Ptr->jobtitle==NULL?" ":Ptr->jobtitle));
				outFile << string(buf).c_str();
				
				sprintf_s(buf, "\"%s\",", (Ptr->campus==NULL?" ":Ptr->campus));
				outFile << string(buf).c_str();

				sprintf_s(buf, "\"%s\",", (Ptr->department==NULL?" ":Ptr->department));
				outFile << string(buf).c_str();


				outFile << endl;
				Ptr = Ptr->next;
			}
			outFile.close();
		};

// load csv/text data file into LinkList
		void LoadAsCSV() {

			char buf[4096];
			string rec;
			ifstream inFile;
			Node* Ptr = this->head;

			inFile.open(filename.c_str());
			if (inFile.good()) {
				clear();

				inFile.getline(buf, 4095);
				int i = 0;
				
				while (!inFile.eof()) {

					string vals[50];
					int cnt = parseCSV(buf, vals);

// add node
					Node* rec = (Node*)add();
					rec->parseData((int)atoi( vals[0].c_str()), vals[1], vals[2], vals[3], vals[4], vals[5], vals[6], vals[7]);

					/*
					rec->recid = (int)atoi(vals[0].c_str());
					strcpy_s(rec->name, vals[1].c_str());
					strcpy_s(rec->batch, vals[2].c_str());
					strcpy_s(rec->company, vals[3].c_str());
					strcpy_s(rec->country, vals[4].c_str());
					strcpy_s(rec->jobtitle, vals[5].c_str());
					*/

					inFile.getline(buf, 4095);
					i++;
				}

				cout << "\n Total records loaded : " << i << endl << endl;
				inFile.close();
			}
		};

//remove spaces from data labels
		
		string trim_spaces(string s) {
			string t;
			char buf[4096] = { 0 };
			int i = 0, j = s.length();
			strcpy_s(buf, s.c_str());
			while (buf[i] == ' ' && i < j)
				i++; //leading spaces, start-index
			while (buf[j - 1] == ' ' && j >= 0)
				j--; //trailing spaces, end-index
			t = s.substr(i, (i - j));
			return t;
		}


// remove leading/trailing spaces and quotations from data values
		string trim_quote(string s) {
			string t;
			s = trim_spaces(s);
			if ((s.substr(0, 1) == "\"") && (s.substr(s.length() - 1, 1) == "\"")) {
				t = s.substr(1, s.length() - 2);
			} else {
				t = s;
			}
			return t;
		}

// parse CSV text line into data values array
		int parseCSV(string line, string vals[50]) {
			int cnt = 0;
			int i = 0;
			int j = 0;
			int pos[100][2] = { 0 };
			int len = line.length();

			char s[4096] = { 0 };
			strcpy_s(s, line.c_str());
			
			bool tag = 0;

			while (s[i] != '\0' && i < 4096) {
				if (s[i] == '\"') {
					if (tag == 0)
						tag = 1;
					else
						tag = 0;
				}
				if (s[i] == ',' && tag == 0) {
					pos[cnt][0] = j; //start index
					pos[cnt][1] = i - j; //length
					cnt++;
					j = i + 1;
				}
				i++;
			}

			if (i > 0) {
				pos[cnt][0] = j; //start index
				pos[cnt][1] = i - j; //length
				cnt++;
			}

			for (int i = 0; i < cnt + 1; i++) {
				vals[i] = trim_quote(line.substr(pos[i][0], pos[i][1]));
			}
			return cnt;
		}
};
#endif   /*LINKLIST_H*/

