/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  r_ke_event_clear(8);
  bVar1 = false;
  bVar2 = false;
  while ((!bVar1 && ((byte)r_ke_malloc != 0xff))) {
    iVar3 = (uint)(byte)r_ke_malloc * 0xc;
    if (*(int *)(r_hci_send_2_host + iVar3) != 0) {
      return;
    }
    if (*(code **)(memset + iVar3) != (code *)0x0) {
      (**(code **)(memset + iVar3))();
    }
    r_ke_malloc = (code)0xff;
    if ((!bVar1) && (_r_hci_send_2_host != 0)) {
      r_ke_malloc = (code)-(DAT_0001102e == '\0');
    }
    bVar1 = true;
    if (r_ke_malloc != (code)0xff) {
      (**(code **)(_h4tl_env + 4))
                (_r_hci_cmd_get_max_param_size + 1,r_h4tl_tx_done,&h4tl_env,
                 *(code **)(_h4tl_env + 4));
      bVar1 = true;
      bVar2 = true;
    }
  }
  if (bVar2) {
    return;
  }
  r_rwip_prevent_sleep_clear(2);
  return;
}

