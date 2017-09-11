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
String ArdUnix::sprint( double t ){
	
}
String ArdUnix::sprint( int t ){
	
}

bool addApp( String name, String lable, char splict, ArdUnixBase* app, SoftwareSerial* source ){
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
