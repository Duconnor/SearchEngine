#define DICTEST 1

#if DICTEST == 0

#include "invertedlist.h"

#include <iostream>
#include <fstream>
#include <string>

int main() {
    Dictionary dictionary;
    for (int i = 0; i < CONTENTNUM; i++) {
        if (i == MISSINGCONTENT)
            continue;
        std::cout << "processing content" + std::to_string(i) << std::endl;
        std::string filename = "/Users/duyx/CLionProjects/SearchEngine/content_final/content"
                               + std::to_string(i) + ".txt";
        std::ifstream infile(filename, std::ios::in);
        string url, word;
        std::getline(infile, url);
        while (!infile.eof()) {
            infile >> word;
            dictionary.insert(word, i);
        }
        infile.close();
    }
    std::cout << "building dictionary" << std::endl;
    dictionary.sort();
    std::cout << "dictionary built success" << std::endl;
    // dictionary.print();
    std::cout << "building inverted list" << std::endl;
    InvertedList invertedList;
    int start = 0;
    while (start <= dictionary.size()) {
        int end = dictionary.getLastSame(start);
        auto pairs = new pair<string, int>[end - start + 1];
        dictionary.getBetween(start, end, pairs);
        invertedList.insert(pairs, end - start + 1);
        // invertedList.print();
        delete[]pairs;
        start = end + 1;
    }
    std::cout << "building list success" << std::endl;
    // invertedList.print();
    while (true) {
        std::cout << "Please input search term A: ";
        string searchTerm, searchTermB;
        std::cin >> searchTerm;
        std::cout << "Please input search term B: ";
        std::cin >> searchTermB;
        if (searchTerm == "quit")
            break;
        int index = invertedList.search(searchTerm);
        int indexB = invertedList.search(searchTermB);
        if (index == -1 || indexB == -1) {
            std::cout << "No match" << std::endl;
            continue;
        }
        int size = invertedList.getSize(index);
        int sizeB = invertedList.getSize(indexB);
        std::cout << "find " << searchTerm << " in: " << index << std::endl;
        std::cout << "find " << size << " matches" << std::endl;
        std::cout << "find " << searchTermB << " in: " << indexB << std::endl;
        std::cout << "find " << sizeB << " matches" << std::endl;
        auto out = new int[size];
        auto outB = new int[sizeB];
        invertedList.getAll(index, out);
        invertedList.getAll(indexB, outB);
        std::cout << searchTerm << " appears in: ";
        for (int i = 0; i < size; i++)
            std::cout << out[i] << " ";
        std::cout << std::endl;
        delete[]out;
        invertedList.test(index, indexB);
    }
    return 0;
}

#endif

#include "searchengine.h"

int main() {
    SearchEngine searchEngine;
    while (true) {
        // searchEngine.booleanSearchWithIndegreeRank();
        searchEngine.booleanSearchWithIndegreeRankAndFrequencyCount();
    }
    return 0;
}
