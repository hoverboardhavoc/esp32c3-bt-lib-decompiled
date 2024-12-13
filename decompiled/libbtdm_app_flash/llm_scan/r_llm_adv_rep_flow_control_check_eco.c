/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_adv_rep_flow_control_check_eco
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
  
  pcVar2 = (char *)r_ble_ll_qa_config_get();
  if ((((*pcVar2 != '\0') && (param_1 != 0)) && (param_2 != (void *)0x0)) &&
     (((*(char *)(_p_llm_env + 0xd7) == '\x01' ||
       ((*(char *)(_p_llm_env + 0xd7) == '\x02' && (*(char *)(param_1 + 0x16) == '\0')))) &&
      (iVar3 = memcmp(param_2,pcVar2 + 2,6), iVar3 == 0)))) {
    *(int *)(pcVar2 + 8) = *(int *)(pcVar2 + 8) + 1;
  }
  if (((DAT_0001408a == '\0') ||
      (r_llm_send_adv_lost_event_to_host(param_1,param_2), *(char *)(_p_llm_env + 0xd7) != '\x01'))
     || ((DAT_0001408a == '\0' || (_llm_le_adv_flow_env != 0)))) {
    cVar1 = '\0';
  }
  else {
    _memcmp = _memcmp + 1;
    cVar1 = DAT_0001408a;
  }
  return cVar1;
}

