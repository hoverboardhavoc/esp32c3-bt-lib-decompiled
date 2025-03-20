/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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

