#include <iostream>
#include <string>
#include <cmath>

class Animal {
private:
    std::string name;
    double weight;
    std::string species;
    std::string type;

public:
    Animal(const std::string& n, double w, const std::string& t, const std::string& s)
        : name(n), weight(w), type(t), species(s) {}

    std::string getName() const { return name; }
    double getWeight() const { return weight; }
    std::string getSpecies() const { return species; }
    std::string getType() const { return type; }
};

class Node {
private:
    Animal* animalPtr;
    Node* left;
    Node* right;
    Node* parent;

public:
    Node(Animal* a) : animalPtr(a), left(nullptr), right(nullptr), parent(nullptr) {}

    Animal* getAnimalPtr() const { return animalPtr; }
    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }
    Node* getParent() const { return parent; }
    void setLeft(Node* n) { left = n; }
    void setRight(Node* n) { right = n; }
    void setParent(Node* n) { parent = n; }
};

class BST {
private:
    Node* root;
    double error = 0.01; // Tolerance for weight comparison

    Node* findInorderSuccessor(Node* nd);
    void traverseAndSumWeight(Node* node, double low, double hi, const std::string& species, double& totalWeight) const;
    void deleteTree(Node* node);

public:
    BST() : root(nullptr) {}
    ~BST();

    Node* search(double wt);
    Node* search(const std::string& nm);
    bool addNode(Animal* a);
    bool deleteNode(const std::string& name);
    double getTotalWeightInRange(double low, double hi) const;
    double getTotalWeightInRange(double low, double hi, const std::string& species) const;
};

// Implementations of BST methods

BST::~BST() {
    deleteTree(root);
}

void BST::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }
}

Node* BST::search(double wt) {
    Node* current = root;
    while (current != nullptr) {
        double nodeWeight = current->getAnimalPtr()->getWeight();
        if (std::abs(nodeWeight - wt) < error) {
            return current;
        } else if (nodeWeight < wt) {
            current = current->getRight();
        } else {
            current = current->getLeft();
        }
    }
    return nullptr;
}

Node* BST::search(const std::string& nm) {
    Node* current = root;
    while (current != nullptr) {
        std::string nodeName = current->getAnimalPtr()->getName();
        if (nodeName == nm) {
            return current;
        } else if (nodeName < nm) {
            current = current->getRight();
        } else {
            current = current->getLeft();
        }
    }
    return nullptr;
}

bool BST::addNode(Animal* a) {
    Node* newNode = new Node(a);
    if (root == nullptr) {
        root = newNode;
        return true;
    }

    Node* parent = nullptr;
    Node* current = root;
    while (current != nullptr) {
        parent = current;
        if (a->getWeight() < current->getAnimalPtr()->getWeight()) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }

    newNode->setParent(parent);
    if (a->getWeight() < parent->getAnimalPtr()->getWeight()) {
        parent->setLeft(newNode);
    } else {
        parent->setRight(newNode);
    }
    return true;
}

Node* BST::findInorderSuccessor(Node* nd) {
    Node* successor = nd->getRight();
    if (successor != nullptr) {
        while (successor->getLeft() != nullptr) {
            successor = successor->getLeft();
        }
        return successor;
    }

    Node* parent = nd->getParent();
    while (parent != nullptr && nd == parent->getRight()) {
        nd = parent;
        parent = parent->getParent();
    }
    return parent;
}

bool BST::deleteNode(const std::string& name) {
    Node* nodeToDelete = search(name);
    if (nodeToDelete == nullptr) {
        return false; // Node with given name not found
    }

    Node* parent = nodeToDelete->getParent();
    if (nodeToDelete->getLeft() == nullptr && nodeToDelete->getRight() == nullptr) {
        if (parent == nullptr) {
            root = nullptr;
        } else if (nodeToDelete == parent->getLeft()) {
            parent->setLeft(nullptr);
        } else {
            parent->setRight(nullptr);
        }
        delete nodeToDelete;
    } else if (nodeToDelete->getLeft() == nullptr || nodeToDelete->getRight() == nullptr) {
        Node* child = (nodeToDelete->getLeft() != nullptr) ? nodeToDelete->getLeft() : nodeToDelete->getRight();
        if (parent == nullptr) {
            root = child;
        } else if (nodeToDelete == parent->getLeft()) {
            parent->setLeft(child);
        } else {
            parent->setRight(child);
        }
        child->setParent(parent);
        delete nodeToDelete;
    } else {
        Node* successor = findInorderSuccessor(nodeToDelete);
        if (successor->getRight() != nullptr) {
            successor->getRight()->setParent(successor->getParent());
        }
        if (successor->getParent() == nodeToDelete) {
            successor->setRight(successor->getRight());
        } else {
            successor->getParent()->setLeft(successor->getRight());
            successor->setRight(nodeToDelete->getRight());
        }
        successor->setLeft(nodeToDelete->getLeft());
        if (parent == nullptr) {
            root = successor;
        } else if (nodeToDelete == parent->getLeft()) {
            parent->setLeft(successor);
        } else {
            parent->setRight(successor);
        }
        successor->setParent(parent);
        delete nodeToDelete;
    }
    return true;
}

double BST::getTotalWeightInRange(double low, double hi) const {
    double totalWeight = 0.0;
    traverseAndSumWeight(root, low, hi, "", totalWeight);
    return totalWeight;
}

double BST::getTotalWeightInRange(double low, double hi, const std::string& species) const {
    double totalWeight = 0.0;
    traverseAndSumWeight(root, low, hi, species, totalWeight);
    return totalWeight;
}

void BST::traverseAndSumWeight(Node* node, double low, double hi, const std::string& species, double& totalWeight) const {
    if (node == nullptr) return;

    traverseAndSumWeight(node->getLeft(), low, hi, species, totalWeight);
    
    double weight = node->getAnimalPtr()->getWeight();
    std::string nodeSpecies = node->getAnimalPtr()->getSpecies();
    if (weight >= low && weight <= hi && (species.empty() || species == nodeSpecies)) {
        totalWeight += weight;
    }

    traverseAndSumWeight(node->getRight(), low, hi, species, totalWeight);
}
