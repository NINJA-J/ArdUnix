#include "ArdUnix.h"


ArdUnixDemo demoApp("demo");

void setup() {
	Console.addApp( "DemoApp", demoApp.getLable(), " ", &demoApp );
}

void loop() {

}

void serialEvent(){
	Console.update();
}
