/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> f_hci_le_set_phy_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_hci_le_set_phy_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = param_1 * 4;
  iVar9 = *(int *)(&llc_env + iVar10);
  r_sdk_config_get_opts();
  iVar5 = r_sdk_config_get_opts();
  uVar3 = 0;
  if ((param_1 < *(byte *)(iVar5 + 0xd)) && (iVar5 = *(int *)(&llc_env + iVar10), iVar5 != 0)) {
    uVar3 = *(byte *)(iVar5 + 0x31) & 1;
  }
  r_sdk_config_get_opts();
  iVar5 = r_sdk_config_get_opts();
  uVar4 = 0;
  if ((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&llc_env + iVar10) != 0)) {
    uVar4 = (int)(uint)*(byte *)(*(int *)(&llc_env + iVar10) + 0x31) >> 3 & 1;
  }
  iVar5 = r_sdk_config_get_opts();
  uVar7 = 0xc;
  if ((((*(byte *)(iVar5 + 0xd) <= param_1) || (*(int *)(&llc_env + iVar10) == 0)) ||
      ((*(byte *)(*(int *)(&llc_env + iVar10) + 0x44) & 3) == 3)) ||
     (uVar7 = 0x3a, (*(byte *)(iVar9 + 0x45) & 0x40) != 0)) goto _L233;
  bVar1 = *(byte *)(param_2 + 2);
  if (((bVar1 & 2) == 0) && (uVar7 = 0x12, *(char *)(param_2 + 4) == '\0')) goto _L233;
  if (((bVar1 & 1) == 0) && (uVar7 = 0x12, *(char *)(param_2 + 3) == '\0')) goto _L233;
  uVar3 = uVar4 << 2 | uVar3 << 1 | 1;
  bVar2 = (byte)uVar3;
  if ((bVar1 & 2) == 0) {
    uVar7 = 0x11;
    if (*(byte *)(param_2 + 4) != (*(byte *)(param_2 + 4) & 7)) goto _L233;
    if ((bVar1 & 1) == 0) goto _L243;
_L237:
    uVar7 = 0x1a;
    if ((*(byte *)(param_2 + 4) & uVar3) == 0) goto _L233;
    if ((bVar1 & 1) == 0) goto _L242;
  }
  else if ((bVar1 & 1) == 0) {
_L243:
    uVar7 = 0x11;
    if (*(byte *)(param_2 + 3) != (*(byte *)(param_2 + 3) & 7)) goto _L233;
    if ((bVar1 & 2) == 0) goto _L237;
_L242:
    uVar7 = 0x1a;
    if ((*(byte *)(param_2 + 3) & uVar3) == 0) goto _L233;
  }
  puVar6 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
  *(undefined1 *)(puVar6 + 1) = 9;
  r_llc_proc_state_set(param_1,0);
  *puVar6 = r_llc_loc_phy_upd_proc_err_cb;
  bVar1 = *(byte *)(param_2 + 2);
  bVar8 = bVar2;
  if ((bVar1 & 2) == 0) {
    bVar8 = *(byte *)(param_2 + 4) & bVar2;
  }
  *(byte *)((int)puVar6 + 0xb) = bVar8;
  if ((bVar1 & 1) == 0) {
    bVar2 = bVar2 & *(byte *)(param_2 + 3);
  }
  *(byte *)((int)puVar6 + 10) = bVar2;
  *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(param_2 + 6);
  *(undefined1 *)((int)puVar6 + 0xe) = 1;
  r_ke_msg_send(puVar6);
  uVar7 = 0;
  *(byte *)(iVar9 + 0x45) = *(byte *)(iVar9 + 0x45) | 0x40;
_L233:
  r_llc_cmd_stat_send(param_1,param_3,uVar7);
  return 0;
}

