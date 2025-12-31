/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_ext_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 hci_le_set_ext_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  byte bStack_2d;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  
  iVar7 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar7 + 0x18) == '\0') ||
     (iVar7 = r_sdk_config_get_opts_ext(), *(char *)(iVar7 + 0x25) == '\0')) {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2,2);
    *puVar8 = 0xc;
    r_hci_send_2_host();
    return 0;
  }
  puVar8 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2,2);
  iVar7 = 0xc;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar6 = r_llm_adv_hdl_to_id(*param_1,0);
    bStack_2d = (byte)iVar6;
    if (iVar6 == 0xff) {
      iVar7 = r_llm_activity_free_get(&bStack_2d);
      if (iVar7 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x3d) = 0xff;
        goto _L378;
      }
    }
    else {
      uVar9 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar6 * 0x44 + 0x40);
      if (uVar9 == 1) {
_L378:
        if ((*param_1 < 0xf0) &&
           ((uVar1 = *(ushort *)(param_1 + 2), (uVar1 & 0x10) == 0 ||
            ((uVar1 < 0x1e && ((0x202d0000U >> (uVar1 & 0x1f) & 1) != 0)))))) {
          iVar7 = r_sdk_config_get_opts_ext();
          uVar1 = *(ushort *)(param_1 + 2);
          if (((*(char *)(iVar7 + 0x22) != '\0') ||
              ((((uVar1 & 0x10) == 0 || (uVar9 = uVar1 - 0x13, 10 < (uVar9 & 0xffff))) ||
               ((0x405U >> (uVar9 & 0x1f) & 1) == 0)))) &&
             (((uVar1 & 0x10) != 0 ||
              (((((uVar1 & 3) != 3 && ((uVar1 & 8) == 0)) &&
                (((uVar1 & 3) == 0 || ((uVar1 & 0x20) == 0)))) &&
               (((uVar1 & 1) == 0 ||
                (iVar7 = r_sdk_config_get_opts_ext(), *(char *)(iVar7 + 0x22) != '\0')))))))) {
            uVar1 = *(ushort *)(param_1 + 2);
            if (((uVar1 & 0x10) == 0) || (param_1[0x15] == 1)) {
              uVar10 = (uint)param_1[6] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[4];
              uVar9 = (uint)param_1[9] << 0x10 | (uint)param_1[8] << 8 | (uint)param_1[7];
              if (((((((uVar10 <= uVar9) && ((byte)(param_1[10] - 1) < 7)) && (param_1[0x13] < 4))
                    && ((7 < uVar10 && (7 < uVar9)))) &&
                   (((param_1[0x15] & 0xfd) == 1 &&
                    (((uVar1 & 0x10) != 0 || ((byte)(param_1[0x17] - 1) < 3)))))) &&
                  (((uVar1 & 4) == 0 ||
                   (iVar7 = r_co_bdaddr_compare(param_1 + 0xd,&co_null_bdaddr), iVar7 == 0)))) &&
                 ((param_1[0x18] < 0x10 && (param_1[0x19] < 2)))) {
                iVar7 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
                if (iVar7 != 0) {
                  r_ke_msg_free(iVar7 + -0xc);
                  *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44) = 0;
                }
                iVar7 = *(int *)(_p_llm_env + 8);
                *(byte **)((uint)bStack_2d * 0x44 + iVar7) = param_1;
                *(undefined1 *)(iVar7 + (uint)bStack_2d * 0x44 + 0x3e) = 0xff;
                if (3 < param_1[0xb]) {
                  r_assert_param(0,"llm_adv.c",0x347);
                }
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) = 1;
                r_ble_log_internal_x1(0x404e0162,bStack_2d | 0x100);
                pcVar2 = _memcpy;
                bVar5 = param_1[0x14];
                if (bVar5 == 0x7f) {
                  (*_r_llm_cmd_cmp_send)(6,0xd,_r_llm_cmd_cmp_send);
                  bVar5 = (*pcVar2)(1);
                }
                pcVar2 = _memcpy;
                (*_r_ble_log_internal_x1)((int)(char)bVar5,0,_r_ble_log_internal_x1);
                uVar4 = (*pcVar2)(1);
                iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44;
                *(undefined1 *)(iVar7 + 0x3c) = uVar4;
                puVar8[1] = uVar4;
                if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
                  uStack_28 = *(undefined2 *)(iVar7 + 0x2a);
                  uStack_26 = *(undefined2 *)(iVar7 + 0x34);
                  bStack_24 = param_1[10];
                  uStack_2c = uVar9;
                  if ((param_1[0x15] < 3) || (iVar7 = lld_phy_coded_500k_get(), iVar7 == 0)) {
                    bStack_23 = param_1[0x15] - 1;
                  }
                  else {
                    bStack_23 = param_1[0x15];
                  }
                  if ((param_1[0x17] < 3) || (iVar7 = lld_phy_coded_500k_get(), iVar7 == 0)) {
                    bStack_22 = param_1[0x17] - 1;
                  }
                  else {
                    bStack_22 = param_1[0x17];
                  }
                  bStack_21 = param_1[0x16];
                  (**(code **)(_bt_rf_coex_hooks_p + 4))
                            (bStack_2d,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
                }
                uVar3 = 0;
                uVar4 = 1;
                goto _L402;
              }
            }
          }
        }
        iVar7 = 0x12;
      }
      else {
        r_ble_log_internal_x1(0x802e0161,iVar6 << 8 | uVar9 << 0x10 | 0xc);
      }
    }
  }
  uVar3 = (undefined1)iVar7;
  uVar4 = 0;
_L402:
  *puVar8 = uVar3;
  r_hci_send_2_host(puVar8);
  return uVar4;
}

