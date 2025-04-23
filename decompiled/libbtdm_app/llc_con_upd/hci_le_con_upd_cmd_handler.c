/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_con_upd.o -> hci_le_con_upd_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_con_upd_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  byte bVar8;
  ushort uVar9;
  code *pcVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  
  iVar13 = param_1 * 4;
  iVar12 = *(int *)(&llc_env + iVar13);
  if (((iVar12 == 0) || (10 < *(ushort *)(param_2 + 2))) ||
     ((uVar4 = (**(code **)(_r_ip_funcs_p + 0x7c8))(*(code **)(_r_ip_funcs_p + 0x7c8)), uVar4 < 2 &&
      ((*(char *)(iVar12 + 0x1c) != '\x03' && (*(char *)(iVar12 + 0x1d) != '\x03')))))) {
    bVar11 = 0xc;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (param_1 < *(byte *)(iVar5 + 0xd)) {
      iVar5 = *(int *)(&llc_env + iVar13);
      if (((iVar5 != 0) && ((*(byte *)(iVar5 + 0x44) & 3) != 3)) &&
         (((iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
           param_1 < *(byte *)(iVar5 + 0xd) &&
           ((iVar5 = *(int *)(&llc_env + iVar13), iVar5 != 0 &&
            (((int)(uint)*(byte *)(iVar5 + 0x30) >> 1 & 1U) != 0)))) ||
          (bVar11 = 0x1a, (*(ushort *)(iVar12 + 0x42) & 1) != 0)))) {
        bVar11 = *(byte *)(iVar12 + 0x45) & 0x10;
        if ((*(byte *)(iVar12 + 0x45) & 0x10) == 0) {
          iVar5 = (**(code **)(_r_ip_funcs_p + 0x5e8))
                            (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                             *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                             *(code **)(_r_ip_funcs_p + 0x5e8));
          if (iVar5 == 0) {
            bVar11 = 0x12;
          }
          else {
            puVar6 = (undefined4 *)
                     (**(code **)(_r_modules_funcs_p + 200))
                               (0x10b,param_1 << 8 | 1,0x30,*(code **)(_r_modules_funcs_p + 200));
            *(undefined1 *)(puVar6 + 1) = 5;
            (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
            uVar1 = *(ushort *)(param_2 + 4);
            uVar7 = (uint)uVar1 << 1;
            *puVar6 = *(undefined4 *)(_r_ip_funcs_p + 0x5f8);
            uVar4 = (uint)*(ushort *)(param_2 + 0xc);
            if (uVar7 < *(ushort *)(param_2 + 0xc)) {
              uVar4 = uVar7;
            }
            uVar2 = *(ushort *)(param_2 + 2);
            *(short *)((int)puVar6 + 0x12) = (short)uVar4;
            uVar9 = *(ushort *)(param_2 + 10);
            uVar4 = (uint)uVar2 << 1;
            if (uVar4 < uVar9) {
              uVar9 = (ushort)uVar4;
            }
            *(ushort *)(puVar6 + 4) = uVar9;
            uVar3 = *(undefined2 *)(param_2 + 6);
            *(ushort *)(puVar6 + 2) = uVar2;
            *(ushort *)((int)puVar6 + 10) = uVar1;
            *(undefined2 *)(puVar6 + 3) = uVar3;
            *(undefined2 *)((int)puVar6 + 0xe) = *(undefined2 *)(param_2 + 8);
            iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
            bVar8 = 0;
            if ((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&llc_env + iVar13) != 0)) {
              bVar8 = (byte)((int)(uint)*(byte *)(*(int *)(&llc_env + iVar13) + 0x30) >> 1) & 1;
            }
            *(byte *)(puVar6 + 0xb) = bVar8 ^ 1;
            *(undefined1 *)((int)puVar6 + 0x2d) = 1;
            *(undefined1 *)((int)puVar6 + 0x2e) = 1;
            (**(code **)(_r_modules_funcs_p + 0xe0))(puVar6,*(code **)(_r_modules_funcs_p + 0xe0));
            *(byte *)(iVar12 + 0x45) = *(byte *)(iVar12 + 0x45) | 0x10;
          }
        }
        else {
          bVar11 = 0x3a;
        }
      }
    }
    pcVar10 = *(code **)(_r_ip_funcs_p + 0x634);
  }
  else {
    bVar11 = 0x12;
    pcVar10 = *(code **)(_r_ip_funcs_p + 0x634);
  }
  (*pcVar10)(param_1,param_3,bVar11,pcVar10);
  return 0;
}

