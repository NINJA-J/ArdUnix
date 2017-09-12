#define ARDUNIX_DEBUG

#include <Arduino.h>
#include "ArdUnix.h"

void setup() {
  Console.begin(9600);
	Console.addApp( "DemoApp", demoApp.getLable(), " ", &demoApp );
  Console.println( "ArdUnix Ready" );
}

void loop() {

}

void serialEvent(){
	Console.update();
}
