/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_per_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_per_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  byte bStack_2d;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L752:
    uVar1 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    if (*param_1 < 0xf0) {
      iVar3 = r_llm_adv_hdl_to_id(0);
      if (iVar3 == 0xff) {
        r_ble_log_internal_x1(0x802e0174,(uint)*param_1 << 8 | 0xff0042);
        uVar1 = 0x42;
        goto _L754;
      }
      iVar6 = iVar3 * 0x44;
      bStack_2d = *(byte *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x3d);
      if (bStack_2d == 0xff) {
        uVar1 = r_llm_activity_free_get(&bStack_2d);
        if (uVar1 != 0) {
          r_ble_log_internal_x1(0x802e0175,(uint)bStack_2d << 0x10 | iVar3 << 8 | uVar1);
          goto _L754;
        }
        iVar3 = *(int *)(_p_llm_env + 8);
        *(byte *)(iVar3 + iVar6 + 0x3d) = bStack_2d;
        *(undefined1 *)(iVar3 + (uint)bStack_2d * 0x44 + 0x32) = 0xff;
      }
      else if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) != '\n')
      goto _L752;
      if (((*param_1 < 0xf0) && (*(ushort *)(param_1 + 2) <= *(ushort *)(param_1 + 4))) &&
         ((*(ushort *)(*(int *)(*(int *)(_p_llm_env + 8) + iVar6) + 2) & 0x20) == 0)) {
        iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
        if (iVar3 != 0) {
          r_ke_msg_free(iVar3 + -0xc);
          *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44) = 0;
        }
        iVar3 = *(int *)(_p_llm_env + 8);
        *(byte **)((uint)bStack_2d * 0x44 + iVar3) = param_1;
        *(undefined1 *)(iVar3 + (uint)bStack_2d * 0x44 + 0x40) = 10;
        r_ble_log_internal_x1(0x404e0176,bStack_2d | 0xa00);
        if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
          piVar5 = (int *)((uint)bStack_2d * 0x44 + *(int *)(_p_llm_env + 8));
          iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + iVar6);
          uStack_2c = (uint)*(ushort *)(*piVar5 + 4);
          uStack_28 = (uint)*(ushort *)((int)piVar5 + 0x2a);
          uStack_24 = 0;
          if ((*(byte *)(iVar3 + 0x17) < 3) || (iVar6 = lld_phy_coded_500k_get(), iVar6 == 0)) {
            cVar4 = *(char *)(iVar3 + 0x17) + -1;
          }
          else {
            cVar4 = *(char *)(iVar3 + 0x17);
          }
          uStack_28._0_3_ = CONCAT12(cVar4,(undefined2)uStack_28);
          (**(code **)(_bt_rf_coex_hooks_p + 4))
                    (bStack_2d,4,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
        }
        uVar1 = 0;
        uVar2 = 1;
        goto _L763;
      }
    }
    else {
      r_ble_log_internal_x1(0x802e0173,(uint)*param_1 << 8 | 0x12);
    }
    uVar1 = 0x12;
  }
_L754:
  uVar2 = 0;
_L763:
  r_llm_cmd_cmp_send(param_2,uVar1);
  return uVar2;
}

