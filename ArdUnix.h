#ifndef ARDUNIX_H
#define ARDUNIX_H

#ifndef SUCCESS
#define SUCCESS 0
#endif

#define NAME_DUPLICATED 1
#define 

class ArdUnixBase{
	private:
		String lable;
	public:
		ArdUnixBase( String lable ){ this->lable = lable; }
		virtual void update() = 0;
		virtual void update( String updStr ) = 0;
		virtual void updateRaw( String updStr ) = 0;
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

	bool addApp( String name, String lable, char splict, ArdUnixBase* app, SoftwareSerial* source = null );

	String sprint( double t );
	String sprint( int t );

	void update();
};

extern ArdUnix Console;

#endif
