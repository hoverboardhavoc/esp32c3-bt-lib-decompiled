/*
 * Last changed at upstream commit 3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * https://github.com/espressif/esp32c3-bt-lib/commit/3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * Upstream date: 2022-08-11 21:28:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f2e5d813)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_rep_flow_control_check_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_rep_flow_control_check_hack(int param_1,void *param_2)

{
  int iVar1;
  
  if (((((g_qa_test_config != '\0') && (param_1 != 0)) && (param_2 != (void *)0x0)) &&
      ((*(char *)(_p_llm_env + 0xd7) == '\x01' ||
       ((*(char *)(_p_llm_env + 0xd7) == '\x02' && (*(char *)(param_1 + 0x16) == '\0')))))) &&
     (iVar1 = memcmp(param_2,&g_qa_test_config,6), iVar1 == 0)) {
    _r_llm_adv_rep_flow_control_check = _r_llm_adv_rep_flow_control_check + 1;
  }
  r_llm_adv_rep_flow_control_check(param_1,param_2);
  return;
}

