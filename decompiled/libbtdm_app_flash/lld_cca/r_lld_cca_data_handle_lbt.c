/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_data_handle_lbt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
      if (((int)(uint)*(ushort *)(iVar2 + 4) >> 8 & 0xfU) == 2) {
        *pbVar3 = bVar4 | 0x88;
      }
    }
    else {
      r_lld_cca_set_thresh(0);
    }
    bVar4 = *pbVar3 & 0xbf;
  }
  *pbVar3 = bVar4;
  return;
}

