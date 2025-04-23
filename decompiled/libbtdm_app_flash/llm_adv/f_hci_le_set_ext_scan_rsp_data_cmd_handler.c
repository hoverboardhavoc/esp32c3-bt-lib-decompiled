/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_ext_scan_rsp_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_scan_rsp_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  void *__dest;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  int iStack_30;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined1 uStack_24;
  char cStack_23;
  char cStack_22;
  undefined1 uStack_21;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') goto _L486;
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar8 = r_llm_adv_hdl_to_id(*param_1,&iStack_30);
  uVar9 = 0x42;
  if (iVar8 == 0xff) goto _L516;
  bVar1 = param_1[1];
  uVar9 = 0x12;
  if (((3 < bVar1) || (1 < (byte)param_1[2])) || (uVar10 = (uint)(byte)param_1[3], 0xfb < uVar10))
  goto _L516;
  uVar6 = *(ushort *)(iStack_30 + 2);
  if ((uVar6 & 0x10) == 0) {
    if ((bVar1 != 3) && (uVar10 == 0)) goto _L516;
  }
  else if ((bVar1 != 3) || (0x1f < uVar10)) goto _L516;
  if (((uVar6 & 2) == 0) && (uVar9 = 0x12, uVar10 != 0)) goto _L516;
  iVar11 = iVar8 * 0x44;
  iVar5 = *(int *)(_p_llm_env + 8) + iVar11;
  if (*(char *)(iVar5 + 0x40) != '\x01') {
    if (bVar1 != 3) {
_L486:
      uVar9 = 0xc;
      goto _L516;
    }
    if ((uVar6 & 2) != 0) {
      if (uVar10 == 0) {
        if ((uVar6 & 0x10) == 0) goto _L486;
      }
      else if (((uVar6 & 0x12) == 0x12) && (uVar9 = 0x12, 0x1f < uVar10)) goto _L516;
    }
  }
  if ((uint)*(ushort *)(iVar5 + 0x3a) < uVar10 + *(ushort *)(iVar5 + 0x38)) {
    if (*(short *)(iVar5 + 0x36) != 0) {
      r_ble_util_buf_adv_tx_free();
      iVar11 = *(int *)(_p_llm_env + 8) + iVar11;
      *(undefined2 *)(iVar11 + 0x36) = 0;
      *(undefined2 *)(iVar11 + 0x38) = 0;
    }
_L495:
    uVar9 = 7;
  }
  else {
    if ((bVar1 & 0xfd) == 1) {
      if (*(short *)(iVar5 + 0x36) != 0) {
        r_ble_util_buf_adv_tx_free();
        iVar5 = *(int *)(_p_llm_env + 8) + iVar11;
        *(undefined2 *)(iVar5 + 0x38) = 0;
      }
      if (param_1[1] == '\x03') {
        uVar6 = (ushort)(byte)param_1[3];
        if (uVar6 != 0) goto _L550;
        uVar7 = 0;
        bVar3 = true;
      }
      else {
        uVar6 = *(ushort *)(iVar5 + 0x3a);
_L550:
        uVar7 = r_ble_util_buf_adv_tx_alloc(uVar6);
        bVar3 = false;
      }
      iVar4 = _p_llm_env;
      *(undefined2 *)(iVar5 + 0x36) = uVar7;
      if ((*(short *)(*(int *)(iVar4 + 8) + iVar11 + 0x36) == 0) && (!bVar3)) goto _L495;
    }
    bVar1 = param_1[3];
    if (bVar1 != 0) {
      iVar5 = *(int *)(_p_llm_env + 8) + iVar11;
      __dest = (void *)r_emi_get_mem_addr_by_offset
                                 (*(short *)(iVar5 + 0x36) + *(short *)(iVar5 + 0x38));
      memcpy(__dest,param_1 + 4,(uint)bVar1);
      iVar5 = *(int *)(_p_llm_env + 8) + iVar11;
      *(ushort *)(iVar5 + 0x38) = *(short *)(iVar5 + 0x38) + (ushort)(byte)param_1[3];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar5 = *(int *)(_p_llm_env + 8) + iVar11;
      if (*(char *)(iVar5 + 0x40) == '\x02') {
        r_lld_adv_scan_rsp_data_update
                  (iVar8,*(undefined1 *)(iVar5 + 0x38),*(undefined2 *)(iVar5 + 0x36));
      }
      else if (*(short *)(iVar5 + 0x32) != 0) {
        r_ble_util_buf_adv_tx_free();
      }
      iVar11 = *(int *)(_p_llm_env + 8) + iVar11;
      uVar7 = *(undefined2 *)(iVar11 + 0x36);
      uVar2 = *(undefined2 *)(iVar11 + 0x38);
      *(undefined2 *)(iVar11 + 0x36) = 0;
      *(undefined2 *)(iVar11 + 0x32) = uVar7;
      iVar5 = _bt_rf_coex_hooks_p;
      *(undefined2 *)(iVar11 + 0x34) = uVar2;
      *(undefined2 *)(iVar11 + 0x38) = 0;
      if ((iVar5 != 0) && (*(int *)(iVar5 + 4) != 0)) {
        uStack_28 = *(undefined2 *)(iVar11 + 0x2a);
        uStack_24 = *(undefined1 *)(iStack_30 + 10);
        uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 | (uint)*(byte *)(iStack_30 + 8) << 8 |
                    (uint)*(byte *)(iStack_30 + 7);
        uStack_26 = uVar2;
        if ((*(byte *)(iStack_30 + 0x15) < 3) || (iVar5 = lld_phy_coded_500k_get(), iVar5 == 0)) {
          cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
        }
        else {
          cStack_23 = *(char *)(iStack_30 + 0x15);
        }
        if ((*(byte *)(iStack_30 + 0x17) < 3) || (iVar5 = lld_phy_coded_500k_get(), iVar5 == 0)) {
          cStack_22 = *(char *)(iStack_30 + 0x17) + -1;
        }
        else {
          cStack_22 = *(char *)(iStack_30 + 0x17);
        }
        uStack_21 = *(undefined1 *)(iStack_30 + 0x16);
        (**(code **)(_bt_rf_coex_hooks_p + 4))
                  (iVar8,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
      }
    }
    else if (param_1[1] == '\x04') {
      r_lld_adv_scan_rsp_data_update(iVar8,0,0);
    }
    uVar9 = 0;
  }
_L516:
  r_llm_cmd_cmp_send(param_2,uVar9);
  return 0;
}

