#include "ArdUnix.h"

String ArdUnixBase::strSplict( String& srcStr, char splict ){
	String temp = "";
	int sLen = srcStr.length();
	int tLen = 0;
	for( int i = 0; i < sLen; i++ ){
		if( srcStr[i] == splict ){
			tLen = temp.length();
			srcStr.substring( tLen, sLen - tLen );
			return temp;
		} else {
			temp += srcStr[i];
		}
	}
	return temp;
}
