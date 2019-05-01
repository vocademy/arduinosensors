/* Reads the value of a LDR on A0 and displays the brightness level across a 5 LED bard graph
 * Assumes that all 5 LEDs on the graph are connected on sequential Arduino digital pins.
 * 
 * Contains three functions showing three different decision making methods. Remove the comment next to the function you want to use.
 * Be sure that the other two function calls in the loop() are commented out.
 * 
 * Written by Brian Cox 4/28/2019
 */

int firstLedPin = 7;  // The Arduino pin for the first LED in the bar graph.
int lastLedPin = 11;  // The Arduino pin for the last LED in the bar graph.
int sensorPin = 0;   // The Arduino pin receiving input from the LDR.
int sensorValue = 0;  // This varible will store the reading from the LDR. 
int counter;          // This will be used as a loop counter.

// the setup routine runs once when you press reset:
void setup() { 
  //Set the 5 LED pins as outputs.
  for(int counter=firstLedPin; counter<=lastLedPin; counter++){
    pinMode(counter,OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop(){
  driveBarGraphUsingIf();
  //driveBarGraphUsingIfElse();
  driveBarGraphUsingSwitch();
  delay(10); // Adds a delay of 10 ms to provide stability. Remember that the LEDs are turned off at the beginning of a loop. This ensures they will stay on for 10ms.
}

/* driveBarGraphUsingIf()
 * This function uses a series of if statments to drive the LED bard graph.
 * This is an example of what not to do. This code is inefficient.
 * The microcontroller must test all conditions no matter what.
 */

void driveBarGraphUsingIf() {
  //Turn all LEDs off
  for(counter=firstLedPin; counter<=lastLedPin+1; counter++){
    digitalWrite(counter, LOW);
  }
  // read the input on analog pin 0:
  int sensorValue = analogRead(sensorPin);
  
  // Activate the appropriate number of LEDs in the bar graph based on the value on A0. (The range is 0 to 1023)
  // Considering that there are 5 LEDs in the bar graph, and there are 1024 possible numbers for the input: (1024 / 5 = 204.8) each increment will be 204.
  
  if (sensorValue > 150 && sensorValue <= 204){  //In order to ensure that all LEDs are off if it is relatively dark, the lowest value that triggers an LED is 50.
    digitalWrite(firstLedPin, HIGH);
  }
  if (sensorValue > 204 && sensorValue <= 408){
    for(counter=firstLedPin; counter<=firstLedPin+1; counter++){
        digitalWrite(counter, HIGH);
    }
  }
  if (sensorValue > 408 && sensorValue <= 612){
    for(counter=firstLedPin; counter<=firstLedPin+2; counter++){
        digitalWrite(counter, HIGH);
    }
  }
  if (sensorValue > 612 && sensorValue <= 816){
    for(counter=firstLedPin; counter<=firstLedPin+3; counter++){
        digitalWrite(counter, HIGH);
    }
  }
  if (sensorValue > 816 && sensorValue <= 1020){      
    for(counter=firstLedPin; counter<=firstLedPin+4; counter++){
        digitalWrite(counter, HIGH);
    }
  }
} //End of the function driveBarGraphUsingIf()

/* driveBarGraphUsingIfElse()
 * This function uses if and else statements to drive the LED bar graph.
 * Once a condition is met, it leaves the if statement.  This method is more efficient. (Although a little cumbersome to type out)
 */

void driveBarGraphUsingIfElse(){
  //Turn all LEDs off
  for(counter=firstLedPin; counter<=lastLedPin+1; counter++){
    digitalWrite(counter, LOW);
  }
  // read the input on analog pin 0:
  int sensorValue = analogRead(sensorPin);
  
  // Activate the appropriate number of LEDs in the bar graph based on the value on A0. (The range is 0 to 1023)
  // Considering that there are 5 LEDs in the bar graph, and there are 1024 possible numbers for the input: (1024 / 10 = 204.8) each increment will be 204.
  
  if (sensorValue > 50 && sensorValue <= 204){  //In order to ensure that all LEDs are off if it is relatively dark, the lowest value that triggers an LED is 50.
    digitalWrite(firstLedPin, HIGH);
  } 
  else if (sensorValue > 204 && sensorValue <= 408){
         for(counter=firstLedPin; counter<=firstLedPin+1; counter++){
          digitalWrite(counter, HIGH);
         }
  }
  else if (sensorValue > 408 && sensorValue <= 612){
         for(counter=firstLedPin; counter<=firstLedPin+2; counter++){
          digitalWrite(counter, HIGH);
         }
  }
  else if (sensorValue > 612 && sensorValue <= 816){
         for(counter=firstLedPin; counter<=firstLedPin+3; counter++){
          digitalWrite(counter, HIGH);
         }
  }
  else if (sensorValue > 816 && sensorValue <= 1020){      
         for(counter=firstLedPin; counter<=firstLedPin+4; counter++){
          digitalWrite(counter, HIGH);
         }
  }//End of the if statements
} //End of the function driveBarGraphUsingIfElse()

/* driveBarGraphUsingSwitch()                                                                 
 * This function uses a switch statement to drive the LED bard graph. 
 * This is an efficient design becuase is only makes a decision once and then runs the proper statements.
 */ 

 void driveBarGraphUsingSwitch(){
  //Turn all LEDs off
  for(counter=firstLedPin; counter<=lastLedPin+1; counter++){
    digitalWrite(counter, LOW);
  }
  // read the input on analog pin 0:
  int sensorValue = analogRead(sensorPin);
  
  // Activate the appropriate number of LEDs in the bar graph based on the value on A0. (The range is 0 to 1023)
  // Considering that there are 5 LEDs in the bar graph, and there are 1024 possible numbers for the input: (1024 / 5 = 102.4) each increment will be 204.
  
  switch(sensorValue){
    case 50 ... 204:        //In order to ensure that all LEDs are off if it is relatively dark, the lowest value that triggers an LED is 50.
      digitalWrite(firstLedPin, HIGH);
      break;
    case 205 ... 408:
      for(counter=firstLedPin; counter<=firstLedPin+1; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 409 ... 612:
      for(counter=firstLedPin; counter<=firstLedPin+2; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 613 ... 816:
      for(counter=firstLedPin; counter<=firstLedPin+3; counter++){
        digitalWrite(counter, HIGH);
      }
      break;
    case 817 ... 1020:
      for(counter=firstLedPin; counter<=firstLedPin+4; counter++){
        digitalWrite(counter, HIGH);
      }
     default:
      break;
  } //End of switch statement
 } //End of the function driveBarGraphUsingSwitch()
