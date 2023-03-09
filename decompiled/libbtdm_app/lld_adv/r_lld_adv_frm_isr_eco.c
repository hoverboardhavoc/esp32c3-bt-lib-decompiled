/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr_eco(int param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  
  if ((*(int *)(&lld_adv_env + param_1 * 4) != 0) && (param_3 == 0)) {
    pcVar1 = (char *)(**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
    if (*pcVar1 != '\0') {
      *(int *)(pcVar1 + 0xc) = *(int *)(pcVar1 + 0xc) + 1;
    }
  }
  r_lld_adv_frm_isr(param_1,param_2,param_3);
  return;
}

