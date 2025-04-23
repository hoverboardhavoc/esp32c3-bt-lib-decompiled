/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_le_ping.o -> r_llc_le_ping_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llc_le_ping_set(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  if (iVar4 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc_le_ping.c",0x27e,*(code **)(_r_plf_funcs_p + 0xc));
    uVar1 = 0xc;
  }
  else {
    uVar3 = param_2 << 4;
    iVar5 = (*(ushort *)(iVar4 + 0x10) + 1) * (uint)*(ushort *)(iVar4 + 0xe);
    uVar1 = 0x12;
    uVar2 = iVar5 * 2;
    if (uVar2 <= uVar3) {
      uVar6 = iVar5 * 8;
      if (uVar3 < uVar6) {
        uVar6 = uVar2 * (uVar3 / uVar2);
      }
      uVar6 = uVar6 >> 4;
      if (uVar6 == 0) {
        uVar6 = 1;
      }
      uVar1 = 0x11;
      if (param_2 != uVar6) {
        *(short *)(iVar4 + 0x3e) = (short)param_2;
        iVar5 = _r_ip_funcs_p;
        *(short *)(iVar4 + 0x40) = (short)param_2 - (short)uVar6;
        (**(code **)(iVar5 + 0x610))(param_1,*(code **)(iVar5 + 0x610));
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

