/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_set_rand_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_rand_addr_cmd_handler(void *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = llm_is_non_con_legacy_act_ongoing_check();
  if (iVar1 == 0) {
    iVar1 = r_co_bdaddr_compare(param_1,&co_null_bdaddr);
    if (iVar1 == 0) {
      memcpy((void *)(_p_llm_env + 0x12),param_1,6);
      uVar2 = 0;
    }
    else {
      r_ble_log_internal_x1(0x802e019b,0x12);
      uVar2 = 0x12;
    }
  }
  else {
    r_ble_log_internal_x1(0x802e019c,0xc);
    uVar2 = 0xc;
  }
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

