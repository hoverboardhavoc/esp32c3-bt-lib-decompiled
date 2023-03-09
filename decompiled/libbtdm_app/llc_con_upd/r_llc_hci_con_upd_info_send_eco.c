/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_hci_con_upd_info_send_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_con_upd_info_send_eco(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  (**(code **)(_r_ip_funcs_p + 2000))(*(code **)(_r_ip_funcs_p + 2000));
  if (((param_3 != 0) && (param_2 == 0)) &&
     ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0)) {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    *(ushort *)(param_3 + 0x12) = (ushort)*(byte *)(iVar1 + 0x10);
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    *(ushort *)(param_3 + 0x10) = (ushort)*(byte *)(iVar1 + 0x10);
  }
  r_llc_hci_con_upd_info_send(param_1,param_2,param_3);
  return;
}

