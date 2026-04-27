/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_set_addr_resol_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_addr_resol_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = r_llm_is_non_con_act_ongoing_check();
  uVar3 = (uint)*param_1;
  if (iVar1 == 0) {
    if (uVar3 < 2) {
      uVar2 = 0;
      *(byte *)(_p_llm_env + 0xc6) = *param_1 & 1;
    }
    else {
      r_ble_log_internal_x1(0x802e01d7,uVar3 << 8 | 0x12);
      uVar2 = 0x12;
    }
  }
  else {
    r_ble_log_internal_x1(0x802e01d8,uVar3 << 8 | 0xc);
    uVar2 = 0xc;
  }
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

