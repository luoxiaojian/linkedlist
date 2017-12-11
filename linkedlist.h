#ifndef CPP_INCLUDE_LINKEDLIST_H_
#define CPP_INCLUDE_LINKEDLIST_H_

#include <stdlib.h>

class LinkedList;

class ENode {
  friend class LinkedList;
  friend class LinkedListIterator;

 private:
  ENode() : next(nullptr) {}
  ENode(const T &data) : data(data), next(nullptr) {}
  ENode *next;
  Edge data;
};

class LinkedListIterator {
  friend class LinkedList;

 public:
  LinkedListIterator(ENode *p) : p(p) {}
  LinkedListIterator(const LinkedListIterator &other) : p(other.p) {}
  LinkedListIterator &operator=(LinkedListIterator other) {
    std::swap(p, other.p);
    return;
  }

  void operator++() { p = p->next; }
  void operator++(int) { p = p->next; }
  bool operator==(const LinkedListIterator &other) { return p == other.p; }
  bool operator!=(const LinkedListIterator &other) { return p != other.p; }
  const Edge &operator*() const { return p->data; }
  LinkedListIterator operator+(int i) {
    LinkedListIterator iter = *this;
    while (i-- > 0 && iter.p) {
      ++iter;
    }
    return iter;
  }

 private:
  ENode *p;
};

#endif
