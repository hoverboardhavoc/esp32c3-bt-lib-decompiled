/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_data_handle_lbt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_data_handle_lbt(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  
  iVar2 = p_lld_cca;
  pbVar3 = (byte *)(*(int *)(p_lld_cca + 0x28) + param_2 * 0xc);
  bVar4 = *pbVar3;
  if ((bVar4 & 8) != 0) {
    return;
  }
  pbVar3[1] = (byte)param_1;
  if ((bVar4 & 0x40) == 0) {
    uVar1 = *(ushort *)(iVar2 + 4) >> 0xc;
    if (uVar1 == 3) {
      if (param_1 <= *(char *)(iVar2 + 7)) {
        *(undefined4 *)(pbVar3 + 4) = param_3;
        return;
      }
      bVar4 = bVar4 | 10;
    }
    else {
      if (uVar1 != 4) {
        return;
      }
      bVar4 = bVar4 & 0xfd | (*(char *)(iVar2 + 7) < param_1) << 1;
    }
  }
  else {
    if (*(char *)(iVar2 + 7) < param_1) {
      *pbVar3 = bVar4 | 8;
      if ((*(ushort *)(iVar2 + 4) & 0xf00) == 0x200) {
        *pbVar3 = bVar4 | 0x88;
      }
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x97c))(0,*(code **)(_r_ip_funcs_p + 0x97c));
    }
    bVar4 = *pbVar3 & 0xbf;
  }
  *pbVar3 = bVar4;
  return;
}

