#include <stdio.h>
#include <msgbox.h>

#define KINI_PORT 15999
#define KINI_TIMEOUT 10

void update(msg_Conn *conn, msg_Event event, msg_Data data) {
  printf("Yay, I like events!\n");
}

int main(void) {
  char address[128];
  snprintf(address, 128, "tcp://*:%d", KINI_PORT);

  printf("Listening at address %s\n", address);
  msg_listen(address, update);

  for (;;) msg_runloop(KINI_TIMEOUT);

  return 0;
}
