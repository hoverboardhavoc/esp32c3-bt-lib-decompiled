/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  undefined4 uVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar6 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,0xc,*(code **)(_r_ip_funcs_p + 0x634));
    return 0;
  }
  iVar10 = param_1 * 4;
  iVar9 = *(int *)(&llc_env + iVar10);
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
  iVar6 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar7 = 0xc;
  if ((((*(byte *)(iVar6 + 0xd) <= param_1) || (*(int *)(&llc_env + iVar10) == 0)) ||
      ((*(byte *)(*(int *)(&llc_env + iVar10) + 0x44) & 3) == 3)) ||
     (uVar7 = 0x3a, (*(byte *)(iVar9 + 0x45) & 0x40) != 0)) goto _L237;
  bVar1 = *(byte *)(param_2 + 2);
  if (((bVar1 & 2) == 0) && (uVar7 = 0x12, *(char *)(param_2 + 4) == '\0')) goto _L237;
  if (((bVar1 & 1) == 0) && (uVar7 = 0x12, *(char *)(param_2 + 3) == '\0')) goto _L237;
  uVar3 = uVar3 << 1 | uVar4 << 2 | 1;
  bVar2 = (byte)uVar3;
  if ((bVar1 & 2) == 0) {
    uVar7 = 0x11;
    if (*(byte *)(param_2 + 4) != (*(byte *)(param_2 + 4) & 7)) goto _L237;
    if ((bVar1 & 1) == 0) goto _L247;
_L241:
    uVar7 = 0x1a;
    if ((*(byte *)(param_2 + 4) & uVar3) == 0) goto _L237;
    if ((bVar1 & 1) == 0) goto _L246;
  }
  else if ((bVar1 & 1) == 0) {
_L247:
    uVar7 = 0x11;
    if (*(byte *)(param_2 + 3) != (*(byte *)(param_2 + 3) & 7)) goto _L237;
    if ((bVar1 & 2) == 0) goto _L241;
_L246:
    uVar7 = 0x1a;
    if ((*(byte *)(param_2 + 3) & uVar3) == 0) goto _L237;
  }
  puVar5 = (undefined4 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
  *(undefined1 *)(puVar5 + 1) = 9;
  (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
  *puVar5 = *(undefined4 *)(_r_ip_funcs_p + 0x64c);
  bVar1 = *(byte *)(param_2 + 2);
  bVar8 = bVar2;
  if ((bVar1 & 2) == 0) {
    bVar8 = *(byte *)(param_2 + 4) & bVar2;
  }
  *(byte *)((int)puVar5 + 0xb) = bVar8;
  if ((bVar1 & 1) == 0) {
    bVar2 = bVar2 & *(byte *)(param_2 + 3);
  }
  *(byte *)((int)puVar5 + 10) = bVar2;
  *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(param_2 + 6);
  *(undefined1 *)((int)puVar5 + 0xe) = 1;
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar5,*(code **)(_r_modules_funcs_p + 0xe0));
  uVar7 = 0;
  *(byte *)(iVar9 + 0x45) = *(byte *)(iVar9 + 0x45) | 0x40;
_L237:
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,uVar7,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

