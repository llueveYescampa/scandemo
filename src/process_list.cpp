#include "scandemo.h"

// **************************************************************
// *                                                            *
// * process_list                                               *
// *                                                            *
// **************************************************************

void process_list(Scan &myScan)
{
  constexpr unsigned int workingArraySize = 100;
  int intlst[workingArraySize],errCode; // variables used to test the trlist() method
  positiveInt listSize, zero=0; 
  int nAll = 10;
  
  cout << "> got list command \n" << endl;
  //myScan.doScan();  // this command here is optional.
  myScan.trlist(intlst,workingArraySize,nAll,listSize,errCode);
  cout << "Compressed list size:" << listSize << endl;
  cout << "errCode:" << errCode << endl;
  cout << "Expanded List Size:" << myScan.sizlst(intlst,listSize) << endl;

  for (auto i=zero; i < listSize ;++i ) {
    cout << intlst[i] << endl;
  } // end for //
  // Testing the sizlst function
  if (errCode == 1) {
    int iplist,next; // variables used to test trxlst() method                         
    iplist = 1;
    do {
      myScan.trxlst(next, iplist, intlst,listSize);
      cout << "next: " << next << endl;
    } while (iplist != 0 );

    // Testing the backsp function
    //myScan.backsp(1);                 //  not needed here
    if (myScan.matchs_exact( "type")) {
      cout << "> got type command \n" << endl;
      if (myScan.matchs_exact( "quad")) {
        cout << "> got quad command after type\n" << endl;
      } else {
        cout << "> miss quad command after type\n" << endl;
      }
    } else {
      cout << "> miss type command \n" << endl;
    } // end if //
    myScan.backsp(2);                
    if (myScan.matchs( "type",4)) {
      cout << "> got type command again after backsp(2)\n" << endl;
    } else {
      cout << "> miss type command again after backsp(2)\n" << endl;
    } // end if //
      // Testing the reset function
    myScan.reset();
    if (myScan.matchs("list",4)) {
      cout << "> got list command after reset the scaner\n" << endl;
    } else {
      cout << "> miss list command. Reset was not issued\n" << endl;
    }
  } else {
    cout << "Error in list was found" << endl;
  } // end if //

  return;
} // end of process_list() //
