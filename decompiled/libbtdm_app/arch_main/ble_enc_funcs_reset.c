/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> arch_main.o -> ble_enc_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_enc_funcs_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(undefined **)(_r_ip_funcs_p + 0x278) = &r_lld_res_list_clear_hack;
  *(undefined **)(iVar1 + 0x28c) = &r_lld_res_list_priv_mode_update_hack;
  *(undefined **)(iVar1 + 0x290) = &r_lld_res_list_rem_hack;
  *(undefined **)(iVar1 + 0x610) = &r_llc_le_ping_restart_hack;
  *(undefined **)(iVar1 + 0x59c) = &r_llc_rem_encrypt_proc_continue_eco;
  *(undefined **)(iVar1 + 0x870) = &r_llc_rem_encrypt_proc_continue_eco;
  *(undefined **)(iVar1 + 0x5b8) = &r_llc_llcp_tx_check_hack;
  *(undefined **)(iVar1 + 0x288) = &r_lld_res_list_peer_update_hack;
  return;
}

