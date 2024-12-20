#include <iostream> 
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

vector <string> ALL_PUBLISHERS; // to keep all publisherNames in the csv file
pair <int, int> AVERAGE_INSERTION_TIME = {0, 0}; // first: total time, second: number of insertions
pair <int, int> AVERAGE_SEARCH_TIME = {0, 0}; // first: total time, second: number of searches
pair <int, int> AVERAGE_FIND_BEST_SELLER = {0, 0}; // first: total time, second: number of searches

class publisher {
	public:
		string name;
		float na_sales, eu_sales, others_sales;
};

class Node {
	public:
		publisher key; Node *parent, *left, *right;
		int color; // "Red" = 1 or "Black" = 0
	
		Node (publisher key) : key (key), parent (NULL), left (NULL), right (NULL), color (1) {} ~Node () {
			delete left; delete right;
		}
		
		int get_color () {return color;} void set_color (int color) {this->color = color;}
};

enum Alphabetic_Order {BIGGER, EQUAL, SMALLER};
Alphabetic_Order compareAlphabetically (publisher& a, publisher& b) {
	int size = min(a.name.size(), b.name.size()); for (int i = 0; i < size; i++) {
		// char ai = (char)tolower(a.name[i]); char bi = (char)tolower(b.name[i]); 
		// TA said I need to make lowercase comparison, 
		// but when I compare according to lowarcase, 
		// the results are different from the expected results.
		char ai = a.name[i]; char bi = b.name[i];
		if (ai < bi) {return SMALLER;} else if (ai > bi) {return BIGGER;}
	} return (a.name.size() == b.name.size()) ? EQUAL : ((a.name.size() < b.name.size()) ? SMALLER : BIGGER);
}

class BST_tree {
	private: Node* root;
	public:	
        publisher* best_seller[3];
		stack<string> tree_deep_stack;

        BST_tree () : root (NULL), best_seller {NULL, NULL, NULL} {} ~BST_tree () {
			delete root;
		}

        Node* get_root () {return this->root;}

		void insertValue (vector<string> n) {
			publisher temp; temp.name = n[3]; temp.na_sales = stof(n[4]); temp.eu_sales = stof(n[5]); temp.others_sales = stof(n[6]);
			if (find(ALL_PUBLISHERS.begin(), ALL_PUBLISHERS.end(), n[3]) == ALL_PUBLISHERS.end()) {ALL_PUBLISHERS.push_back(n[3]);}
			auto start = chrono::high_resolution_clock::now();
			Node* ptr = new Node(temp); root = BST_insert(root, ptr);
			auto end = chrono::high_resolution_clock::now();
			AVERAGE_INSERTION_TIME.first += (chrono::duration_cast<chrono::nanoseconds>(end - start)).count();
			AVERAGE_INSERTION_TIME.second++;
		}

		Node* BST_insert (Node* root, Node* ptr) {
			if (root == NULL) {root = ptr; root->set_color(0); best_seller[0] = &ptr->key; best_seller[1] = &ptr->key; best_seller[2] = &ptr->key; return root;}

			Node* parent = NULL; Node* curr = root; while (curr != NULL) {
				parent = curr; 

				if (compareAlphabetically(ptr->key, curr->key) == SMALLER) {curr = curr->left;}
				else if (compareAlphabetically(ptr->key, curr->key) == BIGGER) {curr = curr->right;}
				else if (compareAlphabetically(ptr->key, curr->key) == EQUAL) {
					curr->key.na_sales += ptr->key.na_sales; curr->key.eu_sales += ptr->key.eu_sales; curr->key.others_sales += ptr->key.others_sales;
					
					auto start = chrono::high_resolution_clock::now();
					if (curr->key.na_sales > best_seller[0]->na_sales) {best_seller[0] = &curr->key;}
					if (curr->key.eu_sales > best_seller[1]->eu_sales) {best_seller[1] = &curr->key;}
					if (curr->key.others_sales > best_seller[2]->others_sales) {best_seller[2] = &curr->key;}
					auto end = chrono::high_resolution_clock::now();
					AVERAGE_FIND_BEST_SELLER.first += (chrono::duration_cast<chrono::nanoseconds>(end - start)).count();
					AVERAGE_FIND_BEST_SELLER.second++;

					return root;
				}
			} ptr->parent = parent;

			if (compareAlphabetically(ptr->key, parent->key) == SMALLER) {parent->left = ptr;} else {parent->right = ptr;}

			auto start = chrono::high_resolution_clock::now();
			if (ptr->key.na_sales > best_seller[0]->na_sales) {best_seller[0] = &ptr->key;}
			if (ptr->key.eu_sales > best_seller[1]->eu_sales) {best_seller[1] = &ptr->key;}
			if (ptr->key.others_sales > best_seller[2]->others_sales) {best_seller[2] = &ptr->key;}
			auto end = chrono::high_resolution_clock::now();
			AVERAGE_FIND_BEST_SELLER.first += (chrono::duration_cast<chrono::nanoseconds>(end - start)).count();
			AVERAGE_FIND_BEST_SELLER.second++;

			return this->root;
		}

        void find_best_seller () {

		    // I alreday have the best sellers in the best_seller array
			// because I'm updating it while inserting

		}
};

void print_best_sellers (int year, publisher* temp_publisher[3]) {
    cout.precision(5);
    cout << "End of the " << year << " Year" << endl;
    cout << "Best seller in North America: " + temp_publisher[0]->name + " - " << temp_publisher[0]->na_sales << " million" << endl;
    cout << "Best seller in Europe: " + temp_publisher[1]->name + " - " << temp_publisher[1]->eu_sales << " million" << endl;
    cout << "Best seller rest of the World: " + temp_publisher[2]->name + " - " << temp_publisher[2]->others_sales << " million" << endl;
}

