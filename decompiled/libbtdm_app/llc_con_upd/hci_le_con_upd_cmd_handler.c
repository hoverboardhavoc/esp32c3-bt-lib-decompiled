/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  undefined4 uVar7;
  uint uVar8;
  byte bVar9;
  ushort uVar10;
  code *pcVar11;
  int iVar12;
  int iVar13;
  
  iVar13 = param_1 * 4;
  iVar12 = *(int *)(&llc_env + iVar13);
  if (((iVar12 == 0) || (10 < *(ushort *)(param_2 + 2))) ||
     ((uVar4 = (**(code **)(_r_ip_funcs_p + 0x7c8))(*(code **)(_r_ip_funcs_p + 0x7c8)), uVar4 < 2 &&
      ((*(char *)(iVar12 + 0x1c) != '\x03' && (*(char *)(iVar12 + 0x1d) != '\x03')))))) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    uVar7 = 0xc;
    if (param_1 < *(byte *)(iVar5 + 0xd)) {
      iVar5 = *(int *)(&llc_env + iVar13);
      if ((((iVar5 != 0) && ((*(byte *)(iVar5 + 0x44) & 3) != 3)) &&
          (((iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(0xc,*(code **)(_r_plf_funcs_p + 0x38)),
            param_1 < *(byte *)(iVar5 + 0xd) &&
            ((iVar5 = *(int *)(&llc_env + iVar13), iVar5 != 0 &&
             (((int)(uint)*(byte *)(iVar5 + 0x30) >> 1 & 1U) != 0)))) ||
           (uVar7 = 0x1a, (*(ushort *)(iVar12 + 0x42) & 1) != 0)))) &&
         (uVar7 = 0x3a, (*(byte *)(iVar12 + 0x45) & 0x10) == 0)) {
        iVar5 = (**(code **)(_r_ip_funcs_p + 0x5e8))
                          (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                           *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                           *(code **)(_r_ip_funcs_p + 0x5e8));
        uVar7 = 0x12;
        if (iVar5 != 0) {
          puVar6 = (undefined4 *)
                   (**(code **)(_r_modules_funcs_p + 200))
                             (0x10b,param_1 << 8 | 1,0x30,*(code **)(_r_modules_funcs_p + 200));
          *(undefined1 *)(puVar6 + 1) = 5;
          (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
          uVar1 = *(ushort *)(param_2 + 4);
          uVar8 = (uint)uVar1 << 1;
          *puVar6 = *(undefined4 *)(_r_ip_funcs_p + 0x5f8);
          uVar4 = (uint)*(ushort *)(param_2 + 0xc);
          if (uVar8 < *(ushort *)(param_2 + 0xc)) {
            uVar4 = uVar8;
          }
          uVar2 = *(ushort *)(param_2 + 2);
          *(short *)((int)puVar6 + 0x12) = (short)uVar4;
          uVar10 = *(ushort *)(param_2 + 10);
          uVar4 = (uint)uVar2 << 1;
          if (uVar4 < uVar10) {
            uVar10 = (ushort)uVar4;
          }
          *(ushort *)(puVar6 + 4) = uVar10;
          uVar3 = *(undefined2 *)(param_2 + 6);
          *(ushort *)(puVar6 + 2) = uVar2;
          *(ushort *)((int)puVar6 + 10) = uVar1;
          *(undefined2 *)(puVar6 + 3) = uVar3;
          *(undefined2 *)((int)puVar6 + 0xe) = *(undefined2 *)(param_2 + 8);
          iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          bVar9 = 0;
          if ((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&llc_env + iVar13) != 0)) {
            bVar9 = (byte)((int)(uint)*(byte *)(*(int *)(&llc_env + iVar13) + 0x30) >> 1) & 1;
          }
          *(byte *)(puVar6 + 0xb) = bVar9 ^ 1;
          *(undefined1 *)((int)puVar6 + 0x2d) = 1;
          *(undefined1 *)((int)puVar6 + 0x2e) = 1;
          (**(code **)(_r_modules_funcs_p + 0xe0))(puVar6,*(code **)(_r_modules_funcs_p + 0xe0));
          uVar7 = 0;
          *(byte *)(iVar12 + 0x45) = *(byte *)(iVar12 + 0x45) | 0x10;
        }
      }
    }
    pcVar11 = *(code **)(_r_ip_funcs_p + 0x634);
  }
  else {
    uVar7 = 0x12;
    pcVar11 = *(code **)(_r_ip_funcs_p + 0x634);
  }
  (*pcVar11)(param_1,param_3,uVar7,pcVar11);
  return 0;
}

