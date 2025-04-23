/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> f_ll_pause_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_ll_pause_enc_req_handler(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) &&
     (iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(1,*(code **)(_r_ip_funcs_p + 0x678)), iVar1 == 0)
     ) {
    puVar2 = (undefined4 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x109,1,0x3c,*(code **)(_r_modules_funcs_p + 200));
    *(undefined1 *)(puVar2 + 1) = 3;
    (**(code **)(_r_ip_funcs_p + 0x684))(param_1,10,*(code **)(_r_ip_funcs_p + 0x684));
    uVar4 = *(undefined4 *)(_r_ip_funcs_p + 0x5a0);
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x67c);
    *(undefined1 *)((int)puVar2 + 0x3a) = 1;
    *puVar2 = uVar4;
    (*pcVar3)(param_1,puVar2,pcVar3);
    (**(code **)(_r_ip_funcs_p + 0x59c))(param_1,10,0,*(code **)(_r_ip_funcs_p + 0x59c));
    uVar4 = 0;
  }
  else {
    uVar4 = 0x24;
  }
  return uVar4;
}

