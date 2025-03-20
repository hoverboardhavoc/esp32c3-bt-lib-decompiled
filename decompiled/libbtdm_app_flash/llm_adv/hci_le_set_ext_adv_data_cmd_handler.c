/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  void *__dest;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iStack_30;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined1 uStack_24;
  char cStack_23;
  char cStack_22;
  undefined1 uStack_21;
  
  iVar7 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar7 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar8 = 0xc;
    goto _L456;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar7 = r_llm_adv_hdl_to_id(*param_1,&iStack_30);
  uVar8 = 0x42;
  if (iVar7 == 0xff) goto _L456;
  bVar1 = param_1[1];
  if (((bVar1 < 5) && ((byte)param_1[2] < 2)) && (bVar2 = param_1[3], bVar2 < 0xfc)) {
    uVar4 = *(ushort *)(iStack_30 + 2);
    if ((uVar4 & 0x10) == 0) {
      if ((bVar1 != 4) ||
         (((iVar9 = *(int *)(_p_llm_env + 8) + iVar7 * 0x44, *(char *)(iVar9 + 0x40) != '\x01' &&
           (*(short *)(iVar9 + 0x28) != 0)) && (bVar2 == 0)))) goto _L425;
    }
    else if ((bVar1 == 3) && (bVar2 < 0x20)) {
_L425:
      if ((((byte)(bVar1 - 3) < 2) || (bVar2 != 0)) && ((uVar4 & 0x12) != 2)) {
        iVar9 = iVar7 * 0x44;
        if (*(char *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x40) != '\x01') {
          uVar8 = 0xc;
          if (1 < (byte)(bVar1 - 3)) goto _L456;
          if ((((uVar4 & 0x11) == 1) && (iVar6 = r_llm_adv_con_len_check(), iVar6 != 0)) ||
             (((*(ushort *)(iStack_30 + 2) & 0x1c) == 0x10 && (0x1f < (byte)param_1[3]))))
          goto _L423;
        }
        if ((*(ushort *)(iStack_30 + 2) & 0x11) == 1) {
          iVar6 = r_llm_adv_con_len_check(param_1[3]);
          uVar8 = 0x45;
          if (iVar6 != 0) goto _L456;
        }
        iVar6 = *(int *)(_p_llm_env + 8) + iVar9;
        if ((uint)*(ushort *)(iVar6 + 0x30) <
            (uint)*(ushort *)(iVar6 + 0x2e) + (uint)(byte)param_1[3]) {
          if (*(short *)(iVar6 + 0x2c) != 0) {
            r_ble_util_buf_adv_tx_free();
            *(undefined4 *)(iVar9 + *(int *)(_p_llm_env + 8) + 0x2c) = 0;
          }
_L485:
          uVar8 = 7;
        }
        else {
          if ((param_1[1] & 0xfd) == 1) {
            if (*(short *)(iVar6 + 0x2c) != 0) {
              r_ble_util_buf_adv_tx_free();
              *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x2e) = 0;
            }
            iVar6 = *(int *)(_p_llm_env + 8) + iVar9;
            if (param_1[1] == '\x03') {
              uVar4 = (ushort)(byte)param_1[3];
              if (uVar4 != 0) goto _L484;
              *(undefined2 *)(iVar6 + 0x2c) = 0;
              bVar3 = true;
            }
            else {
              uVar4 = *(ushort *)(iVar6 + 0x30);
_L484:
              uVar5 = r_ble_util_buf_adv_tx_alloc(uVar4);
              *(undefined2 *)(iVar6 + 0x2c) = uVar5;
              bVar3 = false;
            }
            if ((*(short *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x2c) == 0) && (!bVar3)) goto _L485;
          }
          bVar1 = param_1[3];
          if (bVar1 != 0) {
            iVar6 = *(int *)(_p_llm_env + 8) + iVar9;
            __dest = (void *)r_emi_get_mem_addr_by_offset
                                       (*(short *)(iVar6 + 0x2c) + *(short *)(iVar6 + 0x2e));
            memcpy(__dest,param_1 + 4,(uint)bVar1);
            iVar6 = *(int *)(_p_llm_env + 8) + iVar9;
            *(ushort *)(iVar6 + 0x2e) = *(short *)(iVar6 + 0x2e) + (ushort)(byte)param_1[3];
          }
          if ((byte)(param_1[1] - 2) < 2) {
            iVar6 = *(int *)(_p_llm_env + 8) + iVar9;
            if (*(char *)(iVar6 + 0x40) == '\x02') {
              r_lld_adv_adv_data_update_hack
                        (iVar7,*(undefined1 *)(iVar6 + 0x2e),*(undefined2 *)(iVar6 + 0x2c));
            }
            else if (*(short *)(iVar6 + 0x28) != 0) {
              r_ble_util_buf_adv_tx_free();
            }
            iVar9 = iVar9 + *(int *)(_p_llm_env + 8);
            uVar8 = *(undefined4 *)(iVar9 + 0x2c);
            *(undefined4 *)(iVar9 + 0x2c) = 0;
            *(undefined4 *)(iVar9 + 0x28) = uVar8;
            if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
              uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 |
                          (uint)*(byte *)(iStack_30 + 8) << 8 | (uint)*(byte *)(iStack_30 + 7);
              uStack_26 = *(undefined2 *)(iVar9 + 0x34);
              uStack_24 = *(undefined1 *)(iStack_30 + 10);
              uStack_28 = *(undefined2 *)(iVar9 + 0x2e);
              if ((*(byte *)(iStack_30 + 0x15) < 3) ||
                 (iVar9 = lld_phy_coded_500k_get(), iVar9 == 0)) {
                cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
              }
              else {
                cStack_23 = *(char *)(iStack_30 + 0x15);
              }
              if ((*(byte *)(iStack_30 + 0x17) < 3) ||
                 (iVar9 = lld_phy_coded_500k_get(), iVar9 == 0)) {
                cStack_22 = *(char *)(iStack_30 + 0x17) + -1;
              }
              else {
                cStack_22 = *(char *)(iStack_30 + 0x17);
              }
              uStack_21 = *(undefined1 *)(iStack_30 + 0x16);
              (**(code **)(_bt_rf_coex_hooks_p + 4))
                        (iVar7,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
            }
          }
          else if (param_1[1] == '\x04') {
            r_lld_adv_adv_data_update_hack(iVar7,0,0);
          }
          uVar8 = 0;
        }
        goto _L456;
      }
    }
  }
_L423:
  uVar8 = 0x12;
_L456:
  r_llm_cmd_cmp_send(param_2,uVar8);
  return 0;
}

