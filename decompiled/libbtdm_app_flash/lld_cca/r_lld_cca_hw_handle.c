/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_hw_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_hw_handle(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  
  uVar4 = (uint)(byte)rf_2_ble_chan_tab[param_2];
  if (*(byte *)(p_lld_cca + 8) == uVar4) {
    iVar5 = r_lld_read_clock();
    iVar1 = p_lld_cca;
    if ((*(ushort *)(p_lld_cca + 4) & 0x10) == 0) {
      r_lld_cca_data_handle_daa(param_1,uVar4);
    }
    else {
      r_lld_cca_data_handle_lbt(param_1,uVar4,iVar5);
      r_lld_cca_scst_timeout_check(uVar4,iVar5);
    }
    iVar2 = p_lld_cca;
    if (*(ushort *)(iVar1 + 0x10) < *(ushort *)(iVar1 + 0xe)) {
      pbVar3 = (byte *)(*(int *)(p_lld_cca + 0x28) + uVar4 * 0xc);
      if (((*pbVar3 & 1) != 0) &&
         (((uint)*(ushort *)(p_lld_cca + 0x10) - (uint)*(ushort *)(p_lld_cca + 0x14)) * 2 <
          (iVar5 - *(int *)(pbVar3 + 4) & 0xfffffffU))) {
        if ((*(ushort *)(p_lld_cca + 4) & 1) != 0) {
          r_lld_cca_chan_rssi_cal(pbVar3);
        }
        if ((*pbVar3 & 2) == 0) {
          if (*(ushort *)(iVar2 + 4) >> 0xc == 4) {
            (**(code **)(_r_osi_funcs_p + 0xe0))(0x50,*(code **)(_r_osi_funcs_p + 0xe0));
            r_lld_cca_force_tx(1);
            *pbVar3 = *pbVar3 | 0x10;
            return;
          }
          *(int *)(pbVar3 + 4) = iVar5;
          bVar6 = *pbVar3 & 0xf7;
        }
        else {
          r_lld_cca_force_tx(1);
          bVar6 = *pbVar3 | 0x10;
        }
        *pbVar3 = bVar6;
      }
      return;
    }
  }
  return;
}

