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
	
		Node (publisher key) : key (key), parent (NULL), left (NULL), right (NULL), color (1) {}
		
		int get_color () {return color;} void set_color (int color) {this->color = color;}
};

class BST_tree {
	private: Node* root;
	public:	
        publisher* best_seller[3];
		stack<string> tree_deep_stack;

        BST_tree () : root (NULL), best_seller {NULL, NULL, NULL} {} ~BST_tree () {
			delete root->left; delete root->right; delete root;
		}

        Node* get_root () {return this->root;}

		Node* BST_insert (Node* root, Node* ptr) {
			if (root == NULL) {
				if (best_seller[0] == NULL || ptr->key.na_sales > best_seller[0]->na_sales) {best_seller[0] = &ptr->key;}
				if (best_seller[1] == NULL || ptr->key.eu_sales > best_seller[1]->eu_sales) {best_seller[1] = &ptr->key;}
				if (best_seller[2] == NULL || ptr->key.others_sales > best_seller[2]->others_sales) {best_seller[2] = &ptr->key;}
				return ptr;
			}

			if (compareAlphabetically(ptr->key, root->key) == SMALLER) {
				root->left = BST_insert(root->left, ptr); root->left->parent = root;
			} else if (compareAlphabetically(ptr->key, root->key) == BIGGER) {
				root->right = BST_insert(root->right, ptr); root->right->parent = root;
			} else if (compareAlphabetically(ptr->key, root->key) == EQUAL) {
				root->key.na_sales += ptr->key.na_sales; root->key.eu_sales += ptr->key.eu_sales; root->key.others_sales += ptr->key.others_sales;
				if (best_seller[0] == NULL || root->key.na_sales > best_seller[0]->na_sales) {best_seller[0] = &root->key;}
				if (best_seller[1] == NULL || root->key.eu_sales > best_seller[1]->eu_sales) {best_seller[1] = &root->key;}
				if (best_seller[2] == NULL || root->key.others_sales > best_seller[2]->others_sales) {best_seller[2] = &root->key;}
			}

			return root;
		}

		void insertValue (vector<string> n) {
		    
			// Fill this function.
		
		}

        void find_best_seller () {

		    // Fill this function.

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
    BST_tree temp_BSTtree; 
	
	
	
	vector<publisher> publishers; ifstream file (file_name); if (file.is_open()) {
		string line; getline(file, line); while (getline(file, line)) {
			stringstream ss (line); string name, platform, year, publisherName; float na_sales, eu_sales, others_sales;
			ss >> name; ss.ignore(1, ','); ss >> platform; ss.ignore(1, ','); ss >> year; ss.ignore(1, ','); ss >> publisherName; ss.ignore(1, ','); ss >> na_sales; ss.ignore(1, ','); ss >> eu_sales; ss.ignore(1, ','); ss >> others_sales;
			
			
			
			
			

		} file.close();
	} else {cerr << "Error: Unable to open file " << file_name << endl;
	}

    return temp_BSTtree;
}

int main (int argc, char* argv[]) {
	string fname = argv[1];	BST_tree BSTtree = generate_BST_tree_from_csv(fname);

    // Fill this function.

	return EXIT_SUCCESS;
}

enum Alphabetic_Order {BIGGER, EQUAL, SMALLER};
Alphabetic_Order compareAlphabetically (publisher& a, publisher& b) {
	int size = min(a.name.size(), b.name.size()); for (int i = 0; i < size; i++) {
		char ai = (char)tolower(a.name[i]); char bi = (char)tolower(b.name[i]);
		if (ai == bi) {continue;} 
		else {return (ai < bi) ? SMALLER : BIGGER;}
	}

	return (a.name.size() == b.name.size()) ? EQUAL : ((a.name.size() < b.name.size()) ? SMALLER : BIGGER);
}