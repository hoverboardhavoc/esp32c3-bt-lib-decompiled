/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rd_suggted_dft_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_suggted_dft_data_len_cmd_handler(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  puVar4 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,0x2023,6,*(code **)(_r_modules_funcs_p + 200));
  uVar1 = *(undefined2 *)(_p_llm_env + 0x9c);
  uVar2 = *(undefined2 *)(_p_llm_env + 0x9e);
  *puVar4 = 0;
  iVar3 = _r_ip_funcs_p;
  *(undefined2 *)(puVar4 + 2) = uVar1;
  *(undefined2 *)(puVar4 + 4) = uVar2;
  (**(code **)(iVar3 + 0x8c))(*(code **)(iVar3 + 0x8c));
  return 0;
}

