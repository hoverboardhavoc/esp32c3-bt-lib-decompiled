/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_ext_scan_rsp_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_scan_rsp_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  ushort uVar5;
  undefined2 uVar6;
  void *__dest;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
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
_L493:
    uVar8 = 0xc;
    goto _L521;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar7 = r_llm_adv_hdl_to_id(*param_1,&iStack_30);
  uVar8 = 0x42;
  if (iVar7 == 0xff) goto _L521;
  bVar1 = param_1[1];
  uVar8 = 0x12;
  if (((3 < bVar1) || (1 < (byte)param_1[2])) || (uVar9 = (uint)(byte)param_1[3], 0xfb < uVar9))
  goto _L521;
  uVar5 = *(ushort *)(iStack_30 + 2);
  if ((uVar5 & 0x10) == 0) {
    if ((bVar1 != 3) && (uVar9 == 0)) goto _L521;
  }
  else if ((bVar1 != 3) || (0x1f < uVar9)) goto _L521;
  if (((uVar5 & 2) == 0) && (uVar8 = 0x12, uVar9 != 0)) goto _L521;
  iVar4 = iVar7 * 0x44;
  iVar10 = *(int *)(_p_llm_env + 8) + iVar4;
  if (*(char *)(iVar10 + 0x40) != '\x01') {
    if ((bVar1 != 3) || ((((uVar5 & 2) != 0 && (uVar9 == 0)) && ((uVar5 & 0x10) == 0)))) goto _L493;
    uVar8 = 0x12;
    if (((uVar5 & 0x12) == 0x12) && (0x1f < uVar9)) goto _L521;
  }
  if ((uint)*(ushort *)(iVar10 + 0x3a) < uVar9 + *(ushort *)(iVar10 + 0x38)) {
    if (*(short *)(iVar10 + 0x36) != 0) {
      r_ble_util_buf_adv_tx_free();
      iVar4 = iVar4 + *(int *)(_p_llm_env + 8);
      *(undefined2 *)(iVar4 + 0x36) = 0;
      *(undefined2 *)(iVar4 + 0x38) = 0;
    }
_L555:
    uVar8 = 7;
  }
  else {
    if ((bVar1 & 0xfd) == 1) {
      if (*(short *)(iVar10 + 0x36) != 0) {
        r_ble_util_buf_adv_tx_free();
        *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x38) = 0;
      }
      iVar10 = *(int *)(_p_llm_env + 8) + iVar4;
      if (param_1[1] == '\x03') {
        uVar5 = (ushort)(byte)param_1[3];
        if (uVar5 != 0) goto _L554;
        *(undefined2 *)(iVar10 + 0x36) = 0;
        bVar3 = true;
      }
      else {
        uVar5 = *(ushort *)(iVar10 + 0x3a);
_L554:
        uVar6 = r_ble_util_buf_adv_tx_alloc(uVar5);
        *(undefined2 *)(iVar10 + 0x36) = uVar6;
        bVar3 = false;
      }
      if ((*(short *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x36) == 0) && (!bVar3)) goto _L555;
    }
    bVar1 = param_1[3];
    if (bVar1 != 0) {
      iVar10 = *(int *)(_p_llm_env + 8) + iVar4;
      __dest = (void *)r_emi_get_mem_addr_by_offset
                                 (*(short *)(iVar10 + 0x36) + *(short *)(iVar10 + 0x38));
      memcpy(__dest,param_1 + 4,(uint)bVar1);
      iVar10 = *(int *)(_p_llm_env + 8) + iVar4;
      *(ushort *)(iVar10 + 0x38) = *(short *)(iVar10 + 0x38) + (ushort)(byte)param_1[3];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar10 = *(int *)(_p_llm_env + 8) + iVar4;
      if (*(char *)(iVar10 + 0x40) == '\x02') {
        r_lld_adv_scan_rsp_data_update_hack
                  (iVar7,*(undefined1 *)(iVar10 + 0x38),*(undefined2 *)(iVar10 + 0x36));
      }
      else if (*(short *)(iVar10 + 0x32) != 0) {
        r_ble_util_buf_adv_tx_free();
      }
      iVar4 = iVar4 + *(int *)(_p_llm_env + 8);
      uVar6 = *(undefined2 *)(iVar4 + 0x36);
      uVar2 = *(undefined2 *)(iVar4 + 0x38);
      *(undefined2 *)(iVar4 + 0x36) = 0;
      *(undefined2 *)(iVar4 + 0x32) = uVar6;
      iVar10 = _bt_rf_coex_hooks_p;
      *(undefined2 *)(iVar4 + 0x34) = uVar2;
      *(undefined2 *)(iVar4 + 0x38) = 0;
      if ((iVar10 != 0) && (*(int *)(iVar10 + 4) != 0)) {
        uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 | (uint)*(byte *)(iStack_30 + 8) << 8 |
                    (uint)*(byte *)(iStack_30 + 7);
        uStack_28 = *(undefined2 *)(iVar4 + 0x2a);
        uStack_24 = *(undefined1 *)(iStack_30 + 10);
        uStack_26 = uVar2;
        if ((*(byte *)(iStack_30 + 0x15) < 3) || (iVar4 = lld_phy_coded_500k_get(), iVar4 == 0)) {
          cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
        }
        else {
          cStack_23 = *(char *)(iStack_30 + 0x15);
        }
        if ((*(byte *)(iStack_30 + 0x17) < 3) || (iVar4 = lld_phy_coded_500k_get(), iVar4 == 0)) {
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
      r_lld_adv_scan_rsp_data_update_hack(iVar7,0,0);
    }
    uVar8 = 0;
  }
_L521:
  r_llm_cmd_cmp_send(param_2,uVar8);
  return 0;
}

