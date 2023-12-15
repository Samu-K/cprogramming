#include "signaalit.h"
#include <signal.h>
#include <stdio.h>

jmp_buf paluuTila;

void hoidaSIGFPE(int s) {
  signal(SIGFPE,hoidaSIGFPE);
  longjmp(paluuTila,SIGFPE);
}


void hoidaSIGSEGV(int s) {
  signal(SIGSEGV,hoidaSIGSEGV);
  longjmp(paluuTila,SIGSEGV);
}
