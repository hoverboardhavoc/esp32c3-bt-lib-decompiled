/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  if (((DAT_0001403e == '\0') ||
      ((**(code **)(_r_ip_funcs_p + 0x524))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x524)),
      *(char *)(_p_llm_env + 0xd7) != '\x01')) ||
     ((DAT_0001403e == '\0' || (_llm_le_adv_flow_env != 0)))) {
    cVar1 = '\0';
  }
  else {
    _memcmp = _memcmp + 1;
    cVar1 = DAT_0001403e;
  }
  return cVar1;
}

