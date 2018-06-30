//
// Created by 杜映潇 on 2018/6/20.
//

#include "invertedlist.h"

#include <iostream>
#include <fstream>

int MAX(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

List::~List() {
    Node *h = head;
    while (h != nullptr) {
        Node *temp = h;
        h = h->next;
        delete temp;
    }
}

List::List(const List &that) {
    size = 0;
    head = tail = nullptr;
    for (Node *h = that.head; h != nullptr; h = h->next)
        insertBack(h->docID, h->frequceny);
}

List &List::operator=(const List &that) {
    // delete present
    Node *h = head;
    while (h != nullptr) {
        Node *temp = h;
        h = h->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
    for (h = that.head; h != nullptr; h = h->next)
        insertBack(h->docID, h->frequceny);
    return *this;
}

void List::insertBack(int ID, int freq) {
    auto *node = new Node(ID, freq);
    if (head == nullptr) {
        // the first element to insert
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    size++;
}

void List::getAll(int *all) {
    int count = 0;
    for (Node *h = head; h != nullptr; h = h->next, count++)
        all[count] = h->docID;
}

void List::getAll(int *all, int *freq) {
    int count = 0;
    for (Node *h = head; h != nullptr; h = h->next, count++) {
        all[count] = h->docID;
        freq[count] = h->frequceny;
    }
}

List List::findIntersection(List &that) {
    Node *h1 = head, *h2 = that.head;
    List newList;
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->docID == h2->docID) {
            newList.insertBack(h1->docID, MAX(h1->frequceny, h2->frequceny));
            h1 = h1->next;
            h2 = h2->next;
        } else if (h1->docID < h2->docID)
            h1 = h1->next;
        else
            h2 = h2->next;
    }
    return newList;
}

List List::findUnion(List &that) {
    Node *h1 = head, *h2 = that.head;
    List newList;
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->docID == h2->docID) {
            newList.insertBack(h1->docID, MAX(h1->frequceny, h2->frequceny));
            h1 = h1->next;
            h2 = h2->next;
        } else if (h1->docID < h2->docID) {
            newList.insertBack(h1->docID, h1->frequceny);
            h1 = h1->next;
        } else {
            newList.insertBack(h2->docID, h2->frequceny);
            h2 = h2->next;
        }
    }
    while (h1 != nullptr) {
        newList.insertBack(h1->docID, h1->frequceny);
        h1 = h1->next;
    }
    while (h2 != nullptr) {
        newList.insertBack(h2->docID, h2->frequceny);
        h2 = h2->next;
    }
    return newList;
}

void Dictionary::resize() {
    auto newpairs = new pair<string, int>[maxLength * 2];
    maxLength *= 2;
    for (int i = 0; i < currentSize; i++)
        newpairs[i] = pairs[i];
    delete[]pairs;
    pairs = newpairs;
    newpairs = nullptr;
}

int Dictionary::compareyByTerm(const void *first, const void *second) {
    string firstStr = ((pair<string, int> *) first)->first;
    string secondStr = ((pair<string, int> *) second)->first;
    if (firstStr < secondStr)
        return -1;
    else if (firstStr == secondStr) {
        return ((pair<string, int> *) first)->second - ((pair<string, int> *) second)->second;
    } else
        return 1;
}

/*int Dictionary::compareByDocID(const void *first, const void *second) {
    return ((pair<string, int> *) first)->second - ((pair<string, int> *) second)->second;
}*/

int Dictionary::search(int start, int end, string &key) {
    if (start > end)
        return -1;
    int mid = (end - start) / 2 + start;
    if (pairs[mid].first == key)
        return mid;
    else if (pairs[mid].first < key)
        return search(mid + 1, end, key);
    else
        return search(start, mid - 1, key);
}

Dictionary::Dictionary() {
    currentSize = 0;
    maxLength = INITIALLENGTH;
    pairs = new pair<string, int>[maxLength];
}

void Dictionary::insert(string &term, int docID) {
    if (currentSize >= maxLength)
        resize();
    pair<string, int> newpair = std::make_pair(term, docID);
    pairs[currentSize] = newpair;
    currentSize++;
}

int Dictionary::getLastSame(int start) {
    int i = start + 1;
    for (; i < currentSize; i++)
        if (pairs[i].first != pairs[start].first)
            break;
    return i - 1;
}

void Dictionary::getBetween(int start, int end, pair<string, int> *outpairs) {
    for (int i = start; i <= end; i++)
        outpairs[i - start] = pairs[i];
}

