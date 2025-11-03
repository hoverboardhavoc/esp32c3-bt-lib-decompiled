/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_adv_con_len_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llm_adv_con_len_check(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
    r_assert_err(0,"llm_adv.c",0xcae);
  }
  if ((*(ushort *)(param_1 + 2) & 1) == 0) {
    r_assert_err(0,"llm_adv.c",0xcaf);
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

