/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> llc_encrypt.o -> ll_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_enc_req_handler(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x20) == '\0') {
    return 0x24;
  }
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(1,param_3);
    uVar3 = 0xc;
    if (iVar2 == 0) {
      puVar1 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x109,1,1,0x3c,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar1 + 1) = 3;
      uVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x5a0);
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x67c);
      *(undefined1 *)((int)puVar1 + 0x3a) = 0;
      *puVar1 = uVar3;
      (*pcVar5)(param_1,1,puVar1,pcVar5);
      uVar3 = 10;
      (**(code **)(_r_ip_funcs_p + 0x684))(puVar1,param_1,10,*(code **)(_r_ip_funcs_p + 0x684));
    }
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar2 == 3) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,*(code **)(_r_ip_funcs_p + 0x674));
      *(undefined2 *)(iVar2 + 0x38) = *(undefined2 *)(param_2 + 10);
      memcpy((void *)(iVar2 + 0x20),(void *)(param_2 + 0x14),4);
      memcpy((void *)(iVar2 + 0x28),(void *)(param_2 + 0xc),8);
      memcpy((void *)(iVar2 + 8),(void *)(param_2 + 1),8);
      uVar4 = 0;
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x59c);
      goto _L161;
    }
  }
  else {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(0,param_3);
    if (iVar2 == 3) {
      uVar4 = 0x3d;
      uVar3 = 9;
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x594);
_L161:
      (*pcVar5)(param_1,uVar3,uVar4,pcVar5);
      return 0;
    }
  }
  return 0x24;
}

