/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_per_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_per_adv_data_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  ushort uVar5;
  undefined2 uVar6;
  void *__dest;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  iVar7 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar7 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L713:
    uVar8 = 0xc;
    goto _L711;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (0xef < *param_1) goto _L714;
  iVar7 = r_llm_adv_hdl_to_id(0);
  uVar8 = 0x42;
  if (iVar7 == 0xff) goto _L711;
  iVar11 = *(int *)(_p_llm_env + 8);
  uVar12 = (uint)*(byte *)(iVar11 + iVar7 * 0x44 + 0x3d);
  if (uVar12 == 0xff) goto _L713;
  bVar1 = param_1[1];
  if ((3 < bVar1) || (uVar9 = (uint)param_1[2], 0xfc < uVar9)) {
_L714:
    uVar8 = 0x12;
    goto _L711;
  }
  if (bVar1 != 3) {
    if (uVar9 == 0) goto _L714;
    if (*(char *)(uVar12 * 0x44 + iVar11 + 0x40) == '\f') goto _L713;
  }
  iVar3 = uVar12 * 0x44;
  iVar11 = iVar11 + iVar3;
  if ((uint)*(ushort *)(iVar11 + 0x30) < *(ushort *)(iVar11 + 0x2e) + uVar9) {
    if (*(short *)(iVar11 + 0x2c) != 0) {
      r_ble_util_buf_adv_tx_free();
      *(undefined4 *)(iVar3 + *(int *)(_p_llm_env + 8) + 0x2c) = 0;
    }
_L754:
    uVar8 = 7;
  }
  else {
    if ((bVar1 & 0xfd) == 1) {
      if (*(short *)(iVar11 + 0x2c) != 0) {
        r_ble_util_buf_adv_tx_free();
        *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2e) = 0;
      }
      iVar11 = *(int *)(_p_llm_env + 8) + iVar3;
      if (param_1[1] == 3) {
        uVar5 = (ushort)param_1[2];
        if (uVar5 != 0) goto _L753;
        *(undefined2 *)(iVar11 + 0x2c) = 0;
        bVar2 = true;
      }
      else {
        uVar5 = *(ushort *)(iVar11 + 0x30);
_L753:
        uVar6 = r_ble_util_buf_adv_tx_alloc(uVar5);
        *(undefined2 *)(iVar11 + 0x2c) = uVar6;
        bVar2 = false;
      }
      if ((*(short *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2c) == 0) && (!bVar2)) goto _L754;
    }
    bVar1 = param_1[2];
    if (bVar1 != 0) {
      iVar11 = *(int *)(_p_llm_env + 8) + iVar3;
      __dest = (void *)r_emi_get_mem_addr_by_offset
                                 (*(short *)(iVar11 + 0x2c) + *(short *)(iVar11 + 0x2e));
      memcpy(__dest,param_1 + 3,(uint)bVar1);
      iVar11 = *(int *)(_p_llm_env + 8) + iVar3;
      *(ushort *)(iVar11 + 0x2e) = *(short *)(iVar11 + 0x2e) + (ushort)param_1[2];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar11 = *(int *)(_p_llm_env + 8) + iVar3;
      if (*(char *)(iVar11 + 0x40) == '\f') {
        r_lld_per_adv_data_update_hack
                  (uVar12,*(undefined1 *)(iVar11 + 0x2e),*(undefined2 *)(iVar11 + 0x2c));
      }
      else if (*(short *)(iVar11 + 0x28) != 0) {
        r_ble_util_buf_adv_tx_free();
      }
      iVar11 = *(int *)(_p_llm_env + 8);
      piVar4 = (int *)(iVar3 + iVar11);
      iVar3 = piVar4[0xb];
      piVar4[0xb] = 0;
      piVar4[10] = iVar3;
      if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
        iVar7 = *(int *)(iVar11 + iVar7 * 0x44);
        uStack_2c = (uint)*(ushort *)(*piVar4 + 4);
        uStack_26 = 0;
        uStack_24 = 0;
        uStack_22 = 0;
        uStack_28 = *(undefined2 *)((int)piVar4 + 0x2e);
        if ((*(byte *)(iVar7 + 0x17) < 3) || (iVar11 = lld_phy_coded_500k_get(), iVar11 == 0)) {
          cVar10 = *(char *)(iVar7 + 0x17) + -1;
        }
        else {
          cVar10 = *(char *)(iVar7 + 0x17);
        }
        uStack_26 = CONCAT11(uStack_26._1_1_,cVar10);
        (**(code **)(_bt_rf_coex_hooks_p + 4))
                  (uVar12,4,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
      }
    }
    uVar8 = 0;
  }
_L711:
  r_llm_cmd_cmp_send(param_2,uVar8);
  return 0;
}

