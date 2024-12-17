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
		char ai = (char)tolower(a.name[i]); char bi = (char)tolower(b.name[i]);
		if (ai < bi) {return SMALLER;} else if (ai > bi) {return BIGGER;}
	} return (a.name.size() == b.name.size()) ? EQUAL : ((a.name.size() < b.name.size()) ? SMALLER : BIGGER);
}

class RB_tree {
	private: Node* root;
	public:	
        publisher* best_seller[3];	
		stack<string> tree_deep_stack;

        RB_tree () : root (NULL), best_seller {NULL, NULL, NULL} {} ~RB_tree () {
			delete root;
		}

        Node* get_root () {return this->root;}

		void insertValue (vector<string> n) {
		    publisher temp; temp.name = n[3]; temp.na_sales = stof(n[4]); temp.eu_sales = stof(n[5]); temp.others_sales = stof(n[6]);
			Node* ptr = new Node(temp); root = RB_insert(root, ptr);
		}

		Node* RB_insert (Node* root, Node* ptr) {
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

			RB_insert_fixup(ptr);

			return this->root;
		}

        void RB_insert_fixup (Node* ptr) {
			Node* parent = NULL; Node* grandParent = NULL;
			while (ptr != root && ptr->get_color() == 1 && ptr->parent->get_color() == 1) {
				parent = ptr->parent; grandParent = parent->parent;
				if (parent == grandParent->left) {
					Node* uncle = grandParent->right;
					if (uncle != NULL && uncle->get_color() == 1) {
						grandParent->set_color(1); parent->set_color(0); uncle->set_color(0); ptr = grandParent;
					} else {
						if (ptr == parent->right) {RB_left_rotate(parent); ptr = parent; parent = ptr->parent;}
						RB_right_rotate(grandParent); int temp = parent->get_color(); parent->set_color(grandParent->get_color()); grandParent->set_color(temp); ptr = parent;
					}
				} else {
					Node* uncle = grandParent->left;
					if (uncle != NULL && uncle->get_color() == 1) {
						grandParent->set_color(1); parent->set_color(0); uncle->set_color(0); ptr = grandParent;
					} else {
						if (ptr == parent->left) {RB_right_rotate(parent); ptr = parent; parent = ptr->parent;}
						RB_left_rotate(grandParent); int temp = parent->get_color(); parent->set_color(grandParent->get_color()); grandParent->set_color(temp); ptr = parent;
					}
				}
			} root->set_color(0);
        }

		void RB_left_rotate (Node* ptr) {
			Node* child = ptr->right; ptr->right = child->left;
			if (ptr->right != nullptr) {ptr->right->parent = ptr;}
			child->parent = ptr->parent;
			if (ptr->parent == nullptr) {root = child;}
			else if (ptr == ptr->parent->left) {ptr->parent->left = child;}
			else {ptr->parent->right = child;}
			child->left = ptr; ptr->parent = child;
		}

		void RB_right_rotate (Node* ptr) {
			Node* child = ptr->left; ptr->left = child->right;
			if (ptr->left != nullptr) {ptr->left->parent = ptr;}
			child->parent = ptr->parent;
			if (ptr->parent == nullptr) {root = child;}
			else if (ptr == ptr->parent->left) {ptr->parent->left = child;}
			else {ptr->parent->right = child;}
			child->right = ptr; ptr->parent = child;
		}

        void preorder () {
			if (root == nullptr) return; 
			
			int height = 0;
			stack<pair<Node*, int>> stk; stk.push({root, 0}); while (!stk.empty()) {
				auto [current, depth] = stk.top(); stk.pop();
				
				if (current == NULL) {continue;}
	
				for (int i = 0; i < depth; i++) {cout << "-";} cout << "(" << ((current->color == 1) ? "RED" : "BLACK") << ") " << current->key.name << endl; 
				if (depth > height) {height = depth;}

				if (current->right) {stk.push({current->right, depth + 1});}
				if (current->left) {stk.push({current->left, depth + 1});}
			}

			cout << "Height of the tree: " << height << endl;
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

RB_tree generate_RBT_tree_from_csv (string file_name) {
	RB_tree temp_RBtree; ifstream file (file_name); if (file.is_open()) {
		string line; getline(file, line); int lastPrintedDecade = 1981; while (getline(file, line)) {
			vector<string> tokens; string token = ""; for (int i = 0; i < line.size(); i++) {
				if (line[i] == ',') {tokens.push_back(token); token = "";} else {token += line[i];}
			}

			int year = stoi(tokens[2]); 
			if ((year == 1991 || year == 2001 || year == 2011 || year == 2020) && year != lastPrintedDecade) {print_best_sellers(year-1, temp_RBtree.best_seller); lastPrintedDecade = year;}
		
			tokens.push_back(token); temp_RBtree.insertValue(tokens);
		} file.close();
	} else {cerr << "Error: Unable to open file " << file_name << endl;}

    return temp_RBtree;
}

void inorder (Node* root, ofstream& out) {
	if (root == nullptr) return; 
	inorder(root->left, out); out << root->key.name << endl; inorder(root->right, out);
}

bool is_balanced (Node* root) {
	ofstream output_file ("RBT.txt"); inorder(root, output_file); output_file.close();
	ifstream input_file ("RBT.txt"); string previousLine = ""; string line; while (getline(input_file, line)) {
		int size = min(previousLine.size(), line.size()); for (int i = 0; i < size; i++) {
			char ai = (char)tolower(previousLine[i]); char bi = (char)tolower(line[i]);
			if (ai < bi) {return true;} else if (ai > bi) {return false;}
		} if (previousLine.size() >= line.size()) {return false;}
	} input_file.close(); return true;
}

int main (int argc, char* argv[]) {
	string fname = argv[1];	RB_tree RBtree = generate_RBT_tree_from_csv(fname);
	RBtree.preorder();

	cout << ((is_balanced(RBtree.get_root())) ? "The tree is balanced." : "The tree is not balanced.") << endl;

	return EXIT_SUCCESS;
}