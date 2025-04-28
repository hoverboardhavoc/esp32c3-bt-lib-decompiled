/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> r_llc_le_ping_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_le_ping_set(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (iVar3 == 0) {
    r_assert_param("llc_le_ping.c",0x27e);
    uVar1 = 0xc;
  }
  else {
    uVar4 = param_2 << 4;
    iVar5 = (*(ushort *)(iVar3 + 0x10) + 1) * (uint)*(ushort *)(iVar3 + 0xe);
    uVar1 = 0x12;
    uVar2 = iVar5 * 2;
    if (uVar2 <= uVar4) {
      uVar6 = iVar5 * 8;
      if (uVar4 < uVar6) {
        uVar6 = uVar2 * (uVar4 / uVar2);
      }
      uVar6 = uVar6 >> 4;
      if (uVar6 == 0) {
        uVar6 = 1;
      }
      uVar1 = 0x11;
      if (uVar6 != param_2) {
        *(short *)(iVar3 + 0x3e) = (short)param_2;
        *(short *)(iVar3 + 0x40) = (short)param_2 - (short)uVar6;
        r_llc_le_ping_restart(param_1);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

