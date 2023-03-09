/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_rep_flow_control_check_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_rep_flow_control_check_eco(int param_1,void *param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)(**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
  if (((((*pcVar1 != '\0') && (param_1 != 0)) && (param_2 != (void *)0x0)) &&
      ((*(char *)(_p_llm_env + 0xd7) == '\x01' ||
       ((*(char *)(_p_llm_env + 0xd7) == '\x02' && (*(char *)(param_1 + 0x16) == '\0')))))) &&
     (iVar2 = memcmp(param_2,pcVar1 + 2,6), iVar2 == 0)) {
    *(int *)(pcVar1 + 8) = *(int *)(pcVar1 + 8) + 1;
  }
  r_llm_adv_rep_flow_control_check(param_1,param_2);
  return;
}

