//
// Created by 杜映潇 on 2018/6/23.
//
#ifndef SEARCHENGINE_SEARCHENGINE_H
#define SEARCHENGINE_SEARCHENGINE_H

#include "invertedlist.h"

const string CONTENTFILENAME = "../content_final/content";
const string NEWCONTENTFILENAME = "../content/content";
const string LINKRELATIONFILENAME = "../linkrelation.txt";

class SearchEngine {
private:
    Dictionary dictionary;
    Dictionary urlDictionary;
    Graph linkRelation;
    InvertedList invertedList;

    struct Page {
        int docID;
        int inDegree;
        int frequency;
    };

    static int compareByIndegree(const void *A, const void *B);

    static int compareByIndegreeAndFrequency(const void *A, const void *B);

    List normalBooleanSearch(string &searchTerm);

public:
    SearchEngine();

    void booleanSearchWithIndegreeRank(string &inputTerm);

    void booleanSearchWithIndegreeRankAndFrequencyCount(string &inputTerm);
};


#endif //SEARCHENGINE_SEARCHENGINE_H
