/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_idle_mode_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_idle_mode_handle(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 != 0) {
    return;
  }
  uVar5 = (uint)*(ushort *)(p_lld_cca + 0xe);
  if (*(ushort *)(p_lld_cca + 0x10) < uVar5) {
    uVar2 = *(ushort *)(p_lld_cca + 4) >> 0xc;
    if (uVar2 == 1) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      sVar3 = *(ushort *)(p_lld_cca + 0x10) - *(short *)(p_lld_cca + 0x14);
    }
    else {
      if (uVar2 != 2) {
        return;
      }
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      sVar3 = (short)(((uVar5 - *(ushort *)(p_lld_cca + 0x14)) + (int)uVar5 / -0x14) * 0x10000 >>
                     0x10);
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar4 + (uint)bVar1 * 0x5a + 0x20) = sVar3;
    return;
  }
  return;
}

