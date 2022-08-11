/*
 * Last changed at upstream commit 3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * https://github.com/espressif/esp32c3-bt-lib/commit/3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * Upstream date: 2022-08-11 21:28:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f2e5d813)
 * Source: libbtdm_app -> llm_scan.o -> llm_scan_func_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_scan_func_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(code **)(_r_ip_funcs_p + 0x538) = r_llm_env_adv_dup_filt_init_hack;
  *(code **)(iVar1 + 0x53c) = r_llm_env_adv_dup_filt_deinit_hack;
  *(code **)(iVar1 + 0x534) = r_llm_adv_rep_flow_control_update_hack;
  *(code **)(iVar1 + 0x530) = r_llm_adv_rep_flow_control_check_hack;
  *(code **)(iVar1 + 0x514) = r_llm_scan_start_hack;
  return;
}

