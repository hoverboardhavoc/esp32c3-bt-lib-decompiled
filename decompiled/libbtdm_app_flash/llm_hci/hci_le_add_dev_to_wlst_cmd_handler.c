/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_add_dev_to_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_wlst_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  byte local_19;
  undefined1 auStack_18 [8];
  
  iVar2 = r_llm_is_wl_accessible();
  uVar4 = 0xc;
  if (iVar2 == 0) goto _L232;
  bVar1 = *param_1;
  if ((bVar1 - 2 & 0xff) < 0xfd) {
    r_ble_log_internal_x1(0x802e01ca,(uint)bVar1 << 8 | 0x12);
    uVar4 = 0x12;
    goto _L232;
  }
  local_19 = bVar1;
  memcpy(auStack_18,param_1 + 1,6);
  lld_peer_rpa_to_id(auStack_18,&local_19);
  uVar3 = r_llm_dev_list_search(auStack_18,local_19);
  if (uVar3 < 0xc) {
    if ((*(byte *)(_p_llm_env + uVar3 * 10 + 0x2d) & 2) == 0) goto _L230;
    r_ble_log_internal_x1(0x602e01cb);
  }
  else {
    uVar3 = r_llm_dev_list_empty_entry(uVar3);
    if (uVar3 == 0xc) {
      r_ble_log_internal_x1(0x802e01cc,0xc07);
      uVar4 = 7;
      goto _L232;
    }
_L230:
    iVar2 = _p_llm_env + uVar3 * 10;
    memcpy((void *)(iVar2 + 0x24),auStack_18,6);
    *(byte *)(iVar2 + 0x2c) = local_19;
    *(byte *)(iVar2 + 0x2d) = *(byte *)(iVar2 + 0x2d) | 3;
    iVar2 = r_llm_is_dev_connected(auStack_18);
    if (iVar2 == 0) {
      r_lld_white_list_add(uVar3,auStack_18,local_19);
    }
  }
  uVar4 = 0;
_L232:
  r_llm_cmd_cmp_send(param_2,uVar4);
  return 0;
}

