/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app -> llc_encrypt.o -> f_ll_start_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_ll_start_enc_req_handler(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(1);
    if (iVar1 == 3) {
      uVar3 = 0x3d;
      uVar2 = 0x13;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x59c);
_L198:
      (*pcVar4)(param_1,uVar2,uVar3,pcVar4);
      return 0;
    }
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0);
    if (iVar1 == 3) {
      uVar3 = 0;
      uVar2 = 5;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L198;
    }
  }
  return 0x24;
}

