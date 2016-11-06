//
//  class_i.cpp
//  COMP130 Homework 7 Word Counting
//
//  Created by ax on 11/4/16.
//  Copyright © 2016 COMP130. All rights reserved.
//

#include "class_d.h"
#include <iostream>
#include <string>
using namespace std;

Message::Message() {
    string m_msg_txt = "Hello there";
}

void Message::say_msg(string p_msg_txt) {
    cout << p_msg_txt;
}