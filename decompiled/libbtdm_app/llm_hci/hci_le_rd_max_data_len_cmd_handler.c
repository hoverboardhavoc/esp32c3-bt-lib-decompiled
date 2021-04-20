/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rd_max_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_max_data_len_cmd_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  code *pcVar2;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,param_1,10,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = 0;
  pcVar2 = *(code **)(_r_ip_funcs_p + 0x8c);
  *(undefined2 *)(puVar1 + 6) = 0xfb;
  *(undefined2 *)(puVar1 + 8) = 0x4290;
  *(undefined2 *)(puVar1 + 2) = 0xfb;
  *(undefined2 *)(puVar1 + 4) = 0x4290;
  (*pcVar2)(pcVar2);
  return 0;
}