/*void Dictionary::sortByTerm() {
    qsort(pairs, currentSize, sizeof(pair<string, int>), compareyByTerm);
}

void Dictionary::sortByDocID() {
    qsort(pairs, currentSize, sizeof(pair<string, int>), compareByDocID);
}*/

void Dictionary::sort() {
    qsort(pairs, currentSize, sizeof(pair<string, int>), compareyByTerm);
}

void Dictionary::print() {
    for (int i = 0; i < currentSize; i++)
        std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
}

int Dictionary::get(string &key) {
    int index = search(0, currentSize - 1, key);
    if (index == -1)
        return -1;
    else
        return pairs[index].second;
}

void InvertedList::resize() {
    auto newall = new TermAndFrequency[maxLength * 2];
    maxLength *= 2;
    for (int i = 0; i < currentSize; i++)
        newall[i] = all[i];
    delete[]all;
    all = newall;
}

int InvertedList::search(int start, int end, string &term) {
    if (start > end)
        return -1;
    int mid = (end - start) / 2 + start;
    if (all[mid].term == term)
        return mid;
    else if (all[mid].term < term)
        // go right
        return search(mid + 1, end, term);
    else
        return search(start, mid - 1, term);
}

void InvertedList::insert(pair<string, int> *pairs, int size) {
    if (currentSize + size > maxLength)
        resize();
    all[currentSize].term = pairs[0].first;
    all[currentSize].frequency = size;
    int prev = pairs[0].second, count = 1;
    for (int i = 1; i < size; i++) {
        if (pairs[i].second != prev) {
            all[currentSize].postingLists.insertBack(prev, count);
            prev = pairs[i].second;
            count = 1;
        } else
            count++;
    }
    all[currentSize].postingLists.insertBack(prev, count);
    currentSize++;
}

void InvertedList::print() {
    for (int i = 0; i < currentSize; i++) {
        std::cout << all[i].term << " " << all[i].frequency << " ";
        auto list = new int[all[i].frequency];
        all[i].postingLists.getAll(list);
        for (int j = 0; j < all[i].frequency; j++)
            std::cout << list[j] << "->";
        std::cout << std::endl;
    }
}

int InvertedList::search(string &term) {
    return search(0, currentSize - 1, term);
}

void InvertedList::getAll(int index, int *outall) {
    all[index].postingLists.getAll(outall);
}

int InvertedList::getDocSize(int index) {
    int count = 1;
    int *out = new int[all[index].frequency];
    all[index].postingLists.getAll(out);
    int prevDocID = out[0];
    for (int i = 1; i < all[index].frequency; i++) {
        if (out[i] != prevDocID)
            count++;
        prevDocID = out[i];
    }
    delete[]out;
    return count;
}

void InvertedList::test(int indexA, int indexB) {
    List newList = all[indexA].postingLists.findUnion(all[indexB].postingLists);
    int size = newList.getSize();
    auto out = new int[size];
    newList.getAll(out);
    for (int i = 0; i < size; i++)
        std::cout << out[i] << " ";
    std::cout << std::endl;
}

List InvertedList::getList(int index) {
    if (index == -1)
        return List();
    else
        return all[index].postingLists;
}

Graph::Graph(string filename, Dictionary &dictionary) {
    std::ifstream infile(filename);
    string link, postLink;
    infile >> link;
    infile >> postLink;
    while (true) {
        int docID = dictionary.get(link);
        infile >> link;
        infile >> postLink;
        while (!isdigit(postLink[0])) {
            int docIDNew = dictionary.get(link);
            addEdge(docID, docIDNew);
            link = postLink;
            infile >> postLink;
            if (infile.peek() == EOF)
                break;
        }
        if (infile.peek() == EOF)
            break;
    }
    infile.close();
}

Graph::Graph(const Graph &that) {
    for (int i = 0; i < CONTENTNUM; i++)
        graph[i] = that.graph[i];
}

void Graph::addEdge(int v, int w) {
    graph[v].insertBack(w);
}

int Graph::inDegree(int v) {
    int count = 0;
    for (int i = 0; i < CONTENTNUM; i++) {
        if (i == v)
            continue;
        int size = graph[i].getSize();
        auto out = new int[size];
        graph[i].getAll(out);
        for (int j = 0; j < size; j++)
            if (out[j] == v)
                count++;
        delete[]out;
    }
    return count;
}