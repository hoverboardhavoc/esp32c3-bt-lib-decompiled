/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_send_empty_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_send_empty_packet(int param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = p_lld_cca;
  if (param_1 == 0) {
    sVar2 = *(short *)(p_lld_cca + 0x18);
    if (sVar2 != 0) {
      bVar1 = *(byte *)(p_lld_cca + 0xd);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = p_lld_cca;
      *(short *)((uint)bVar1 * 0x5a + 0x1c + iVar3) = sVar2;
      *(undefined2 *)(iVar4 + 0x18) = 0;
    }
  }
  else {
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(iVar4 + 0x18) = *(undefined2 *)((uint)bVar1 * 0x5a + 0x1c + iVar3);
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)((uint)bVar1 * 0x5a + 0x1c + iVar4) = 0;
  }
  return;
}

