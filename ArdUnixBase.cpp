#include "ArdUnix.h"
#include <Arduino.h>

String ArdUnixBase::strSplict( String& srcStr, char splict ){
#ifdef ARDUNIX_DEBUG
    Console.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    Console.print( "String To Splict    = [" + srcStr + "], by \"");Console.print(splict);Console.println( "\"" );
#endif
    String temp = "";
    int sLen = srcStr.length();   
    int tLen = 0;
    bool splictFound = false;

    while( tLen < sLen && srcStr[tLen] == splict ) tLen++;
    srcStr = srcStr.substring( tLen );
  
    for( int i = 0; i < sLen; i++ ){
      	if( srcStr[i] == splict ){
            break;
        } else {
        temp += srcStr[i];
      }
    }
    tLen = temp.length();
  
    while( tLen < sLen && srcStr[tLen] == splict ) tLen++;
    srcStr = srcStr.substring( tLen );
  
#ifdef ARDUNIX_DEBUG
    Console.print  ("    sLen            = ");Console.println(sLen);
    Console.print  ("    tLen            = ");Console.println(tLen);
    Console.println("    String Splicted = [" + temp   + "]");
    Console.println("    String Lasted   = [" + srcStr + "]");
    Console.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
#endif

    return temp;
}
