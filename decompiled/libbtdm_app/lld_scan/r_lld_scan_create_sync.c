/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xd46,*(code **)(_r_plf_funcs_p + 8));
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

