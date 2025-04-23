/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> r_llm_is_non_con_act_ongoing_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_is_non_con_act_ongoing_check(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar2 + 0xd) <= uVar1) {
      return 0;
    }
    uVar3 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40);
    if ((uVar3 < 0xf) && (uVar3 = 0x40acU >> (uVar3 & 0x1f) & 1, uVar3 != 0)) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return uVar3;
}

