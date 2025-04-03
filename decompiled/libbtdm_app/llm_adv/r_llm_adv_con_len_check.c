/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> llm_adv.o -> r_llm_adv_con_len_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_adv_con_len_check(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xc17,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((*(ushort *)(param_1 + 2) & 1) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xc18,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar2 = 6;
  if ((*(ushort *)(param_1 + 2) & 4) != 0) {
    iVar2 = 0xc;
  }
  iVar3 = iVar2 + 3;
  if ((*(ushort *)(param_1 + 2) & 0x40) == 0) {
    iVar3 = iVar2 + 2;
  }
  uVar1 = 0;
  if (0xfe < iVar3 + 1 + param_2) {
    uVar1 = 0x12;
  }
  return uVar1;
}

