/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_create_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_scan_create_sync
          (undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
          undefined4 param_5,undefined4 param_6)

{
  undefined1 *puVar1;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = param_5;
  uStack_24 = param_6;
  if (_lld_scan_sync_env != (undefined1 *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xcd7,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 0x120))(10,0,*(code **)(_r_modules_funcs_p + 0x120));
  _lld_scan_sync_env = puVar1;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  puVar1[3] = param_4;
  memcpy(puVar1 + 4,&uStack_28,6);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return 0;
}

