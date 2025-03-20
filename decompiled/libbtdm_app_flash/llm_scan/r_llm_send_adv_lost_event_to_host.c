/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  
  if ((DAT_0001408e != '\0') && (_llm_le_adv_flow_env != 0)) {
    if (_co_rate_to_phy <= _memcmp) {
      puVar1 = (undefined1 *)r_ke_msg_alloc(0x1104,0,0,8);
      *puVar1 = 0xf0;
      *(uint *)(puVar1 + 4) = _memcmp;
      r_hci_send_2_host();
      _memcmp = 0;
      _llm_le_adv_flow_env = _llm_le_adv_flow_env + -1;
    }
  }
  return;
}

