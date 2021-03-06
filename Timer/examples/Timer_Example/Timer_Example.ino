/* Written by Jacob Smith for Brandeis Robotics club.
    Provides sample usage of the Timer class, which allows
    a task to be repeated on an interval without delay statements, see the
    loop. In the setup, the more basic functions of the Timer class are
    demonstrated.
    April 4 2018
*/

//include the classes necessary to make this one work
#include <Timer.h>
#include <Zumo32U4LCD.h>

//declare robot display timer, and secondCount variable
Zumo32U4LCD lcd;
Timer timer;
int secCount;

//setup is executed before main loop
void setup() {

  printNumber("getTime:", timer.getTime());
  waitAndClear();

  printNumber("Rsetime:", timer.resetTime());
  waitAndClear();

  printNumber("getReset", timer.getAndResetTime());
  waitAndClear();

  printNumber("getTime:", timer.getTime());
  waitAndClear();
}

//main loop of execution
//prints the time every second without usage of delay statements
void loop() {
  if (timer.interval(1000)) {
    printNumber("Secs ", secCount);
    secCount++;
  }
}

//wait for 2 seconds and clears the robot's display
void waitAndClear() {
  delay(2000);
  lcd.clear();
}

//print a message and a number to the robot's display
void printNumber (const char *message, long number) {
  lcd.print(message);
  lcd.gotoXY(0, 1);
  lcd.print(number);
}