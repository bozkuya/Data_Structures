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
const int HT_SIZE = 65536;

class HT_Item {
public:
  Matrix key;
  long value;
};

class HashTable {
public:
  HashTable() {
    for (int i = 0; i < HT_SIZE; i++) {
      table[i] = nullptr;
    }
  }

  // Check if the table has an HT_Item with key == A
  bool key_exists(const Matrix& A) {
    int h = A.hash() % HT_SIZE;
    for (int i = h; i < HT_SIZE; i++) {
      if (table[i] == nullptr) return false;
      if (table[i]->key == A) return true;
    }
    return false;
  }

  // Return the value field of the item whose key == A
  long search(const Matrix& A) {
    int h = A.hash() % HT_SIZE;
    for (int i = h; i < HT_SIZE; i++) {
      if (table[i] == nullptr) return 0;
      if (table[i]->key == A) return table[i]->value;
    }
    return 0;
  }

  // Insert a HT_Item with key=A and value=detA 
  void insert(const Matrix& A, long detA) {
    int h = A.hash() % HT_SIZE;
    for (int i = h; i < HT_SIZE; i++) {
      if (table[i] == nullptr) {
        table[i] = new HT_Item{A, detA};
        break;
      }
    }
  }

private:
  HT_Item* table[HT_SIZE];
};

// Recursive matrix determinant calculation function with memoization using a hash table as the storage
int determinant(HashTable& storage, const Matrix& M) {
  // Check if M exists in the table
  if (storage.key_exists(M)) return storage.search(M);

  // Calculate result recursively
  // ...
  // Store (M, result) in the table
  storage.insert(M, result);
  return result;
}

