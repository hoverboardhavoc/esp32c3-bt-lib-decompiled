/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> llm_hci_env_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool llm_hci_env_init(void)

{
  bool bVar1;
  
  llm_hci_command_handler_tab =
       (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x260,*(code **)(_r_osi_funcs_p + 0x78));
  bVar1 = llm_hci_command_handler_tab != (void *)0x0;
  if (bVar1) {
    memcpy(llm_hci_command_handler_tab,llm_hci_command_handler_tab_ro,0x260);
  }
  return bVar1;
}

