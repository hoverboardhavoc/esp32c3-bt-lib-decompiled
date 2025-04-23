/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  byte bStack_3d;
  uint uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  byte bStack_34;
  byte bStack_33;
  byte bStack_32;
  byte bStack_31;
  
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2,2);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L348:
    iVar7 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar7 = r_llm_adv_hdl_to_id(*param_1,0);
    bStack_3d = (byte)iVar7;
    if (iVar7 == 0xff) {
      iVar7 = r_llm_activity_free_get(&bStack_3d);
      if (iVar7 != 0) goto _L351;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x3d) = 0xff;
    }
    else if (*(char *)(*(int *)(_p_llm_env + 8) + iVar7 * 0x44 + 0x40) != '\x01') goto _L348;
    if (*param_1 < 0xf0) {
      uVar1 = *(ushort *)(param_1 + 2);
      uVar9 = (uint)uVar1;
      if ((uVar1 & 0x10) == 0) {
        if ((((uVar9 & 3) != 3) && ((uVar1 & 8) == 0)) &&
           (((uVar1 & 3) == 0 || ((uVar1 & 0x20) == 0)))) goto _L357;
      }
      else if (((uVar9 < 0x1e) && ((0x202d0000U >> (uVar9 & 0x1f) & 1) != 0)) &&
              (param_1[0x15] == 1)) {
_L357:
        uVar8 = (uint)param_1[6] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[4];
        uVar9 = (uint)param_1[9] << 0x10 | (uint)param_1[8] << 8 | (uint)param_1[7];
        if (((((uVar8 <= uVar9) && ((byte)(param_1[10] - 1) < 7)) &&
             ((param_1[0x13] < 4 &&
              (((7 < uVar8 && (7 < uVar9)) &&
               (((param_1[0x15] & 0xfd) == 1 &&
                (((uVar1 & 0x10) != 0 || ((byte)(param_1[0x17] - 1) < 3)))))))))) &&
            (((uVar1 & 4) == 0 ||
             (iVar7 = r_co_bdaddr_compare(param_1 + 0xd,&co_null_bdaddr), iVar7 == 0)))) &&
           ((param_1[0x18] < 0x10 && (param_1[0x19] < 2)))) {
          piVar10 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
          if (*piVar10 != 0) {
            r_ke_msg_free(*piVar10 + -0xc);
            piVar10 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
            *piVar10 = 0;
          }
          *piVar10 = (int)param_1;
          *(undefined1 *)((int)piVar10 + 0x3e) = 0xff;
          if (3 < param_1[0xb]) {
            r_assert_param(0,"llm_adv.c",0x311);
          }
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x40) = 1;
          pcVar2 = _memcpy;
          bVar4 = param_1[0x14];
          if (bVar4 == 0x7f) {
            (*_r_llm_cmd_cmp_send)(6,0xd,_r_llm_cmd_cmp_send);
            bVar4 = (*pcVar2)(1);
          }
          pcVar2 = _memcpy;
          (*_r_ble_log_internal_x1)((int)(char)bVar4,0,_r_ble_log_internal_x1);
          uVar5 = (*pcVar2)(1);
          iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44;
          *(undefined1 *)(iVar7 + 0x3c) = uVar5;
          puVar6[1] = uVar5;
          if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
            uStack_38 = *(undefined2 *)(iVar7 + 0x2a);
            uStack_36 = *(undefined2 *)(iVar7 + 0x34);
            bStack_34 = param_1[10];
            uStack_3c = uVar9;
            if ((param_1[0x15] < 3) || (iVar7 = lld_phy_coded_500k_get(), iVar7 == 0)) {
              bStack_33 = param_1[0x15] - 1;
            }
            else {
              bStack_33 = param_1[0x15];
            }
            if ((param_1[0x17] < 3) || (iVar7 = lld_phy_coded_500k_get(), iVar7 == 0)) {
              bStack_32 = param_1[0x17] - 1;
            }
            else {
              bStack_32 = param_1[0x17];
            }
            bStack_31 = param_1[0x16];
            (**(code **)(_bt_rf_coex_hooks_p + 4))
                      (bStack_3d,2,&uStack_3c,*(code **)(_bt_rf_coex_hooks_p + 4));
          }
          uVar3 = 0;
          uVar5 = 1;
          goto _L373;
        }
      }
    }
    iVar7 = 0x12;
  }
_L351:
  uVar3 = (undefined1)iVar7;
  uVar5 = 0;
_L373:
  *puVar6 = uVar3;
  r_hci_send_2_host(puVar6);
  return uVar5;
}

