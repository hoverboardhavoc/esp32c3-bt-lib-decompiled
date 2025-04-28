/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_tx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_tx_evt_handler(void)

{
  int iVar1;
  
  r_ke_event_clear(8);
  if ((byte)r_hci_cmd_get_max_param_size != 0xff) {
    iVar1 = (uint)(byte)r_hci_cmd_get_max_param_size * 0xc;
    if (*(int *)(r_ke_msg_alloc + iVar1) != 0) {
      return;
    }
    if (*(code **)(r_hci_send_2_host + iVar1) != (code *)0x0) {
      (**(code **)(r_hci_send_2_host + iVar1))();
    }
    r_hci_cmd_get_max_param_size = (code)0xff;
    if (_r_ke_msg_alloc != 0) {
      r_hci_cmd_get_max_param_size = (code)-(DAT_0001102a == '\0');
    }
    if (r_hci_cmd_get_max_param_size != (code)0xff) {
                    /* WARNING: Could not recover jumptable at 0x000100c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_h4tl_env + 4))(_memset + 1,r_h4tl_tx_done,&h4tl_env,*(code **)(_h4tl_env + 4));
      return;
    }
  }
  r_rwip_prevent_sleep_clear(2);
  return;
}

