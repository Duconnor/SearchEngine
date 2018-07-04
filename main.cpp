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
#include <iostream>

void demo();

int main() {
    SearchEngine searchEngine;
    while (true) {
        // searchEngine.booleanSearchWithIndegreeRank();
        std::cout << "\033[31;4m" << "input search term here: " << "\e[0m";
        string searchTerm;
        std::cin >> searchTerm;
        if (searchTerm == "demo")
            demo();
        else if (searchTerm == "break")
            break;
        else
            searchEngine.booleanSearchWithIndegreeRankAndFrequencyCount(searchTerm);
    }
    return 0;
}


void demo() {
    SearchEngine searchEngine;
    string stringArray[] = {"假期实习", "篮球比赛", "足球", "中国特色社会主义", "社会主义核心价值观", "中国梦", "计算机科学与技术", "南大新闻网", "音乐会", "青共校学习",
                            "实习岗位", "社会实践", "习近平", "张异宾", "南京大学"};
    const int PHASEACCU = 10, PHASEINDEGREE = 12, PHASENAME = 14, PHASETIME = 15;
    std::cout << "demo start..." << std::endl;
    string control;
    std::cin >> control;
    int count = 0;
    while (control == "n" && count < PHASETIME) {
        if (count < PHASEACCU)
            std::cout << "Showing accuracy" << std::endl;
        else if (count < PHASEINDEGREE)
            std::cout << "Showing indegree rank" << std::endl;
        else if (count < PHASENAME)
            std::cout << "Showing name search" << std::endl;
        else
            std::cout << "Showing search latency" << std::endl;
        std::cout << "Now search" << stringArray[count];
        searchEngine.booleanSearchWithIndegreeRankAndFrequencyCount(stringArray[count]);
        count++;
        std::cout << "next?:";
        std::cin >> control;
    }
    std::cout << "demo end" << std::endl;
}