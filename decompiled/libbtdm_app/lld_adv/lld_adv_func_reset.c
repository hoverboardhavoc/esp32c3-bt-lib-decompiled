/*
 * Last changed at upstream commit 3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * https://github.com/espressif/esp32c3-bt-lib/commit/3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * Upstream date: 2022-08-11 21:28:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f2e5d813)
 * Source: libbtdm_app -> lld_adv.o -> lld_adv_func_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_adv_func_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(code **)(_r_ip_funcs_p + 0x760) = r_lld_ext_adv_dynamic_aux_pti_process_hack;
  *(code **)(iVar1 + 0x774) = r_lld_adv_ext_chain_scannable_construct_hack;
  *(code **)(iVar1 + 0x1b8) = r_lld_adv_frm_isr_hack;
  *(undefined4 *)(iVar1 + 0x1e4) = 0x10000;
  return;
}

