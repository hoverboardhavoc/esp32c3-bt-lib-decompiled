/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_id_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 r_llc_proc_id_get(int param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param("llc.c",0x1fb);
  }
  iVar1 = *(int *)(iVar1 + param_2 * 4);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined1 *)(iVar1 + 4);
  }
  return uVar2;
}

