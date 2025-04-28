/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> f_ll_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_ll_enc_req_handler(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(1);
    uVar3 = 0xc;
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x109,1,1,0x3c,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar2 + 1) = 3;
      uVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x5a0);
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x67c);
      *(undefined1 *)((int)puVar2 + 0x3a) = 0;
      *puVar2 = uVar3;
      (*pcVar5)(param_1,1,puVar2,pcVar5);
      uVar3 = 10;
      (**(code **)(_r_ip_funcs_p + 0x684))(puVar2,param_1,10,*(code **)(_r_ip_funcs_p + 0x684));
    }
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 == 3) {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,*(code **)(_r_ip_funcs_p + 0x674));
      *(undefined2 *)(iVar1 + 0x38) = *(undefined2 *)(param_2 + 10);
      memcpy((void *)(iVar1 + 0x20),(void *)(param_2 + 0x14),4);
      memcpy((void *)(iVar1 + 0x28),(void *)(param_2 + 0xc),8);
      memcpy((void *)(iVar1 + 8),(void *)(param_2 + 1),8);
      uVar4 = 0;
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x59c);
      goto _L173;
    }
  }
  else {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0);
    if (iVar1 == 3) {
      uVar4 = 0x3d;
      uVar3 = 9;
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x594);
_L173:
      (*pcVar5)(param_1,uVar3,uVar4,pcVar5);
      return 0;
    }
  }
  return 0x24;
}

