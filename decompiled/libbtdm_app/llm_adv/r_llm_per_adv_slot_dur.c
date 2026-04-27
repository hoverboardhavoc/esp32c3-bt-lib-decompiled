/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_adv.o -> r_llm_per_adv_slot_dur
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_per_adv_slot_dur(uint param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0x672 < param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xcd0,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar1 = (param_1 / 0xf0 + 1 & 0xff) - 1;
  iVar2 = (**(code **)(_r_modules_funcs_p + 4))(0xff,*(code **)(_r_modules_funcs_p + 4));
  iVar3 = (**(code **)(_r_modules_funcs_p + 4))
                    ((param_1 + iVar1 * -0xf0 & 0xffff) + 1 & 0xff,param_2 + -1,
                     *(code **)(_r_modules_funcs_p + 4));
  return (uint)(iVar3 + 300 + (iVar2 + 300) * iVar1) / 0x271 + 1 & 0xff;
}

