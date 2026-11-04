#include "ObjectScan.h"

// **************************************************************
// *                                                            *
// * message: send message to stdout                            *
// *                                                            *
// **************************************************************

void message(Scan &scan, const positiveInt &messVal, const char *const message,const int &ivalue, const float &value)
{
  switch (messVal) {
    case 1:
      cout << "\n *** ObjectScan " << scan.getObjectScanVersion() << " - Demo Program  ***\n\n"  << endl;
      cout << "Type any input line at the > prompt and it will be parsed...\n\n" << endl;
      break;
    case 2:
      cout << "\n>> Normal termination. Bye!\n\n" << endl;
      break;
    case 3:
      cout << "\n>> string found: " << setw(5) <<  message << endl<< endl;
      cout << "  number of characters in string: " << setw(2) << ivalue<< endl;
      break;
    case 4:
      cout << "\n>> label found: " <<  setw(5) << message << endl << endl;
      cout << "   number of characters in label: " <<  setw(3) << ivalue << endl<< endl;
      break;
    case 5:
      cout << "\n>> integer found: " << setw(3) <<ivalue << endl<< endl;
      break;
    case 6:
      cout << "\n>> float found: "                   << value << endl<< endl;
      break;
    case 7:
      cout << "\n>> separator found: " << setw(3) <<ivalue << endl<< endl;
      break;
    case 8:
      cout << "\n>> name found: " << setw(3) << message<< endl<< endl;
      break;
    case 9:
      cout << "\n>> unrecognized item: " <<  message << endl;
      cout << "\n>> scanning of this line terminated...\n" << endl;
      break;
    default:
      cout << ">> Fatal Error: invalid menssage specified\n\n";
      cout << ">> Program Terminated....\n\n" << endl;
      exit(0);
      break;
  } // end switch //
} // end of message() //
