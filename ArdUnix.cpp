#include "ArdUnix.h"

ArdUnix::ArdUnix():ArdUnixBase("Base"),HardwareSerial(){
	head = tail = NULL;
}
ArdUnix::ArdUnix( String lable ):ArdUnixBase(lable),HardwareSerial(){
	head = tail = NULL;
}
String ArdUnix::sprint( double t ){
	
}
String ArdUnix::sprint( int t ){
	
}
