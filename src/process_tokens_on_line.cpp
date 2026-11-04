#include "scandemo.h"

// **************************************************************
// *                                                            *
// * process_tokens_on_line                                     *
// *                                                            *
// **************************************************************

void process_tokens_on_line(Scan &scan)
{
  char text[80];
  positiveInt nchars;
  int ivalue;
  positiveInt sep_type;
  float value;

  while ( true ) {
    if( scan.isstring() ) {
      scan.scan_contents( text, nchars );
      ivalue = nchars;
      message(scan, 3, text, ivalue, value );
      scan.getstr();
      while (!scan.endstr() ) {
        scan.scan_contents( text, nchars );
        ivalue = nchars;
        message(scan, 4, text, ivalue, value );
        if (scan.matchs("stop", 4)) {
          scan.skpstr();
        } // end if //
      } // end while //
      
    } else if( scan.label() ) {
      scan.scan_contents( text, nchars);
      ivalue = nchars;
      message(scan, 4, text, ivalue, value );
      
    } else if(scan.name() ) {
      scan.scan_contents( text, nchars );
      ivalue = nchars;
      message(scan, 8, text, ivalue, value);
      
    } else if( scan.integr( ivalue )) {
      message(scan, 5, text, ivalue, value );
      
    } else if( scan.floatn(value) ) {
      message(scan, 6, text, ivalue, value );
      
    } else if( scan.sep( sep_type ) ) {
      message(scan, 7, text, sep_type, value);
      
    } else if( scan.endcrd() ) {
      break; // jump out of the while loop
      
    } else {
      scan.scan_contents( text, nchars );
      message(scan, 9, text, ivalue, value );
      break; // jump out of the while loop
    } // end if //
  } // end while //
  return;
} // end of process_tokens_on_line() //
