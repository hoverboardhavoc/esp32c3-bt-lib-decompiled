/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_task.o -> llm_pub_key_gen_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_pub_key_gen_ind_handler(void *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1104,0,0x3e,0x42,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = 8;
  puVar1[1] = 0;
  memcpy(puVar1 + 2,param_1,0x20);
  memcpy(puVar1 + 0x22,(void *)((int)param_1 + 0x20),0x20);
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar1,*(code **)(_r_ip_funcs_p + 0x8c));
  (*_lld_scan_req_ind_handler)(0x80,0x20,_p_llm_env + 0xa4,_lld_scan_req_ind_handler);
  return 0;
}

