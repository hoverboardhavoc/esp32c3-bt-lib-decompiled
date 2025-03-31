/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app -> llc_encrypt.o -> ll_pause_enc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_pause_enc_rsp_handler(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x20) == '\0') {
    return 0x24;
  }
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if ((*(ushort *)(iVar2 + 0x42) & 1) != 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,param_2,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 == 3) {
      uVar3 = 1;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L166;
    }
    if ((*(ushort *)(iVar2 + 0x42) & 1) != 0) {
      return 0x24;
    }
  }
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar2 != 3) {
    return 0x24;
  }
  uVar3 = 0xb;
  pcVar4 = *(code **)(_r_ip_funcs_p + 0x59c);
_L166:
  (*pcVar4)(param_1,uVar3,0,pcVar4);
  return 0;
}

