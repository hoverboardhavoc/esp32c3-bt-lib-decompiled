/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_trunc_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_trunc_ind(int param_1)

{
  void *__dest;
  int iVar1;
  
  iVar1 = *(int *)(_lld_scan_env + param_1 * 4);
  r_lld_ext_scan_dynamic_pti_process_eco(iVar1,2);
  __dest = (void *)r_ke_msg_alloc(0x201,0,0xff,0x2c);
  memcpy(__dest,(void *)(iVar1 + 0x58),0x2c);
  *(undefined1 *)((int)__dest + 0x16) = 2;
  *(undefined1 *)((int)__dest + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
  r_ke_msg_send(__dest);
  return;
}

