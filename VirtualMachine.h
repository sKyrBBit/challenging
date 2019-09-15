//
// Created by mirro on 2019/09/13.
//

#ifndef UNTITLED7_VIRTUALMACHINE_H
#define UNTITLED7_VIRTUALMACHINE_H

#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include "Object_.h"
#include "Frame.h"

using namespace std;

class VirtualMachine {
private:
    /* method area */
    vector<uint8_t> input;
    int position;
    int* instructions;
    Object_** constant_pool;
    int counter; // program counter
    Object_** registers;
    int* functions;
    /* stack */
    stack<Frame*> runtime_stack;
    /* heap */
public:
    VirtualMachine() {
        this->position = 0;
        this->counter = 0;
    }
    int load(string file_name);
    void execute(int entry_point);
private:
    vector<uint8_t> read(int length);
    unsigned int read_int();
    unsigned int type();
    unsigned int operand1();
    unsigned int operand2();
    unsigned int operand3();
    unsigned int type(int instruction);
    unsigned int operand1(int instruction);
    unsigned int operand2(int instruction);
    unsigned int operand3(int instruction);
};


#endif //UNTITLED7_VIRTUALMACHINE_H
