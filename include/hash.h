#ifndef __HASH_H__
#define __HASH_H__

#include <stddef.h>
#include <stdint.h>

uint32_t str_hash(const void *data, size_t length) {
  uint32_t x = 0xfb73c5fc;
  const uint8_t *buffer = (const uint8_t *)(data);

  while (length) {
    x += buffer[--length];
    x ^= x >> 15;
    x *= 0x2c1b3c6d;
    x ^= x >> 12;
    x *= 0x297a2d39;
    x ^= x >> 15;
  }

  x ^= x >> 17;
  x *= 0xed5ad4bb;
  x ^= x >> 11;
  x *= 0xac4c1b51;
  x ^= x >> 15;
  x *= 0x31848bab;
  x ^= x >> 14;

  return x + 0xefa96b94;
}

uint32_t num_hash(uint32_t x) {
  x ^= x >> 17;
  x *= 0xed5ad4bb;
  x ^= x >> 11;
  x *= 0xac4c1b51;
  x ^= x >> 15;
  x *= 0x31848bab;
  x ^= x >> 14;

  return x;
}

#endif
