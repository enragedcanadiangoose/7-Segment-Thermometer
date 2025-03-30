#include <Arduino.h>

class SevenSegment{
  private:
    int segmentPin[8]; //stores which pin is associated with which segment
    int digitPin[4]; //stores which pin is associated with which digit
    int digitValue[4] = {0}; //stores what value is stored in a given digit
    bool decimal[4] = {0}; //stores wether or not a digit has a decimal on it
    bool state[4] = {0}; //stores if a digit is turned on or not

  public:
    SevenSegment(int a, int b, int c, int d, int e, int f, int g, int decimal, int d1, int d2, int d3, int d4){ //constructor for the display, inputs each segment's pin number into an array, or each digits pin number
      segmentPin[0] = a;
      segmentPin[1] = b;
      segmentPin[2] = c;
      segmentPin[3] = d;
      segmentPin[4] = e;
      segmentPin[5] = f;
      segmentPin[6] = g;
      segmentPin[7] = decimal;

      digitPin[0] = d1;
      digitPin[1] = d2;
      digitPin[2] = d3;
      digitPin[3] = d4;

    }
    begin(){ //initializes the display by setting all of it's segment pins and digit pins as outputs
      for(int i = 0; i< 8; i++){
        pinMode(segmentPin[i], OUTPUT);
      }
      for(int i = 0; i< 4; i++){
        pinMode(digitPin[i], OUTPUT);
      }
    }

    allSegments(bool state){ //turns on all the segments of the display at once **BE CAREFUL TO NOT BURN OUT YOUR DISPLAY**
      for(int i = 0; i<8; i++){
        digitalWrite(segmentPin[i], state);
      }
      for(int i = 0; i<4; i++){
        digitalWrite(digitPin[i], state);
      }
    }

    setDigit(int digit, int number, bool decimal, bool state){ //sets and individual digit to be a value
      digitValue[digit] = number; //sets the digit value
      this->decimal[digit] = decimal; //sets wether or not the digit has a decimal
      this->state[digit] = state; //sets the digit on or off
    }

    drawDisplay(){ //the draw display method draws the display one digit at a time and relys on object persistance of the human eye to make it appear as though all digits are illuminated simultaneously
      for(int i = 0; i < 4; i++){ //cycles through the 4 digits
        if(state[i]){ //if the current digit is enabled
          digitalWrite(digitPin[i], 1); //turns on the current digit
          switch(digitValue[i]){ //writes whichever value is assigned to the digit to the digital pins for said digit
            case 0:
              digitalWrite(segmentPin[0], 1); //a
              digitalWrite(segmentPin[1], 1); //b
              digitalWrite(segmentPin[2], 1); //c
              digitalWrite(segmentPin[3], 1); //d
              digitalWrite(segmentPin[4], 1); //e
              digitalWrite(segmentPin[5], 1); //f
              digitalWrite(segmentPin[7], decimal[i]); //if the decimal is enabled enable the decimal
              break;
            case 1:
              digitalWrite(segmentPin[1], 1);
              digitalWrite(segmentPin[2], 1);
              digitalWrite(segmentPin[7], decimal[i]);
              break;
            case 2:
              digitalWrite(segmentPin[0], 1); //a
              digitalWrite(segmentPin[1], 1); //b
              digitalWrite(segmentPin[3], 1); //d
              digitalWrite(segmentPin[4], 1); //e
              digitalWrite(segmentPin[6], 1); //g
              digitalWrite(segmentPin[7], decimal[i]);
              break;
            case 3:
              digitalWrite(segmentPin[0], 1); //a
              digitalWrite(segmentPin[1], 1); //b
              digitalWrite(segmentPin[2], 1); //c
              digitalWrite(segmentPin[3], 1); //d
              digitalWrite(segmentPin[6], 1); //g
              digitalWrite(segmentPin[7], decimal[i]);
              break;
            case 4:
              digitalWrite(segmentPin[1], 1); //b
              digitalWrite(segmentPin[2], 1); //c
              digitalWrite(segmentPin[5], 1); //f
              digitalWrite(segmentPin[6], 1); //g
              digitalWrite(segmentPin[7], decimal[i]);
              break;
            case 5:
              digitalWrite(segmentPin[0], 1); //a
              digitalWrite(segmentPin[2], 1); //c
              digitalWrite(segmentPin[3], 1); //d
              digitalWrite(segmentPin[5], 1); //f
              digitalWrite(segmentPin[6], 1); //g
              digitalWrite(segmentPin[7], decimal[i]);
              break;
            case 6:
              digitalWrite(segmentPin[0], 1); //a
              digitalWrite(segmentPin[2], 1); //c
              digitalWrite(segmentPin[3], 1); //d
              digitalWrite(segmentPin[4], 1); //e
              digitalWrite(segmentPin[5], 1); //f
              digitalWrite(segmentPin[6], 1); //g
              digitalWrite(segmentPin[7], decimal[i]);
              break;
            case 7:
              digitalWrite(segmentPin[0], 1); //a
              digitalWrite(segmentPin[1], 1); //b
              digitalWrite(segmentPin[2], 1); //c
              digitalWrite(segmentPin[7], decimal[i]);
              break;
            case 8:
              digitalWrite(segmentPin[0], 1); //a
              digitalWrite(segmentPin[1], 1); //b
              digitalWrite(segmentPin[2], 1); //c
              digitalWrite(segmentPin[3], 1); //d
              digitalWrite(segmentPin[4], 1); //e
              digitalWrite(segmentPin[5], 1); //f
              digitalWrite(segmentPin[6], 1); //g
              digitalWrite(segmentPin[7], decimal[i]);
              break;
            case 9:
              digitalWrite(segmentPin[0], 1); //a
              digitalWrite(segmentPin[1], 1); //b
              digitalWrite(segmentPin[2], 1); //c
              digitalWrite(segmentPin[3], 1); //d
              digitalWrite(segmentPin[5], 1); //f
              digitalWrite(segmentPin[6], 1); //g
              digitalWrite(segmentPin[7], decimal[i]);
              break;
          }
          delay(1); //a 1ms delay to allow for the digits to properly illuminate
          allSegments(0); //turns off all the digits to allow for the display of the next digit
          digitalWrite(digitPin[i], 0); //disables the current digit to allow the next one to be displayed
        }
        else{digitalWrite(i, 0);} //disables the current digit if it is not enabled
      }
    }

    setNumber(int number, bool decimal){ //sets a 4 digit number to be displayed on the 7 segment display (if it is a decimal number it is assumed the the decimal is in the middle ex. xx.yy)
      setDigit(3, number%10, 0, 1); //using basic intager math to isolate each digit and setting it on the display
      setDigit(2, (number/10)%10, 0, 1);
      setDigit(1, (number/100)%10, decimal, 1);
      setDigit(0, (number/1000)%10, 0, 1);
    }
};