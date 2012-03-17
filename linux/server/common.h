#pragma once

#ifndef _COMMON_H_
#define _COMMON_H_

#include <string.h>

#define PROGRAM_FAILURE 2
#define DEFAULT_PROTOCOL 0 

#define LOCAL_HOST "127.0.0.1"

struct unicast_pkt {
  char data[400];
};

#endif

