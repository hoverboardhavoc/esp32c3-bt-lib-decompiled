/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
      r_ble_log_internal_x1(0x802e014e,uVar3 << 8 | 0x12);
      uVar2 = 0x12;
    }
  }
  else {
    r_ble_log_internal_x1(0x802e014f,uVar3 << 8 | 0xc);
    uVar2 = 0xc;
  }
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

