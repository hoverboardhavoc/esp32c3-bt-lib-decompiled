/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> r_llm_adv_con_len_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte r_llm_adv_con_len_check(int param_1,int param_2)

{
  if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xc17,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((*(ushort *)(param_1 + 2) & 1) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xc18,*(code **)(_r_plf_funcs_p + 8));
  }
  return -(0xfe < (int)((uint)((*(ushort *)(param_1 + 2) & 0x40) != 0) +
                        ((int)((uint)*(ushort *)(param_1 + 2) << 0x1d) >> 0x1f & 6U) + 9 + param_2))
         & 0x12;
}

