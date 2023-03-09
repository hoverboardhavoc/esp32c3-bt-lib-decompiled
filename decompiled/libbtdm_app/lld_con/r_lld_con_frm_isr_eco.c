/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_isr_eco(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x7dc))
                    ((int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_1 * 4) + 0x84) >> 8 & 1,
                     *(code **)(_r_ip_funcs_p + 0x7dc));
  if (iVar1 == 0) {
    r_lld_con_frm_isr(param_1,param_2,param_3);
    return;
  }
  return;
}

