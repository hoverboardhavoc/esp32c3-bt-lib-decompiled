/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> lld_scan_sched_optimize
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_scan_sched_optimize(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(byte *)(_lld_scan_env + 0xc) & 3) == 3) {
    uVar3 = (&scan_anchor_point)[*(byte *)(param_1 + 0x40) + 1 & 1] - (uint)rwip_prog_delay &
            0xfffffff;
    if (param_2 == -1) {
      uVar3 = (uVar3 - *(int *)(param_1 + 4)) * 0x10 >> 5;
      if (uVar3 < *(uint *)(param_1 + 0x24)) {
        bVar1 = *(byte *)(param_1 + 0x38);
        *(uint *)(param_1 + 0x24) = uVar3;
        iVar2 = r_emi_get_mem_addr_by_offset(0x400);
        *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar2) = (short)uVar3;
        return;
      }
    }
    else if (((param_2 + (uint)rwip_prog_delay) - uVar3 & 0xfffffff) < 0x7ffffff) {
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
  }
  return;
}

