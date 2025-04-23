/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_set_tx_power
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_set_tx_power(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = (*_r_sch_slice_bg_remove)(param_2,param_1,_r_sch_slice_bg_remove);
  iVar2 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(param_1 * 0x5a + 0x18 + iVar2) = uVar1;
  return;
}

