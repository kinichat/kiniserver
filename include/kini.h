#ifndef __KINI_H__
#define __KINI_H__

#include <stdint.h>

typedef struct kini_packet_t kini_packet_t;

struct kini_packet_t {
  uint32_t checksum;
  uint32_t password;

  char user[20];
  char channel[32];

  uint32_t length;

};

#endif
