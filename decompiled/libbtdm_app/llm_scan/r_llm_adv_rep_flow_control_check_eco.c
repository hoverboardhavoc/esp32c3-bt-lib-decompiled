/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_rep_flow_control_check_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_llm_adv_rep_flow_control_check_eco(int param_1,void *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)(**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
  if ((((*pcVar2 != '\0') && (param_1 != 0)) && (param_2 != (void *)0x0)) &&
     (((*(char *)(_p_llm_env + 0xd7) == '\x01' ||
       ((*(char *)(_p_llm_env + 0xd7) == '\x02' && (*(char *)(param_1 + 0x16) == '\0')))) &&
      (iVar3 = memcmp(param_2,pcVar2 + 2,6), iVar3 == 0)))) {
    *(int *)(pcVar2 + 8) = *(int *)(pcVar2 + 8) + 1;
  }
  if (((DAT_00014042 == '\0') ||
      ((**(code **)(_r_ip_funcs_p + 0x524))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x524)),
      *(char *)(_p_llm_env + 0xd7) != '\x01')) ||
     ((DAT_00014042 == '\0' || (_llm_le_adv_flow_env != 0)))) {
    cVar1 = '\0';
  }
  else {
    _memcmp = _memcmp + 1;
    cVar1 = DAT_00014042;
  }
  return cVar1;
}

