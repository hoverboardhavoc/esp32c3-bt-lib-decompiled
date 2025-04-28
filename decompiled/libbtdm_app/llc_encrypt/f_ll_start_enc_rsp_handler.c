/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> f_ll_start_enc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_ll_start_enc_rsp_handler(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(1);
    if (iVar1 == 3) {
      uVar2 = 0x10;
      pcVar3 = *(code **)(_r_ip_funcs_p + 0x59c);
_L203:
      (*pcVar3)(param_1,uVar2,0,pcVar3);
      return 0;
    }
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0);
    if (iVar1 == 3) {
      uVar2 = 8;
      pcVar3 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L203;
    }
  }
  return 0x24;
}

