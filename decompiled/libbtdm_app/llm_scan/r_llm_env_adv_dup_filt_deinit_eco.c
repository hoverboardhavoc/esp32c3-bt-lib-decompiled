/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_env_adv_dup_filt_deinit_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_env_adv_dup_filt_deinit_eco(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
    r_llm_env_adv_dup_filt_deinit();
    return;
  }
  if (*(int *)(_p_llm_env + 0xcc) == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x8d8);
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x65c,*(code **)(_r_plf_funcs_p + 8));
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x8d8);
  }
                    /* WARNING: Could not recover jumptable at 0x00013708. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

