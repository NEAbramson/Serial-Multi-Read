#include <SerialMultiRead.h>

/************************************************
 * Basic Multi-Digit Serial Input Conversion
 * Created by Zachary W. Groce, February 22, 2019
 * Released into the public domain.
 ************************************************/

 //Note:  The int data type can hold values between -32,768 and 32,767, if you enter a value outside the range,
 //       the multiRead() function will not return the expected value

SerialMultiRead multi;  //Create an instance of the SerialMultiRead class to utilize the functions in the library

signed long int number;  //Create an integer to store the converted user input

void setup() {
  Serial.begin(9600);  //Begin the Serial Monitor
}

void loop() {
  Serial.println("Please enter a number"); Serial.println();  //Prompt the user for input
  while(Serial.available() == 0);  //Halts the program until it receives serial input
  number = multi.multiRead();  //Utilize the instance created above (multi) to call the multiRead function inside the library
  Serial.println(number); Serial.println();  //Output the converted number
  delay(500);
}
