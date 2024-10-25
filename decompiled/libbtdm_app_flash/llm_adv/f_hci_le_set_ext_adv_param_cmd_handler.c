/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_ext_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  byte bStack_2d;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2,2);
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L343:
    iVar7 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar7 = r_llm_adv_hdl_to_id(*param_1,0);
    bStack_2d = (byte)iVar7;
    if (iVar7 == 0xff) {
      iVar7 = r_llm_activity_free_get(&bStack_2d);
      if (iVar7 != 0) goto _L346;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x3d) = 0xff;
    }
    else if (*(char *)(iVar7 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x01') goto _L343;
    if (*param_1 < 0xf0) {
      uVar1 = *(ushort *)(param_1 + 2);
      uVar8 = (uint)uVar1;
      if ((uVar1 & 0x10) == 0) {
        if ((((uVar8 & 3) != 3) && ((uVar1 & 8) == 0)) &&
           (((uVar1 & 3) == 0 || ((uVar1 & 0x20) == 0)))) goto _L351;
      }
      else if (((uVar8 < 0x1e) && ((0x202d0000U >> (uVar8 & 0x1f) & 1) != 0)) &&
              (param_1[0x15] == 1)) {
_L351:
        uVar8 = (uint)param_1[6] << 0x10 | (uint)param_1[5] << 8 | (uint)param_1[4];
        uVar10 = (uint)param_1[9] << 0x10 | (uint)param_1[8] << 8 | (uint)param_1[7];
        if (((((uVar8 <= uVar10) && ((byte)(param_1[10] - 1) < 7)) &&
             ((param_1[0x13] < 4 &&
              (((7 < uVar8 && (7 < uVar10)) &&
               (((param_1[0x15] & 0xfd) == 1 &&
                (((uVar1 & 0x10) != 0 || ((byte)(param_1[0x17] - 1) < 3)))))))))) &&
            (((uVar1 & 4) == 0 ||
             (iVar7 = r_co_bdaddr_compare(param_1 + 0xd,&co_null_bdaddr), iVar7 == 0)))) &&
           ((param_1[0x18] < 0x10 && (param_1[0x19] < 2)))) {
          iVar7 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
          if (iVar7 != 0) {
            r_ke_msg_free(iVar7 + -0xc);
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44) = 0;
          }
          puVar9 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
          *puVar9 = param_1;
          *(undefined1 *)((int)puVar9 + 0x3e) = 0xff;
          if (3 < param_1[0xb]) {
            r_assert_param(0,"llm_adv.c",0x311);
          }
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) = 1;
          pcVar2 = _memcpy;
          bVar5 = param_1[0x14];
          if (bVar5 == 0x7f) {
            (*_r_assert_err)(6,0xd,_r_assert_err);
            bVar5 = (*pcVar2)(1);
          }
          pcVar2 = _memcpy;
          (*_r_llm_cmd_cmp_send)((int)(char)bVar5,0,_r_llm_cmd_cmp_send);
          uVar4 = (*pcVar2)(1);
          iVar7 = *(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44;
          *(undefined1 *)(iVar7 + 0x3c) = uVar4;
          puVar6[1] = uVar4;
          if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
            uStack_28 = *(undefined2 *)(iVar7 + 0x2a);
            uStack_26 = *(undefined2 *)(iVar7 + 0x34);
            bStack_24 = param_1[10];
            uStack_2c = uVar10;
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
          uVar4 = 0;
          uVar3 = 1;
          goto _L365;
        }
      }
    }
    iVar7 = 0x12;
  }
_L346:
  uVar4 = (undefined1)iVar7;
  uVar3 = 0;
_L365:
  *puVar6 = uVar4;
  r_hci_send_2_host(puVar6);
  return uVar3;
}

