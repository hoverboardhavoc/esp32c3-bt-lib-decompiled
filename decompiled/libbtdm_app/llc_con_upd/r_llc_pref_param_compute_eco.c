/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_pref_param_compute_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_pref_param_compute_eco(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((*(uint *)(param_2 + 0x2c) & 0xffff00) != 0) {
    uVar1 = (**(code **)(_r_ip_funcs_p + 0x7c8))(*(code **)(_r_ip_funcs_p + 0x7c8));
    if (uVar1 < 2) {
      if (*(short *)(param_2 + 0x16) != -1) {
        iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(param_2,*(code **)(_r_ip_funcs_p + 0x680));
        if (iVar2 == 2) {
          *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_2 + 0x16);
          *(undefined2 *)(param_2 + 0x28) = *(undefined2 *)(param_2 + 8);
          return;
        }
      }
    }
  }
  r_llc_pref_param_compute(param_1);
  return;
}

