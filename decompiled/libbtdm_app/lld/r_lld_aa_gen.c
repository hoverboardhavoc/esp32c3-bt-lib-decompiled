/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> r_lld_aa_gen
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_aa_gen(byte *param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  bVar1 = (byte)(1 << (uVar2 & 3));
  *param_1 = (&LLM_AA_CT2)[DAT_0001403e] << 4 | aa_gen & 0xf | bVar1;
  param_1[1] = (&LLM_AA_CT2)[DAT_0001403e] << 4 | aa_gen >> 4;
  aa_gen = aa_gen + 1;
  param_1[2] = (&LLM_AA_CT2)[DAT_0001403e] << 4 | param_2 & 0xf;
  param_1[3] = bVar1 | (byte)((uVar2 & 0xff) >> 4) | (&LLM_AA_CT1)[DAT_0001403d] << 4;
  DAT_0001403e = DAT_0001403e + 1 & 1;
  DAT_0001403d = (char)((DAT_0001403d + 1) % 3);
  return;
}

