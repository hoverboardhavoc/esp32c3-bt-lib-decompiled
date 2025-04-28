/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar4;
  undefined4 *puVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  
  iVar10 = param_1 * 4;
  iVar8 = *(int *)(&llc_env + iVar10);
  r_sdk_config_get_opts();
  iVar4 = r_sdk_config_get_opts();
  uVar3 = 0;
  if ((param_1 < *(byte *)(iVar4 + 0xd)) && (iVar4 = *(int *)(&llc_env + iVar10), iVar4 != 0)) {
    uVar3 = *(byte *)(iVar4 + 0x31) & 1;
  }
  r_sdk_config_get_opts();
  iVar4 = r_sdk_config_get_opts();
  uVar7 = 0;
  if ((param_1 < *(byte *)(iVar4 + 0xd)) && (*(int *)(&llc_env + iVar10) != 0)) {
    uVar7 = (int)(uint)*(byte *)(*(int *)(&llc_env + iVar10) + 0x31) >> 3 & 1;
  }
  iVar4 = r_sdk_config_get_opts();
  bVar9 = 0xc;
  if (((*(byte *)(iVar4 + 0xd) <= param_1) || (*(int *)(&llc_env + iVar10) == 0)) ||
     ((*(byte *)(*(int *)(&llc_env + iVar10) + 0x44) & 3) == 3)) goto _L230;
  bVar9 = *(byte *)(iVar8 + 0x45) & 0x40;
  if ((*(byte *)(iVar8 + 0x45) & 0x40) != 0) {
    bVar9 = 0x3a;
    goto _L230;
  }
  bVar1 = *(byte *)(param_2 + 2);
  if (((bVar1 & 2) != 0) || (*(char *)(param_2 + 4) != '\0')) {
    if (((bVar1 & 1) != 0) || (*(char *)(param_2 + 3) != '\0')) {
      uVar3 = uVar3 << 1 | uVar7 << 2 | 1;
      bVar2 = (byte)uVar3;
      if ((bVar1 & 2) == 0) {
        if (*(byte *)(param_2 + 4) != (*(byte *)(param_2 + 4) & 7)) {
_L252:
          bVar9 = 0x11;
          goto _L230;
        }
        if ((bVar1 & 1) == 0) goto _L240;
_L234:
        if ((*(byte *)(param_2 + 4) & uVar3) == 0) {
_L254:
          bVar9 = 0x1a;
          goto _L230;
        }
        if ((bVar1 & 1) == 0) goto _L239;
      }
      else if ((bVar1 & 1) == 0) {
_L240:
        if (*(byte *)(param_2 + 3) != (*(byte *)(param_2 + 3) & 7)) goto _L252;
        if ((bVar1 & 2) == 0) goto _L234;
_L239:
        if ((*(byte *)(param_2 + 3) & uVar3) == 0) goto _L254;
      }
      puVar5 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
      *(undefined1 *)(puVar5 + 1) = 9;
      r_llc_proc_state_set(param_1,0);
      *puVar5 = r_llc_loc_phy_upd_proc_err_cb;
      bVar1 = *(byte *)(param_2 + 2);
      bVar6 = bVar2;
      if ((bVar1 & 2) == 0) {
        bVar6 = *(byte *)(param_2 + 4) & bVar2;
      }
      *(byte *)((int)puVar5 + 0xb) = bVar6;
      if ((bVar1 & 1) == 0) {
        bVar2 = bVar2 & *(byte *)(param_2 + 3);
      }
      *(byte *)((int)puVar5 + 10) = bVar2;
      *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(param_2 + 6);
      *(undefined1 *)((int)puVar5 + 0xe) = 1;
      r_ke_msg_send(puVar5);
      *(byte *)(iVar8 + 0x45) = *(byte *)(iVar8 + 0x45) | 0x40;
      goto _L230;
    }
  }
  bVar9 = 0x12;
_L230:
  r_llc_cmd_stat_send(param_1,param_3,bVar9);
  return 0;
}

