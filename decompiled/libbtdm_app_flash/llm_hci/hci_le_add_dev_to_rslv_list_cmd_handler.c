/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_add_dev_to_rslv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_rslv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*param_1 < 2) {
    if ((*(char *)(_p_llm_env + 0xc6) == '\0') ||
       (iVar3 = r_llm_is_non_con_act_ongoing_check(), iVar3 == 0)) {
      uVar2 = r_llm_dev_list_search(param_1 + 1,*param_1);
      if (uVar2 < 0xc) {
        uVar1 = (int)(uint)*(byte *)(_p_llm_env + uVar2 * 10 + 0x2d) >> 1 & 1;
      }
      else {
        uVar1 = 0;
      }
      uVar1 = r_lld_res_list_add(param_1 + 1,param_1 + 7,param_1 + 0x17,*param_1,0,uVar1);
      if (uVar1 != 0) {
        r_ble_log_internal_x1(0x802e0149,uVar2 << 8 | uVar1);
      }
    }
    else {
      uVar1 = 0xc;
      r_ble_log_internal_x1(0x802e014a,(uint)*(byte *)(_p_llm_env + 0xc6) << 8 | 0xc);
    }
  }
  else {
    r_ble_log_internal_x1(0x802e0148,(uint)*param_1 << 8 | 0x12);
    uVar1 = 0x12;
  }
  r_llm_cmd_cmp_send(param_2,uVar1);
  return 0;
}

