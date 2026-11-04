#include "scandemo.h"

// **************************************************************
// *                                                            *
// * input_command                                              *
// *                                                            *
// **************************************************************

void input_command(Scan &ObjScan)
{
  ObjScan.matchs_exact("from");
  ObjScan.matchs_exact("file");

  if ( ObjScan.matchs("remote", 4) or ObjScan.matchs_exact("stdin") or ObjScan.matchs("keyboard", 5)) {
    ObjScan.in_from_stdin();
  } else if ( ObjScan.isstring() or ObjScan.label() ) {
    if (!ObjScan.setInputFile()) { // setInputFile() == true means file was opened
      cerr << ".... Specified file cannot be opened.... \n"
           << "....command ignored....\n";
    } // end if //
  } // end if //
} // end of input_command() //
