#ifndef ARDUNIX_H
#define ARDUNIX_H

#include <Arduino.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>

class ArdUnixBase{
	private:
		String lable;
		String cmdIn;
	public:
		ArdUnixBase( String lable ){ this->lable = lable; }
		virtual void update() = 0;
		virtual void update( String updStr ) = 0;
		virtual void updateRaw( String updStr ) = 0;
		String strSplict( String& srcStr, char splict );
		String getLable(){ return lable; }
};

class ArdUnix : public ArdUnixBase, public HardwareSerial{
private:
	struct BaseBlock{
		String name;
		String lable;
		char splict;
		char source;
		ArdUnixBase* app;
		struct BaseBlock* next;
	};

	typedef struct BaseBlock BaseBlock;

	BaseBlock *head, *tail;
	SoftwareSerial **sSerialList;

	int sSerialLen;
public:
	static const char SUCCESS         = 0;
	static const char NAME_DUPLICATED = 1;
	static const char MEMORY_FAILED   = 2;
	static const char SSERIAL_FULL    = 3;
	// static char SUCCESS = 0;
	// static char SUCCESS = 0;

	ArdUnix();
	ArdUnix( String lable );

	bool addApp( String name, String lable, char splict, ArdUnixBase* app, SoftwareSerial* source = NULL );

	String sprint( double t, int digits );
	String sprint( int t );

	virtual void update();
	virtual void update( String updStr );
	virtual void updateRaw( String updStr );
};

class ArdUnixDemo : public ArdUnixBase{
private:
	static char cnt;
public:
	ArdUnixDemo();
	ArdUnixDemo( String lable );
	void doSomething();
	virtual void update();
	virtual void update( String updStr );
	virtual void updateRaw( String updStr );
};

char ArdUnixDemo::cnt = 0;

extern ArdUnix Console;
extern ArdUnixDemo demoApp("demo");

#endif
