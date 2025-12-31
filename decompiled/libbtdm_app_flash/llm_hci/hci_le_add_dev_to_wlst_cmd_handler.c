/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_add_dev_to_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_wlst_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte local_19;
  undefined1 auStack_18 [8];
  
  iVar1 = r_llm_is_wl_accessible();
  uVar2 = 0xc;
  if (iVar1 == 0) goto _L232;
  uVar3 = (uint)*param_1;
  if ((uVar3 - 2 & 0xff) < 0xfd) {
    uVar2 = 0x802e019f;
_L238:
    r_ble_log_internal_x1(uVar2,uVar3 << 8 | 0x12);
    uVar2 = 0x12;
  }
  else {
    local_19 = *param_1;
    memcpy(auStack_18,param_1 + 1,6);
    lld_peer_rpa_to_id(auStack_18,&local_19);
    uVar3 = r_llm_dev_list_search(auStack_18,local_19);
    if (uVar3 < 0xc) {
      if ((*(byte *)(_p_llm_env + uVar3 * 10 + 0x2d) & 2) != 0) {
        uVar2 = 0x802e01a0;
        goto _L238;
      }
    }
    else {
      uVar3 = r_llm_dev_list_empty_entry();
      if (uVar3 == 0xc) {
        r_ble_log_internal_x1(0x802e01a1,0xc07);
        uVar2 = 7;
        goto _L232;
      }
    }
    iVar1 = _p_llm_env + uVar3 * 10;
    memcpy((void *)(iVar1 + 0x24),auStack_18,6);
    *(byte *)(iVar1 + 0x2c) = local_19;
    *(byte *)(iVar1 + 0x2d) = *(byte *)(iVar1 + 0x2d) | 3;
    iVar1 = r_llm_is_dev_connected(auStack_18);
    if (iVar1 == 0) {
      r_lld_white_list_add(uVar3,auStack_18,local_19);
    }
    uVar2 = 0;
  }
_L232:
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

