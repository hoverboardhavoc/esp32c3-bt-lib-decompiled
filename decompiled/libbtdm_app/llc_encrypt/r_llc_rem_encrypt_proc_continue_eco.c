/*
 * Last changed at upstream commit d7513ebe88d7d207f6c062ce9381d347a0a70918
 * https://github.com/espressif/esp32c3-bt-lib/commit/d7513ebe88d7d207f6c062ce9381d347a0a70918
 * Upstream date: 2023-05-05 21:49:57 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85b425c)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_rem_encrypt_proc_continue_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_encrypt_proc_continue_eco(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  
  uVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  puVar2 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(uVar1,*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar3 == param_2) {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(uVar1,*(code **)(_r_ip_funcs_p + 0x680));
    if ((iVar3 != 0x11) && (iVar3 != 0x12)) goto _L3;
  }
  *puVar2 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar2;
_L3:
  r_llc_rem_encrypt_proc_continue(param_1,param_2,param_3);
  return;
}

