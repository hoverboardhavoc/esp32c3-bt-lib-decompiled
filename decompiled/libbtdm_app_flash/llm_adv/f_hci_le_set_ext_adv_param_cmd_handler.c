/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_ext_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 f_hci_le_set_ext_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 uVar5;
  byte bVar6;
  undefined1 *puVar7;
  int iVar8;
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
  
  puVar7 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2,2);
  iVar4 = 0xc;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar8 = r_llm_adv_hdl_to_id(*param_1,0);
    bStack_2d = (byte)iVar8;
    if (iVar8 == 0xff) {
      iVar4 = r_llm_activity_free_get(&bStack_2d);
      if (iVar4 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x3d) = 0xff;
        goto _L378;
      }
    }
    else {
      uVar9 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar8 * 0x44 + 0x40);
      if (uVar9 == 1) {
_L378:
        if ((*param_1 < 0xf0) &&
           ((uVar1 = *(ushort *)(param_1 + 2), (uVar1 & 0x10) == 0 ||
            ((uVar1 < 0x1e && ((0x202d0000U >> (uVar1 & 0x1f) & 1) != 0)))))) {
          iVar4 = r_sdk_config_get_opts_ext();
          uVar1 = *(ushort *)(param_1 + 2);
          if (((*(char *)(iVar4 + 0x22) != '\0') ||
              ((((uVar1 & 0x10) == 0 || (uVar9 = uVar1 - 0x13, 10 < (uVar9 & 0xffff))) ||
               ((0x405U >> (uVar9 & 0x1f) & 1) == 0)))) &&
             (((uVar1 & 0x10) != 0 ||
              (((((uVar1 & 3) != 3 && ((uVar1 & 8) == 0)) &&
                (((uVar1 & 3) == 0 || ((uVar1 & 0x20) == 0)))) &&
               (((uVar1 & 1) == 0 ||
                (iVar4 = r_sdk_config_get_opts_ext(), *(char *)(iVar4 + 0x22) != '\0')))))))) {
            uVar1 = *(ushort *)(param_1 + 2);
            if (((uVar1 & 0x10) == 0) || (param_1[0x15] == 1)) {
              uVar10 = (uint)param_1[6] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[4];
              uVar9 = (uint)param_1[9] << 0x10 | (uint)param_1[8] << 8 | (uint)param_1[7];
              if (((((((uVar10 <= uVar9) && ((byte)(param_1[10] - 1) < 7)) && (param_1[0x13] < 4))
                    && ((7 < uVar10 && (7 < uVar9)))) &&
                   (((param_1[0x15] & 0xfd) == 1 &&
                    (((uVar1 & 0x10) != 0 || ((byte)(param_1[0x17] - 1) < 3)))))) &&
                  (((uVar1 & 4) == 0 ||
                   (iVar4 = r_co_bdaddr_compare(param_1 + 0xd,&co_null_bdaddr), iVar4 == 0)))) &&
                 ((param_1[0x18] < 0x10 && (param_1[0x19] < 2)))) {
                iVar4 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
                if (iVar4 != 0) {
                  r_ke_msg_free(iVar4 + -0xc);
                  *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44) = 0;
                }
                iVar4 = *(int *)(_p_llm_env + 8);
                *(byte **)((uint)bStack_2d * 0x44 + iVar4) = param_1;
                *(undefined1 *)(iVar4 + (uint)bStack_2d * 0x44 + 0x3e) = 0xff;
                if (3 < param_1[0xb]) {
                  r_assert_param(0,"llm_adv.c",0x347);
                }
                *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) = 1;
                r_ble_log_internal_x1(0x404e018d,bStack_2d | 0x100);
                pcVar2 = _memcpy;
                bVar6 = param_1[0x14];
                if (bVar6 == 0x7f) {
                  (*_r_llm_cmd_cmp_send)(6,0xd,_r_llm_cmd_cmp_send);
                  bVar6 = (*pcVar2)(1);
                }
                pcVar2 = _memcpy;
                (*_r_ble_log_internal_x1)((int)(char)bVar6,0,_r_ble_log_internal_x1);
                uVar5 = (*pcVar2)(1);
                iVar4 = *(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44;
                *(undefined1 *)(iVar4 + 0x3c) = uVar5;
                puVar7[1] = uVar5;
                if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
                  uStack_28 = *(undefined2 *)(iVar4 + 0x2a);
                  uStack_26 = *(undefined2 *)(iVar4 + 0x34);
                  bStack_24 = param_1[10];
                  uStack_2c = uVar9;
                  if ((param_1[0x15] < 3) || (iVar4 = lld_phy_coded_500k_get(), iVar4 == 0)) {
                    bStack_23 = param_1[0x15] - 1;
                  }
                  else {
                    bStack_23 = param_1[0x15];
                  }
                  if ((param_1[0x17] < 3) || (iVar4 = lld_phy_coded_500k_get(), iVar4 == 0)) {
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
                uVar5 = 1;
                goto _L402;
              }
            }
          }
        }
        iVar4 = 0x12;
      }
      else {
        r_ble_log_internal_x1(0x802e018c,iVar8 << 8 | uVar9 << 0x10 | 0xc);
      }
    }
  }
  uVar3 = (undefined1)iVar4;
  uVar5 = 0;
_L402:
  *puVar7 = uVar3;
  r_hci_send_2_host(puVar7);
  return uVar5;
}

