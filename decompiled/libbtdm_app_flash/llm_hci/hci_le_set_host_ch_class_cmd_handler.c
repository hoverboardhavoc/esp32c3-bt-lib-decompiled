/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_set_host_ch_class_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_host_ch_class_cmd_handler(void *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc;
  if (*(char *)(_p_llm_env + 0x23) == '\0') {
    if ((*(byte *)((int)param_1 + 4) < 0x20) &&
       (cVar1 = r_co_nb_good_le_channels(0xc), (byte)(cVar1 - 1U) < 0x25)) {
      memcpy((void *)(_p_llm_env + 0x18),param_1,5);
      r_ke_timer_set(5,0,100);
      *(undefined1 *)(_p_llm_env + 0x23) = 1;
      r_ke_timer_clear(4,0);
      r_llm_ch_map_update_hack();
      uVar2 = 0;
    }
    else {
      uVar2 = 0x12;
    }
  }
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

