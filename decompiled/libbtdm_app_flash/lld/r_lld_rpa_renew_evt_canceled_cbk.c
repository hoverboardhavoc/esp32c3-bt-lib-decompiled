/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rpa_renew_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew_evt_canceled_cbk(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (_lld_rpa_renew_env == 0) {
    uVar2 = 0x49e;
  }
  else {
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    iVar1 = r_sch_arb_insert();
    if (iVar1 == 0) {
      return;
    }
    uVar2 = 0x499;
  }
  r_assert_err(0,"lld.c",uVar2);
  return;
}

