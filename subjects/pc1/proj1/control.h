#ifndef CONTROL_H
#define CONTROL_H 1

#include "types.h"

unsigned parse_size();
cmd_t parse_cmd();
inst_t parse_inst(cmd_t cmd);
void exec_inst();

#endif