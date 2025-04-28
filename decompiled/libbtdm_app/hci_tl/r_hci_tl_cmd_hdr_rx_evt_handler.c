/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_tl_cmd_hdr_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tl_cmd_hdr_rx_evt_handler(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x48))(*(code **)(_r_ip_funcs_p + 0x48));
  if (_DAT_00012030 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x5a5,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_modules_funcs_p + 0xec))(6,*(code **)(_r_modules_funcs_p + 0xec));
  (**(code **)(_r_ip_funcs_p + 0x2c))
            (*(undefined2 *)(iVar1 + 1),*(undefined1 *)(iVar1 + 3),0,
             *(code **)(_r_ip_funcs_p + 0x2c));
                    /* WARNING: Could not recover jumptable at 0x00010bee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xdc))(*(code **)(_r_plf_funcs_p + 0xdc));
  return;
}

