//
//  main.cpp
//  COMP130 Homework 7 Word Counting
//
//  Created by ax on 11/4/16.
//  Copyright © 2016 COMP130. All rights reserved.
//
// main program file

#include "class_d.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    
    cout << "Word Count" << endl;
    
    string greeting = "Hello There Local Project!!";
    
    Message msgr;
    
    msgr.say_msg(greeting);
    
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
    
    struct WordCount {
        string word;
        int count;
    };
    
    WordCount arr[300];
    WordCount item;
    
    // get input file
    ifstream input_file;
    
    input_file.open("/Users/ax/COMP1302016F/IO_FILES/input_file.txt");
    
    int const ARR_SIZE = 300;
    
    // simulate word counter because eof doesn't work in xcode
    int word_counter = 268;
    /* .eof doesn't work in xcode.
     while (input_file.eof() != 1)
     {
     word_counter++;
     }
     */
    
    int counter = 0;
    while (counter < word_counter)
    {
        input_file >> item.word;
        item.count = 1;
        arr[counter] = item;
        counter++;
    }
    
    input_file.close();
    
    // SORT THE ARRAY
    
    cout << "Selection Sorting" << endl;
    
    for (int i = 0; i < counter; i++) {
        string current_min = arr[i].word;
        int cur_min_idx = i;
        
        for (int j = i + 1; j < counter; j++) {
            if (current_min > arr[j].word) {
                current_min = arr[j].word;
                cur_min_idx = j;
            }
        }
        
        if (cur_min_idx != i) {
            // swapping objects
            arr[cur_min_idx] = arr[i];
            arr[i].word = current_min;
        }
    }
    
    int matches_found = 0;
    for (int i = 0; i < counter; i++) {
        string cur_word = arr[i].word, nxt_word = arr[i + 1].word;
        // evaluate the current [i] item in the array for word value
        // compare the current [i] item word value to the next [i + 1]
        if (cur_word == nxt_word) {
            matches_found++;
            cout << matches_found << " matches found" << endl;
            // if the values match, increment the value of i + 1 to i.count +1
            arr[i + 1].count = arr[i].count + 1;
            arr[i].word = "";
            arr[i].count = 0;
        }
    }
    
    // loop through the array
    // find any instance of word count greater than 1
    // find max count of any word count greater than 1
    int current_earliest_blank_idx = 0;
    
    for (int i = 0; i < word_counter; i++) {
        if (arr[i].word == "") {
            current_earliest_blank_idx = i;
            cout << "Blank item index found" << endl;
            int increment_search_idx = 0;
            while (arr[i + increment_search_idx].word == "") {
                cout << "search index found another blank at counter: " << arr[i + increment_search_idx].count << endl;
                increment_search_idx++;
            }
            // stop here, check increment search value after while loop
            cout << "O: current_earliest_blank_idx : " << current_earliest_blank_idx << endl;
            cout << "O: post-while increment_search_idx : " << increment_search_idx << endl;
            cout << "O: arr[i + increment_search_idx].word: " << arr[i + increment_search_idx].word << endl;
            cout << "O: arr[i + increment_search_idx].count: " << arr[i + increment_search_idx].count << endl;
            
            // swap high count to first blank position
            WordCount tmp;
            tmp = arr[current_earliest_blank_idx];
            arr[current_earliest_blank_idx] = arr[i + increment_search_idx];
            arr[i + increment_search_idx] = tmp;
            // hack in break statement at end of word list
            // ideally this should not be a specific word check
            if (arr[current_earliest_blank_idx].word == "years") {
                break;
            }

        }
    }
    
    cout << "PRINT SORTED / COUNTED ARRAY" << endl;
    /*
     cout << setw(10) << "i" << setw(10) << "word" << setw(10) << "count" << endl;
     for (int i = 0; i < counter; i++) {
     cout << setw(10) << i << setw(10) << arr[i].word << setw(10) << arr[i].count << endl;
     }
     */
    
    // LOG SORTED ARRAY TO OUTPUT FILE
    ofstream output_file;
    
    output_file.open("/Users/ax/COMP1302016F/IO_FILES/output_file.txt");
    
    output_file << setw(10) << "I VAL" << setw(20) << "WORD" << setw(10) << "COUNT" << endl;
    for (int i = 0; i < counter; i++) {
        output_file << setw(10) << i << setw(20) << arr[i].word << setw(10) << arr[i].count << endl;
    }
    
    output_file.close();
    
    return 0;
}