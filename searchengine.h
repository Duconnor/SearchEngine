//
// Created by 杜映潇 on 2018/6/23.
//
#ifndef SEARCHENGINE_SEARCHENGINE_H
#define SEARCHENGINE_SEARCHENGINE_H

#include "invertedlist.h"

const string CONTENTFILENAME = "/Users/duyx/ClionProjects/SearchEngine/content_final/content";
const string LINKRELATIONFILENAME = "/Users/duyx/ClionProjects/SearchEngine/linkrelation.txt";

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

    List normalBooleanSearch();

public:
    SearchEngine();

    void booleanSearchWithIndegreeRank();

    void booleanSearchWithIndegreeRankAndFrequencyCount();
};


#endif //SEARCHENGINE_SEARCHENGINE_H
