/*
    SerialMultiRead.h - Library for reading serial input and converting to a single, multi-digit integer
    Created by Zachary W. Groce, February 22, 2019
    Released into the public domain.
*/

#ifndef SerialMultiRead_h
#define SerialMultiRead_h

#include "Arduino.h"

class SerialMultiRead{
    public:
        SerialMultiRead();
        signed long int multiRead();
};

#endif