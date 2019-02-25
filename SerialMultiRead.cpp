/*
    SerialMultiRead.h - Library for reading serial input and converting to a single, multi-digit integer
    Created by Zachary W. Groce, February 22, 2019
    Released into the public domain.
*/

#include "Arduino.h"
#include "SerialMultiRead.h"

SerialMultiRead::SerialMultiRead(){
}

signed long int SerialMultiRead::multiRead(){
    /*
        Calculation Process:
            User inputs a number in the serial window (Example: 123)
            Values added to an array (Example: [1, 2, 3])
            When serial reads "\n" (new line character), convert the array to an integer
            The first digit while be multiplied by 10^exponent, where exponent is one less 
                than the number of digits (Example: 1 * 10^2 = 100)
            Add the result of the above calculation to the variable "number"
            Loop through the above process for each digit, decreasing the value of the exponent
                by one each time, adding each result to "number"
            Return the number
    */            

    int characters[50];  //Creates an array to hold the incoming digits
    int digit, num_digits, exponent;  //Creates variables for use in the function
    int counter = 0, pos = 0;
    signed long int number = 0;

    /*
        digit = Current serial input being evaluated
        num_digits = The number of digits the user entered
        exponent = Tracks the value of the exponent for use in the calculation
        counter = Incremental input used to track the number of digits entered
        pos = tracks the position in the array
        number = Final ouput of a multi-digit integer
    */
  
    while(Serial.available() > 0){
        digit = Serial.read() - '0';

        if(digit == -38){  //Serial input is the "\n" new line character, convert array
            num_digits = counter;
            exponent = counter - 1;
            for(exponent; exponent > -1; exponent--){
                number += characters[pos] * (signed long int)round(pow(10,exponent));
                pos++;
            }  
        }else if(digit >= 0 && digit <= 9){  //Serial input is a digit 0 - 9
            characters[counter] = digit;
            counter++;
        }else{
            Serial.println("Only enter digits 0 - 9");  //Unexpected Serial entry
        }
        delay(10);
    }

    return number;
}