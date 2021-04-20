/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rd_buff_size_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_buff_size_cmd_handler(void)

{
  int iVar1;
  undefined1 *puVar2;
  code *pcVar3;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,0x2002,6,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = 0;
  iVar1 = _r_ip_funcs_p;
  puVar2[4] = 0xc;
  pcVar3 = *(code **)(iVar1 + 0x8c);
  *(undefined2 *)(puVar2 + 2) = 0xfb;
  (*pcVar3)(pcVar3);
  return 0;
}

