#ifndef SCANDEMO_H
#define SCANDEMO_H

#include "ObjectScan.h"

// scan_demo_prog functions prototypes
void check_specified_item(  Scan &);
void input_command(         Scan &);
void output_command(        Scan &);
void process_tokens_on_line(Scan &);
void process_list          (Scan &);
void message(               Scan &, 
                            const positiveInt &, 
                            const char *const mensage=" ", 
                            const int &ivalue=0, 
                            const float &value=0.0f);
// end of scan_demo_prog functions prototypes
#endif

