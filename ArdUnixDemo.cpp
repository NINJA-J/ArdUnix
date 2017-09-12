#include "ArdUnix.h"

ArdUnixDemo::ArdUnixDemo() : ArdUnixBase( "demo" + ('0' + ArdUnixDemo.cnt++ ) ) {

}
ArdUnixDemo::ArdUnixDemo( String lable ) : ArdUnixDemo( lable ){

}
void ArdUnixDemo::doSomething(){
	Serial.println( "Console has called me to do something" );
}

void update(){
	while(Serial.available()){
		char c = (char)Serial.read();
		if( c != '\n' ){
			cmdIn += c;
		} else {
			updateRaw(cmdIn);
			cmdIn = "";
		}
	}
}
void update( String updStr ){
	String cmd = strSplict( updStr, " " );
	switch(cmd){
		case "-play": doSomething()                            ;break;
		case "-info": Console.println("This is a demo")        ;break;
		case ""     : Console.println("Please enter a command");break;
		default     : Console.println("cmd : [" + cmd + "] not found");
	}
}
void updateRaw( String updStr ){
	int uLen = updStr.length();
	int lLen = updStr.length();

	String s = strSplict( updStr, " " );

	if( s == lable )
		update( updStr );
	else
		Console.println("Operating app not found");
}