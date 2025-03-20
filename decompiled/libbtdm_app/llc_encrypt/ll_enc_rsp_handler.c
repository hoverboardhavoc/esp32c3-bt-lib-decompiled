/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> llc_encrypt.o -> ll_enc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_enc_rsp_handler(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x20) == '\0') {
    return 0x24;
  }
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(1,param_3);
    if (iVar1 == 3) {
      uVar3 = 0x3d;
      uVar2 = 0x13;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x59c);
_L171:
      (*pcVar4)(param_1,uVar2,uVar3,pcVar4);
      return 0;
    }
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,param_3);
    if (iVar1 == 3) {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
      memcpy((void *)(iVar1 + 0x24),(void *)(param_2 + 9),4);
      memcpy((void *)(iVar1 + 0x30),(void *)(param_2 + 1),8);
      uVar3 = 0;
      uVar2 = 4;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L171;
    }
  }
  return 0x24;
}

