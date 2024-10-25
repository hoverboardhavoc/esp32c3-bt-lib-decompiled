/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  undefined4 uVar2;
  int iVar3;
  
  if (_lld_scan_env != 0) {
    iVar3 = *(int *)(_lld_scan_env + param_1 * 4);
    if (iVar3 != 0) {
      uVar2 = r_lld_read_clock();
      if ((*(byte *)(_lld_scan_env + 0xc) & 3) == 3) {
        lld_scan_sched_optimize_part_0(iVar3,uVar2,param_3);
      }
    }
  }
  uVar1 = _rwip_priority;
  _rwip_priority = 0x9c4;
  r_lld_scan_try_sched(param_1,param_2,param_3);
  _rwip_priority = uVar1;
  if (_lld_scan_env != 0) {
    iVar3 = *(int *)(_lld_scan_env + param_1 * 4);
    if ((iVar3 != 0) && (*(uint *)(iVar3 + 0x24) == (uint)*(ushort *)(iVar3 + 0x32))) {
      (&_LANCHOR0)[param_1] = *(undefined4 *)(iVar3 + 4);
    }
  }
  return;
}

