///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 The Johns Hopkins University Applied Physics Laboratory LLC (JHU/APL).  All Rights Reserved.
//
// This material may be only be used, modified, or reproduced by or for the U.S. Government pursuant to the license
// rights granted under the clauses at DFARS 252.227-7013/7014 or FAR 52.227-14. For any other permission, please
// contact the Office of Technology Transfer at JHU/APL: Telephone: 443-778-2792, Internet: www.jhuapl.edu/ott
//
// NO WARRANTY, NO LIABILITY. THIS MATERIAL IS PROVIDED "AS IS." JHU/APL MAKES NO REPRESENTATION OR WARRANTY WITH
// RESPECT TO THE PERFORMANCE OF THE MATERIALS, INCLUDING THEIR SAFETY, EFFECTIVENESS, OR COMMERCIAL VIABILITY, AND
// DISCLAIMS ALL WARRANTIES IN THE MATERIAL, WHETHER EXPRESS OR IMPLIED, INCLUDING (BUT NOT LIMITED TO) ANY AND ALL
// IMPLIED WARRANTIES OF PERFORMANCE, MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF
// INTELLECTUAL PROPERTY OR OTHER THIRD PARTY RIGHTS. ANY USER OF THE MATERIAL ASSUMES THE ENTIRE RISK AND LIABILITY
// FOR USING THE MATERIAL. IN NO EVENT SHALL JHU/APL BE LIABLE TO ANY USER OF THE MATERIAL FOR ANY ACTUAL, INDIRECT,
// CONSEQUENTIAL, SPECIAL OR OTHER DAMAGES ARISING FROM THE USE OF, OR INABILITY TO USE, THE MATERIAL, INCLUDING,
// BUT NOT LIMITED TO, ANY DAMAGES FOR LOST PROFITS.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "linked_list.h"

// #include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

// Default constructor
LinkedList::LinkedList()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

LinkedList::LinkedList(size_t numberNodes)
{
  head = NULL;
  tail = NULL;
  size = 0;
  for(size_t i = 0; i < numberNodes; i++) {
    LinkedList::addNode("", "");
  }
}

void LinkedList::push(string key, string value)
{
  // cout << "Pushing node: " << key << "\n";
  LinkedList::addNode(key, value);
}

size_t LinkedList::addNode(string key, string value)
{
  Node *tmp = new Node;
  tmp->key.assign(key);
  tmp->value.assign(value);
  tmp->next = NULL;
  // cout << "Adding " << key << " Old size: " << size << "\n";
  // cout << "Line: " << __LINE__ << "\n";
  if(head == NULL) {
    head = tmp;
    tail = tmp;
  } else {
    tail->next = tmp;
    tail = tail->next;
  }
  size++;
  return size;
}

int LinkedList::writeNode(string key, string value, size_t index)
{
  if (index > size) {
    // invalid index
    return -1;
  }

  Node * tmp = head;
  size_t i;
  for(i = 0; i < index; i++) {
    tmp = tmp->next;
  }
  tmp->key.assign(key);
  tmp->value.assign(value);
  // strcpy(tmp->key, key);
  // strcpy(tmp->value, value);
  return (int) i;
}

size_t LinkedList::length()
{
  return size;
}

Node * LinkedList::peek()
{
  return tail;
}

Node * LinkedList::peek(size_t index)
{
  if (index > size) {
    // invalid index
    return NULL;
  }

  Node * tmp = head;
  size_t i;
  for(i = 0; i < index; i++) {
    tmp = tmp->next;
  }
  return tmp;
}

/**
* More efficient method for writing multiple, sequential nodes at once
*/

int LinkedList::writeNodes(string keys[], string values[], size_t startIndex, size_t length)
{
  if (startIndex+length > size) {
    // invalid index
    return -1;
  }

  Node * tmp = head;
  size_t i;
  for(i = 0; i < startIndex; i++) {
    tmp = tmp->next;
  }
  for (i = 0; i < length; i++) {
    tmp->key.assign(keys[i]);
    tmp->value.assign(values[i]);
    tmp = tmp->next;
  }

  // strcpy(tmp->key, key);
  // strcpy(tmp->value, value);
  return (int) i+startIndex;
}

int LinkedList::find(string key)
{
  Node * tmp = head;
  int i;
  i = 0;
  while (tmp != NULL) {
    if (key.compare(tmp->key) == 0) {
      return i;
    }
    i++;
    tmp = tmp->next;
  }
  return -1;
}

int LinkedList::remove(size_t index)
{
  if (index > size) {
    // invalid index
    return -1;
  }

  Node * tmp = head;
  Node * oldtmp = NULL;
  size_t i;
  for(i = 0; i < index; i++) {
    oldtmp = tmp;
    tmp = tmp->next;
  }
  // change pointers
  if (oldtmp != NULL) {
    oldtmp->next = tmp->next;
  } else {
    // HEAD
    head = tmp->next;
  }
  // delete old node
  delete tmp;
  size--;
  return (int) size;
}

/**
Inserts just after the first node
*/

size_t LinkedList::insert(string key, string value)
{
  Node * secondNode = head->next;
  Node * newNode = new Node;

  // inserting the node
  newNode->next = secondNode;
  head->next = newNode;
  size++;

  // assigning its values
  newNode->key.assign(key);
  newNode->value.assign(value);

  return size;
}
