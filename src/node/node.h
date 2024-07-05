#ifndef NODE_NODE_H
#define NODE_NODE_H

namespace bintree {

/// Repräsentiert einen Knoten in einem binären Suchbaum.
template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node* left = nullptr;
  Node* right = nullptr;

  /// Konstruiert einen neuen leeren Node.
  Node() = default;

  /// Konstruiert ein neues Node-Objekt mit dem gegebenen Schlüssel und Wert.
  Node(K key_, V value_)
      : key(key_), value(value_), left(new Node()), right(new Node()) {}

  /// Liefert true, wenn der Knoten leer ist.
  /// D.h. wenn die Kind-Pointer nullptr sind.
  bool is_empty() const {
    if (left == nullptr && right == nullptr) {
      return true;
    }
    return false;
  }

  /// Setzt den gegebenen Schlüssel und Wert in den Knoten ein.
  /// Ein vorhandener Schlüssel/Wert wird überschrieben.
  /// Wenn der Knoten leer ist, werden leere Kind-Knoten erzeugt.
  void set(K key_, V value_) {
    key = key_;
    value = value_;
    if(is_empty()){
      left = new Node();
      right = new Node();
    }
  }

  /// Fügt einen neuen Knoten in den Baum ein.
  void insert(K key_, V value_) {

    //überprüft, ob die Parent Node leer ist, wenn ja wird set aufgrufen
    if (this -> is_empty()) {
      set(key_, value_);
      return;
    }

    //überprüft ob der linke Kindknoten leer ist, wenn ja, dann wird eingefügt, wenn nein, dann wird en neuer Kindknoten erstellt
    if (key > key_) {
      if (left == nullptr) {
        left = new Node(key_, value_);
        return;
      }else {
        left -> insert(key_, value_);
      }
    }

    //überprüft ob der rechte Kindknoten leer ist, wenn ja, dann wird eingefügt, wenn nein, dann wird en neuer Kindknoten erstellt
    if (key < key_) {
      if (right == nullptr) {
        right = new Node(key_, value_);
        return;
      }else {
        right -> insert(key_, value_);
      }
    }
  }

  /// Liefert einen Pointer auf den Knoten mit dem gegebenen Schlüssel.
  /// Wenn der Schlüssel nicht gefunden wird, wird nullptr zurückgegeben.
  Node<K, V>* find(K key_) {
    if (this -> is_empty() && left == nullptr && right == nullptr) {
      return nullptr;
    }else {

      if (key == key_) {
        return this;
      }

      if (key > key_){
        if (left -> key == key_) {
        return left;
      }else{return left -> find(key_);}
      }

      if (key < key_){
        if (right -> key == key_) {
        return right;
      }else{return right -> find(key_);}
      }

    }
    return nullptr;
  }
};

}  // namespace bintree

#endif
