/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_send_adv_lost_event_to_host
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_send_adv_lost_event_to_host(void)

{
  undefined1 *puVar1;
  
  if ((DAT_00014086 != '\0') && (_llm_le_adv_flow_env != 0)) {
    if (_memcmp <= _r_co_bdaddr_compare) {
      puVar1 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0,8);
      *puVar1 = 0xf0;
      *(uint *)(puVar1 + 4) = _r_co_bdaddr_compare;
      r_hci_send_2_host();
      _r_co_bdaddr_compare = 0;
      _llm_le_adv_flow_env = _llm_le_adv_flow_env + -1;
    }
  }
  return;
}

