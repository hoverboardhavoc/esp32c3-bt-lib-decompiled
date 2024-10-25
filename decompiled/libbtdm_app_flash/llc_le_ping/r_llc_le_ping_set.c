/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> r_llc_le_ping_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_le_ping_set(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  if (iVar5 == 0) {
    r_assert_param("llc_le_ping.c",0x27e);
    uVar1 = 0xc;
  }
  else {
    uVar6 = param_2 << 4;
    iVar2 = (*(ushort *)(iVar5 + 0x10) + 1) * (uint)*(ushort *)(iVar5 + 0xe);
    uVar1 = 0x12;
    uVar4 = iVar2 * 2;
    if (uVar4 <= uVar6) {
      uVar3 = iVar2 * 8;
      if (uVar6 < uVar3) {
        uVar3 = uVar4 * (uVar6 / uVar4);
      }
      uVar3 = uVar3 >> 4;
      if (uVar3 == 0) {
        uVar3 = 1;
      }
      uVar1 = 0x11;
      if (param_2 != uVar3) {
        *(short *)(iVar5 + 0x3e) = (short)param_2;
        *(short *)(iVar5 + 0x40) = (short)param_2 - (short)uVar3;
        r_llc_le_ping_restart(param_1);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

