/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_cmd_hdr_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_cmd_hdr_rx_evt_handler(void)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  
  r_ke_event_clear(9);
  r_h4tl_rx_cmd_hdr_extract(&h4tl_env,&h4tl_env);
  uVar3 = (uint)(byte)r_ke_free;
  if (uVar3 == 0) {
    r_hci_cmd_received(0,0);
    r_ke_msg_alloc = (code)0x0;
    (*(code *)*_h4tl_env)(0x1101f,1,r_h4tl_rx_done,&h4tl_env,(code *)*_h4tl_env);
    r_rwip_prevent_sleep_clear(4);
    return;
  }
  uVar2 = r_hci_cmd_get_max_param_size(_DAT_00011016);
  if (uVar3 <= uVar2) {
    _r_hci_cmd_received = 0;
    _r_rwip_prevent_sleep_clear = r_ke_malloc(r_ke_free,2);
    if (_r_rwip_prevent_sleep_clear != 0) {
      r_ke_msg_alloc = (code)0x2;
                    /* WARNING: Could not recover jumptable at 0x000101fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*_h4tl_env)
                (_r_rwip_prevent_sleep_clear,r_ke_free,r_h4tl_rx_done,&h4tl_env,(code *)*_h4tl_env);
      return;
    }
  }
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1103,0,0x10,1);
  *puVar1 = 0;
  r_hci_send_2_host();
  memset(&DAT_00011016,0,8);
  uRam0001101e = uRam0001101f;
  r_h4tl_read_next_out_of_sync(&h4tl_env);
  r_rwip_prevent_sleep_clear(4);
  return;
}

