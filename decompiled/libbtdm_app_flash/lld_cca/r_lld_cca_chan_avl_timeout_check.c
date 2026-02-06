/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chan_avl_timeout_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_chan_avl_timeout_check(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  
  iVar1 = p_lld_cca;
  pbVar2 = (byte *)(*(int *)(p_lld_cca + 0x28) + param_1 * 0xc);
  if (((*pbVar2 & 1) != 0) &&
     (((uint)*(ushort *)(p_lld_cca + 0x10) - (uint)*(ushort *)(p_lld_cca + 0x14)) * 2 <
      (param_2 - *(int *)(pbVar2 + 4) & 0xfffffffU))) {
    if ((*(ushort *)(p_lld_cca + 4) & 1) != 0) {
      r_lld_cca_chan_rssi_cal(pbVar2);
    }
    if ((*pbVar2 & 2) == 0) {
      if (*(ushort *)(iVar1 + 4) >> 0xc == 4) {
        (**(code **)(_r_osi_funcs_p + 0xe4))(0x50,*(code **)(_r_osi_funcs_p + 0xe4));
        r_lld_cca_force_tx(1);
        *pbVar2 = *pbVar2 | 0x10;
        return;
      }
      *(int *)(pbVar2 + 4) = param_2;
      bVar3 = *pbVar2 & 0xf7;
    }
    else {
      r_lld_cca_force_tx(1);
      bVar3 = *pbVar2 | 0x10;
    }
    *pbVar2 = bVar3;
  }
  return;
}

