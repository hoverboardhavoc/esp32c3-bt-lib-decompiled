/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
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
  pbVar3 = (byte *)(param_2 * 0xc + *(int *)(p_lld_cca + 0x28));
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
      if (((int)(uint)*(ushort *)(iVar2 + 4) >> 8 & 0xfU) == 2) {
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

