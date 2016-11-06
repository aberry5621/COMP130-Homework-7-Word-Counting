//
//  class_d.h
//  COMP130 Homework 7 Word Counting
//
//  Created by ax on 11/4/16.
//  Copyright © 2016 COMP130. All rights reserved.
//

#ifndef class_d_h
#define class_d_h
#include <string>
using namespace std;

class Message {
    
public:
    
    Message();
    
    void say_msg(string p_msg_txt);
    
private:
    
    string m_msg_txt;
    
};


#endif // !class_d_h