/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_create_sync
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
    r_assert_err(0,"lld_scan.c",0xce4);
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  puVar1 = (undefined1 *)r_ke_malloc(10,0);
  _lld_scan_sync_env = puVar1;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  puVar1[3] = param_4;
  memcpy(puVar1 + 4,&uStack_28,6);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return 0;
}

