/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_scan.o -> lld_scan_sched_optimize.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void lld_scan_sched_optimize_part_0(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (&_LANCHOR0)[*(byte *)(param_1 + 0x40) + 1 & 1] - (uint)rwip_prog_delay & 0xfffffff;
  if (param_2 == -1) {
    uVar3 = (uVar3 - *(int *)(param_1 + 4)) * 0x10 >> 5;
    if (uVar3 < *(uint *)(param_1 + 0x24)) {
      bVar1 = *(byte *)(param_1 + 0x38);
      *(uint *)(param_1 + 0x24) = uVar3;
      iVar2 = r_emi_get_mem_addr_by_offset(0x400);
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

