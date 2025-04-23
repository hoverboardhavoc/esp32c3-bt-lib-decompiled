/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_feat_exch.o -> hci_le_rd_rem_feats_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_rem_feats_cmd_handler(uint param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(&llc_env + param_1 * 4);
  iVar5 = *piVar4;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  bVar1 = 0xc;
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    bVar1 = 0xc;
    if ((*piVar4 != 0) && ((*(byte *)(*piVar4 + 0x44) & 3) != 3)) {
      bVar1 = *(byte *)(iVar5 + 0x45) & 4;
      if ((*(byte *)(iVar5 + 0x45) & 4) == 0) {
        iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
        if ((((param_1 < *(byte *)(iVar2 + 0xd)) && (*piVar4 != 0)) &&
            (((int)(uint)*(byte *)(*piVar4 + 0x30) >> 3 & 1U) != 0)) ||
           ((*(ushort *)(iVar5 + 0x42) & 0x81) != 0)) {
          puVar3 = (undefined4 *)
                   (**(code **)(_r_modules_funcs_p + 200))
                             (0x107,param_1 << 8 | 1,0xc,*(code **)(_r_modules_funcs_p + 200));
          *(undefined1 *)(puVar3 + 1) = 4;
          (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
          *(undefined1 *)(puVar3 + 2) = 1;
          *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x5a8);
          (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
          *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 4;
        }
        else {
          bVar1 = 0x1a;
        }
      }
      else {
        bVar1 = 0x3a;
      }
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_2,bVar1,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

