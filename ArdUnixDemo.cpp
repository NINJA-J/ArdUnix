#include "ArdUnix.h"

ArdUnixDemo::ArdUnixDemo() : ArdUnixBase( "demo" ) {

}
ArdUnixDemo::ArdUnixDemo( String lable ) : ArdUnixBase( lable ){

}
void ArdUnixDemo::doSomething(){
	Console.println( "DemoApp : Console has called me to do something" );
}
void ArdUnixDemo::Info(){
  Console.println( "DemoApp : Version v1.0" );
}

void ArdUnixDemo::update( String updStr ){
	String cmd = strSplict( updStr );

	if     ( cmd == "-play" )doSomething();
	else if( cmd == "-info" )Info();
	else if( cmd == ""      )Console.println("DemoApp : Please enter a command");
	else                     Console.println("DemoApp : cmd [" + cmd + "] not found");
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

ArdUnixDemo demoApp("demo");
