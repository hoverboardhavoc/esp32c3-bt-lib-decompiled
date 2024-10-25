/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_avl_timeout_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_chan_avl_timeout_check(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  
  pbVar1 = (byte *)(param_1 * 0xc + *(int *)(p_lld_cca + 0x28));
  if (((*pbVar1 & 1) != 0) &&
     (((uint)*(ushort *)(p_lld_cca + 0x10) - (uint)*(ushort *)(p_lld_cca + 0x14)) * 2 <
      (param_2 - *(int *)(pbVar1 + 4) & 0xfffffffU))) {
    if ((*(ushort *)(p_lld_cca + 4) & 1) != 0) {
      r_lld_cca_chan_rssi_cal(pbVar1);
    }
    if ((*pbVar1 & 2) == 0) {
      if (*(ushort *)(p_lld_cca + 4) >> 0xc == 4) {
        (**(code **)(_r_osi_funcs_p + 0xe0))(0x50,*(code **)(_r_osi_funcs_p + 0xe0));
        r_lld_cca_force_tx(1);
        *pbVar1 = *pbVar1 | 0x10;
        return;
      }
      *(int *)(pbVar1 + 4) = param_2;
      bVar2 = *pbVar1 & 0xf7;
    }
    else {
      r_lld_cca_force_tx(1);
      bVar2 = *pbVar1 | 0x10;
    }
    *pbVar1 = bVar2;
  }
  return;
}

