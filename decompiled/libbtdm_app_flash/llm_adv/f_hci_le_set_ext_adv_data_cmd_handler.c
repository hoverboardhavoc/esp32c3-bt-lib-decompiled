/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_ext_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_adv_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  void *__dest;
  undefined4 uVar6;
  uint uVar7;
  uint extraout_a1;
  byte bVar8;
  int iVar9;
  int iVar10;
  int iStack_30;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined1 uStack_24;
  char cStack_23;
  char cStack_22;
  undefined1 uStack_21;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L414:
    uVar6 = 0xc;
    goto _L452;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar5 = r_llm_adv_hdl_to_id(*param_1,&iStack_30);
  uVar6 = 0x42;
  if (iVar5 == 0xff) goto _L452;
  bVar8 = param_1[1];
  if (((bVar8 < 5) && ((byte)param_1[2] < 2)) && (uVar7 = (uint)(byte)param_1[3], uVar7 < 0xfc)) {
    uVar3 = *(ushort *)(iStack_30 + 2);
    if ((uVar3 & 0x10) == 0) {
      if (bVar8 == 4) {
        iVar10 = *(int *)(_p_llm_env + 8) + iVar5 * 0x44;
        if (((*(char *)(iVar10 + 0x40) != '\x01') && (*(short *)(iVar10 + 0x28) != 0)) &&
           (bVar8 = 1, uVar7 == 0)) goto _L419;
      }
      else {
        bVar8 = bVar8 - 3;
        if (bVar8 < 2) goto _L454;
        if (uVar7 != 0) goto _L419;
      }
    }
    else if ((bVar8 == 3) && (uVar7 < 0x20)) {
_L454:
      bVar8 = 0;
_L419:
      if ((uVar3 & 0x12) != 2) {
        iVar10 = iVar5 * 0x44;
        if (*(char *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x40) != '\x01') {
          if (1 < bVar8) goto _L414;
          if ((((uVar3 & 0x11) == 1) &&
              (iVar9 = r_llm_adv_con_len_check(iStack_30), uVar7 = extraout_a1, iVar9 != 0)) ||
             ((uVar3 = *(ushort *)(iStack_30 + 2), (uVar3 & 0x1c) == 0x10 &&
              (0x1f < (byte)param_1[3])))) goto _L417;
        }
        if ((uVar3 & 0x11) == 1) {
          iVar9 = r_llm_adv_con_len_check(iStack_30,param_1[3]);
          uVar7 = 0x45;
          uVar6 = 0x45;
          if (iVar9 != 0) goto _L452;
        }
        iVar9 = *(int *)(_p_llm_env + 8) + iVar10;
        if ((uint)*(ushort *)(iVar9 + 0x30) <
            (uint)*(ushort *)(iVar9 + 0x2e) + (uint)(byte)param_1[3]) {
          if (*(short *)(iVar9 + 0x2c) != 0) {
            r_ble_util_buf_adv_tx_free(uVar7);
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x2c) = 0;
          }
_L431:
          uVar6 = 7;
        }
        else {
          if ((param_1[1] & 0xfd) == 1) {
            if (*(short *)(iVar9 + 0x2c) != 0) {
              r_ble_util_buf_adv_tx_free();
              iVar9 = *(int *)(_p_llm_env + 8) + iVar10;
              *(undefined2 *)(iVar9 + 0x2e) = 0;
            }
            if (param_1[1] == '\x03') {
              uVar3 = (ushort)(byte)param_1[3];
              if (uVar3 != 0) goto _L480;
              uVar4 = 0;
              bVar1 = true;
            }
            else {
              uVar3 = *(ushort *)(iVar9 + 0x30);
_L480:
              uVar4 = r_ble_util_buf_adv_tx_alloc(uVar3);
              bVar1 = false;
            }
            iVar2 = _p_llm_env;
            *(undefined2 *)(iVar9 + 0x2c) = uVar4;
            if ((*(short *)(*(int *)(iVar2 + 8) + iVar10 + 0x2c) == 0) && (!bVar1)) goto _L431;
          }
          bVar8 = param_1[3];
          if (bVar8 != 0) {
            iVar9 = *(int *)(_p_llm_env + 8) + iVar10;
            __dest = (void *)r_emi_get_mem_addr_by_offset
                                       (*(short *)(iVar9 + 0x2c) + *(short *)(iVar9 + 0x2e));
            memcpy(__dest,param_1 + 4,(uint)bVar8);
            iVar9 = *(int *)(_p_llm_env + 8) + iVar10;
            *(ushort *)(iVar9 + 0x2e) = *(short *)(iVar9 + 0x2e) + (ushort)(byte)param_1[3];
          }
          if ((byte)(param_1[1] - 2) < 2) {
            iVar9 = *(int *)(_p_llm_env + 8) + iVar10;
            if (*(char *)(iVar9 + 0x40) == '\x02') {
              r_lld_adv_adv_data_update
                        (iVar5,*(undefined1 *)(iVar9 + 0x2e),*(undefined2 *)(iVar9 + 0x2c));
            }
            else if (*(short *)(iVar9 + 0x28) != 0) {
              r_ble_util_buf_adv_tx_free();
            }
            iVar10 = *(int *)(_p_llm_env + 8) + iVar10;
            uVar6 = *(undefined4 *)(iVar10 + 0x2c);
            *(undefined4 *)(iVar10 + 0x2c) = 0;
            *(undefined4 *)(iVar10 + 0x28) = uVar6;
            if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
              uStack_26 = *(undefined2 *)(iVar10 + 0x34);
              uStack_24 = *(undefined1 *)(iStack_30 + 10);
              uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 |
                          (uint)*(byte *)(iStack_30 + 8) << 8 | (uint)*(byte *)(iStack_30 + 7);
              uStack_28 = *(undefined2 *)(iVar10 + 0x2e);
              if ((*(byte *)(iStack_30 + 0x15) < 3) ||
                 (iVar10 = lld_phy_coded_500k_get(), iVar10 == 0)) {
                cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
              }
              else {
                cStack_23 = *(char *)(iStack_30 + 0x15);
              }
              if ((*(byte *)(iStack_30 + 0x17) < 3) ||
                 (iVar10 = lld_phy_coded_500k_get(), iVar10 == 0)) {
                cStack_22 = *(char *)(iStack_30 + 0x17) + -1;
              }
              else {
                cStack_22 = *(char *)(iStack_30 + 0x17);
              }
              uStack_21 = *(undefined1 *)(iStack_30 + 0x16);
              (**(code **)(_bt_rf_coex_hooks_p + 4))
                        (iVar5,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
            }
          }
          else if (param_1[1] == '\x04') {
            r_lld_adv_adv_data_update(iVar5,0,0);
          }
          uVar6 = 0;
        }
        goto _L452;
      }
    }
  }
_L417:
  uVar6 = 0x12;
_L452:
  r_llm_cmd_cmp_send(param_2,uVar6);
  return 0;
}

