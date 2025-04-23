/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> f_hci_le_set_phy_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_phy_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  byte bVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  
  iVar10 = param_1 * 4;
  iVar8 = *(int *)(&llc_env + iVar10);
  (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar3 = 0;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar5 + 0xd)) && (iVar5 = *(int *)(&llc_env + iVar10), iVar5 != 0)) {
    uVar3 = *(byte *)(iVar5 + 0x31) & 1;
  }
  uVar4 = 0;
  (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&llc_env + iVar10) != 0)) {
    uVar4 = (int)(uint)*(byte *)(*(int *)(&llc_env + iVar10) + 0x31) >> 3 & 1;
  }
  bVar9 = 0xc;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((*(byte *)(iVar5 + 0xd) <= param_1) || (*(int *)(&llc_env + iVar10) == 0)) ||
     ((*(byte *)(*(int *)(&llc_env + iVar10) + 0x44) & 3) == 3)) goto _L242;
  bVar9 = *(byte *)(iVar8 + 0x45) & 0x40;
  if ((*(byte *)(iVar8 + 0x45) & 0x40) != 0) {
    bVar9 = 0x3a;
    goto _L242;
  }
  bVar1 = *(byte *)(param_2 + 2);
  if (((bVar1 & 2) == 0) && (*(char *)(param_2 + 4) == '\0')) {
_L263:
    bVar9 = 0x12;
  }
  else {
    uVar3 = uVar3 << 1 | uVar4 << 2 | 1;
    bVar2 = (byte)uVar3;
    if ((bVar1 & 1) == 0) {
      if (*(char *)(param_2 + 3) == '\0') goto _L263;
      if ((bVar1 & 2) == 0) goto _L252;
_L253:
      if (7 < *(byte *)(param_2 + 3)) {
_L265:
        bVar9 = 0x11;
        goto _L242;
      }
      if ((bVar1 & 2) == 0) goto _L247;
_L251:
      if ((*(byte *)(param_2 + 3) & uVar3) == 0) {
_L267:
        bVar9 = 0x1a;
        goto _L242;
      }
    }
    else if ((bVar1 & 2) == 0) {
_L252:
      if (7 < *(byte *)(param_2 + 4)) goto _L265;
      if ((bVar1 & 1) == 0) goto _L253;
_L247:
      if ((*(byte *)(param_2 + 4) & uVar3) == 0) goto _L267;
      if ((bVar1 & 1) == 0) goto _L251;
    }
    puVar6 = (undefined4 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
    *(undefined1 *)(puVar6 + 1) = 9;
    (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
    *puVar6 = *(undefined4 *)(_r_ip_funcs_p + 0x64c);
    bVar1 = *(byte *)(param_2 + 2);
    bVar7 = bVar2;
    if ((bVar1 & 2) == 0) {
      bVar7 = *(byte *)(param_2 + 4) & bVar2;
    }
    *(byte *)((int)puVar6 + 0xb) = bVar7;
    if ((bVar1 & 1) == 0) {
      bVar2 = bVar2 & *(byte *)(param_2 + 3);
    }
    *(byte *)((int)puVar6 + 10) = bVar2;
    *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(param_2 + 6);
    *(undefined1 *)((int)puVar6 + 0xe) = 1;
    (**(code **)(_r_modules_funcs_p + 0xe0))(puVar6,*(code **)(_r_modules_funcs_p + 0xe0));
    *(byte *)(iVar8 + 0x45) = *(byte *)(iVar8 + 0x45) | 0x40;
  }
_L242:
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,bVar9,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

