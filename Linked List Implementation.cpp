class Node {
public:
    int row;
    int col;
    int value;
    Node* next;
};

class SparseMatrix {
private:
    Node* head;
public:
    SparseMatrix() {
        head = nullptr;
    }

    void addElement(int row, int col, int value) {
        // Implement logic to add element to LinkedList
    }

    void generateCompactMatrix() {
        // Implement logic to generate compact matrix from LinkedList
    }
};