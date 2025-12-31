/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_max_lat_calc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_max_lat_calc(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (*(short *)(iVar2 + 0x72) != 0) {
    uVar1 = (500000 - 0x8e300 / *(uint *)(iVar2 + 100)) /
            ((uint)*(ushort *)(_p_lld_env + 0xd4) + (uint)*(ushort *)(iVar2 + 0x7a)) - 1;
    if (*(uint *)(iVar2 + 0x68) <= *(uint *)(iVar2 + 100)) {
      r_assert_err(0,"lld_con.c",0x695);
    }
    uVar3 = *(uint *)(iVar2 + 0x68) / *(uint *)(iVar2 + 100) - 1;
    if (*(ushort *)(iVar2 + 0x72) < uVar3) {
      uVar3 = (uint)*(ushort *)(iVar2 + 0x72);
    }
    if (uVar1 < uVar3) {
      uVar3 = uVar1;
    }
    *(short *)(iVar2 + 0x72) = (short)uVar3;
    if (499 < uVar3) {
      r_assert_err(0,"lld_con.c",0x69d);
      return;
    }
  }
  return;
}

