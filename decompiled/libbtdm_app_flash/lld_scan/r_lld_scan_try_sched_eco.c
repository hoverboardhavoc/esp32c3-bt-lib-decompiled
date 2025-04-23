/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_try_sched_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_try_sched_eco(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (_lld_scan_env != 0) {
    iVar2 = *(int *)(_lld_scan_env + param_1 * 4);
    if (iVar2 != 0) {
      uVar3 = r_lld_read_clock();
      lld_scan_sched_optimize(iVar2,uVar3);
    }
  }
  uVar1 = _rwip_priority;
  _rwip_priority = 0x9c4;
  r_lld_scan_try_sched(param_1,param_2,param_3);
  _rwip_priority = uVar1;
  if (_lld_scan_env != 0) {
    iVar2 = *(int *)(_lld_scan_env + param_1 * 4);
    if ((iVar2 != 0) && (*(uint *)(iVar2 + 0x24) == (uint)*(ushort *)(iVar2 + 0x32))) {
      (&scan_anchor_point)[param_1] = *(undefined4 *)(iVar2 + 4);
    }
  }
  return;
}

