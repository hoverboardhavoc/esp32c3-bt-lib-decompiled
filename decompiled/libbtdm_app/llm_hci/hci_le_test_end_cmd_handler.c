/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_test_end_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_test_end_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x1f) == '\0') {
    puVar2 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,0,0x201f,4,*(code **)(_r_modules_funcs_p + 200));
    *puVar2 = 0xc;
    iVar1 = _r_ip_funcs_p;
    *(undefined2 *)(puVar2 + 2) = 0;
    (**(code **)(iVar1 + 0x8c))(*(code **)(iVar1 + 0x8c));
    return 0;
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x21c))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x21c));
  if (iVar1 == 0) {
    rw_rf_le_exit_test_mode();
  }
  else {
    puVar2 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1101,0,0x201f,4,*(code **)(_r_modules_funcs_p + 200));
    *puVar2 = (char)iVar1;
    iVar1 = _r_ip_funcs_p;
    *(undefined2 *)(puVar2 + 2) = 0;
    (**(code **)(iVar1 + 0x8c))(*(code **)(iVar1 + 0x8c));
  }
  return 0;
}

