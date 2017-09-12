#include <Arduino.h>
#include "ArdUnix.h"


ArdUnixDemo demoApp("demo");

void setup() {
  Console.begin(9600);
//  Serial.begin(9600);
//  Serial.println("Ready");
  Console.println( "ArdUnix Begin" );
//	Console.addApp( "DemoApp", demoApp.getLable(), " ", &demoApp );
  Console.println( "-ArdUnix Ready" );
}

void loop() {

}

void serialEvent(){
//	Console.update();
}
