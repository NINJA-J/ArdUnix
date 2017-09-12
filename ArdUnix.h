#ifndef ARDUNIX_H
#define ARDUNIX_H

#include <Arduino.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>

typedef char STATUS;

class ArdUnixBase{
	protected:
		String lable;
		String cmdIn;
	public:
		ArdUnixBase( String lable ){ this->lable = lable; }
		virtual void update();
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
	SoftwareSerial* sSerialList[5];

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

	STATUS addApp( String name, String lable, char splict, ArdUnixBase* app, SoftwareSerial* source = NULL );

	String sprint( double t, int digits );
	String sprint( int t );

  virtual void update(){ ArdUnixBase::update(); }
	virtual void update( String updStr );
	virtual void updateRaw( String updStr );
};

class ArdUnixDemo : public ArdUnixBase{
private:
public:
	ArdUnixDemo();
	ArdUnixDemo( String lable );
	void doSomething();
  virtual void update(){ ArdUnixBase::update(); };
	virtual void update( String updStr );
	virtual void updateRaw( String updStr );
};

extern ArdUnix Console;
extern ArdUnixDemo demoApp;

#endif
