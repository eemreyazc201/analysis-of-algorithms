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
			Node* ptr = new Node(temp); root = BST_insert(root, ptr);
		}

		Node* BST_insert (Node* root, Node* ptr) {
			if (root == NULL) {root = ptr; root->set_color(0); best_seller[0] = &ptr->key; best_seller[1] = &ptr->key; best_seller[2] = &ptr->key; return root;}

			Node* parent = NULL; Node* curr = root; while (curr != NULL) {
				parent = curr; 

				if (compareAlphabetically(ptr->key, curr->key) == SMALLER) {curr = curr->left;}
				else if (compareAlphabetically(ptr->key, curr->key) == BIGGER) {curr = curr->right;}
				else if (compareAlphabetically(ptr->key, curr->key) == EQUAL) {
					curr->key.na_sales += ptr->key.na_sales; curr->key.eu_sales += ptr->key.eu_sales; curr->key.others_sales += ptr->key.others_sales;
					
					if (curr->key.na_sales > best_seller[0]->na_sales) {best_seller[0] = &curr->key;}
					if (curr->key.eu_sales > best_seller[1]->eu_sales) {best_seller[1] = &curr->key;}
					if (curr->key.others_sales > best_seller[2]->others_sales) {best_seller[2] = &curr->key;}

					return root;
				}
			} ptr->parent = parent;

			if (compareAlphabetically(ptr->key, parent->key) == SMALLER) {parent->left = ptr;} else {parent->right = ptr;}

			if (ptr->key.na_sales > best_seller[0]->na_sales) {best_seller[0] = &ptr->key;}
			if (ptr->key.eu_sales > best_seller[1]->eu_sales) {best_seller[1] = &ptr->key;}
			if (ptr->key.others_sales > best_seller[2]->others_sales) {best_seller[2] = &ptr->key;}

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
	return EXIT_SUCCESS;
}