//
// Created by 杜映潇 on 2018/6/20.
//

#ifndef SEARCHENGINE_STL
#define SEARCHENGINE_STL

#include <string>

using std::string;
using std::pair;

#endif

#ifndef SEARCHENGINE_INVERTEDLIST_H
#define SEARCHENGINE_INVERTEDLIST_H

const int CONTENTNUM = 7800;
const int MISSINGCONTENT = 7663;

class List {
    struct Node {
        int docID;
        int frequceny;
        Node *next;

        explicit Node(int ID, int freq) : docID(ID), frequceny(freq), next(nullptr) {}
    };

private:
    Node *head;
    Node *tail;
    int size;
public:
    List() : size(0) { head = tail = nullptr; };

    ~List();

    List(const List &that);

    List &operator=(const List &that);

    void insertBack(int ID, int freq = -1);

    inline int getSize() { return size; };

    void getAll(int *all); // get all elements in the list

    void getAll(int *all, int *freq); // get all elements as well as their frequency

    List findIntersection(List &that);

    List findUnion(List &that);
};

const int INITIALLENGTH = 10000;

class Dictionary {
private:
    pair<string, int> *pairs; // word & docID
    int currentSize;
    int maxLength;

    void resize();

    static int compareyByTerm(const void *first, const void *second);

    // static int compareByDocID(const void *first, const void *second);

    int search(int start, int end, string &key);

public:
    Dictionary();

    ~Dictionary() { delete[]pairs; };

    void insert(string &term, int docID);

    void sort();

    inline int size() { return currentSize; };

    int getLastSame(int start); // starting from "start", find the index of the last same element

    void getBetween(int start, int end, pair<string, int> *outpairs); // no range check will be made

    void print(); // for test purpose

    int get(string &key);
};

class InvertedList {
    struct TermAndFrequency {
        string term;
        int frequency;
        List postingLists;

        TermAndFrequency() : term(""), frequency(-1) {}

        TermAndFrequency(string &ter, int freq) : term(ter), frequency(freq) {}

        TermAndFrequency(const TermAndFrequency &that) {
            term = that.term;
            frequency = that.frequency;
            postingLists = that.postingLists;
        }

        TermAndFrequency &operator=(const TermAndFrequency &that) {
            term = that.term;
            frequency = that.frequency;
            postingLists = that.postingLists;
            return *this;
        }
    };

private:
    TermAndFrequency *all;
    int currentSize;
    int maxLength;

    void resize();

    int search(int start, int end, string &term);

public:
    InvertedList() : currentSize(0), maxLength(INITIALLENGTH) { all = new TermAndFrequency[maxLength]; };

    void insert(pair<string, int> *pairs, int size); // insert pairs that have the same term

    void print(); // for test purpose

    int search(string &term); // return all docIDs matched the given term

    void getAll(int index, int *outall);

    inline int getSize(int index) { return all[index].postingLists.getSize(); };

    int getDocSize(int index); // this term appears in how many docs?

    void test(int indexA, int indexB);

    List getList(int index);

};

// a graph data type used in search engine pafe rank
// using adjacent list
class Graph {
private:
    List graph[CONTENTNUM];

public:
    Graph() = default;

    Graph(string filename, Dictionary &dictionary); // create the graph from file

    Graph(const Graph &that);

    void addEdge(int v, int w); // add an edge from v to w

    int inDegree(int v); // count in degree of vertex v
};

#endif //SEARCHENGINE_INVERTEDLIST_H
