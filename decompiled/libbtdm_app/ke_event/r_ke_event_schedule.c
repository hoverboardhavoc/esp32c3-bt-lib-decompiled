/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> ke_event.o -> r_ke_event_schedule
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
      (**(code **)(_r_plf_funcs_p + 0xc))
                (uVar2,iVar1,"ke_event.c",0xbd,*(code **)(_r_plf_funcs_p + 0xc));
    }
    if (*(code **)(memset + uVar2 * 4) == (code *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"ke_event.c",0xc9,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      (**(code **)(memset + uVar2 * 4))();
    }
  }
  return;
}

