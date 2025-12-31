/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_ext_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_adv_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
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
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar9 = 0xc;
    goto _L487;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar7 = r_llm_adv_hdl_to_id(*param_1,&iStack_30);
  uVar9 = 0x42;
  if (iVar7 == 0xff) goto _L487;
  bVar1 = param_1[1];
  uVar9 = 0x12;
  if (((4 < bVar1) || (1 < (byte)param_1[2])) || (bVar2 = param_1[3], 0xfb < bVar2)) goto _L487;
  uVar5 = *(ushort *)(iStack_30 + 2);
  if ((uVar5 & 0x10) == 0) {
    if ((bVar1 == 4) &&
       (((iVar11 = *(int *)(_p_llm_env + 8) + iVar7 * 0x44, *(char *)(iVar11 + 0x40) == '\x01' ||
         (*(short *)(iVar11 + 0x28) == 0)) || (bVar2 != 0)))) goto _L487;
  }
  else if ((bVar1 != 3) || (0x1f < bVar2)) goto _L487;
  if (((1 < (byte)(bVar1 - 3)) && (uVar9 = 0x12, bVar2 == 0)) || (uVar9 = 0x12, (uVar5 & 0x12) == 2)
     ) goto _L487;
  iVar11 = iVar7 * 0x44;
  if (*(char *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x40) != '\x01') {
    uVar9 = 0xc;
    if (1 < (byte)(bVar1 - 3)) goto _L487;
    if (((uVar5 & 0x11) == 1) && (iVar8 = r_llm_adv_con_len_check(), iVar8 != 0)) {
      uVar10 = (uint)*(ushort *)(iStack_30 + 2) | (uint)(byte)param_1[3] << 0x18;
      uVar9 = 0x802e0163;
    }
    else {
      if (((*(ushort *)(iStack_30 + 2) & 0x1c) != 0x10) || ((byte)param_1[3] < 0x20)) goto _L462;
      uVar10 = (uint)(byte)param_1[3] << 0x18 | (uint)*(ushort *)(iStack_30 + 2);
      uVar9 = 0x802e0164;
    }
    r_ble_log_internal_x1(uVar9,uVar10 | 0x120000);
    uVar9 = 0x12;
    goto _L487;
  }
_L462:
  if ((*(ushort *)(iStack_30 + 2) & 0x11) == 1) {
    iVar8 = r_llm_adv_con_len_check(param_1[3]);
    uVar9 = 0x45;
    if (iVar8 != 0) goto _L487;
  }
  iVar8 = *(int *)(_p_llm_env + 8) + iVar11;
  if ((uint)*(ushort *)(iVar8 + 0x30) < (uint)*(ushort *)(iVar8 + 0x2e) + (uint)(byte)param_1[3]) {
    r_ble_log_internal_x2(0x802e0165,iVar7 << 8 | (uint)(byte)param_1[3] << 0x10 | 7);
    if (*(short *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x2c) != 0) {
      r_ble_util_buf_adv_tx_free();
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x2c) = 0;
    }
_L527:
    uVar9 = 7;
  }
  else {
    if ((param_1[1] & 0xfd) == 1) {
      if (*(short *)(iVar8 + 0x2c) != 0) {
        r_ble_util_buf_adv_tx_free(*(undefined4 *)(iVar8 + 0x2e));
        *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x2e) = 0;
      }
      iVar8 = *(int *)(_p_llm_env + 8) + iVar11;
      if (param_1[1] == '\x03') {
        uVar5 = (ushort)(byte)param_1[3];
        if (uVar5 != 0) goto _L525;
        uVar6 = 0;
        bVar3 = true;
      }
      else {
        uVar5 = *(ushort *)(iVar8 + 0x30);
_L525:
        uVar6 = r_ble_util_buf_adv_tx_alloc(uVar5);
        bVar3 = false;
      }
      iVar4 = _p_llm_env;
      *(undefined2 *)(iVar8 + 0x2c) = uVar6;
      if ((*(short *)(*(int *)(iVar4 + 8) + iVar11 + 0x2c) == 0) && (!bVar3)) goto _L527;
    }
    bVar1 = param_1[3];
    if (bVar1 != 0) {
      iVar8 = *(int *)(_p_llm_env + 8) + iVar11;
      __dest = (void *)r_emi_get_mem_addr_by_offset
                                 (*(short *)(iVar8 + 0x2c) + *(short *)(iVar8 + 0x2e));
      memcpy(__dest,param_1 + 4,(uint)bVar1);
      iVar8 = *(int *)(_p_llm_env + 8) + iVar11;
      *(ushort *)(iVar8 + 0x2e) = *(short *)(iVar8 + 0x2e) + (ushort)(byte)param_1[3];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar8 = *(int *)(_p_llm_env + 8) + iVar11;
      if (*(char *)(iVar8 + 0x40) == '\x02') {
        r_lld_adv_adv_data_update_hack
                  (iVar7,*(undefined1 *)(iVar8 + 0x2e),*(undefined2 *)(iVar8 + 0x2c));
      }
      else if (*(short *)(iVar8 + 0x28) != 0) {
        r_ble_util_buf_adv_tx_free();
      }
      iVar11 = *(int *)(_p_llm_env + 8) + iVar11;
      uVar9 = *(undefined4 *)(iVar11 + 0x2c);
      *(undefined4 *)(iVar11 + 0x2c) = 0;
      *(undefined4 *)(iVar11 + 0x28) = uVar9;
      if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
        uStack_26 = *(undefined2 *)(iVar11 + 0x34);
        uStack_24 = *(undefined1 *)(iStack_30 + 10);
        uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 | (uint)*(byte *)(iStack_30 + 8) << 8 |
                    (uint)*(byte *)(iStack_30 + 7);
        uStack_28 = *(undefined2 *)(iVar11 + 0x2e);
        if ((*(byte *)(iStack_30 + 0x15) < 3) || (iVar11 = lld_phy_coded_500k_get(), iVar11 == 0)) {
          cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
        }
        else {
          cStack_23 = *(char *)(iStack_30 + 0x15);
        }
        if ((*(byte *)(iStack_30 + 0x17) < 3) || (iVar11 = lld_phy_coded_500k_get(), iVar11 == 0)) {
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
    uVar9 = 0;
  }
_L487:
  r_llm_cmd_cmp_send(param_2,uVar9);
  return 0;
}

