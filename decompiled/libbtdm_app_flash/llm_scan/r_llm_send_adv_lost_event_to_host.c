/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
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
  
  if ((DAT_0001408a != '\0') && (_llm_le_adv_flow_env != 0)) {
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

