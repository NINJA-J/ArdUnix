#include "ArdUnix.h"
#include <HardwareSerial.h>
#include <HardwareSerial_private.h>
#include <Arduino.h>

ArdUnix Console;

ArdUnix::ArdUnix():
	ArdUnixBase("Base"),
	HardwareSerial( &UBRR0H, &UBRR0L, &UCSR0A, &UCSR0B, &UCSR0C, &UDR0 )
{
	head = tail = NULL;
	sSerialLen = 0;
  for( int i = 0; i < 5; i++ )
    sSerialList[i] = NULL;
}
ArdUnix::ArdUnix( String lable ):
	ArdUnixBase(lable),
	HardwareSerial( &UBRR0H, &UBRR0L, &UCSR0A, &UCSR0B, &UCSR0C, &UDR0 )
{
	head = tail = NULL;
	sSerialLen = 0;
  for( int i = 0; i < 5; i++ )
    sSerialList[i] = NULL;
}
String ArdUnix::sprint( double number, int digits ){
	String str = "";
	
	if (isnan(number)) return "nan";
	if (isinf(number)) return "inf";
	if (number > 4294967040.0 || number <-4294967040.0) return "ovf";
  
	if (number < 0.0) {
		str = "-";
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
		int toPrint = (int)remainder;
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

STATUS ArdUnix::addApp( String name, String lable, char splict, ArdUnixBase* app, SoftwareSerial* source ){
	BaseBlock *p = head;
	while( p != NULL ){
		if( p->name == name )
			return Console.NAME_DUPLICATED;
		p = p->next;
	}
	p = new BaseBlock();
	if( p == NULL ) return Console.MEMORY_FAILED;
	//error: expected primary-expression before '.' token
	p->name = name;
	p->lable = lable;
	p->splict = splict;
	p->app = app;
	p->next = NULL;
	if( source == NULL )
		p->source = -1;
	else{
    p->source = -2;
		for( int i = 0; i < sSerialLen; i++ ){
			if( sSerialList[i] == source ){
				p->source = i;
			}
		}
    if( p->source == -2 )
		  if( sSerialLen == 5 )
			  return Console.SSERIAL_FULL;
		sSerialList[sSerialLen] = source;
		p->source = sSerialLen++;
	}
	if( head == NULL ){
		head = tail = p;
	} else {
		tail->next = p;
		tail = p;
	}
  return SUCCESS;
}

void ArdUnix::update( String updStr ){

}
void ArdUnix::updateRaw( String updStr ){
	println("Found String : [" + updStr + "]");
	String strLable = strSplict( updStr, " " );
	
	BaseBlock *p = head;
	while( head != NULL ){
		println("Confirming " + head->name + " with  lable [" + head->lable + "]");
		if( head->lable == strLable )
			head->app->update( updStr );
		head = head->next;
	}
}
