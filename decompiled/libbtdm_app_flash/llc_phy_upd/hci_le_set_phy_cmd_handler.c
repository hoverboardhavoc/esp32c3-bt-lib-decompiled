/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> hci_le_set_phy_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_set_phy_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  iVar5 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar5 + 0x18) == '\0') {
    r_llc_cmd_stat_send(param_1,param_3,0xc);
    return 0;
  }
  iVar8 = param_1 * 4;
  iVar7 = *(int *)(&llc_env + iVar8);
  r_sdk_config_get_opts();
  iVar5 = r_sdk_config_get_opts();
  uVar2 = 0;
  if ((param_1 < *(byte *)(iVar5 + 0xd)) && (iVar5 = *(int *)(&llc_env + iVar8), iVar5 != 0)) {
    uVar2 = *(byte *)(iVar5 + 0x31) & 1;
  }
  r_sdk_config_get_opts();
  iVar5 = r_sdk_config_get_opts();
  uVar3 = 0;
  if ((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&llc_env + iVar8) != 0)) {
    uVar3 = (int)(uint)*(byte *)(*(int *)(&llc_env + iVar8) + 0x31) >> 3 & 1;
  }
  iVar5 = r_sdk_config_get_opts();
  uVar6 = param_1 << 8;
  if (((*(byte *)(iVar5 + 0xd) <= param_1) || (*(int *)(&llc_env + iVar8) == 0)) ||
     ((*(byte *)(*(int *)(&llc_env + iVar8) + 0x44) & 3) == 3)) {
    r_ble_log_internal_x1(0x800300c2,uVar6 | 0xc);
    uVar9 = 0xc;
    goto _L237;
  }
  bVar1 = *(byte *)(iVar7 + 0x45);
  uVar9 = bVar1 & 0x40;
  if ((bVar1 & 0x40) != 0) {
    r_ble_log_internal_x1(0x800300c3,(uint)bVar1 << 0x10 | uVar6 | 0x3a);
    uVar9 = 0x3a;
    goto _L237;
  }
  bVar1 = *(byte *)(param_2 + 2);
  if (((bVar1 & 2) != 0) || (*(char *)(param_2 + 4) != '\0')) {
    if (((bVar1 & 1) != 0) || (*(char *)(param_2 + 3) != '\0')) {
      uVar2 = uVar2 << 1 | uVar3 << 2 | 1;
      if ((bVar1 & 2) == 0) {
        if (*(byte *)(param_2 + 4) != (*(byte *)(param_2 + 4) & 7)) {
_L243:
          r_ble_log_internal_x1(0x800300c5,uVar6 | 0x70011);
          uVar9 = 0x11;
          goto _L237;
        }
        if ((bVar1 & 1) == 0) goto _L251;
_L244:
        if ((*(byte *)(param_2 + 4) & uVar2) == 0) {
_L246:
          r_ble_log_internal_x1(0x800300c6,uVar2 << 0x10 | uVar6 | 0x1a);
          uVar9 = 0x1a;
          goto _L237;
        }
        if ((bVar1 & 1) == 0) goto _L250;
      }
      else if ((bVar1 & 1) == 0) {
_L251:
        if (*(byte *)(param_2 + 3) != (*(byte *)(param_2 + 3) & 7)) goto _L243;
        if ((bVar1 & 2) == 0) goto _L244;
_L250:
        if ((*(byte *)(param_2 + 3) & uVar2) == 0) goto _L246;
      }
      puVar4 = (undefined4 *)r_ke_msg_alloc(0x10e,uVar6 | 1,0x14);
      *(undefined1 *)(puVar4 + 1) = 9;
      r_llc_proc_state_set(param_1,0);
      *puVar4 = r_llc_loc_phy_upd_proc_err_cb;
      bVar1 = *(byte *)(param_2 + 2);
      uVar3 = uVar2;
      if ((bVar1 & 2) == 0) {
        uVar3 = *(byte *)(param_2 + 4) & uVar2;
      }
      *(char *)((int)puVar4 + 0xb) = (char)uVar3;
      if ((bVar1 & 1) == 0) {
        uVar2 = uVar2 & *(byte *)(param_2 + 3);
      }
      *(char *)((int)puVar4 + 10) = (char)uVar2;
      *(undefined2 *)(puVar4 + 4) = *(undefined2 *)(param_2 + 6);
      *(undefined1 *)((int)puVar4 + 0xe) = 1;
      r_ke_msg_send(puVar4);
      *(byte *)(iVar7 + 0x45) = *(byte *)(iVar7 + 0x45) | 0x40;
      goto _L237;
    }
  }
  r_ble_log_internal_x2
            (0x800300c4,(uint)*(byte *)(param_2 + 3) << 0x18 | (uint)bVar1 << 0x10 | uVar6 | 0x12,
             *(undefined1 *)(param_2 + 4));
  uVar9 = 0x12;
_L237:
  r_llc_cmd_stat_send(param_1,param_3,uVar9);
  return 0;
}

