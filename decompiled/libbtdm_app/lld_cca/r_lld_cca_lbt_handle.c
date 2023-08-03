/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_lbt_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_lbt_handle(int param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  
  pbVar4 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  if (((int)(uint)*(ushort *)(p_lld_cca + 4) >> 8 & 0xfU) == 2) {
    (**(code **)(_r_ip_funcs_p + 0x97c))(0);
    *pbVar4 = *pbVar4 & 0x7f;
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x97c))((int)*(char *)(p_lld_cca + 7));
  }
  if (*(ushort *)(p_lld_cca + 4) >> 0xc == 1) {
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    sVar2 = *(short *)(p_lld_cca + 0x10);
    sVar3 = *(short *)(p_lld_cca + 0x14);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar5 + (uint)bVar1 * 0x5a + 0x20) = sVar2 - sVar3;
  }
  uVar6 = (uint)rwip_prog_delay;
  *pbVar4 = *pbVar4 & 0xf5 | 0x41;
  *(uint *)(pbVar4 + 4) = (uVar6 - 1) + param_1;
  return;
}

