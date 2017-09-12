#include "ArdUnix.h"

ArdUnixDemo::ArdUnixDemo() : ArdUnixBase( "demo" ) {

}
ArdUnixDemo::ArdUnixDemo( String lable ) : ArdUnixBase( lable ){

}
void ArdUnixDemo::doSomething(){
	Console.println( "Console has called me to do something" );
}

void ArdUnixDemo::update( String updStr ){
	String cmd = strSplict( updStr, " " );

	if     ( cmd == "-play" )doSomething();
	else if( cmd == "-info" )Console.println("This is a demo");
	else if( cmd == ""      )Console.println("Please enter a command");
	else                     Console.println("cmd : [" + cmd + "] not found");
}
void ArdUnixDemo::updateRaw( String updStr ){
	int uLen = updStr.length();
	int lLen = updStr.length();

	String s = strSplict( updStr, " " );

	if( s == lable )
		update( updStr );
	else
		Console.println("Operating app not found");
}
