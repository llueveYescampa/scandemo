#include "scandemo.h"

// **************************************************************
// *                                                            *
// * check_specified_item                                       *
// *                                                            *
// **************************************************************

void check_specified_item(Scan &scan)
{
  int ivalue;
  float fvalue;
  double dvalue;

  if (scan.matchs_exact("double")) {
    if (scan.floatn( fvalue )) {
      dvalue = static_cast<double> (fvalue);
      cout << "\n >> double found: " << dvalue << endl << endl;
    } else {
      cout << "\n>> double not found...\n" << endl;
    } // end if //
    
  } else if (scan.matchs_exact("numf")) {
    if (scan.numf( fvalue )) {
      cout << "\n>> float found: " << fvalue  << endl << endl;
    } else {
      cout << "\n>> float not found...\n"<< endl;
    } // end if //
    
  } else if (scan.matchs_exact("numd")) {
    if (scan.numd(dvalue)) {
      cout << "\n>> double found: " << dvalue << endl << endl;
    } else {
      cout << "\n>> double not found...\n" << endl;
    } // end if //
    
  } else if (scan.matchs( "float", 4 )) {
    if (scan.floatn(fvalue)) {
      cout << "\n>> float found: " << fvalue << endl << endl;
    } else {
      cout << "\n>> float not found...\n" << endl;
    } // end if //
    
  } else if (scan.matchs_exact( "numi" )) {
    if (scan.numi( ivalue )) {
      cout << "\n>> integer found: " << setw(10) << ivalue << endl << endl;
    } else {
      cout << "\n>> integer not found...\n" << endl;
    } // end if //
    
  } else if (scan.matchs( "integer", 4 )) {  
    if (scan.integr( ivalue )) {
      cout << "\n>> integer found: " << setw(10) << ivalue << endl << endl;
    } else {
      cout << "\n>> integer not found...\n" << endl;
    }  // end if //
    
  } else {
    cout << "\n>> unknown option for check command...\n\n";
  } // end if //

  return;
} // end of check_specified_item() //
