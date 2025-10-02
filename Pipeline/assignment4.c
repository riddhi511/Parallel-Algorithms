#include <stdlib.h>

#define NUMBERS 32000
#define PROCESSES 100
#define MODULUS 24681

int tools[PROCESSES] = {
   3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,
   79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,
   181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,
   293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,
   421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547
};

typedef struct {
  int initial;
  int current;
} message;

message stream channels[PROCESSES];


void Producer(message stream ochn) { /* Producer */
  int ix, rnd = 13;
  message msg;
  for (ix = 0; ix < NUMBERS; ix++) {
    rnd = (rnd + 619) % MODULUS;
    msg.initial = rnd;
    msg.current = rnd;
    send(ochn, msg);
  }
  msg.initial = 0;
  msg.current = 0;
  send(ochn, msg);
}

void Worker(int p, message stream ichn, message stream ochn) { /* Worker */
  message msg;
  while (1) {
    recv(ichn, msg);
    if (msg.initial == 0) {
      send(ochn, msg);
      return;
    }
    msg.current -= tools[p];
    if (msg.current > 0) {
      send(ochn, msg);
    }
  }
}

void Consumer(int p, message stream ichn) { /* Consumer (final process) */
  int working = 0, fixable = 0;
  message msg;
  while (1) {
    recv(ichn, msg);
    if (msg.initial == 0) break;

    msg.current -= tools[p];

    if (msg.current < 5 && msg.current > -5) {
      cout << "pipeline completed with initial value " << msg.initial << endl;
      working++;
    } else if ((msg.current >= 5 && msg.current < 10) ||
               (msg.current <= -5 && msg.current > -10)) {
      fixable++;
    }
  }
  cout << "assembly line produced " << working << " working units" << endl;
  cout << "assembly line produced " << fixable << " fixable units" << endl;
}

int main() {
  int i;
  /* start Consumer */
  FORK Consumer(PROCESSES-1, channels[PROCESSES-1]);

  /* start Workers */
  for (i = PROCESSES-2; i >= 0; i--) {
    FORK Worker(i, channels[i], channels[i+1]);
  }

  /* start Producer */
  FORK Producer(channels[0]);

  /* join all */
  for (i = 0; i < PROCESSES+1; i++) {
    JOIN;
  }

  return 0;
}
