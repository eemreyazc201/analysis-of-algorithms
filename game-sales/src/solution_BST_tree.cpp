#include <iostream> 
#include <stdlib.h>
#include <iomanip>
#include <string.h>
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
			
		    // Fill this function.
			
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

    // Fill this function.

    return temp_BSTtree;
}

int main (int argc, char* argv[]) {
	string fname = argv[1];	BST_tree BSTtree = generate_BST_tree_from_csv(fname);

    // Fill this function.

	return EXIT_SUCCESS;
}