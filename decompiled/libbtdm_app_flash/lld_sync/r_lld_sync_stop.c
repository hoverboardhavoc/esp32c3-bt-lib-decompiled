/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_sync_stop(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar2 = 0xc;
  }
  else {
    if (*(char *)(iVar1 + 0x5b) == '\0') {
      r_sch_arb_remove(0);
      r_lld_sync_cleanup(param_1,0);
    }
    else if (*(char *)(iVar1 + 0x5b) == '\x01') {
      *(undefined1 *)(iVar1 + 0x5b) = 2;
    }
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

