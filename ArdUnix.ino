#include "ArdUnix.h"

void setup() {
	Console.addApp( "DemoApp", demoApp.getLable(), " ", &demoApp );
}

void loop() {

}

void serialEvent(){
	Console.update();
}
