/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_sw_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_sw_handle(int param_1,uint param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte bVar4;
  
  if ((byte)ble_2_rf_chan_tab[*(byte *)(p_lld_cca + 8)] == param_2) {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    iVar1 = p_lld_cca;
    pbVar2 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
    if ((0x7fffffe < (iVar3 - *(int *)(pbVar2 + 4) & 0xfffffffU)) && (param_3 == 0)) {
      pbVar2[1] = (byte)param_1;
      iVar3 = (int)*(char *)(iVar1 + 7);
      if ((*(ushort *)(iVar1 + 4) & 0x10) == 0) {
        if (iVar3 < param_1) {
          (**(code **)(_r_ip_funcs_p + 0x97c))(0xffffff88,*(code **)(_r_ip_funcs_p + 0x97c));
          *pbVar2 = *pbVar2 | 0x20;
          iVar1 = p_lld_cca;
          pbVar2[8] = pbVar2[8] + 1;
          if ((*(ushort *)(iVar1 + 4) & 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010c44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**(code **)(_r_ip_funcs_p + 0x9a0))(pbVar2);
            return;
          }
        }
        else {
          pbVar2[8] = 0;
          *pbVar2 = *pbVar2 & 0xdf;
        }
      }
      else {
        if (iVar3 < param_1) {
          (**(code **)(_r_ip_funcs_p + 0x994))(1);
          bVar4 = *pbVar2 | 8;
        }
        else {
          (**(code **)(_r_ip_funcs_p + 0x994))(0);
          bVar4 = *pbVar2 & 0xf5;
        }
        *pbVar2 = bVar4;
      }
    }
  }
  return;
}

