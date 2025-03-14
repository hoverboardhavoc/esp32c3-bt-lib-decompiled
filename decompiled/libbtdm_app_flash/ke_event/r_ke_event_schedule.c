/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> ke_event.o -> r_ke_event_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_event_schedule(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  while (iVar1 = _ke_event_env, _ke_event_env != 0) {
    iVar3 = __clzsi2(_ke_event_env);
    uVar2 = 0x1fU - iVar3 & 0xff;
    if (0xe < uVar2) {
      r_assert_param(uVar2,iVar1,"ke_event.c",0xba);
    }
    if (*(code **)(memset + uVar2 * 4) == (code *)0x0) {
      r_assert_err(0,"ke_event.c",0xc6);
    }
    else {
      (**(code **)(memset + uVar2 * 4))();
    }
  }
  return;
}