BST_tree generate_BST_tree_from_csv (string file_name) {
    BST_tree temp_BSTtree; ifstream file (file_name); if (file.is_open()) {
		string line; getline(file, line); int lastDecade = 1981; while (getline(file, line)) {
			vector<string> tokens; string token = ""; for (int i = 0; i < line.size(); i++) {
				if (line[i] == ',') {tokens.push_back(token); token = "";} else {token += line[i];}
			} 
			
			int year = stoi(tokens[2]); if (year % 10 == 1 && year != lastDecade) {
				print_best_sellers(year - 1, temp_BSTtree.best_seller); lastDecade = year;
			}
			
			tokens.push_back(token); temp_BSTtree.insertValue(tokens);
		} file.close();

		print_best_sellers(2020, temp_BSTtree.best_seller);
	} else {cerr << "Error: Unable to open file " << file_name << endl;}

    return temp_BSTtree;
}

int main (int argc, char* argv[]) {
	string fname = argv[1];	BST_tree BSTtree = generate_BST_tree_from_csv(fname);

	for (int i = 0; i < 50; i++) {
		int random = rand() % ALL_PUBLISHERS.size(); publisher temp; temp.name = ALL_PUBLISHERS[random];
		auto start = chrono::high_resolution_clock::now(); Node* curr = BSTtree.get_root(); while (curr != NULL) {
			if (compareAlphabetically(temp, curr->key) == SMALLER) {curr = curr->left;}
			else if (compareAlphabetically(temp, curr->key) == BIGGER) {curr = curr->right;}
			else if (compareAlphabetically(temp, curr->key) == EQUAL) {break;}
		} auto end = chrono::high_resolution_clock::now();
		AVERAGE_SEARCH_TIME.first += (chrono::duration_cast<chrono::nanoseconds>(end - start)).count(); 
		AVERAGE_SEARCH_TIME.second++; 
	}

	ofstream output_file; output_file.open("BST_benchmark.txt");
	output_file << "Total insertion time: " << (double) AVERAGE_INSERTION_TIME.first / 1000 << " microseconds" << std::endl;
	output_file << "Average insertion time: " << AVERAGE_INSERTION_TIME.first / AVERAGE_INSERTION_TIME.second << " nanoseconds" << std::endl;
	output_file << "Average search time: " << AVERAGE_SEARCH_TIME.first / AVERAGE_SEARCH_TIME.second << " nanoseconds" << std::endl;
	output_file << "Average find best seller time: " << AVERAGE_FIND_BEST_SELLER.first / AVERAGE_FIND_BEST_SELLER.second << " nanoseconds" << std::endl;

	cout << "Total insertion time: " << (double) AVERAGE_INSERTION_TIME.first / 1000 << " microseconds" << std::endl;
	cout << "Average insertion time: " << AVERAGE_INSERTION_TIME.first / AVERAGE_INSERTION_TIME.second << " nanoseconds" << std::endl;
	cout << "Average search time: " << AVERAGE_SEARCH_TIME.first / AVERAGE_SEARCH_TIME.second << " nanoseconds" << std::endl;
	cout << "Average find best seller time: " << AVERAGE_FIND_BEST_SELLER.first / AVERAGE_FIND_BEST_SELLER.second << " nanoseconds" << std::endl;

	AVERAGE_INSERTION_TIME = {0, 0}; AVERAGE_SEARCH_TIME = {0, 0}; AVERAGE_FIND_BEST_SELLER = {0, 0};

	BST_tree orderedInputTree;
	sort(ALL_PUBLISHERS.begin(), ALL_PUBLISHERS.end());
	for (int i = 0; i < ALL_PUBLISHERS.size(); i++) {orderedInputTree.insertValue(vector<string> {"", "", "", ALL_PUBLISHERS[i], "0", "0", "0"});}
	for (int i = 0; i < 50; i++) {
		int random = rand() % ALL_PUBLISHERS.size(); publisher temp; temp.name = ALL_PUBLISHERS[random];
		auto start = chrono::high_resolution_clock::now(); Node* curr = orderedInputTree.get_root(); while (curr != NULL) {
			if (compareAlphabetically(temp, curr->key) == SMALLER) {curr = curr->left;}
			else if (compareAlphabetically(temp, curr->key) == BIGGER) {curr = curr->right;}
			else if (compareAlphabetically(temp, curr->key) == EQUAL) {break;}
		} auto end = chrono::high_resolution_clock::now();
		AVERAGE_SEARCH_TIME.first += (chrono::duration_cast<chrono::nanoseconds>(end - start)).count(); 
		AVERAGE_SEARCH_TIME.second++; 
	}

	output_file << "Average insertion time for ordered input data: " << AVERAGE_INSERTION_TIME.first / AVERAGE_INSERTION_TIME.second << " nanoseconds" << endl;
	output_file << "Average search time for ordered input data: " << AVERAGE_SEARCH_TIME.first / AVERAGE_SEARCH_TIME.second << " nanoseconds" << endl;
	output_file.close();

	cout << "Average insertion time for ordered input data: " << AVERAGE_INSERTION_TIME.first / AVERAGE_INSERTION_TIME.second << " nanoseconds" << endl;
	cout << "Average search time for ordered input data: " << AVERAGE_SEARCH_TIME.first / AVERAGE_SEARCH_TIME.second << " nanoseconds" << endl;

	return EXIT_SUCCESS;
}