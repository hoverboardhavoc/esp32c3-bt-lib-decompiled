/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_add_dev_to_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_wlst_cmd_handler(char *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char local_19;
  undefined1 auStack_18 [8];
  
  iVar1 = r_llm_is_wl_accessible();
  uVar3 = 0xc;
  if (iVar1 == 0) goto _L230;
  if ((byte)(*param_1 - 2U) < 0xfd) {
_L227:
    uVar3 = 0x12;
  }
  else {
    local_19 = *param_1;
    memcpy(auStack_18,param_1 + 1,6);
    lld_peer_rpa_to_id(auStack_18,&local_19);
    uVar2 = r_llm_dev_list_search(auStack_18,local_19);
    if (uVar2 < 0xc) {
      if ((*(byte *)(_p_llm_env + uVar2 * 10 + 0x2d) & 2) != 0) goto _L227;
    }
    else {
      uVar2 = r_llm_dev_list_empty_entry();
      uVar3 = 7;
      if (uVar2 == 0xc) goto _L230;
    }
    iVar1 = _p_llm_env + uVar2 * 10;
    memcpy((void *)(iVar1 + 0x24),auStack_18,6);
    *(char *)(iVar1 + 0x2c) = local_19;
    *(byte *)(iVar1 + 0x2d) = *(byte *)(iVar1 + 0x2d) | 3;
    iVar1 = r_llm_is_dev_connected(auStack_18);
    if (iVar1 == 0) {
      r_lld_white_list_add(uVar2,auStack_18,local_19);
    }
    uVar3 = 0;
  }
_L230:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

