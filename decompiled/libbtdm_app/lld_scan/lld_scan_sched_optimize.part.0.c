/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
 * Source: libbtdm_app -> lld_scan.o -> lld_scan_sched_optimize.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_scan_sched_optimize_part_0(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (&_LANCHOR0)[*(byte *)(param_1 + 0x40) + 1 & 1] - (uint)rwip_prog_delay & 0xfffffff;
  if (param_2 == -1) {
    uVar3 = (uVar3 - *(int *)(param_1 + 4)) * 0x10 >> 5;
    if (uVar3 < *(uint *)(param_1 + 0x24)) {
      *(uint *)(param_1 + 0x24) = uVar3;
      bVar1 = *(byte *)(param_1 + 0x38);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(short *)(iVar2 + (uint)bVar1 * 0x5a + 0x20) = (short)uVar3;
      return;
    }
  }
  else if ((((uint)rwip_prog_delay + param_2) - uVar3 & 0xfffffff) < 0x7ffffff) {
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  return;
}

