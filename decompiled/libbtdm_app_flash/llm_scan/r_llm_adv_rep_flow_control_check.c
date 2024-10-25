/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_adv_rep_flow_control_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_llm_adv_rep_flow_control_check(void)

{
  char cVar1;
  
  if ((((DAT_00014086 == '\0') ||
       (r_llm_send_adv_lost_event_to_host(), *(char *)(_p_llm_env + 0xd7) != '\x01')) ||
      (DAT_00014086 == '\0')) || (_llm_le_adv_flow_env != 0)) {
    cVar1 = '\0';
  }
  else {
    _r_co_bdaddr_compare = _r_co_bdaddr_compare + 1;
    cVar1 = DAT_00014086;
  }
  return cVar1;
}

