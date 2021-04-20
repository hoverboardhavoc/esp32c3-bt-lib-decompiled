/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_set_evt_mask_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_evt_mask_cmd_handler(void *param_1,undefined4 param_2)

{
  memcpy(_p_llm_env,param_1,8);
  (**(code **)(_r_ip_funcs_p + 0x80))(_p_llm_env,4,*(code **)(_r_ip_funcs_p + 0x80));
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

