/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_ext_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_adv_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  void *__dest;
  int iVar9;
  undefined4 uVar10;
  int iStack_30;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined1 uStack_24;
  char cStack_23;
  char cStack_22;
  undefined1 uStack_21;
  
  iVar9 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar9 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar10 = 0xc;
    goto _L459;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar9 = r_llm_adv_hdl_to_id(*param_1,&iStack_30);
  uVar10 = 0x42;
  if (iVar9 == 0xff) goto _L459;
  bVar1 = param_1[1];
  if (((bVar1 < 5) && ((byte)param_1[2] < 2)) && (bVar2 = param_1[3], bVar2 < 0xfc)) {
    uVar6 = *(ushort *)(iStack_30 + 2);
    if ((uVar6 & 0x10) == 0) {
      if ((bVar1 != 4) ||
         (((iVar5 = *(int *)(_p_llm_env + 8) + iVar9 * 0x44, *(char *)(iVar5 + 0x40) != '\x01' &&
           (*(short *)(iVar5 + 0x28) != 0)) && (bVar2 == 0)))) goto _L429;
    }
    else if ((bVar1 == 3) && (bVar2 < 0x20)) {
_L429:
      if ((((byte)(bVar1 - 3) < 2) || (bVar2 != 0)) && ((uVar6 & 0x12) != 2)) {
        iVar5 = iVar9 * 0x44;
        if (*(char *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40) != '\x01') {
          uVar10 = 0xc;
          if (1 < (byte)(bVar1 - 3)) goto _L459;
          if ((((uVar6 & 0x11) == 1) && (iVar8 = r_llm_adv_con_len_check(), iVar8 != 0)) ||
             (((*(ushort *)(iStack_30 + 2) & 0x1c) == 0x10 && (0x1f < (byte)param_1[3]))))
          goto _L427;
        }
        if ((*(ushort *)(iStack_30 + 2) & 0x11) == 1) {
          iVar8 = r_llm_adv_con_len_check(param_1[3]);
          uVar10 = 0x45;
          if (iVar8 != 0) goto _L459;
        }
        iVar8 = *(int *)(_p_llm_env + 8) + iVar5;
        if ((uint)*(ushort *)(iVar8 + 0x30) <
            (uint)*(ushort *)(iVar8 + 0x2e) + (uint)(byte)param_1[3]) {
          if (*(short *)(iVar8 + 0x2c) != 0) {
            r_ble_util_buf_adv_tx_free();
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x2c) = 0;
          }
_L489:
          uVar10 = 7;
        }
        else {
          if ((param_1[1] & 0xfd) == 1) {
            if (*(short *)(iVar8 + 0x2c) != 0) {
              r_ble_util_buf_adv_tx_free();
              *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x2e) = 0;
            }
            iVar8 = *(int *)(_p_llm_env + 8) + iVar5;
            if (param_1[1] == '\x03') {
              uVar6 = (ushort)(byte)param_1[3];
              if (uVar6 != 0) goto _L488;
              uVar7 = 0;
              bVar3 = true;
            }
            else {
              uVar6 = *(ushort *)(iVar8 + 0x30);
_L488:
              uVar7 = r_ble_util_buf_adv_tx_alloc(uVar6);
              bVar3 = false;
            }
            iVar4 = _p_llm_env;
            *(undefined2 *)(iVar8 + 0x2c) = uVar7;
            if ((*(short *)(*(int *)(iVar4 + 8) + iVar5 + 0x2c) == 0) && (!bVar3)) goto _L489;
          }
          bVar1 = param_1[3];
          if (bVar1 != 0) {
            iVar8 = *(int *)(_p_llm_env + 8) + iVar5;
            __dest = (void *)r_emi_get_mem_addr_by_offset
                                       (*(short *)(iVar8 + 0x2c) + *(short *)(iVar8 + 0x2e));
            memcpy(__dest,param_1 + 4,(uint)bVar1);
            iVar8 = *(int *)(_p_llm_env + 8) + iVar5;
            *(ushort *)(iVar8 + 0x2e) = *(short *)(iVar8 + 0x2e) + (ushort)(byte)param_1[3];
          }
          if ((byte)(param_1[1] - 2) < 2) {
            iVar8 = *(int *)(_p_llm_env + 8) + iVar5;
            if (*(char *)(iVar8 + 0x40) == '\x02') {
              r_lld_adv_adv_data_update
                        (iVar9,*(undefined1 *)(iVar8 + 0x2e),*(undefined2 *)(iVar8 + 0x2c));
            }
            else if (*(short *)(iVar8 + 0x28) != 0) {
              r_ble_util_buf_adv_tx_free();
            }
            iVar5 = *(int *)(_p_llm_env + 8) + iVar5;
            uVar10 = *(undefined4 *)(iVar5 + 0x2c);
            *(undefined4 *)(iVar5 + 0x2c) = 0;
            *(undefined4 *)(iVar5 + 0x28) = uVar10;
            if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
              uStack_26 = *(undefined2 *)(iVar5 + 0x34);
              uStack_24 = *(undefined1 *)(iStack_30 + 10);
              uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 |
                          (uint)*(byte *)(iStack_30 + 8) << 8 | (uint)*(byte *)(iStack_30 + 7);
              uStack_28 = *(undefined2 *)(iVar5 + 0x2e);
              if ((*(byte *)(iStack_30 + 0x15) < 3) ||
                 (iVar5 = lld_phy_coded_500k_get(), iVar5 == 0)) {
                cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
              }
              else {
                cStack_23 = *(char *)(iStack_30 + 0x15);
              }
              if ((*(byte *)(iStack_30 + 0x17) < 3) ||
                 (iVar5 = lld_phy_coded_500k_get(), iVar5 == 0)) {
                cStack_22 = *(char *)(iStack_30 + 0x17) + -1;
              }
              else {
                cStack_22 = *(char *)(iStack_30 + 0x17);
              }
              uStack_21 = *(undefined1 *)(iStack_30 + 0x16);
              (**(code **)(_bt_rf_coex_hooks_p + 4))
                        (iVar9,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
            }
          }
          else if (param_1[1] == '\x04') {
            r_lld_adv_adv_data_update(iVar9,0,0);
          }
          uVar10 = 0;
        }
        goto _L459;
      }
    }
  }
_L427:
  uVar10 = 0x12;
_L459:
  r_llm_cmd_cmp_send(param_2,uVar10);
  return 0;
}

