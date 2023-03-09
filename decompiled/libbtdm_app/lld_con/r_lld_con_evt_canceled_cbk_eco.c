/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_canceled_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_canceled_cbk_eco(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  r_lld_con_evt_canceled_cbk();
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x7c8))(*(code **)(_r_ip_funcs_p + 0x7c8));
  if ((1 < uVar3) && (0x1900 < (uint)(iVar1 - *(int *)(iVar2 + 0x50)))) {
    (**(code **)(_r_ip_funcs_p + 0x7cc))(*(code **)(_r_ip_funcs_p + 0x7cc));
    (**(code **)(_r_ip_funcs_p + 0x8f8))
              (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x8f8));
    *(int *)(iVar2 + 0x50) = iVar1;
  }
  return;
}

