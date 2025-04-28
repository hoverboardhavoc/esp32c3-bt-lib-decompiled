/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  byte bVar1;
  char cVar2;
  
  bVar1 = 0xc;
  if (*(char *)(_p_llm_env + 0x23) == '\0') {
    bVar1 = *(byte *)((int)param_1 + 4) & 0xe0;
    if (((*(byte *)((int)param_1 + 4) & 0xe0) == 0) &&
       (cVar2 = r_co_nb_good_le_channels(), (byte)(cVar2 - 1U) < 0x25)) {
      memcpy((void *)(_p_llm_env + 0x18),param_1,5);
      r_ke_timer_set(5,0,100);
      *(undefined1 *)(_p_llm_env + 0x23) = 1;
      r_ke_timer_clear(4,0);
      r_llm_ch_map_update_hack();
    }
    else {
      bVar1 = 0x12;
    }
  }
  r_llm_cmd_cmp_send(param_2,bVar1);
  return 0;
}

