/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_hci.o -> f_hci_le_test_end_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_test_end_cmd_handler(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x21c))(*(code **)(_r_ip_funcs_p + 0x21c));
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

