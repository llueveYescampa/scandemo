//-------------------------------------------------------------------------------
//
//    Scandemo --  A program demonstrating  use of the ObjectScan system
//                 Thu 21 Nov 2024 08:14:59 AM CST
//
//    questions may be addressed to :
//       Edgar F. Black -- email edgarfblack@hotmail.com
//
//
//    Program is designed to start up with 
//       standard input = keyboard and
//       standard output = screen. 
//
//    The user can then redirect
//    them to various files, back to standard input-output, etc. using
//    ObjectScan supplied functions.
//
//-----------------------------------------------------------------------------
//  Here is the alphabetic list of the ObjectScan system functions:
//  backsp()                    done
//  doscan()                    done
//  endcrd()                    done
//  endstr()                    done
//  floatn()                    done
//  getEcho()			        done
//  getstr()                    done
//  getVersion()                done
//  in_from_stdin()		        done ! former in_from_remote()
//  integr()                    done
//  isStdinKybrd()              done
//  isStdoutScreen()		    done
//  isstring()                  done
//  label()                     done
//  matchs()                    done
//  matchs_exact()              done
//  name()                      done
//  numd()                      done
//  numf()                      done
//  numi()                      done
//  out_to_stdout()             done
//  readLine()			        done ! former readsc()
//  reset()                     done
//  scan_contents()             done
//  sep()                       done
//  setInputFile(filename)	    done ! former open_input_file()
//  setInputFile()		        done ! Overloaded version of setInputFile(filename)
//  setOutputFile(filename)     done
//  setOutputFile()             done ! Overloaded version of setOutputFile(filename)
//  setEcho()			        done ! now renamed setEcho()
//  sizlst()                    done
//  skpstr()                    done
//  trlist()                    done
//  trxlist()                   done ! the arguments for this function has been changed
//  getVersion()		        done
// _____________________________________________________
//  init_scan()			        not needed any more. The class constructor do the house keeping now.
//  istrue()			        not needed any more
//---------------------------------------------------------------------
//   Here are some command examples and its correct answers:
//
//   > check double 12
//         check double 12
//
//   >> double not found...
//
//   > check double 12.13
//         check double 12.13
//
//   >> double found: 12.13
//
//   > check double 12e-3
//         check double 12e-3
//
//   >> double found: 0.012
//
//   > check numi 23.23
//         check numi 23.23
//
//   >> integer found:         23
//
//
//   > this is a n.a.m.e
//         this is a n.a.m.e
//
//   >> label found:  this
//
//      number of characters in label:   4
//
//
//   >> label found:    is
//
//      number of characters in label:   2
//
//
//   >> label found:     a
//
//      number of characters in label:   1
//
//
//   >> Name found: name
//
//   > list 1-8 by 2 100 to 9 by -20 type quad
//         list 1-8 by 2 9 to 100 by 20 type quad
//   > got list command
//
//   1
//   -8
//   2
//   100
//   -9
//   -20
//   lenlst:6
//   errCode:1
//   Size of the list:9
//   next: 1
//   next: 3
//   next: 5
//   next: 7
//   next: 100
//   next: 80
//   next: 60
//   next: 40
//   next: 20
//   > got type command
//
//   > got quad command after type
//
//   > got type command again after backsp(2)
//
//   > got list command after reset the scaner
//
//   > quit
//         quit
//
//   >> Normal termination. Bye!
//
//---------------------------------------------------------------------


#include <iostream>
#include <iomanip>

//#include "ObjectScan.h"
#include "scandemo.h"

int main(int argc, char *argv[])
{

  Scan myScan(256,50,"$",true,10," ");  // default values are shown here

  switch (argc) {
    case (2):
    case (3):
      if (!myScan.setInputFile(argv[1])) {
        cerr << "Input data file '" << argv[1] << "' not found\n";
        exit(-1);
      } // end if //  
      if (argc >= 3) {
        if (!myScan.setOutputFile(argv[2])) {    // setOutputFile() == true means file was opened
          cerr << ".... Specified file cannot be opened.... \n"
            << "....command ignored....\n";
        } // end if //
      } // end if //
      break;
  } // endswitch //


  message(myScan, 1);  // Notice the defult arguments on prototype.

  //      start infinite loop to read and process command lines

  while (myScan.readLine()) {

    if (myScan.matchs_exact("stop")  or myScan.matchs_exact("quit")  or myScan.matchs_exact("exit")) {
      // stop, quit, exit command
      message(myScan,2);
      break;  // jump out of the while loop
      
    } else if( myScan.matchs_exact( "echo" ) ) { 
      // turn read echo on or off
      myScan.matchs_exact( "on" ) ? myScan.setEcho( true ) : myScan.setEcho( false );

    } else if( myScan.matchs( "input",4 ) ) {
      // input from a different file
      input_command(myScan);

    } else if( myScan.matchs( "output",4 ) ) {
      // output to a different file
      output_command(myScan);

    } else if( myScan.matchs_exact( "list" ) ) {
      // check for and process integer list
      process_list(myScan);
      
    } else if( myScan.matchs( "check",4 ) ) {
      // process "check" command
      check_specified_item(myScan);

    } else {
      // not a command. just identify each "token" on the line
      process_tokens_on_line(myScan);
    } // end if
  } // end while //
  return 0;
} // end of main() //
