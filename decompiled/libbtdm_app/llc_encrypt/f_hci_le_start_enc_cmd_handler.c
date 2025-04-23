/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> f_hci_le_start_enc_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_start_enc_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  piVar2 = (int *)(&llc_env + param_1 * 4);
  iVar5 = *piVar2;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  bVar1 = 0xc;
  if (param_1 < *(byte *)(iVar3 + 0xd)) {
    bVar1 = 0xc;
    if (((*piVar2 != 0) && ((*(byte *)(*piVar2 + 0x44) & 3) != 3)) &&
       ((*(ushort *)(iVar5 + 0x42) & 1) != 0)) {
      bVar1 = 0x1a;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*piVar2 != 0)) &&
         ((*(byte *)(*piVar2 + 0x30) & 1) != 0)) {
        bVar1 = *(byte *)(iVar5 + 0x45) & 8;
        if ((*(byte *)(iVar5 + 0x45) & 8) == 0) {
          puVar4 = (undefined4 *)
                   (**(code **)(_r_modules_funcs_p + 200))
                             (0x109,param_1 << 8 | 1,0x3c,*(code **)(_r_modules_funcs_p + 200));
          iVar3 = _r_ip_funcs_p;
          *(undefined1 *)(puVar4 + 1) = 3;
          (**(code **)(iVar3 + 0x684))(param_1,0,*(code **)(iVar3 + 0x684));
          *puVar4 = *(undefined4 *)(_r_ip_funcs_p + 0x598);
          memcpy(puVar4 + 2,(void *)(param_2 + 2),8);
          *(undefined2 *)(puVar4 + 0xe) = *(undefined2 *)(param_2 + 10);
          memcpy(puVar4 + 4,(void *)(param_2 + 0xc),0x10);
          *(byte *)((int)puVar4 + 0x3a) = (byte)((int)(uint)*(ushort *)(iVar5 + 0x42) >> 5) & 1;
          (**(code **)(_r_modules_funcs_p + 0xe0))(puVar4,*(code **)(_r_modules_funcs_p + 0xe0));
          *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 8;
        }
        else {
          bVar1 = 0x3a;
        }
      }
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,bVar1,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

