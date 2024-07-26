//File: SortList.h (A)


#ifndef SORTLIST_H
#define SORTLIST_H

class Node;
class LinkList;

// Sorted List Class
// Sorted List Entry Node
// Sorted List Class
// Sorted List Entry Node

class SortNode {
	public:
		int id;
		string sortKey;
		Node* rec_ptr;

		SortNode* prev;
		SortNode* next;

		SortNode() {
			id = 0;
			prev = nullptr;
			next = nullptr;
		}
};

class SortList {
	public:
		SortNode* head = NULL;
		SortNode* tail = NULL;
		SortNode* cursor = NULL;
		int count = 0;

//add sorted node in list
		SortNode* add(string k, Node* n) {
			SortNode* newnode = new SortNode();
			if (head == NULL) {
				head = newnode;
				tail = newnode;
				cursor = newnode;
			} else {
				tail->next = newnode;
				newnode->prev = tail;
				newnode->next = NULL;
				tail = newnode;
			}
			count++;
			newnode->id = count;
			newnode->sortKey = k;
			newnode->rec_ptr = n;

			return newnode;
		}

		void swap(SortNode* a, SortNode* b) {
			SortNode* tmp = new SortNode();

//tmp = a
			tmp->rec_ptr = a->rec_ptr;
			tmp->id = a->id;
			tmp->sortKey = a->sortKey;

//a = b;
			a->rec_ptr = b->rec_ptr;
			a->id = b->id;
			a->sortKey = b->sortKey;

			//b = tmp;
			b->rec_ptr = tmp->rec_ptr;
			b->id = tmp->id;
			b->sortKey = tmp->sortKey;

			return;
		}

		void updateSL() {
			MergeSort(&head, head->sortKey);
		}

		/* sorts the linked list by changing next pointers (not data) */
		void MergeSort(SortNode** headRef, string sortfield) {

			SortNode* head = *headRef;
			SortNode* a;
			SortNode* b;

			/* Base case -- length 0 or 1 */
			if ((head == NULL) || (head->next == NULL)) {
				return;
			}

			/* Split head into 'a' and 'b' sublists */
			split(head, &a, &b);

			/* Recursively sort the sublists */
			MergeSort(&a, sortfield);
			MergeSort(&b, sortfield);

			/* answer = merge the two sorted lists together */
			*headRef = SortedMerge(a, b);
		}

		SortNode* SortedMerge(SortNode* a, SortNode* b) {
			SortNode* result = NULL;

			/* Base cases */
			if (a == NULL)
				return (b);
			else if (b == NULL)
				return (a);

			// sorting condition
			/* Pick either a or b, and recur */
			// if (a->data <= b->data)
			if (strcmp(a->sortKey.c_str(), b->sortKey.c_str()) < 0) {
				result = a;
				result->next = SortedMerge(a->next, b);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next);
			}
			return (result);
		}

		void split(SortNode* source, SortNode** frontRef, SortNode** backRef) {
			SortNode* fast;
			SortNode* slow;
			slow = source;
			fast = source->next;

			/* Advance 'fast' two nodes, and advance 'slow' one node */
			while (fast != NULL) {
				fast = fast->next;
				if (fast != NULL) {
					slow = slow->next;
					fast = fast->next;
				}
			}

			/* 'slow' is before the midpoint in the list, so split it in two
			at that point. */
			*frontRef = source;
			*backRef = slow->next;
			slow->next = NULL;
		}

		//Clear all list nodes
		void clear() {
			this->count = 0;
			SortNode* cursor = this->tail;
			SortNode* tmp;
			while (cursor != nullptr) {
				tmp = cursor;
				cursor = cursor->prev;
				delete tmp;
			}
			this->head = NULL;
		}
		
		SortNode* find_middle_node(SortNode* start, SortNode* last) {
			if (start == NULL) {
				return NULL;
			}

			SortNode* slow = start;
			SortNode* fast = start->next;

			while (fast != last) {
				fast = fast->next;
				if (fast != last) {
					slow = slow->next;
					fast = fast->next;
				}
			}
			return slow;
		}

		SortNode* binarySearch(SortNode* head, int value) {
			SortNode* mid;
			SortNode* start = head;
			SortNode* last = NULL;

			do {
				mid = find_middle_node(start, last);
				if (mid == NULL) {
					return NULL;
				}

				if (mid->id == value) {
					return mid;			//success
				}
				else if (mid->id < value) {
					start = mid->next;
				}
				else {
					last = mid;
				}
			} while (last == NULL || last != start);
			return NULL;
		}

		SortNode* searchSL(int a) {
			SortNode* element = NULL;
			if (a <= 0) {
				cout << "\n Wrong Entry" << endl;
			}
			else {
				element = binarySearch(head, a);
				//displayEntry(element);
				return element;
			}
			return nullptr;
		}

		int searchSL_all(char* a, SortList* ptr) {
			//SortList all_rec = SortList();
			string target_str = string(a);
			if (a == nullptr) {
				cout << "\n Wrong Entry" << endl;
			}
			else {
				this->cursor = head;
				//				ptr->add(cursor->sortKey,cursor->rec_ptr);
				//				ptr->add(cursor->next->sortKey,cursor->next->rec_ptr);
				do {
					size_t found = cursor->sortKey.find(target_str);
					if (found != string::npos) {
						ptr->add(cursor->sortKey, cursor->rec_ptr);
					}
					this->cursor = this->cursor->next;
				} while (this->cursor != NULL);

				return ptr->count;
			}
			return 0;
		}
	
};

#endif /*SORTLIST_H*/
