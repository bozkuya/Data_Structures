#include <array>
#include <unordered_map>
#include<iostream>
using namespace std;

const int MAX_N = 20;
// here matrix class starts. I use this to create and initialize my matrix

class Matrix {
public:
  // Default constructor that initializes the matrix as a 0x0 matrix
  Matrix() : n(0) {}

  // Constructor that takes size N and initializes the matrix as NxN identity matrix
  Matrix(int N) : n(N) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          elements[i][j] = 1;
        } else {
          elements[i][j] = 0;
        }
      }
    }
  }

  // Copy assignment operator
  Matrix& operator=(const Matrix& other) {
    n = other.n;
    elements = other.elements;
    return *this;
  }

  // Getter function to get an element for a given pair of (row, column)
  int get(int row, int col) const { return elements[row][col]; }

  // Setter function to set an element for a given pair of (row, column)
  void set(int row, int col, int value) { elements[row][col] = value; }

  // Comparison operator ==
  bool operator==(const Matrix& other) const {
    if (n != other.n) return false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (elements[i][j] != other.elements[i][j]) return false;
      }
    }
    return true;
  }

  // Comparison operator <
  bool operator<(const Matrix& other) const {
    if (n < other.n) return true;
    if (n > other.n) return false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (elements[i][j] < other.elements[i][j]) return true;
        if (elements[i][j] > other.elements[i][j]) return false;
      }
    }
    return false;
  }

  // Hash function
  size_t hash() const {
    size_t h = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        h = h * 31 + elements[i][j];
      }
    }
    return h;
  }

private:
  int n;
  array<array<int, MAX_N>, MAX_N> elements;
};
// first question starts here
class BST_Node {
public:
  Matrix key;
  long value;
  BST_Node* left;
  BST_Node* right;

  BST_Node(const Matrix& k, long v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// Comparison operator == for Matrix
bool operator==(const Matrix& A, const Matrix& B) {
  if (A.n != B.n) return false;
  for (int i = 0; i < A.n; i++) {
    for (int j = 0; j < A.n; j++) {
      if (A.get(i, j) != B.get(i, j)) return false;
    }
  }
  return true;
}

// Comparison operator < for Matrix
bool operator<(const Matrix& A, const Matrix& B) {
  if (A.n < B.n) return true;
  if (A.n > B.n) return false;
  for (int i = 0; i < A.n; i++) {
    for (int j = 0; j < A.n; j++) {
      if (A.get(i, j) < B.get(i, j)) return true;
      if (A.get(i, j) > B.get(i, j)) return false;
    }
  }
  return false;
}

// Check if the tree has a BST_Node with key == A
bool key_exists(BST_Node* root, const Matrix& A) {
  if (root == nullptr) return false;
  if (root->key == A) return true;
  if (root->key < A) return key_exists(root->right, A);
  return key_exists(root->left, A);
}

// Return the value field of the node whose key == A
long search(BST_Node* root, const Matrix& A) {
  if (root == nullptr) return 0;
  if (root->key == A) return root->value;
  if (root->key < A) return search(root->right, A);
  return search(root->left, A);
}

// Insert a Node with key=A and value=detA into the tree
void insert(BST_Node*& root, const Matrix& A, long detA) {
  if (root == nullptr) {
    root = new BST_Node(A, detA);
    return;
  }
  if (root->key == A) {
    root->value = detA;
  } else if (root->key < A) {
    insert(root->right, A, detA);
  } else {
    insert(root->left, A, detA);
  }
}

// Recursive matrix determinant calculation function with memoization using a binary search tree as the storage
int determinant(BST_Node*& root, const Matrix& M) {
  // Check if M exists in the tree
  if (key_exists(root, M)) return search(root, M);

  // Call itself recursively

