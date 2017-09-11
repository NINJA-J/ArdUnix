#ifndef ARDUNIX_H
#define ARDUNIX_H

class ArdUnixBase{
	private:
		String lable;
	public:
		ArdUnixBase( String lable ){ this->lable = lable; }
		virtual void update() = 0;
		virtual void update( String updStr ) = 0;
		virtual void updateRaw( String updStr ) = 0;
};

typedef struct BaseBlock{
	String name;
	String lable;
	bool withSplict;
	ArdUnixBase* app;
	struct BaseBlock* next;
}BaseBlock;

class ArdUnix : public ArdUnixBase, public HardwareSerial{
	private:
		BaseBlock* head, tail;
	public:
		ArdUnix();
		ArdUnix( String lable );
		String sprint( double t );
		String sprint( int t );
};

extern ArdUnix Console;

#endif
