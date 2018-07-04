//
// Created by 杜映潇 on 2018/6/23.
//

#include "searchengine.h"
#include "include/cppjieba/Jieba.hpp"

#include <vector>
#include <iostream>
#include <fstream>

using std::vector;

const char *const DICT_PATH = "../dict/jieba.dict.utf8";
const char *const HMM_PATH = "../dict/hmm_model.utf8";
const char *const USER_DICT_PATH = "../dict/user.dict.utf8";
const char *const IDF_PATH = "../dict/idf.utf8";
const char *const STOP_WORD_PATH = "../dict/stop_words.utf8";

int SearchEngine::compareByIndegree(const void *A, const void *B) {
    return ((Page *) B)->inDegree - ((Page *) A)->inDegree;
}

int SearchEngine::compareByIndegreeAndFrequency(const void *A, const void *B) {
    if (((Page *) B)->inDegree == ((Page *) A)->inDegree) {
        return ((Page *) B)->frequency - ((Page *) A)->frequency;
    } else
        return ((Page *) B)->inDegree - ((Page *) A)->inDegree;
}

SearchEngine::SearchEngine() {
    // initial search engine
    // include: word dictionary, url dictionary, inverted list and graph

    std::cout << "initialize search engine" << std::endl;

    // first: word dictionary and url dictionary
    for (int i = 0; i < CONTENTNUM; i++) {
        if (i == MISSINGCONTENT)
            continue;
        std::cout << "processing content" + std::to_string(i) << std::endl;
        std::string filename = CONTENTFILENAME + std::to_string(i) + ".txt";
        std::ifstream infile(filename, std::ios::in);
        string url, word;
        std::getline(infile, url);
        urlDictionary.insert(url, i);
        while (!infile.eof()) {
            infile >> word;
            dictionary.insert(word, i);
        }
        infile.close();
    }
    std::cout << "building two dictionaries" << std::endl;
    dictionary.sort();
    urlDictionary.sort();
    std::cout << "dictionaries built success" << std::endl;

    // second: inverted list
    std::cout << "building inverted list" << std::endl;
    int start = 0;
    while (start <= dictionary.size()) {
        int end = dictionary.getLastSame(start);
        auto pairs = new pair<string, int>[end - start + 1];
        dictionary.getBetween(start, end, pairs);
        invertedList.insert(pairs, end - start + 1);
        delete[]pairs;
        start = end + 1;
    }
    std::cout << "building list success" << std::endl;

    // last: graph
    std::cout << "building graph" << std::endl;
    linkRelation = Graph(LINKRELATIONFILENAME, urlDictionary);
    std::cout << "building graph success" << std::endl;

    std::cout << "search engine is ready to roll" << std::endl;
}

List SearchEngine::normalBooleanSearch(string &searchTerm) {
    cppjieba::Jieba jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
    vector<string> words;
    jieba.CutForSearch(searchTerm, words);
    auto indexList = new int[words.size()];
    // get all indexes
    for (int i = 0; i < words.size(); i++)
        indexList[i] = invertedList.search(words[i]);
    int count = words.size(); // count is the number of find union we do
    List result;
    while (result.getSize() <= 3 && count >= 0) {
        result = invertedList.getList(indexList[0]);
        for (int i = 1; i < count; i++)
            result = invertedList.getList(indexList[i]).findIntersection(result);
        for (int i = count; i < words.size(); i++)
            result = invertedList.getList(indexList[i]).findUnion(result);
        count--;
    }
/*    auto *all = new int[result.getSize()];
    result.getAll(all);
    for (int i = 0; i < result.getSize(); i++)
        std::cout << all[i] << " ";
    std::cout << std::endl;
    delete[]all;*/
    return result;
}

void SearchEngine::booleanSearchWithIndegreeRank(string &inputTerm) {
    List result = normalBooleanSearch(inputTerm);
    auto all = new int[result.getSize()];
    result.getAll(all);
    auto pages = new Page[result.getSize()];
    for (int i = 0; i < result.getSize(); i++) {
        pages[i].docID = all[i];
        pages[i].inDegree = linkRelation.inDegree(all[i]);
    }
    delete[]all;
    qsort(pages, result.getSize(), sizeof(Page), compareByIndegree);
    std::cout << "find in " << result.getSize() << " pages" << std::endl;
    for (int i = 0; i < result.getSize(); i++) {
        std::ifstream infile(CONTENTFILENAME + std::to_string(pages[i].docID) + ".txt");
        string url;
        infile >> url;
        infile.close();
        std::cout << "No. " << i + 1 << " result " << url << " with indegree " << pages[i].inDegree
                  << std::endl;
    }
}

void SearchEngine::booleanSearchWithIndegreeRankAndFrequencyCount(string &inputTerm) {
    List result = normalBooleanSearch(inputTerm);
    auto all = new int[result.getSize()];
    auto freq = new int[result.getSize()];
    result.getAll(all, freq);
    auto pages = new Page[result.getSize()];
    for (int i = 0; i < result.getSize(); i++) {
        pages[i].docID = all[i];
        pages[i].inDegree = linkRelation.inDegree(all[i]);
        pages[i].frequency = freq[i];
    }
    delete[]all;
    qsort(pages, result.getSize(), sizeof(Page), compareByIndegreeAndFrequency);
    std::cout << "find in " << result.getSize() << " pages" << std::endl;
    int count = 0;
    for (int i = 0; i < result.getSize(); i++) {
        std::ifstream infile(NEWCONTENTFILENAME + std::to_string(pages[i].docID) + ".txt");
        string url, title, s;
        std::getline(infile, url);
        std::getline(infile, title);
        infile.close();
        std::cout << "No. " << i + 1 << " result " << title << " with indegree " << pages[i].inDegree
                  << std::endl;
        std::cout << "No. " << i + 1 << " result " << url << " with indegree " << pages[i].inDegree
                  << std::endl;
        count++;
        if (count == 5) {
            char c;
            std::cin >> c;
            if (c != 'c')
                break;
            count = 0;
        }
    }
}