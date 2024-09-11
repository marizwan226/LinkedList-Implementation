#include <iostream>

class SparseMatrixNode {
public:
    int row;
    int col;
    int value;
    SparseMatrixNode* next;

    SparseMatrixNode(int row, int col, int value) : row(row), col(col), value(value), next(nullptr) {}
};

class SparseMatrix {
public:
    SparseMatrixNode* head;

    SparseMatrix() : head(nullptr) {}

    void insert(int row, int col, int value) {
        SparseMatrixNode* newNode = new SparseMatrixNode(row, col, value);

        // Find the appropriate position in the linked list
        SparseMatrixNode* current = head;
        SparseMatrixNode* previous = nullptr;
        while (current != nullptr && current->row <= row) {
            if (current->row == row && current->col <= col) {
                break;
            }
            previous = current;
            current = current->next;
        }

        // Insert the new node
        if (previous == nullptr) {
            head = newNode;
        } else {
            previous->next = newNode;
        }
        newNode->next = current;
    }

    void display() {
        SparseMatrixNode* current = head;
        while (current != nullptr) {
            std::cout << "(" << current->row << ", " << current->col << ", " << current->value << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SparseMatrix matrix;

    matrix.insert(1, 2, 3);
    matrix.insert(0, 0, 5);
    matrix.insert(3, 1, 7);

    matrix.display();

    return 0;
}