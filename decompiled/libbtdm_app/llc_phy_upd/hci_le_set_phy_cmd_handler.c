/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> hci_le_set_phy_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_phy_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar6 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,0xc,*(code **)(_r_ip_funcs_p + 0x634));
    return 0;
  }
  iVar10 = param_1 * 4;
  iVar8 = *(int *)(&llc_env + iVar10);
  (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar3 = 0;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar6 + 0xd)) && (iVar6 = *(int *)(&llc_env + iVar10), iVar6 != 0)) {
    uVar3 = *(byte *)(iVar6 + 0x31) & 1;
  }
  uVar4 = 0;
  (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar6 + 0xd)) && (*(int *)(&llc_env + iVar10) != 0)) {
    uVar4 = (int)(uint)*(byte *)(*(int *)(&llc_env + iVar10) + 0x31) >> 3 & 1;
  }
  bVar9 = 0xc;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((*(byte *)(iVar6 + 0xd) <= param_1) || (*(int *)(&llc_env + iVar10) == 0)) ||
     ((*(byte *)(*(int *)(&llc_env + iVar10) + 0x44) & 3) == 3)) goto _L234;
  bVar9 = *(byte *)(iVar8 + 0x45) & 0x40;
  if ((*(byte *)(iVar8 + 0x45) & 0x40) != 0) {
    bVar9 = 0x3a;
    goto _L234;
  }
  bVar1 = *(byte *)(param_2 + 2);
  if (((bVar1 & 2) != 0) || (*(char *)(param_2 + 4) != '\0')) {
    if (((bVar1 & 1) != 0) || (*(char *)(param_2 + 3) != '\0')) {
      uVar3 = uVar3 << 1 | uVar4 << 2 | 1;
      bVar2 = (byte)uVar3;
      if ((bVar1 & 2) == 0) {
        if (*(byte *)(param_2 + 4) != (*(byte *)(param_2 + 4) & 7)) {
_L256:
          bVar9 = 0x11;
          goto _L234;
        }
        if ((bVar1 & 1) == 0) goto _L244;
_L238:
        if ((*(byte *)(param_2 + 4) & uVar3) == 0) {
_L258:
          bVar9 = 0x1a;
          goto _L234;
        }
        if ((bVar1 & 1) == 0) goto _L243;
      }
      else if ((bVar1 & 1) == 0) {
_L244:
        if (*(byte *)(param_2 + 3) != (*(byte *)(param_2 + 3) & 7)) goto _L256;
        if ((bVar1 & 2) == 0) goto _L238;
_L243:
        if ((*(byte *)(param_2 + 3) & uVar3) == 0) goto _L258;
      }
      puVar5 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar5 + 1) = 9;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
      *puVar5 = *(undefined4 *)(_r_ip_funcs_p + 0x64c);
      bVar1 = *(byte *)(param_2 + 2);
      bVar7 = bVar2;
      if ((bVar1 & 2) == 0) {
        bVar7 = *(byte *)(param_2 + 4) & bVar2;
      }
      *(byte *)((int)puVar5 + 0xb) = bVar7;
      if ((bVar1 & 1) == 0) {
        bVar2 = bVar2 & *(byte *)(param_2 + 3);
      }
      *(byte *)((int)puVar5 + 10) = bVar2;
      *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(param_2 + 6);
      *(undefined1 *)((int)puVar5 + 0xe) = 1;
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar5,*(code **)(_r_modules_funcs_p + 0xe0));
      *(byte *)(iVar8 + 0x45) = *(byte *)(iVar8 + 0x45) | 0x40;
      goto _L234;
    }
  }
  bVar9 = 0x12;
_L234:
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,bVar9,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

