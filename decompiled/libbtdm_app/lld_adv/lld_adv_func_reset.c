/*
 * Last changed at upstream commit 86145c184578f9061d2d0efb30fefa20a91a75e9
 * https://github.com/espressif/esp32c3-bt-lib/commit/86145c184578f9061d2d0efb30fefa20a91a75e9
 * Upstream date: 2021-12-17 19:26:32 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(68818697)
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
  return;
}

