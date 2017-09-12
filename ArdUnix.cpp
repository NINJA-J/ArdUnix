#include "ArdUnix.h"

ArdUnix::ArdUnix():ArdUnixBase("Base"),HardwareSerial(){
	head = tail = NULL;
	sSerialList = (SoftwareSerial**)new *SoftwareSerial[5];
	sSerialLen = 0;
}
ArdUnix::ArdUnix( String lable ):ArdUnixBase(lable),HardwareSerial(){
	head = tail = NULL;
	sSerialList = (SoftwareSerial**)new *SoftwareSerial[5];
	sSerialLen = 0;
}
String ArdUnix::sprint( double number, int digits ){
	String str = "";
	
	if (isnan(number)) return "nan";
	if (isinf(number)) return "inf";
	if (number > 4294967040.0 || number <-4294967040.0) return "ovf";
  
	if (number < 0.0) {
		str = "-"
		number = -number;
	}

	double rounding = 0.5;
	for ( int i = 0; i < digits; ++i )
		rounding /= 10.0;
  
	number += rounding;

	unsigned long int_part = (unsigned long)number;
	double remainder = number - (double)int_part;
	str += sprint( int_part );

	if ( digits > 0 )
		str += ".";

	while ( digits-- > 0 ) {
		remainder *= 10.0;
		int toPrint = (int)remainder);
		str += ( '0' + toPrint );
		remainder -= toPrint; 
	}

	return str;
}
String ArdUnix::sprint( int t ){
	String str = "";
	if( t < 0 ){
		t = -t;
		str = "-";
	}

	do{
		str += ( t % 10 + '0' );
		t /= 10;
	}while( t != 0 );

	return str;
}

bool ArdUnix::addApp( String name, String lable, char splict, ArdUnixBase* app, SoftwareSerial* source ){
	BaseBlock *p = head;
	while( p != NULL ){
		if( p->name == name )
			return ArdUnix.NAME_DUPLICATED;
		p = p->next;
	}
	p = new BaseBlock();
	if( p == NULL ) return ArdUnix.MEMORY_FAILED;
	p->name = name;
	p->lable = lable;
	p->splict = splict;
	p->app = app;
	if( source == NULL )
		p->source = -1;
	else{
		for( int i = 0; i < sSerialLen; i++ ){
			if( sSerialList[i] == source ){
				p->source = i;
				return ArdUnix.SUCCESS;
			}
		}
		if( sSerialLen == 5 )
			return ArdUnix.SSERIAL_FULL;
		sSerialList[sSerialLen] = source;
		p->source = sSerialLen++;
		return ArdUnix.SUCCESS;
	}
}

void ArdUnix::update(){
	BaseBlock *p = head;

	while( head != null ){

	}
}
void ArdUnix::update( String updStr ){

}
void ArdUnix::updateRaw( String updStr ){

}
