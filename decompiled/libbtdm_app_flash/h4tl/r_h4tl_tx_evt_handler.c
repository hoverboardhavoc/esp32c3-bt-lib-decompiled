/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    if ((_r_ke_msg_alloc != 0) && (DAT_0001102a != '\0')) {
      r_hci_cmd_get_max_param_size = (code)0x0;
                    /* WARNING: Could not recover jumptable at 0x000100ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_h4tl_env + 4))(_memset + 1,0x10000,&h4tl_env);
      return;
    }
    r_hci_cmd_get_max_param_size = (code)0xff;
  }
  r_rwip_prevent_sleep_clear(2);
  return;
}

