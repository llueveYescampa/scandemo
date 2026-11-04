#include "scandemo.h"

// **************************************************************
// *                                                            *
// * output_command                                             *
// *                                                            *
// **************************************************************

void output_command(Scan &ScanObj)
{  
  ScanObj.matchs_exact("to");
  ScanObj.matchs_exact("file");

  if ( ScanObj.matchs("remote", 4) or ScanObj.matchs_exact("stdout") ) {
    ScanObj.out_to_stdout();
//  } else if ( ScanObj.isstring() or ScanObj.label() ) {
  } else {
    char text[81];
    positiveInt nchar;
    ScanObj.scan_contents(text, nchar);
    if (!ScanObj.setOutputFile(text)) {  // setOutputFile() == true means file was opened
      cerr << ".... Specified file cannot be opened.... \n"
           << "....command ignored....\n";
    } // end if //
  } // end if //
  return;
} // end of output_command() //
