/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_acl_hdr_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_acl_hdr_rx_evt_handler(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  r_ke_event_clear(0xb);
  r_h4tl_rx_acl_hdr_extract(&h4tl_env,&h4tl_env);
  if (_r_hci_cmd_received == 0) {
    r_hci_acl_tx_data_received(_DAT_00011012,0,0);
    r_rwip_prevent_sleep_set = (code)0x0;
    (*(code *)*_h4tl_env)(0x1101b,1,r_h4tl_rx_done,&h4tl_env,(code *)*_h4tl_env);
    r_rwip_prevent_sleep_clear(4);
    return;
  }
  iVar2 = r_hci_acl_tx_data_alloc();
  _r_rwip_prevent_sleep_clear = (undefined2)iVar2;
  if (iVar2 == 0) {
    _r_ke_event_clear = 0;
  }
  else {
    _r_ke_event_clear = r_emi_get_mem_addr_by_offset();
    if (_r_ke_event_clear != 0) {
      r_rwip_prevent_sleep_set = (code)0x2;
                    /* WARNING: Could not recover jumptable at 0x000101de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*_h4tl_env)
                (_r_ke_event_clear,_r_hci_cmd_received,r_h4tl_rx_done,&h4tl_env,(code *)*_h4tl_env);
      return;
    }
  }
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1103,0,0x10,1);
  *puVar1 = 0;
  r_hci_send_2_host();
  memset(&DAT_00011012,0,8);
  uRam0001101a = uRam0001101b;
  r_h4tl_read_next_out_of_sync(&h4tl_env);
  r_rwip_prevent_sleep_clear(4);
  return;
}

