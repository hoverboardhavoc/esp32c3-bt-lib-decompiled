/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_aa_gen
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
  *param_1 = (&LLM_AA_CT2)[DAT_00014096] << 4 | aa_gen & 0xf | bVar1;
  param_1[1] = (&LLM_AA_CT2)[DAT_00014096] << 4 | aa_gen >> 4;
  param_1[2] = (&LLM_AA_CT2)[DAT_00014096] << 4 | param_2 & 0xf;
  DAT_00014096 = DAT_00014096 + 1 & 1;
  param_1[3] = (&LLM_AA_CT1)[DAT_00014095] << 4 | (byte)((uVar2 & 0xff) >> 4) | bVar1;
  aa_gen = aa_gen + 1;
  DAT_00014095 = (char)((DAT_00014095 + 1) % 3);
  return;
}

