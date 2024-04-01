#ifndef _SYS_INTERRUPTS_H
#define _SYS_INTERRUPTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>


struct InterruptAPI
{
  int (*MaskInterrupt)(int irq);
  int (*UnmaskInterrupt)(int irq);
  int (*EventNotifyFromISR)(struct InterruptAPI *api, int hint);

  void *context;
};


#ifdef __cplusplus
}
#endif 
#endif
